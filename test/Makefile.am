# Copyright (C) 2014-2015 Cryptotronix, LLC.

TESTS = ecc hmac hkdf
check_PROGRAMS = ecc hmac hkdf

ecc_SOURCES = ecc.c
ecc_CFLAGS = @CHECK_CFLAGS@
ecc_LDADD = ../libyacl.la @CHECK_LIBS@

hmac_SOURCES = hmac.c
hmac_CFLAGS = @CHECK_CFLAGS@
hmac_LDADD = ../libyacl.la @CHECK_LIBS@

hkdf_SOURCES = hkdf_test.c
hkdf_CFLAGS = @CHECK_CFLAGS@
hkdf_LDADD = ../libyacl.la @CHECK_LIBS@