/*
 * runalltests.c
 *
 *  Created on: Dec 23, 2021
 *      Author: bill_
 */

#include "unity.h"
#include <stdio.h>
#include "unity_fixture.h"
#include "unity.h"
#include "../../../keypad-nxn.h"
#include "../../../test/keypad_test.c"

extern keypad_t mykeypad;

void runAllTests(void) {
	RUN_TEST_GROUP(keypad_driver);
}

int mainTest(void) {
	testkeypad = &mykeypad;

	//const char *args[] = {"main_test.c", "-v", "", "-g", "", "-n", "", "-r", ""};
	const char *args[] =
			{ "main_test.c", "-v", "-g", "keypad_driver", "-r", "2" };

	UnityMain(sizeof(args) / sizeof(char*), args, runAllTests);
	return 1;
}

