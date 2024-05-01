(require :cffi)
(require :cffi-libffi)
(require :cl-ppcre)


(cffi:define-foreign-library libsimple-genie
  (t (:default "libsimple-genie")))

(setq cffi:*foreign-library-directories* (list #P"/home/p-hasan/work/aoe/simple-genie/build/"))

(cffi:use-foreign-library libsimple-genie)


(cffi:defctype genie-pointer :pointer)

(defclass my-genie ()
  ((pointer :initform (cffi:foreign-alloc :char :count 1
                                     :initial-element 0)
            :initarg :pointer)))

(cffi:define-foreign-type my-genie-type ()
  ()
  (:actual-type genie-pointer)
  (:simple-parser my-genie))


(defmethod cffi:translate-to-foreign (handle (type my-genie-type))
  (slot-value handle 'pointer))

(defmethod cffi:translate-from-foreign (ptr (type my-genie-type))
  (make-instance 'my-genie :pointer ptr))


(cffi:defcfun "load_dat" my-genie
  (filename :pointer))

(cffi:defcfun "get_unit" :int
  (handle my-genie)
  (unitname :pointer))

(cffi:defcfun "print_all" :int
  (handle my-genie))

(defun my-load (filename)
  (let ()
    (unwind-protect
         (cffi:with-foreign-string (f filename)
           (let ()
             (load-dat f))))))


(defun my-get-unit (handle unit-name)
  (let ()
    (unwind-protect
         (cffi:with-foreign-string (u unit-name)
           (let ()
             (get-unit handle u))))))
(defparameter *my-g* (my-load "/data/empires2_x2_p1.dat"))
(print-all *my-g*)
(my-get-unit *my-g* "GHULAM")
(my-get-unit *my-g* "ARCHR")


(sb-ext:exit)


