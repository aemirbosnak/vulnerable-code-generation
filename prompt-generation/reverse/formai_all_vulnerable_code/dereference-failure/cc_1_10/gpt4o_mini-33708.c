//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

#define LOG_FILE_PATH "/var/log/auth.log" // Change the path according to your system
#define MAX_LINE_LENGTH 256
#define MAX_FAILED_ATTEMPTS 5

typedef struct {
    char username[50];
    int failed_attempts;
} UserActivity;

void process_line(UserActivity *userActivities, int *count, const char *line) {
    regex_t regex;
    regmatch_t pmatch[1];
    char username[50];

    // Regex to match failed login attempts
    const char *failed_login_regex = "Failed password for (\\w+)";

    if (regcomp(&regex, failed_login_regex, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    // Check if the line matches the regex
    if (regexec(&regex, line, 1, pmatch, 0) == 0) {
        // Extract the username from the line
        strncpy(username, line + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
        username[pmatch[0].rm_eo - pmatch[0].rm_so] = '\0';
        
        // Update user activities
        for (int i = 0; i < *count; i++) {
            if (strcmp(userActivities[i].username, username) == 0) {
                userActivities[i].failed_attempts++;
                return;
            }
        }
        
        // New user activity
        strcpy(userActivities[*count].username, username);
        userActivities[*count].failed_attempts = 1;
        (*count)++;
    }
    
    regfree(&regex);
}

void check_for_intrusions(UserActivity *userActivities, int count) {
    for (int i = 0; i < count; i++) {
        if (userActivities[i].failed_attempts > MAX_FAILED_ATTEMPTS) {
            printf("ALERT: User '%s' has %d failed login attempts!\n",
                   userActivities[i].username,
                   userActivities[i].failed_attempts);
        }
    }
}

void monitor_log_file() {
    FILE *file = fopen(LOG_FILE_PATH, "r");
    if (!file) {
        perror("Error opening log file");
        return;
    }

    UserActivity userActivities[100] = {0};   // Keep track of activities
    int count = 0;                             // Number of different users

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        process_line(userActivities, &count, line);
    }

    fclose(file);
    check_for_intrusions(userActivities, count);
}

int main() {
    printf("Starting Intrusion Detection System...\n");
    
    while (1) {
        monitor_log_file();
        sleep(60); // Check every 60 seconds
    }

    return 0;
}