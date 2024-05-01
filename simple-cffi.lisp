(require :cffi)
(require :cffi-libffi)
(require :cl-ppcre)


(cffi:define-foreign-library libsimple-genie
  (t (:default "libsimple-genie")))

(setq cffi:*foreign-library-directories* (list #P"/home/p-hasan/work/aoe/simple-genie/build/"))

(cffi:use-foreign-library libsimple-genie)


(sb-ext:exit)

