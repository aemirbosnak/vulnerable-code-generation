//Gemma-7B DATASET v1.0 Category: Firewall ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIREWALL_SIZE 1024

typedef struct Firewall {
  char data[FIREWALL_SIZE];
  int size;
  int pos;
  struct Firewall* next;
} Firewall;

Firewall* firewall_create() {
  Firewall* firewall = malloc(sizeof(Firewall));
  firewall->size = 0;
  firewall->pos = 0;
  firewall->next = NULL;
  return firewall;
}

void firewall_add(Firewall* firewall, char data) {
  if (firewall->size >= FIREWALL_SIZE) {
    return;
  }
  firewall->data[firewall->pos] = data;
  firewall->size++;
  firewall->pos++;
  if (firewall->pos >= FIREWALL_SIZE - 1) {
    firewall->pos = 0;
  }
}

int firewall_check(Firewall* firewall, char data) {
  for (int i = 0; i < firewall->size; i++) {
    if (firewall->data[i] == data) {
      return 1;
    }
  }
  return 0;
}

int main() {
  Firewall* firewall = firewall_create();

  // Simulate post-apocalyptic data flow
  firewall_add(firewall, 'a');
  firewall_add(firewall, 'b');
  firewall_add(firewall, 'c');
  firewall_add(firewall, 'a');

  // Check if data is present in the firewall
  if (firewall_check(firewall, 'a')) {
    printf("Data found!\n");
  } else {
    printf("Data not found.\n");
  }

  return 0;
}