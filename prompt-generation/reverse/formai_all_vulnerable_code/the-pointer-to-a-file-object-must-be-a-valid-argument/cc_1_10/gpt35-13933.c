//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LINE 256        // Maximum length of input

bool checkRoot() {
    FILE *fp = popen("whoami", "r");    // Execute command 'whoami' and read output
    char username[MAX_LINE];
    fgets(username, MAX_LINE, fp);      // Extract username from output
    pclose(fp);                         // Close pipe

    if (strcmp(username, "root\n") == 0)    // Check if user is root
        return true;

    return false;
}

void logEvent(char* event) {
    FILE *fp;
    if (!checkRoot()) {     // Check if user is root
        fprintf(stderr, "Error: Cannot log event, user not root\n");
        return;
    }

    fp = fopen("/var/log/intrusion_detection.log", "a");    // Open log file in append mode
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open log file\n");
        return;
    }

    fprintf(fp, "%s\n", event);     // Write event to log file
    fclose(fp);
}

void checkIntrusion() {
    FILE *authlog;
    char buffer[MAX_LINE];

    if (!checkRoot()) {     // Check if user is root
        fprintf(stderr, "Error: Cannot read auth.log, user not root\n");
        return;
    }

    authlog = fopen("/var/log/auth.log", "r"); // Open auth.log file in read mode
    if (authlog == NULL) {
        fprintf(stderr, "Error: Cannot open auth.log\n");
        return;
    }

    while (fgets(buffer, MAX_LINE, authlog)) {
        if (strstr(buffer, "Invalid user")) {     // Check if log contains "Invalid user" string
            logEvent(buffer);   // If yes, log this event
        }
    }

    fclose(authlog);
}

int main() {
    checkIntrusion();       // Check for intrusion attempts
    return 0;
}