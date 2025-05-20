//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRcuits 10

typedef struct Circuit {
  char name[20];
  int components;
  struct Component **components_list;
} Circuit;

typedef struct Component {
  char name[20];
  int type;
  double value;
} Component;

Circuit **circuits = NULL;

void add_circuit(char *name) {
  Circuit *new_circuit = malloc(sizeof(Circuit));
  strcpy(new_circuit->name, name);
  new_circuit->components = 0;
  new_circuit->components_list = NULL;
  circuits = realloc(circuits, (MAX_CIRcuits + 1) * sizeof(Circuit));
  circuits[MAX_CIRcuits] = new_circuit;
}

void add_component(Circuit *circuit, int type, double value) {
  Component *new_component = malloc(sizeof(Component));
  strcpy(new_component->name, "component");
  new_component->type = type;
  new_component->value = value;
  circuit->components++;
  circuit->components_list = realloc(circuit->components_list, circuit->components * sizeof(Component));
  circuit->components_list[circuit->components - 1] = new_component;
}

int main() {
  add_circuit("My Circuit");
  add_component(circuits[0], 1, 10);
  add_component(circuits[0], 2, 20);
  add_component(circuits[0], 3, 30);

  for (int i = 0; i < MAX_CIRcuits; i++) {
    if (circuits[i] != NULL) {
      printf("Circuit: %s\n", circuits[i]->name);
      for (int j = 0; j < circuits[i]->components; j++) {
        printf("Component: %s, Type: %d, Value: %.2lf\n", circuits[i]->components_list[j]->name, circuits[i]->components_list[j]->type, circuits[i]->components_list[j]->value);
      }
    }
  }

  return 0;
}