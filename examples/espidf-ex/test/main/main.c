#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"

static void runAllTests(void)
{
    RUN_TEST_GROUP(keypad_driver);
}

void app_main(void)
{
    //const char *args[] = {"main_test.c", "-v", "", "-g", "", "-n", "", "-r", ""};
    const char *args[] = {"main_test.c", "-v", "-g", "keypad_driver", "-r", "1"};

    UnityMain(sizeof(args) / sizeof(char *), args, runAllTests);
    return;
}