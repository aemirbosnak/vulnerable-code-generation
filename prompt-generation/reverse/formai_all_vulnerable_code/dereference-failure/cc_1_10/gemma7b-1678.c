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

Packet* packet_insert(Packet* head, char* data, int length) {
  Packet* new_packet = malloc(sizeof(Packet));
  new_packet->length = length;
  memcpy(new_packet->data, data, length);
  new_packet->next = NULL;

  if (head) {
    head->next = new_packet;
  } else {
    head = new_packet;
  }

  return head;
}

int packet_match(Packet* head, char* data, int length) {
  for (Packet* current = head; current; current = current->next) {
    if (current->length == length && memcmp(current->data, data, length) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  Packet* head = NULL;

  // Insert packets
  packet_insert(head, "abc", 3);
  packet_insert(head, "xyz", 3);

  // Check for packet match
  if (packet_match(head, "abc", 3)) {
    printf("Packet found!\n");
  } else {
    printf("Packet not found.\n");
  }

  return 0;
}