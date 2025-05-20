//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define LOG_FILE "intrusion.log"
#define MAX_LOG_ENTRIES 100

// Function to log intrusion detection events
void log_event(const char *format,...) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fclose(log_file);
}

// Function to check for suspicious activity
void check_activity(const char *username, const char *activity) {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), log_file)!= NULL) {
        if (strstr(line, username)!= NULL && strstr(line, activity)!= NULL) {
            printf("Suspicious activity detected for user '%s' performing '%s'.\n", username, activity);
            log_event("Suspicious activity detected for user '%s' performing '%s'.\n", username, activity);
        }
    }

    fclose(log_file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <username> <activity>\n", argv[0]);
        return 1;
    }

    const char *username = argv[1];
    const char *activity = argv[2];

    check_activity(username, activity);

    return 0;
}