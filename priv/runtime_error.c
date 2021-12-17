
#include "runtime_error.h"
#include "assert.h"
#include "stdio.h"

#define TEST_MODE true

// parameter == -1: no errors
// parameter == 0 : error

static const char *message = "No Error";
static int parameter = -1;
static const char *file = 0;
static int line = -1;

void RuntimeError_Reset(void)
{
    message = "No Error";
    parameter = -1;
}
const char *RuntimeError_GetLastMessage(void)
{
    return message;
}
void RuntimeError(const char *m, const char *f, int l)
{
#if (TEST_MODE == true)
    message = m;
    //parameter = p;
    parameter = 0;
    file = f;
    line = l;
#else
    assert(0);
#endif
}
int RuntimeError_GetLastParameter(void)
{
    return parameter;
}
