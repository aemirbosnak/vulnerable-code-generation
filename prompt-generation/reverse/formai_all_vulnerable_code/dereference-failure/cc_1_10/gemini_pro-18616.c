//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define LOGGER_SIZE 1000  // Arbitrary size

typedef struct _logger_t {
    char* buffer;
    size_t size;
    size_t offset;
    int level;
} logger_t;

logger_t logger;

void logg(int level, const char* format, ...) {
    if (level < logger.level) return;
    
    va_list args;
    va_start(args, format);
    
    size_t len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    if (logger.offset + len >= logger.size) return;
    
    va_start(args, format);
    vsnprintf(logger.buffer + logger.offset, len + 1, format, args);
    va_end(args);
    
    size_t add = strlen(logger.buffer + logger.offset);
    logger.offset += add;
}

void loggln(int level, const char* format, ...) {
    if (level < logger.level) return;
    
    logg(level, "%s\n", format);
}

void loggd(int level, const char* label, const char* data) {
    if (level < logger.level) return;
    
    if (strlen(label) + strlen(data) + 5 > logger.size) return;
    
    snprintf(logger.buffer + logger.offset, logger.size - logger.offset, "[%s] %s\n", label, data);
    logger.offset += strlen(logger.buffer + logger.offset);
}

void logger_init(size_t size, int level) {
    if (size < 64) size = 64;  // Arbitrary minimum size
    
    logger.buffer = malloc(size);
    logger.size = size;
    logger.offset = 0;
    logger.level = level;
}

void logger_deinit() {
    free(logger.buffer);
}

int main() {
    logger_init(LOGGER_SIZE, 2);
    
    logg(3, "This is a level 3 message");
    loggln(2, "This is a level 2 message");
    loggd(1, "Label", "Some data");
    
    printf("%s", logger.buffer);
    
    logger_deinit();
    
    return 0;
}