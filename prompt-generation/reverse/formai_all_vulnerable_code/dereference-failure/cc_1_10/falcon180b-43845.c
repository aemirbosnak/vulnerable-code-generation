//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int value;
} Subnet;

Subnet *create_subnet(char *name, int value) {
  Subnet *subnet = (Subnet *) malloc(sizeof(Subnet));
  subnet->name = strdup(name);
  subnet->value = value;
  return subnet;
}

void print_subnet(Subnet *subnet) {
  printf("%s: %d\n", subnet->name, subnet->value);
}

void free_subnet(Subnet *subnet) {
  free(subnet->name);
  free(subnet);
}

int main() {
  Subnet *subnet1 = create_subnet("subnet1", 192);
  Subnet *subnet2 = create_subnet("subnet2", 10);
  Subnet *subnet3 = create_subnet("subnet3", 0);

  printf("Initial subnets:\n");
  print_subnet(subnet1);
  print_subnet(subnet2);
  print_subnet(subnet3);

  subnet1->value = 128;
  subnet2->value = 64;
  subnet3->value = 16;

  printf("\nModified subnets:\n");
  print_subnet(subnet1);
  print_subnet(subnet2);
  print_subnet(subnet3);

  free_subnet(subnet1);
  free_subnet(subnet2);
  free_subnet(subnet3);

  return 0;
}