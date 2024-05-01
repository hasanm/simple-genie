(require :cffi)
(require :cffi-libffi)
(require :cl-ppcre)


(cffi:define-foreign-library libsimple-genie
  (t (:default "libsimple-genie")))

(setq cffi:*foreign-library-directories* (list #P"/home/p-hasan/work/aoe/simple-genie/build/"))

(cffi:use-foreign-library libsimple-genie)


(cffi:defctype genie-pointer :pointer)

(defclass my-genie ()
  ((pointer :initform '()
            :initarg :pointer)))

(cffi:define-foreign-type my-genie-type ()
  ()
  (:actual-type genie-pointer)
  (:simple-parser my-genie))


(defmethod cffi:translate-to-foreign (handle (type my-genie-type))
  (slot-value handle 'pointer))

(defmethod cffi:translate-from-foreign (ptr (type my-genie-type))
  (make-instance 'my-genie :pointer ptr))


(cffi:defcfun "load_dat" :int
  (handle my-genie)
  (filename :pointer))


(defun my-load (filename)
  (let ((handle (make-instance 'my-genie)))
    (unwind-protect
         (cffi:with-foreign-string (f filename)
           (let ()
             (load-dat handle f)
             handle)))))

(my-load "/data/empires2_x2_p1.dat")


(sb-ext:exit)

