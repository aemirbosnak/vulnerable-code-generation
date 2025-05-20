//Gemma-7B DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet
{
    char data[MAX_PACKET_SIZE];
    int length;
    struct Packet* next;
} Packet;

Packet* createPacket(int length)
{
    Packet* packet = malloc(sizeof(Packet));
    packet->length = length;
    packet->next = NULL;

    return packet;
}

void insertPacket(Packet* head, Packet* newPacket)
{
    if (head == NULL)
    {
        head = newPacket;
    }
    else
    {
        newPacket->next = head;
        head = newPacket;
    }
}

int main()
{
    Packet* head = NULL;
    Packet* newPacket = createPacket(10);
    insertPacket(head, newPacket);

    newPacket = createPacket(20);
    insertPacket(head, newPacket);

    newPacket = createPacket(30);
    insertPacket(head, newPacket);

    Packet* currentPacket = head;

    while (currentPacket)
    {
        printf("Packet length: %d\n", currentPacket->length);
        currentPacket = currentPacket->next;
    }

    return 0;
}