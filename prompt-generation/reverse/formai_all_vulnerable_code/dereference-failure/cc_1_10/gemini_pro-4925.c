//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <errno.h>

// Define the maximum size of a log message
#define MAX_LOG_SIZE 1024

// Define the name of the application for syslog messages
#define APP_NAME "my_app"

// Define the facility for syslog messages
#define FACILITY LOG_USER

// Declare the syslog message priority levels
const char *priority_names[] = {
    [LOG_EMERG]    = "emerg",
    [LOG_ALERT]    = "alert",
    [LOG_CRIT]     = "crit",
    [LOG_ERR]      = "err",
    [LOG_WARNING]  = "warning",
    [LOG_NOTICE]   = "notice",
    [LOG_INFO]     = "info",
    [LOG_DEBUG]    = "debug"
};

// Declare the syslog message facility names
const char *facility_names[] = {
    [LOG_KERN]     = "kern",
    [LOG_USER]     = "user",
    [LOG_MAIL]     = "mail",
    [LOG_DAEMON]   = "daemon",
    [LOG_AUTH]     = "auth",
    [LOG_SYSLOG]   = "syslog",
    [LOG_LPR]      = "lpr",
    [LOG_NEWS]     = "news",
    [LOG_UUCP]     = "uucp",
    [LOG_CRON]     = "cron",
    [LOG_AUTHPRIV] = "authpriv",
    [LOG_FTP]      = "ftp",
    [LOG_LOCAL0]   = "local0",
    [LOG_LOCAL1]   = "local1",
    [LOG_LOCAL2]   = "local2",
    [LOG_LOCAL3]   = "local3",
    [LOG_LOCAL4]   = "local4",
    [LOG_LOCAL5]   = "local5",
    [LOG_LOCAL6]   = "local6",
    [LOG_LOCAL7]   = "local7"
};

// Define the struct for the log message
typedef struct log_message {
    int priority;
    int facility;
    char *message;
} log_message;

// Create a new log message
log_message *new_log_message(int priority, int facility, char *message) {
    log_message *lm = malloc(sizeof(log_message));
    lm->priority = priority;
    lm->facility = facility;
    lm->message = message;
    return lm;
}

// Free a log message
void free_log_message(log_message *lm) {
    free(lm->message);
    free(lm);
}

// Format a log message
char *format_log_message(log_message *lm) {
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    char *priority_name = priority_names[lm->priority];
    char *facility_name = facility_names[lm->facility];
    char *formatted_message = malloc(MAX_LOG_SIZE);
    snprintf(formatted_message, MAX_LOG_SIZE, "%s %s %s: %s\n", timestamp, priority_name, facility_name, lm->message);
    return formatted_message;
}

// Send a log message to syslog
void send_log_message(log_message *lm) {
    // Open the syslog connection
    openlog(APP_NAME, LOG_CONS | LOG_PID, lm->facility);
    // Send the log message
    syslog(lm->priority, "%s", lm->message);
    // Close the syslog connection
    closelog();
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a priority and facility
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <priority> <facility> <message>\n", argv[0]);
        return 1;
    }

    // Parse the priority and facility
    int priority = atoi(argv[1]);
    int facility = atoi(argv[2]);

    // Check if the priority and facility are valid
    if (priority < LOG_EMERG || priority > LOG_DEBUG) {
        fprintf(stderr, "Invalid priority: %s\n", argv[1]);
        return 1;
    }
    if (facility < LOG_KERN || facility > LOG_LOCAL7) {
        fprintf(stderr, "Invalid facility: %s\n", argv[2]);
        return 1;
    }

    // Parse the message
    char *message = argv[3];

    // Create a log message
    log_message *lm = new_log_message(priority, facility, message);

    // Format the log message
    char *formatted_message = format_log_message(lm);

    // Send the log message to syslog
    send_log_message(lm);

    // Free the log message
    free_log_message(lm);

    // Free the formatted log message
    free(formatted_message);

    return 0;
}