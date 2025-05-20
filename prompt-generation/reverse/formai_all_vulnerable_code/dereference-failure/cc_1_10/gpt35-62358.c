//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 1000

int num_nodes = 0;
int num_res = 0;

typedef struct {
  float value;
  char unit;
} res_t;

typedef struct {
  int node1;
  int node2;
} conn_t;

typedef struct {
  char type;
  int num_conns;
  conn_t *conns;
  res_t value;
} elem_t;

elem_t circuit[MAX_NODES];

void add_resistor(int node1, int node2, float val, char unit) {
  circuit[num_res].type = 'r';
  circuit[num_res].num_conns = 2;
  circuit[num_res].conns = malloc(2*sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node1;
  circuit[num_res].conns[0].node2 = node2;
  circuit[num_res].value.value = val;
  circuit[num_res].value.unit = unit;
  num_res++;
}

void add_capacitor(int node1, int node2, float val, char unit) {
  circuit[num_res].type = 'c';
  circuit[num_res].num_conns = 2;
  circuit[num_res].conns = malloc(2*sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node1;
  circuit[num_res].conns[0].node2 = node2;
  circuit[num_res].value.value = val;
  circuit[num_res].value.unit = unit;
  num_res++;
}

void add_inductor(int node1, int node2, float val, char unit) {
  circuit[num_res].type = 'l';
  circuit[num_res].num_conns = 2;
  circuit[num_res].conns = malloc(2*sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node1;
  circuit[num_res].conns[0].node2 = node2;
  circuit[num_res].value.value = val;
  circuit[num_res].value.unit = unit;
  num_res++;
}

void add_voltage_source(int node1, int node2, float val, char unit) {
  circuit[num_res].type = 'v';
  circuit[num_res].num_conns = 2;
  circuit[num_res].conns = malloc(2*sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node1;
  circuit[num_res].conns[0].node2 = node2;
  circuit[num_res].value.value = val;
  circuit[num_res].value.unit = unit;
  num_res++;
}

void add_current_source(int node1, int node2, float val, char unit) {
  circuit[num_res].type = 'i';
  circuit[num_res].num_conns = 2;
  circuit[num_res].conns = malloc(2*sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node1;
  circuit[num_res].conns[0].node2 = node2;
  circuit[num_res].value.value = val;
  circuit[num_res].value.unit = unit;
  num_res++;
}

void add_ground(int node) {
  circuit[num_res].type = 'g';
  circuit[num_res].num_conns = 1;
  circuit[num_res].conns = malloc(sizeof(conn_t));
  circuit[num_res].conns[0].node1 = node;
  num_res++;
}

void print_circuit() {
  int i,j;
  for (i=0; i<num_nodes; i++) {
    printf("Node %d: ",i);
    for (j=0; j<num_res; j++) {
      if (circuit[j].type != 'g') {
        if (circuit[j].conns[0].node1 == i)
          printf("%c%d-%c%d ",circuit[j].type,circuit[j].conns[0].node1,
            circuit[j].type,circuit[j].conns[1].node1);
        else if (circuit[j].conns[0].node2 == i)
          printf("%c%d-%c%d ",circuit[j].type,circuit[j].conns[1].node1,
            circuit[j].type,circuit[j].conns[0].node1);
      }
    }
    printf("\n");
  }
}

int main() {
  add_ground(0);
  add_resistor(0,1,1000,'R');
  add_voltage_source(1,2,12,'V');
  add_capacitor(2,0,1e-6,'F');
  print_circuit();
  return 0;
}