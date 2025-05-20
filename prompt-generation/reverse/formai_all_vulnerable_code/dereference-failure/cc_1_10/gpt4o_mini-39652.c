//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_ATTEMPTS 3
#define LOG_FILE "/var/log/secure.log"

void log_attempt(const char *username, bool success) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        time_t now = time(NULL);
        char *time_str = ctime(&now);
        time_str[strlen(time_str) - 1] = '\0'; // Remove newline

        fprintf(file, "%s | User: %s | Attempt: %s\n", time_str, username, success ? "SUCCESS" : "FAILURE");
        fclose(file);
    } else {
        fprintf(stderr, "Failed to log attempt!\n");
    }
}

bool ask_for_password(const char *username) {
    char password[64];
    const char *correct_password = "securePass";  // This should be securely hashed in production

    printf("Enter password for user %s: ", username);
    // Mask input by reading character by character
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && i < sizeof(password) - 1) {
        if (ch == 127 || ch == 8) { // Only handle backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
            continue;
        }
        password[i++] = ch;
        printf("\b*");
    }
    password[i] = '\0';

    return strcmp(password, correct_password) == 0;
}

bool user_login(const char *username) {
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        if (ask_for_password(username)) {
            log_attempt(username, true);
            printf("\nAccess granted.\n");
            return true;
        } else {
            attempts++;
            log_attempt(username, false);
            printf("\nAccess denied. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }
    printf("Max attempts reached. Exiting...\n");
    return false;
}

void check_system_integrity() {
    struct stat fileStat;
    // Check critical files' access rights; you can add more sensitive file paths.
    const char *files_to_check[] = {"/etc/passwd", "/etc/shadow", "/etc/hosts"};
    
    for (int i = 0; i < sizeof(files_to_check) / sizeof(files_to_check[0]); i++) {
        if (stat(files_to_check[i], &fileStat) < 0) {
            printf("Error accessing %s\n", files_to_check[i]);
            continue;
        }

        if (fileStat.st_mode & S_ISUID) {
            printf("Warning: %s has SUID set!\n", files_to_check[i]);
        }
        if (fileStat.st_mode & S_ISGID) {
            printf("Warning: %s has SGID set!\n", files_to_check[i]);
        }
        if ((fileStat.st_mode & S_IRUSR) == 0) {
            printf("Warning: %s is not readable by owner!\n", files_to_check[i]);
        }
    }
}

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
            printf("\nInterrupt signal caught! Exiting program securely...\n");
            exit(0);
        case SIGTERM:
            printf("\nTermination signal caught! Exiting program securely...\n");
            exit(0);
        default:
            break;
    }
}

void setup_signal_handling() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
}

int main() {
    setup_signal_handling();

    struct passwd *pw;
    char *username;

    username = getenv("USER");
    if (username == NULL) {
        fprintf(stderr, "Could not retrieve username.\n");
        return 1;
    }

    printf("Welcome, %s! The system is monitoring your attempts...\n", username);
    
    if (!user_login(username)) {
        return 1; // Exit if login failed
    }

    printf("Running system integrity checks...\n");
    check_system_integrity();

    printf("All checks complete. System stable.\n");
    // Any further privileged actions would go here

    return 0;
}