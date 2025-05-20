//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

// Define the event facility.
#define FACILITY LOG_USER

// Define the event priorities.
#define LOG_INFO 6
#define LOG_WARNING 4
#define LOG_ERROR 3
#define LOG_CRITICAL 2

// Define the event tags.
#define TAG_APPLICATION "application"
#define TAG_SYSTEM "system"
#define TAG_NETWORK "network"

// Initialize the event logger.
void init_event_logger()
{
    // Set the logging facility and the minimum priority level.
    openlog(TAG_APPLICATION, LOG_CONS | LOG_PID, FACILITY);
    setlogmask(LOG_UPTO(LOG_DEBUG));
}

// Log an event.
void log_event(int priority, const char *tag, const char *message)
{
    // Create a syslog message.
    char *syslog_message;
    asprintf(&syslog_message, "%s: %s", tag, message);

    // Log the message.
    syslog(priority, "%s", syslog_message);

    // Free the memory allocated for the syslog message.
    free(syslog_message);
}

// Main function.
int main()
{
    // Initialize the event logger.
    init_event_logger();

    // Log an info event.
    log_event(LOG_INFO, TAG_APPLICATION, "Application started");

    // Log a warning event.
    log_event(LOG_WARNING, TAG_SYSTEM, "Low disk space");

    // Log an error event.
    log_event(LOG_ERROR, TAG_NETWORK, "Network connection failed");

    // Log a critical event.
    log_event(LOG_CRITICAL, TAG_SYSTEM, "System crash");

    // Close the event logger.
    closelog();

    return 0;
}