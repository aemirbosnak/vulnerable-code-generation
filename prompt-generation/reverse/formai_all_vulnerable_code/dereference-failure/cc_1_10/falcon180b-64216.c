//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "/var/log/intrusion_detection.log"
#define MAX_ATTEMPTS 3
#define SLEEP_TIME 5

char *log_file = LOG_FILE;
int max_attempts = MAX_ATTEMPTS;
int sleep_time = SLEEP_TIME;

void log_event(char *message) {
    FILE *log;
    time_t current_time;

    current_time = time(NULL);
    log = fopen(log_file, "a");

    if (log == NULL) {
        printf("Error opening log file: %s\n", strerror(errno));
        return;
    }

    fprintf(log, "%s - Event: %s\n", ctime(&current_time), message);
    fclose(log);
}

int is_authorized(char *username, char *password) {
    // Check if the user is authorized to access the system
}

int main() {
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int attempts = 0;

    while (1) {
        printf("Enter username: ");
        fgets(username, BUFFER_SIZE, stdin);
        printf("Enter password: ");
        fgets(password, BUFFER_SIZE, stdin);

        if (is_authorized(username, password)) {
            printf("Access granted\n");
            break;
        } else {
            attempts++;
            if (attempts == max_attempts) {
                log_event("Failed login attempt");
                printf("Too many failed attempts, access denied\n");
                exit(1);
            } else {
                printf("Incorrect username or password\n");
                usleep(sleep_time * 1000);
            }
        }
    }

    return 0;
}