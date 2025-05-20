//Gemma-7B DATASET v1.0 Category: Wireless Network Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_SITES 10

typedef struct Site {
  char name[256];
  int signal_strength;
  struct Site* next;
} Site;

Site* insert_site(Site* head, char* name, int signal_strength) {
  Site* new_site = malloc(sizeof(Site));
  strcpy(new_site->name, name);
  new_site->signal_strength = signal_strength;
  new_site->next = NULL;

  if (head == NULL) {
    return new_site;
  } else {
    head->next = new_site;
    return head;
  }
}

void print_sites(Site* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->signal_strength);
    head = head->next;
  }
}

int main() {
  Site* sites = NULL;

  // Scan for sites
  for (int i = 0; i < MAX_SITES; i++) {
    char name[256];
    int signal_strength;
    scanf("Enter site name: ", name);
    scanf("Enter signal strength: ", &signal_strength);
    insert_site(sites, name, signal_strength);
  }

  // Print sites
  print_sites(sites);

  return 0;
}