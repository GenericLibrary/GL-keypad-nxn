#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

#include <stdint.h>

#define UNITY_EXCLUDE_TIME_H

#ifdef __cplusplus
extern "C"
{
#endif

    void unity_flush(void);
    void unity_putc(int c);
    void unity_exec_time_start(void);
    void unity_exec_time_stop(void);
    uint32_t unity_exec_time_get_ms(void);
    
#ifdef __cplusplus
}
#endif

#define UNITY_OUTPUT_CHAR(a) unity_putc(a)
#define UNITY_OUTPUT_FLUSH() unity_flush()
#define UNITY_EXEC_TIME_START() unity_exec_time_start()
#define UNITY_EXEC_TIME_STOP() unity_exec_time_stop()
#define UNITY_EXEC_TIME_MS() unity_exec_time_get_ms()



#endif