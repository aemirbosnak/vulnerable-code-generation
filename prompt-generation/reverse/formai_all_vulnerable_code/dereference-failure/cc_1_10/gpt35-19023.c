//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PACKET_SIZE 1024

struct packet {
    int id;
    char data[MAX_PACKET_SIZE];
};

struct node {
    struct packet data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insert_packet(struct packet pkt) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = pkt;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void analyze_packets() {
    struct node* current = head;
    while (current != NULL) {
        if (current->data.id == 12345) {
            printf("Intrusion detected! Packet ID = %d\n", current->data.id);
            strcpy(current->data.data, "Intrusion Detected");
        }
        current = current->next;
    }
}

void print_packets() {
    struct node* current = head;
    while (current != NULL) {
        printf("Packet ID = %d, Data = %s\n", current->data.id, current->data.data);
        current = current->next;
    }
}

int main() {
    struct packet pkt1 = {1111, "Hello World"};
    struct packet pkt2 = {2222, "This is a test packet"};
    struct packet pkt3 = {12345, "Attempted intrusion here"};
    
    insert_packet(pkt1);
    insert_packet(pkt2);
    insert_packet(pkt3);
    
    printf("Original Packets:\n");
    print_packets();
    
    analyze_packets();
    
    printf("\nAfter Intrusion Detection:\n");
    print_packets();
    
    return 0;
}