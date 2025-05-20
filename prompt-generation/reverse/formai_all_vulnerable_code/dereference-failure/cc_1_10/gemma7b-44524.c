//Gemma-7B DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_ENTRIES 100

typedef struct LogEntry {
    char timestamp[26];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void logEvent(char* message) {
    LogEntry* newEntry = malloc(sizeof(LogEntry));
    time_t t = time(NULL);
    strftime(newEntry->timestamp, sizeof(newEntry->timestamp), "%H:%M:%S", localtime(&t));
    strcpy(newEntry->message, message);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        LogEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }

    if (head->next == NULL) {
        printf("Log full!\n");
    }
}

int main() {
    logEvent("User logged in.");
    logEvent("User purchased item.");
    logEvent("User updated profile.");
    logEvent("User logged out.");

    LogEntry* current = head;
    while (current) {
        printf("%s: %s\n", current->timestamp, current->message);
        current = current->next;
    }

    return 0;
}