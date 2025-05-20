//Gemma-7B DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
  char data[MAX_PACKET_SIZE];
  int length;
  struct Packet* next;
} Packet;

Packet* packet_insert(Packet* head, char* data, int length) {
  Packet* new_packet = (Packet*)malloc(sizeof(Packet));
  new_packet->length = length;
  memcpy(new_packet->data, data, length);
  new_packet->next = NULL;

  if (head == NULL) {
    head = new_packet;
  } else {
    head->next = new_packet;
  }

  return head;
}

void packet_traverse(Packet* head) {
  Packet* current_packet = head;

  while (current_packet) {
    printf("Packet length: %d\n", current_packet->length);
    printf("Packet data: ");
    for (int i = 0; i < current_packet->length; i++) {
      printf("%c ", current_packet->data[i]);
    }
    printf("\n");

    current_packet = current_packet->next;
  }
}

int main() {
  Packet* head = NULL;

  // Insert some packets
  packet_insert(head, "Hello, world!", 13);
  packet_insert(head, "This is a packet", 19);
  packet_insert(head, "Goodbye, cruel world!", 22);

  // Traverse the packets
  packet_traverse(head);

  return 0;
}