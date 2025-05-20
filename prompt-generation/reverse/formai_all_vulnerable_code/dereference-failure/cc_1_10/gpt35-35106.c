//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct packet {
    char sourceIP[16];
    char destinationIP[16];
    char protocol[5];
    int port;
} packet;

typedef struct node {
    packet p;
    struct node* next;
} node;

node* head = NULL;
int packetCount = 0;

void addPacket(char sourceIP[16], char destinationIP[16], char protocol[5], int port) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->p.sourceIP, sourceIP);
    strcpy(temp->p.destinationIP, destinationIP);
    strcpy(temp->p.protocol, protocol);
    temp->p.port = port;
    temp->next = head;
    head = temp;
    packetCount++;
}

void removePacket() {
    node* temp = head;
    head = head->next;
    free(temp);
    packetCount--;
}

void checkForIntrusion() {
    node* current = head;
    int count = 0;

    while (current != NULL) {
        if (strcmp(current->p.sourceIP, "10.0.0.1") == 0 && strcmp(current->p.protocol, "UDP") == 0) {
            count++;
        }
        if (count > 5) {
            printf("INTRUSION DETECTED!\n");
            break;
        }
        current = current->next;
    }
}

void displayPackets() {
    node* current = head;

    while (current != NULL) {
        printf("Source IP: %s, Destination IP: %s, Protocol: %s, Port: %d\n", current->p.sourceIP, current->p.destinationIP, current->p.protocol, current->p.port);
        current = current->next;
    }
}

int main() {
    addPacket("10.0.0.1", "192.168.0.1", "UDP", 1337);
    addPacket("192.168.2.1", "10.0.0.1", "TCP", 80);
    addPacket("10.0.0.1", "192.168.0.2", "UDP", 1337);
    addPacket("192.168.3.1", "10.0.0.1", "UDP", 1337);
    addPacket("10.0.0.1", "192.168.0.3", "UDP", 1337);
    addPacket("192.168.4.1", "10.0.0.1", "UDP", 1337);
    addPacket("10.0.0.1", "192.168.0.4", "UDP", 1337);

    displayPackets();
    checkForIntrusion();

    removePacket();
    removePacket();
    removePacket();

    displayPackets();
    return 0;
}