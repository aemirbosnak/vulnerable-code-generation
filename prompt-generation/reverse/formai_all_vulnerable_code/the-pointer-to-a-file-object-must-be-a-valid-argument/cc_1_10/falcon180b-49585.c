//Falcon-180B DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_MESSAGES 100

typedef struct {
    time_t timestamp;
    char message[1024];
} LogMessage;

void log_message(char* message) {
    LogMessage log_entry;
    time(&log_entry.timestamp);
    strcpy(log_entry.message, message);
    printf("Logged message: %s\n", message);
}

void print_log() {
    FILE* log_file = fopen("event_log.txt", "r");
    char line[1024];
    int count = 0;
    while(fgets(line, sizeof(line), log_file)!= NULL) {
        printf("%s", line);
        count++;
        if(count >= MAX_LOG_MESSAGES) {
            break;
        }
    }
    fclose(log_file);
}

int main() {
    printf("Welcome to the Happy Event Logger!\n");
    printf("Please enter your name:\n");
    char name[1024];
    fgets(name, sizeof(name), stdin);

    printf("Hello, %s! What would you like to log today?\n", name);
    char message[1024];
    fgets(message, sizeof(message), stdin);
    log_message(message);
    printf("Your message has been logged!\n");

    printf("Would you like to view the event log? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y') {
        print_log();
    }

    return 0;
}