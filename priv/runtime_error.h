#pragma once

void RuntimeError(const char *message,
                  const char *file, int line);

#define RUNTIME_ERROR(description) \
    RuntimeError(description, __FILE__, __LINE__)

void RuntimeError_Reset(void);
const char *RuntimeError_GetLastMessage(void);
int RuntimeError_GetLastParameter(void);