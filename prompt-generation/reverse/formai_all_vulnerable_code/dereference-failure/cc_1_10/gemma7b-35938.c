//Gemma-7B DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Packet {
  char data[BUFFER_SIZE];
  int length;
  struct Packet* next;
} Packet;

Packet* createPacket(int length) {
  Packet* packet = malloc(sizeof(Packet));
  packet->length = length;
  packet->next = NULL;
  return packet;
}

void insertPacket(Packet* head, Packet* packet) {
  if (head == NULL) {
    head = packet;
  } else {
    packet->next = head;
    head = packet;
  }
}

void sendPacket(Packet* packet) {
  // Simulate sending the packet
  printf("Sending packet of size %d: ", packet->length);
  for (int i = 0; i < packet->length; i++) {
    printf("%c ", packet->data[i]);
  }
  printf("\n");
}

int main() {
  Packet* head = NULL;

  // Create and insert packets
  insertPacket(head, createPacket(5));
  insertPacket(head, createPacket(10));
  insertPacket(head, createPacket(15));

  // Send packets
  sendPacket(head);

  return 0;
}