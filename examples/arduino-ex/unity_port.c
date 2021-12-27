#if defined(ARDUINO) && defined(__AVR_ATmega2560__) && defined(TEST_PROJECT)

#include <string.h>
#include "unity/unity.h"
#include "Arduino.h"

static uint32_t s_test_start, s_test_stop;

void unity_putc(int c)
{
    if (c == '\n')
    {
        Serial.write('\r');
        Serial.write('\n');
    }
    else if (c == '\r')
    {
    }
    else
    {
        Serial.write(c);
    }
}

void unity_flush(void)
{
    //Serial.flush();
}

void unity_exec_time_start(void)
{
    s_test_start = millis();
}

void unity_exec_time_stop(void)
{
    s_test_stop = millis();
}

uint32_t unity_exec_time_get_ms(void)
{
    return (s_test_stop - s_test_start);
}

#endif
