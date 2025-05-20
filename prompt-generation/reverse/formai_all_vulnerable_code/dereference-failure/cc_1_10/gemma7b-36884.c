//Gemma-7B DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct Firewall {
  char buffer[BUFFER_SIZE];
  int head;
  int tail;
  int size;
  int capacity;
} Firewall;

Firewall* firewall_init(int capacity) {
  Firewall* fw = malloc(sizeof(Firewall));
  fw->size = 0;
  fw->capacity = capacity;
  fw->head = 0;
  fw->tail = -1;
  return fw;
}

void firewall_add(Firewall* fw, char data) {
  if (fw->size >= fw->capacity) {
    return;
  }
  fw->buffer[++fw->tail] = data;
  fw->size++;
}

char firewall_peek(Firewall* fw) {
  if (fw->size == 0) {
    return -1;
  }
  return fw->buffer[fw->head];
}

void firewall_flush(Firewall* fw) {
  fw->size = 0;
  fw->head = 0;
  fw->tail = -1;
}

int main() {
  Firewall* fw = firewall_init(5);
  firewall_add(fw, 'a');
  firewall_add(fw, 'b');
  firewall_add(fw, 'c');
  firewall_add(fw, 'd');
  firewall_add(fw, 'e');

  printf("Data at head: %c\n", firewall_peek(fw));

  firewall_flush(fw);

  printf("Data at head after flush: %c\n", firewall_peek(fw));

  return 0;
}