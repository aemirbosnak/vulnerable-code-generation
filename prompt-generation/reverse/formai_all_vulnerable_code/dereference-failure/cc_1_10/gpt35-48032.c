//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // maximum length of the packet

struct Packet {
    char src[16]; // source IP address
    char dest[16]; // destination IP address
    int port; // port number
    char data[MAX_LENGTH]; // packet data
};

struct Node {
    struct Packet val; // packet value
    struct Node* next; // pointer to next node
};

struct LinkedList {
    struct Node* head; // pointer to the head node
};

struct LinkedList blackList; // linked list for blacklisted packets

// Initialize the linked list
void initializeList(struct LinkedList* list) {
    list->head = NULL;
}

// Add a packet to the linked list
void addPacket(struct LinkedList* list, struct Packet packet) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = packet;
    node->next = list->head;
    list->head = node;
}

// Remove a packet from the linked list
void removePacket(struct LinkedList* list, struct Packet packet) {
    struct Node* node = list->head;
    
    // if head node contains the packet
    if (node != NULL && memcmp(&node->val, &packet, sizeof(struct Packet)) == 0) {
        list->head = node->next;
        free(node);
        return;
    }
    
    // search for the packet in the rest of the list
    while (node != NULL && memcmp(&node->val, &packet, sizeof(struct Packet)) != 0) {
        node = node->next;
    }
    
    // if packet is found, remove it
    if (node != NULL) {
        struct Node* nextNode = node->next;
        memcpy(node, nextNode, sizeof(struct Node));
        free(nextNode);
    }
}

// Check if a packet is blacklisted
int isBlacklisted(struct LinkedList* list, struct Packet packet) {
    struct Node* node = list->head;
    
    // search for the packet in the list
    while (node != NULL && memcmp(&node->val, &packet, sizeof(struct Packet)) != 0) {
        node = node->next;
    }
    
    // if packet is found, it is blacklisted
    if (node != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    initializeList(&blackList);
    struct Packet packet;
    
    // read packets from input file until end of file is reached
    while (scanf(" %s %s %d %[^\n]%*c", packet.src, packet.dest, &packet.port, packet.data) != EOF) {
        
        // check if packet is blacklisted
        if (isBlacklisted(&blackList, packet)) {
            printf("Intrusion detected!\n");
            
            // remove packet from blacklist
            removePacket(&blackList, packet);
            
        } else {
            printf("Packet received\n");
            
            // add packet to blacklist
            addPacket(&blackList, packet);
        }
    }
    
    return 0;
}