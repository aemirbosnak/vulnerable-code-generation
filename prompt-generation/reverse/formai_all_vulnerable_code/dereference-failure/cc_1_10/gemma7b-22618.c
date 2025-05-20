//Gemma-7B DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
  char data[MAX_PACKET_SIZE];
  int length;
  struct Packet* next;
} Packet;

Packet* createPacket(int length) {
  Packet* packet = malloc(sizeof(Packet));
  packet->length = length;
  packet->next = NULL;
  return packet;
}

void insertPacket(Packet* head, Packet* newPacket) {
  if (head == NULL) {
    head = newPacket;
  } else {
    newPacket->next = head;
    head = newPacket;
  }
}

void processPackets(Packet* head) {
  while (head) {
    printf("Packet length: %d\n", head->length);
    printf("Packet data: %s\n", head->data);
    head = head->next;
  }
}

int main() {
  Packet* packetHead = NULL;

  // Create some packets
  Packet* packet1 = createPacket(10);
  strcpy(packet1->data, "Hello, world!");

  Packet* packet2 = createPacket(20);
  strcpy(packet2->data, "This is a longer packet.");

  insertPacket(packetHead, packet1);
  insertPacket(packetHead, packet2);

  // Process the packets
  processPackets(packetHead);

  return 0;
}