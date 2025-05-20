//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000
#define MAX_IP_SIZE 16

// Linked List node to hold IP addresses
struct Node {
    char ip[MAX_IP_SIZE];
    int count;
    struct Node* next;
};

// Function declarations
void logMessage(char* ip);
void printLogs();
void detectIntrusion();

// Global variables
int logSize = 0;
time_t lastUpdated;
struct Node* head = NULL;

int main() {
    lastUpdated = time(NULL);
    printf("Intrusion detection system started...\n");
    while(1) {
        char ip[MAX_IP_SIZE];
        printf("\nEnter IP address: ");
        scanf("%s", ip);
        logMessage(ip);
        detectIntrusion();
    }
    return 0;
}

// Function to log IP addresses
void logMessage(char* ip) {
    if(logSize == MAX_LOG_SIZE) {
        printLogs();
        lastUpdated = time(NULL);
        logSize = 0;
    }
    if(head == NULL) {
        head = (struct Node*) malloc(sizeof(struct Node));
        strcpy(head->ip, ip);
        head->count = 1;
        head->next = NULL;
        logSize++;
        return;
    }
    struct Node* curr = head;
    while(curr != NULL) {
        if(strcmp(curr->ip, ip) == 0) {
            curr->count++;
            return;
        }
        if(curr->next == NULL) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            strcpy(newNode->ip, ip);
            newNode->count = 1;
            newNode->next = NULL;
            curr->next = newNode;
            logSize++;
            return;
        }
        curr = curr->next;
    }
}

// Function to print IP address logs and reset the linked list
void printLogs() {
    printf("\n\n******** Intrusion Detection System Logs ********\n\n");
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%s - %d\n", curr->ip, curr->count);
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
}

// Function to detect intrusion
void detectIntrusion() {
    time_t currentTime = time(NULL);
    if(currentTime - lastUpdated > 60) { // if logs haven't been printed in the last minute
        if(logSize > 10) { // if more than 10 IP addresses have been logged
            printf("\n\n*** WARNING: Possible intrusion detected! ***\n\n");
            printLogs();
        } else {
            printf("\n\nNo intrusion detected.\n\n");
            head = NULL;
            logSize = 0;
        }
        lastUpdated = currentTime;
    }
}