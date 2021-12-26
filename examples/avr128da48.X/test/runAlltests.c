#include "../components/unity_onedir/unity.h"
#include "../components/unity_onedir/unity_fixture.h"
#include <stdio.h>
#include "../../../keypad-nxn.h"
#include "../../../test/keypad_test.c"

extern keypad_t mykeypad;

void runAllTests(void) {
    RUN_TEST_GROUP(keypad_driver);
}

int mainTest(void) {   
  
    testkeypad = &mykeypad; 
    
    const char *arg[] ={"rullAllTests.c", "-v", "-g", "keypad_driver", "-r", "2"};
    return UnityMain(sizeof (arg) / sizeof (char*), arg, runAllTests);
    
}
