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

typedef struct Firewall {
  Packet* head;
  Packet* tail;
  int rules[10];
  int rule_count;
} Firewall;

void firewall_add_rule(Firewall* fw, int rule) {
  fw->rules[fw->rule_count++] = rule;
}

int firewall_check_rule(Firewall* fw, int rule) {
  for (int i = 0; i < fw->rule_count; i++) {
    if (fw->rules[i] == rule) {
      return 1;
    }
  }

  return 0;
}

void firewall_process_packet(Firewall* fw, Packet* packet) {
  for (int i = 0; i < packet->length; i++) {
    char data = packet->data[i];

    if (!firewall_check_rule(fw, data)) {
      printf("Packet dropped: Data %c not allowed.\n", data);
      return;
    }
  }

  printf("Packet accepted: Data %s.\n", packet->data);
}

int main() {
  Firewall* fw = malloc(sizeof(Firewall));
  fw->head = NULL;
  fw->tail = NULL;
  fw->rule_count = 0;

  firewall_add_rule(fw, 51);
  firewall_add_rule(fw, 65);
  firewall_add_rule(fw, 83);

  Packet* packet = malloc(sizeof(Packet));
  packet->length = 10;
  packet->data[0] = 65;
  packet->data[1] = 83;
  packet->data[2] = 51;

  firewall_process_packet(fw, packet);

  return 0;
}