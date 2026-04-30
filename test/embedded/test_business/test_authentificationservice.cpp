#include <unity.h>
#include <LittleFS.h>

#include "UserDao.h"
#include "AuthenticationService.h"

UserDao* userDao;
AuthenticationService* authService;

void setUp(void) {
    // IMPORTANT: mount filesystem first
    if (!LittleFS.begin(true)) {
        Serial.println("LittleFS mount failed");
    }

    userDao = new UserDao("/littlefs/test.db");
    authService = new AuthenticationService(userDao);
}

void tearDown(void) {
    delete authService;
    delete userDao;
}

void test_verify_user_success() {
    bool result = authService->VerifyUser("123");
    TEST_ASSERT_TRUE(result);
}

void test_verify_user_fail() {
    bool result = authService->VerifyUser("999");
    TEST_ASSERT_FALSE(result);
}

void setup() {
    Serial.begin(115200);

    UNITY_BEGIN();

    RUN_TEST(test_verify_user_success);
    RUN_TEST(test_verify_user_fail);

    UNITY_END();
}

void loop() {
    // nothing
}