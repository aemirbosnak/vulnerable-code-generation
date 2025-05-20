//Gemma-7B DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct Firewall {
  int state;
  struct Firewall *next;
} Firewall;

Firewall *firewall_insert(Firewall *head, int state) {
  Firewall *new_node = malloc(sizeof(Firewall));
  new_node->state = state;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  head->next = firewall_insert(head->next, state);

  return head;
}

int firewall_search(Firewall *head, int state) {
  while (head) {
    if (head->state == state) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Firewall *firewall = NULL;

  firewall = firewall_insert(firewall, 1);
  firewall = firewall_insert(firewall, 2);
  firewall = firewall_insert(firewall, 3);
  firewall = firewall_insert(firewall, 4);
  firewall = firewall_insert(firewall, 5);

  if (firewall_search(firewall, 3) == 1) {
    printf("State 3 is in the firewall.\n");
  } else {
    printf("State 3 is not in the firewall.\n");
  }

  return 0;
}