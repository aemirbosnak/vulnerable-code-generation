//Gemma-7B DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ firewall_size 1024
#define MAX_ packet_size 1024

typedef struct Packet {
  char *data;
  int size;
  struct Packet *next;
} Packet;

typedef struct Firewall {
  Packet **buckets;
  int size;
  struct Firewall *next;
} Firewall;

Firewall *firewall_create() {
  Firewall *firewall = malloc(sizeof(Firewall));
  firewall->buckets = NULL;
  firewall->size = 0;
  firewall->next = NULL;
  return firewall;
}

void firewall_add_packet(Firewall *firewall, Packet *packet) {
  int bucket_index = packet->size % firewall->size;
  if (firewall->buckets[bucket_index] == NULL) {
    firewall->buckets[bucket_index] = packet;
  } else {
    firewall->buckets[bucket_index]->next = packet;
  }
  firewall->size++;
}

Packet *firewall_get_packet(Firewall *firewall, int size) {
  int bucket_index = size % firewall->size;
  Packet *packet = firewall->buckets[bucket_index];
  while (packet && packet->size != size) {
    packet = packet->next;
  }
  return packet;
}

int main() {
  Firewall *firewall = firewall_create();
  Packet *packet = malloc(sizeof(Packet));
  packet->data = "Hello, world!";
  packet->size = 12;
  firewall_add_packet(firewall, packet);

  packet = firewall_get_packet(firewall, 12);
  printf("%s", packet->data);

  return 0;
}