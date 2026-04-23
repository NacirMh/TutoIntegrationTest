#include <Arduino.h>
#include <unity.h>

#include "Rom.h"
#include "ContentService.h"

Rom rom(64);
ContentService service(&rom);

void setUp(void) {
    rom.begin();
}

void tearDown(void) {}

void test_save_and_load_int() {

    int input = 987654;

    service.saveContent(input);
    delay(50);

    int output = service.loadContent();

    TEST_ASSERT_EQUAL_INT(input, output);
}

void test_overwrite_value() {
    service.saveContent(111);
    delay(50);

    service.saveContent(222);
    delay(50);

    int result = service.loadContent();

    TEST_ASSERT_EQUAL_INT(222, result);
}

void setup() {
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(test_save_and_load_int);
    RUN_TEST(test_overwrite_value);

    UNITY_END();
}

void loop() {
    // leave empty
}