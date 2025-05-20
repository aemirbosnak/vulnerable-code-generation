//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define LOG_FILE "intrusion_log.txt"
#define MAX_ATTEMPTS 3
#define BLOCKED_TIME 60 // in seconds
#define MONITOR_FILE "/etc/passwd"

typedef struct {
    char username[50];
    int attempts;
    time_t last_attempt_time;
} User;

User blocked_users[MAX_ATTEMPTS];
int blocked_user_count = 0;

void log_intrusion(const char *username) {
    FILE *log_file = fopen(LOG_FILE, "a");
    time_t now = time(NULL);
    fprintf(log_file, "Intrusion attempt by user %s at %s", username, ctime(&now));
    fclose(log_file);
}

int is_user_blocked(const char *username) {
    for (int i = 0; i < blocked_user_count; i++) {
        if (strcmp(blocked_users[i].username, username) == 0) {
            if (difftime(time(NULL), blocked_users[i].last_attempt_time) < BLOCKED_TIME) {
                return 1; // User is still blocked
            } else {
                // Unblock user after BLOCKED_TIME
                blocked_users[i] = blocked_users[--blocked_user_count];
            }
        }
    }
    return 0; // User is not blocked
}

void block_user(const char *username) {
    if (blocked_user_count < MAX_ATTEMPTS) {
        strcpy(blocked_users[blocked_user_count].username, username);
        blocked_users[blocked_user_count].attempts = 1;
        blocked_users[blocked_user_count++].last_attempt_time = time(NULL);
    } else {
        // if array is full, replace the first blocked user
        strcpy(blocked_users[0].username, username);
        blocked_users[0].attempts++;
        blocked_users[0].last_attempt_time = time(NULL);
    }
    log_intrusion(username);
    printf("User %s is blocked for %d seconds.\n", username, BLOCKED_TIME);
}

void monitor_file() {
    struct stat file_stat;
    time_t last_size = 0;
    
    while (1) {
        stat(MONITOR_FILE, &file_stat);
        if (last_size != file_stat.st_mtime) {
            printf("[INFO] Change detected in %s. Checking...\n", MONITOR_FILE);
            FILE *file = fopen(MONITOR_FILE, "r");
            char line[256];
            while (fgets(line, sizeof(line), file)) {
                char *username = strtok(line, ":");
                if (is_user_blocked(username)) {
                    printf("Access denied for blocked user: %s\n", username);
                } else {
                    printf("User %s accessed the file.\n", username);
                }
            }
            fclose(file);
            last_size = file_stat.st_mtime;
        }
        sleep(5); // Delay between checks
    }
}

int main() {
    printf("Intrusion Detection System is monitoring changes to %s\n", MONITOR_FILE);
    monitor_file();

    return 0;
}