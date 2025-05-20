//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>

// Define the log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

// Define the log file name
#define LOG_FILE_NAME "log.txt"

// Define the maximum log file size
#define LOG_FILE_MAX_SIZE 1024 * 1024

// Declare the log file pointer
FILE *log_file = NULL;

// Open the log file
int open_log_file()
{
    // Open the log file in append mode
    log_file = fopen(LOG_FILE_NAME, "a");

    // Check if the log file was opened successfully
    if (log_file == NULL)
    {
        return -1;
    }

    // Return 0 to indicate success
    return 0;
}

// Close the log file
int close_log_file()
{
    // Check if the log file is open
    if (log_file != NULL)
    {
        // Close the log file
        fclose(log_file);
    }

    // Return 0 to indicate success
    return 0;
}

// Log a message
int log_message(int log_level, const char *format, ...)
{
    // Check if the log file is open
    if (log_file == NULL)
    {
        // Open the log file
        if (open_log_file() != 0)
        {
            return -1;
        }
    }

    // Get the current time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Format the log message
    char log_message[1024];
    snprintf(log_message, sizeof(log_message), "[%02d:%02d:%02d] [%s] ", tm->tm_hour, tm->tm_min, tm->tm_sec, log_level == LOG_LEVEL_DEBUG ? "DEBUG" : log_level == LOG_LEVEL_INFO ? "INFO" : log_level == LOG_LEVEL_WARN ? "WARN" : "ERROR");

    // Append the log message to the log file
    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    // Flush the log file
    fflush(log_file);

    // Return 0 to indicate success
    return 0;
}

// Main function
int main()
{
    // Open the log file
    if (open_log_file() != 0)
    {
        return -1;
    }

    // Log a debug message
    log_message(LOG_LEVEL_DEBUG, "This is a debug message\n");

    // Log an info message
    log_message(LOG_LEVEL_INFO, "This is an info message\n");

    // Log a warn message
    log_message(LOG_LEVEL_WARN, "This is a warn message\n");

    // Log an error message
    log_message(LOG_LEVEL_ERROR, "This is an error message\n");

    // Close the log file
    close_log_file();

    return 0;
}