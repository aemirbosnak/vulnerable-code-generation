//Gemma-7B DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

typedef struct Firewall {
  char buffer[BUFFER_SIZE];
  int head;
  int tail;
  int capacity;
} Firewall;

Firewall* createFirewall() {
  Firewall* firewall = (Firewall*)malloc(sizeof(Firewall));
  firewall->head = 0;
  firewall->tail = 0;
  firewall->capacity = BUFFER_SIZE;
  return firewall;
}

void addToFirewall(Firewall* firewall, char data) {
  if (firewall->head - firewall->tail >= firewall->capacity - 1) {
    printf("Firewall is full!\n");
    return;
  }
  firewall->buffer[firewall->head++] = data;
}

char readFromFirewall(Firewall* firewall) {
  if (firewall->head - firewall->tail <= 0) {
    printf("Firewall is empty!\n");
    return '\0';
  }
  return firewall->buffer[firewall->tail++];
}

int main() {
  Firewall* firewall = createFirewall();
  addToFirewall(firewall, 'a');
  addToFirewall(firewall, 'b');
  addToFirewall(firewall, 'c');
  addToFirewall(firewall, 'd');
  addToFirewall(firewall, 'e');

  char data = readFromFirewall(firewall);
  printf("Data read from firewall: %c\n", data);

  data = readFromFirewall(firewall);
  printf("Data read from firewall: %c\n", data);

  return 0;
}