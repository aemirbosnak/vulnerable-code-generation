//Gemma-7B DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Packet {
    char data[BUFFER_SIZE];
    int length;
    struct Packet* next;
} Packet;

Packet* packet_add(Packet* head, char* data, int length) {
    Packet* new_packet = malloc(sizeof(Packet));
    new_packet->length = length;
    memcpy(new_packet->data, data, length);

    if (head == NULL) {
        head = new_packet;
    } else {
        head->next = new_packet;
    }

    return head;
}

void packet_print(Packet* head) {
    while (head) {
        printf("Data: ");
        for (int i = 0; i < head->length; i++) {
            printf("%c ", head->data[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    Packet* head = NULL;

    // Packet addition
    packet_add(head, "Hello, world!", 13);
    packet_add(head, "This is a packet!", 16);
    packet_add(head, "The quick brown fox jumps over the lazy dog.", 42);

    // Packet printing
    packet_print(head);

    return 0;
}