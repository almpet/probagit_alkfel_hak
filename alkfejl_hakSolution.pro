TEMPLATE = subdirs
SUBDIRS += alkfejl_hak \
    alkfejl_hakTest \
    alkfejl_hakLib

alkfejl_hakTest.depends = alkfejl_hakLib
alkfejl_hak.depends = alkfejl_hakLib

