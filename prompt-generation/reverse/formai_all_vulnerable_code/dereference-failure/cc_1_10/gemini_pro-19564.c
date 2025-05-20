//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_CONNECTIONS 1000
#define MAX_TIME_STEPS 1000

typedef struct {
  char name[20];
  int type;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
} component;

typedef struct {
  int source;
  int destination;
} connection;

typedef struct {
  int num_components;
  int num_connections;
  component *components;
  connection *connections;
} circuit;

void create_circuit(circuit *c) {
  c->num_components = 0;
  c->num_connections = 0;
  c->components = malloc(sizeof(component) * MAX_COMPONENTS);
  c->connections = malloc(sizeof(connection) * MAX_CONNECTIONS);
}

void destroy_circuit(circuit *c) {
  free(c->components);
  free(c->connections);
}

void add_component(circuit *c, component *comp) {
  c->components[c->num_components++] = *comp;
}

void add_connection(circuit *c, connection *conn) {
  c->connections[c->num_connections++] = *conn;
}

void simulate_circuit(circuit *c) {
  int i, j, k;
  int inputs[MAX_COMPONENTS];
  int outputs[MAX_COMPONENTS];

  for (i = 0; i < c->num_components; i++) {
    inputs[i] = 0;
    outputs[i] = 0;
  }

  for (i = 0; i < MAX_TIME_STEPS; i++) {
    for (j = 0; j < c->num_connections; j++) {
      inputs[c->connections[j].destination] = outputs[c->connections[j].source];
    }

    for (k = 0; k < c->num_components; k++) {
      switch (c->components[k].type) {
        case 0: // NOT gate
          outputs[k] = !inputs[k];
          break;
        case 1: // AND gate
          outputs[k] = inputs[k] & inputs[k + 1];
          break;
        case 2: // OR gate
          outputs[k] = inputs[k] | inputs[k + 1];
          break;
        case 3: // XOR gate
          outputs[k] = inputs[k] ^ inputs[k + 1];
          break;
      }
    }

    for (k = 0; k < c->num_components; k++) {
      printf("%s: %d\n", c->components[k].name, outputs[k]);
    }
  }
}

int main() {
  circuit c;
  component comp1, comp2, comp3, comp4;
  connection conn1, conn2, conn3, conn4;

  create_circuit(&c);

  strcpy(comp1.name, "NOT1");
  comp1.type = 0;
  comp1.num_inputs = 1;
  comp1.num_outputs = 1;
  comp1.inputs = malloc(sizeof(int) * comp1.num_inputs);
  comp1.outputs = malloc(sizeof(int) * comp1.num_outputs);

  strcpy(comp2.name, "AND1");
  comp2.type = 1;
  comp2.num_inputs = 2;
  comp2.num_outputs = 1;
  comp2.inputs = malloc(sizeof(int) * comp2.num_inputs);
  comp2.outputs = malloc(sizeof(int) * comp2.num_outputs);

  strcpy(comp3.name, "OR1");
  comp3.type = 2;
  comp3.num_inputs = 2;
  comp3.num_outputs = 1;
  comp3.inputs = malloc(sizeof(int) * comp3.num_inputs);
  comp3.outputs = malloc(sizeof(int) * comp3.num_outputs);

  strcpy(comp4.name, "XOR1");
  comp4.type = 3;
  comp4.num_inputs = 2;
  comp4.num_outputs = 1;
  comp4.inputs = malloc(sizeof(int) * comp4.num_inputs);
  comp4.outputs = malloc(sizeof(int) * comp4.num_outputs);

  add_component(&c, &comp1);
  add_component(&c, &comp2);
  add_component(&c, &comp3);
  add_component(&c, &comp4);

  conn1.source = 0;
  conn1.destination = 1;
  add_connection(&c, &conn1);

  conn2.source = 0;
  conn2.destination = 2;
  add_connection(&c, &conn2);

  conn3.source = 1;
  conn3.destination = 3;
  add_connection(&c, &conn3);

  conn4.source = 2;
  conn4.destination = 3;
  add_connection(&c, &conn4);

  simulate_circuit(&c);

  destroy_circuit(&c);

  return 0;
}