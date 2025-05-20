//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 256
#define THRESHOLD 10
#define MAX_TIME_DELAY 5 // In seconds

typedef struct {
    time_t timestamp;
    char sourceIP[BUFFER_SIZE];
    char destinationIP[BUFFER_SIZE];
    bool isMalicious;
} LogEntry;

typedef struct {
    int currentIndex;
    int size;
    LogEntry* entries;
} LogBuffer;

void printLogEntry(LogEntry entry) {
    char* isMaliciousString = entry.isMalicious ? "Malicious" : "Non-Malicious";
    printf("Timestamp: %ld | Source IP: %s | Destination IP: %s | %s\n",
           entry.timestamp, entry.sourceIP, entry.destinationIP, isMaliciousString);
}

void initLogBuffer(LogBuffer* buffer, int size) {
    buffer->currentIndex = 0;
    buffer->size = size;
    buffer->entries = (LogEntry*) malloc(sizeof(LogEntry) * size);
    for (int i = 0; i < buffer->size; i++) {
        buffer->entries[i].timestamp = 0;
        buffer->entries[i].isMalicious = false;
    }
}

void destroyLogBuffer(LogBuffer* buffer) {
    free(buffer->entries);
}

void updateLogBuffer(LogBuffer* buffer, LogEntry entry) {
    buffer->entries[buffer->currentIndex] = entry;
    buffer->currentIndex = (buffer->currentIndex + 1) % buffer->size;
}

bool hasRecentMaliciousLogs(LogBuffer* buffer) {
    for (int i = 0; i < buffer->size; i++) {
        time_t currentTime;
        time(&currentTime);
        double timeDifference = difftime(currentTime, buffer->entries[i].timestamp);
        if (buffer->entries[i].isMalicious && timeDifference <= MAX_TIME_DELAY) {
            return true;
        }
    }
    return false;
}

bool isMaliciousIP(char ip[BUFFER_SIZE]) {
    // Placeholder function for determining whether an IP is malicious or not
    return (int) ip[0] % 2 == 0;
}

int main() {
    LogBuffer buffer;
    initLogBuffer(&buffer, THRESHOLD);
    printf("Intrusion Detection System - Running...\n");
    while (true) {
        LogEntry entry;
        time(&entry.timestamp);
        printf("Enter source IP: ");
        fgets(entry.sourceIP, BUFFER_SIZE, stdin);
        entry.sourceIP[strcspn(entry.sourceIP, "\n")] = 0;
        printf("Enter destination IP: ");
        fgets(entry.destinationIP, BUFFER_SIZE, stdin);
        entry.destinationIP[strcspn(entry.destinationIP, "\n")] = 0;
        entry.isMalicious = isMaliciousIP(entry.sourceIP) || isMaliciousIP(entry.destinationIP);
        if (hasRecentMaliciousLogs(&buffer) || entry.isMalicious) {
            printf("ALERT! Possible intrusion detected:\n");
            printLogEntry(entry);
        } else {
            printf("Log Entry:\n");
            printLogEntry(entry);
        }
        updateLogBuffer(&buffer, entry);
    }
    destroyLogBuffer(&buffer);
    return 0;
}