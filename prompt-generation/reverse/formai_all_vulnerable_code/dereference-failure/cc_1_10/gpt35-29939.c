//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define THRESHOLD 3

// A struct to represent IP addresses
typedef struct {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} IPAddress;

// A struct to represent a log entry
typedef struct {
    char timestamp[MAX_LENGTH];
    char sourceIP[MAX_LENGTH];
    char destIP[MAX_LENGTH];
} LogEntry;

// A function to parse IP addresses from a string
IPAddress parseIP(char *ipString) {
    char *split = strtok(ipString, ".");
    IPAddress ip;
    ip.octet1 = atoi(split);
    split = strtok(NULL, ".");
    ip.octet2 = atoi(split);
    split = strtok(NULL, ".");
    ip.octet3 = atoi(split);
    split = strtok(NULL, ".");
    ip.octet4 = atoi(split);
    return ip;
}

int main() {
    char input[MAX_LENGTH];
    int count = 0;
    LogEntry logs[THRESHOLD];
    printf("Enter log entries (timestamp sourceIP destIP):\n");
    while (1) {
        gets(input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        char *split = strtok(input, " ");
        LogEntry log;
        strcpy(log.timestamp, split);
        split = strtok(NULL, " ");
        strcpy(log.sourceIP, split);
        split = strtok(NULL, " ");
        strcpy(log.destIP, split);
        IPAddress source = parseIP(log.sourceIP);
        IPAddress dest = parseIP(log.destIP);
        if (count == THRESHOLD) {
            IPAddress lastSource = parseIP(logs[0].sourceIP);
            IPAddress lastDest = parseIP(logs[0].destIP);
            int sameSource = source.octet1 == lastSource.octet1 && source.octet2 == lastSource.octet2 &&
                             source.octet3 == lastSource.octet3 && source.octet4 == lastSource.octet4;
            int sameDest = dest.octet1 == lastDest.octet1 && dest.octet2 == lastDest.octet2 &&
                           dest.octet3 == lastDest.octet3 && dest.octet4 == lastDest.octet4;
            if (sameSource && sameDest) {
                printf("Intrusion detected - %d consecutive requests from %s to %s\n", THRESHOLD, log.sourceIP, log.destIP);
            }
            for (int i = 0; i < THRESHOLD - 1; i++) {
                logs[i] = logs[i+1];
            }
            logs[THRESHOLD-1] = log;
        } else {
            logs[count] = log;
            count++;
        }
    }
    return 0;
}