 #include "../unity_config.h"
#include "../unity/unity.h"
#include "../unity/unity_fixture.h"
#include "stdio.h"
#include "keypad-nxn.h"
 
 void runAllTests(void)
{
  RUN_TEST_GROUP(keypad_driver);
}