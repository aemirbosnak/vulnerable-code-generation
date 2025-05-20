//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Define the data structure for a network packet
struct Packet {
    char* sourceIP;
    char* destIP;
    int sourcePort;
    int destPort;
    char* protocol;
    char* payload;
};

// Function to parse a line of the log file and populate the packet struct
void parseLine(char* line, struct Packet* packet) {
    char* token = strtok(line, ",");
    packet->sourceIP = strdup(token);
    token = strtok(NULL, ",");
    packet->destIP = strdup(token);
    token = strtok(NULL, ",");
    packet->sourcePort = atoi(token);
    token = strtok(NULL, ",");
    packet->destPort = atoi(token);
    token = strtok(NULL, ",");
    packet->protocol = strdup(token);
    token = strtok(NULL, ",");
    packet->payload = strdup(token);
}

// Function to check if a given packet meets the criteria for intrusion detection
int checkPacket(struct Packet packet) {
    if(strcmp(packet.payload, "DROP") == 0) {
        return 1;
    }
    if(packet.sourcePort < 1024 && strcmp(packet.protocol, "TCP") == 0) {
        return 1;
    }
    if(strcmp(packet.payload, "FLAGGED") == 0) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    struct Packet packet;
    int count = 0;
    
    fp = fopen("network_log.txt", "r");
    if(fp == NULL) {
        printf("Error opening log file\n");
        return 1;
    }
    
    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        parseLine(line, &packet);
        if(checkPacket(packet)){
            printf("Intrusion detected in packet %d:\n", count);
            printf("Source IP: %s\n", packet.sourceIP);
            printf("Dest IP: %s\n", packet.destIP);
            printf("Source Port: %d\n", packet.sourcePort);
            printf("Dest Port: %d\n", packet.destPort);
            printf("Protocol: %s\n", packet.protocol);
            printf("Payload: %s\n", packet.payload);
        }
        count++;
    }
    
    fclose(fp);
    return 0;
}