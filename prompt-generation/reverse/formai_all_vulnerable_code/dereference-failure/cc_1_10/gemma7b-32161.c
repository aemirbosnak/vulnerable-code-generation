//Gemma-7B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Firewall {
  int state;
  char buffer[BUFFER_SIZE];
  int index;
  struct Firewall* next;
} Firewall;

Firewall* firewall_create() {
  Firewall* new_firewall = malloc(sizeof(Firewall));
  new_firewall->state = 0;
  new_firewall->index = 0;
  new_firewall->next = NULL;
  return new_firewall;
}

void firewall_append(Firewall* firewall, char data) {
  if (firewall->index >= BUFFER_SIZE - 1) {
    firewall_create(firewall);
  }
  firewall->buffer[firewall->index++] = data;
}

int firewall_check(Firewall* firewall, char* pattern) {
  int i = 0;
  for (i = 0; pattern[i] != '\0'; i++) {
    if (firewall->buffer[firewall->index - i] != pattern[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Firewall* firewall = firewall_create();
  firewall_append(firewall, 'a');
  firewall_append(firewall, 'b');
  firewall_append(firewall, 'c');
  firewall_append(firewall, 'a');

  char* pattern = "abb";
  if (firewall_check(firewall, pattern) == 1) {
    printf("Pattern matched!\n");
  } else {
    printf("Pattern not matched.\n");
  }

  return 0;
}