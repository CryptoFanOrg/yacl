#include "../yacl.h"
#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/ecc/uECC.h"
#include <stdio.h>

#define NUM_TESTS 1

uint8_t *keys[NUM_TESTS];
uint8_t *msg[NUM_TESTS];
uint8_t *mac[NUM_TESTS];

static void
init_tests (void)
{

}

START_TEST(t_hmac_kat)
{

    uint8_t key[] =
        {0x97, 0x79, 0xd9, 0x12, 0x06, 0x42, 0x79, 0x7f, 0x17, 0x47, 0x02,
               0x5d, 0x5b, 0x22, 0xb7, 0xac, 0x60, 0x7c, 0xab, 0x08, 0xe1, 0x75,
               0x8f, 0x2f, 0x3a, 0x46, 0xc8, 0xbe, 0x1e, 0x25, 0xc5, 0x3b, 0x8c,
               0x6a, 0x8f, 0x58, 0xff, 0xef, 0xa1, 0x76 };
    uint8_t msg[] =
        {0xb1, 0x68, 0x9c, 0x25, 0x91, 0xea, 0xf3, 0xc9, 0xe6, 0x60, 0x70,
              0xf8, 0xa7, 0x79, 0x54, 0xff, 0xb8, 0x17, 0x49, 0xf1, 0xb0, 0x03,
              0x46, 0xf9, 0xdf, 0xe0, 0xb2, 0xee, 0x90, 0x5d, 0xcc, 0x28, 0x8b,
              0xaf, 0x4a, 0x92, 0xde, 0x3f, 0x40, 0x01, 0xdd, 0x9f, 0x44, 0xc4,
              0x68, 0xc3, 0xd0, 0x7d, 0x6c, 0x6e, 0xe8, 0x2f, 0xac, 0xea, 0xfc,
              0x97, 0xc2, 0xfc, 0x0f, 0xc0, 0x60, 0x17, 0x19, 0xd2, 0xdc, 0xd0,
              0xaa, 0x2a, 0xec, 0x92, 0xd1, 0xb0, 0xae, 0x93, 0x3c, 0x65, 0xeb,
              0x06, 0xa0, 0x3c, 0x9c, 0x93, 0x5c, 0x2b, 0xad, 0x04, 0x59, 0x81,
              0x02, 0x41, 0x34, 0x7a, 0xb8, 0x7e, 0x9f, 0x11, 0xad, 0xb3, 0x04,
              0x15, 0x42, 0x4c, 0x6c, 0x7f, 0x5f, 0x22, 0xa0, 0x03, 0xb8, 0xab,
              0x8d, 0xe5, 0x4f, 0x6d, 0xed, 0x0e, 0x3a, 0xb9, 0x24, 0x5f, 0xa7,
              0x95, 0x68, 0x45, 0x1d, 0xfa, 0x25, 0x8e };
    uint8_t mac[] =
        {0x76, 0x9f, 0x00, 0xd3, 0xe6, 0xa6, 0xcc, 0x1f, 0xb4, 0x26, 0xa1,
              0x4a, 0x4f, 0x76, 0xc6, 0x46, 0x2e, 0x61, 0x49, 0x72, 0x6e, 0x0d,
              0xee, 0x0e, 0xc0, 0xcf, 0x97, 0xa1, 0x66, 0x05, 0xac, 0x8b };

    int rc;
    uint8_t result[YACL_SHA256_LEN];

    rc = yacl_hmac_sha256(key, sizeof(key),
                          msg, sizeof(msg),
                          result);

    ck_assert (0 == rc);
    ck_assert (0 == memcmp (result, mac, sizeof(mac)));
}
END_TEST


static Suite *
witech2_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("hmac");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, t_hmac_kat);

    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = witech2_suite();
    sr = srunner_create(s);

    srunner_set_log (sr, "hmac_result.log");
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}