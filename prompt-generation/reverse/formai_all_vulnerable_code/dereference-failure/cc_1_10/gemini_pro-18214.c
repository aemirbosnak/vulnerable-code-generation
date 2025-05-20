//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADDR 100

typedef struct _addr {
  char *name;
  char *email;
} addr;

typedef struct _list {
  addr *addrs;
  int size;
} list;

list *create_list() {
  list *l = malloc(sizeof(list));
  l->addrs = NULL;
  l->size = 0;
  return l;
}

void add_addr(list *l, char *name, char *email) {
  l->addrs = realloc(l->addrs, sizeof(addr) * (l->size + 1));
  l->addrs[l->size++].name = strdup(name);
  l->addrs[l->size++].email = strdup(email);
}

void print_list(list *l) {
  for (int i = 0; i < l->size; i++) {
    printf("%s: %s\n", l->addrs[i].name, l->addrs[i].email);
  }
}

void delete_list(list *l) {
  for (int i = 0; i < l->size; i++) {
    free(l->addrs[i].name);
    free(l->addrs[i].email);
  }
  free(l->addrs);
  free(l);
}

int main() {
  list *l = create_list();
  add_addr(l, "Donald", "knuth@stanford.edu");
  add_addr(l, "Edsger", "dijkstra@cs.utexas.edu");
  add_addr(l, "Grace", "hopper@navy.mil");
  print_list(l);
  delete_list(l);
  return 0;
}