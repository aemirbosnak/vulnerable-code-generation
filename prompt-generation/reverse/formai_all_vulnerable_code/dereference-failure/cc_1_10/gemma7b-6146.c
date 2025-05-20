//Gemma-7B DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct Packet
{
    char data[BUFFER_SIZE];
    int length;
    struct Packet* next;
} Packet;

Packet* packet_head = NULL;

void packet_add(char* data, int length)
{
    Packet* new_packet = malloc(sizeof(Packet));
    new_packet->length = length;
    memcpy(new_packet->data, data, length);

    if (packet_head)
    {
        packet_head->next = new_packet;
    }
    else
    {
        packet_head = new_packet;
    }
}

int main()
{
    packet_add("Hello, world!", 13);
    packet_add("This is a packet.", 18);
    packet_add("I am a firewall.", 19);

    Packet* current_packet = packet_head;

    while (current_packet)
    {
        printf("Packet length: %d\n", current_packet->length);
        printf("Packet data: %s\n", current_packet->data);
        printf("\n");

        current_packet = current_packet->next;
    }

    return 0;
}