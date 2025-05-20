//FormAI DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure representing the log entry.
typedef struct LogEntry {
    char timestamp[20];
    char source[20];
    char message[100];
} LogEntry;

// A structure representing a node of the linked list.
typedef struct Node {
    LogEntry *entry;
    struct Node *next;
} Node;

// The head of the linked list.
Node *head = NULL;

// This method adds a log entry to the linked list.
void addLogEntry(LogEntry *entry) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->entry = entry;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *curr_node = head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }

    curr_node->next = new_node;
}

// This method prints the contents of the linked list.
void printLogEntries() {
    if (head == NULL) {
        printf("The log is empty.\n");
        return;
    }

    Node *curr_node = head;
    while (curr_node != NULL) {
        printf("[%s] [%s] %s\n", curr_node->entry->timestamp, curr_node->entry->source, curr_node->entry->message);
        curr_node = curr_node->next;
    }
}

int main() {
    // Creating some log entries.
    LogEntry *entry1 = (LogEntry *)malloc(sizeof(LogEntry));
    LogEntry *entry2 = (LogEntry *)malloc(sizeof(LogEntry));
    LogEntry *entry3 = (LogEntry *)malloc(sizeof(LogEntry));

    strcpy(entry1->timestamp, "2022-01-01 10:00:00");
    strcpy(entry1->source, "Server 1");
    strcpy(entry1->message, "Connection established.");

    strcpy(entry2->timestamp, "2022-01-02 08:00:00");
    strcpy(entry2->source, "Server 2");
    strcpy(entry2->message, "Connection terminated due to timeout.");

    strcpy(entry3->timestamp, "2022-01-03 16:00:00");
    strcpy(entry3->source, "Server 3");
    strcpy(entry3->message, "System shutdown initiated.");

    // Adding the log entries to the linked list.
    addLogEntry(entry1);
    addLogEntry(entry2);
    addLogEntry(entry3);

    // Printing the log entries.
    printLogEntries();

    return 0;
}