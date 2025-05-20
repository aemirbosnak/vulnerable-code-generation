//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Post-Apocalyptic Classical Circuit Simulator */

#define MAX_NODES 10000
#define MAX_NAME_LEN 20
#define MAX_CONN 10
#define PI 3.14159265

/* Circuit components */
typedef enum {
  RESISTOR,
  CAPACITOR,
  INDUCTOR,
  VOLTAGE_SOURCE,
  CURRENT_SOURCE,
  DIODE
} comp_type_t;

/* Circuit component */
typedef struct {
  comp_type_t type;               /* Resistor, capacitor, etc. */
  char name[MAX_NAME_LEN];        /* Component name */
  double value;                   /* Component value */
  int conn[MAX_CONN];             /* Node connections */
  int num_conn;                   /* Number of node connections */
  double voltage;                 /* Component voltage */
  double current;                 /* Component current */
} component_t;

/* Circuit */
typedef struct {
  component_t *components[MAX_NODES]; /* Circuit components */
  int num_components;             /* Number of circuit components */
} circuit_t;

/* Functions */
void add_resistor(circuit_t *circuit, char *name, double value, int n1, int n2);
void add_capacitor(circuit_t *circuit, char *name, double value, int n1, int n2);
void add_inductor(circuit_t *circuit, char *name, double value, int n1, int n2);
void add_voltage_source(circuit_t *circuit, char *name, double value, int n1, int n2);
void add_current_source(circuit_t *circuit, char *name, double value, int n1, int n2);
void add_diode(circuit_t *circuit, char *name, double value, int n1, int n2);
void update_node_voltage(circuit_t *circuit, int node, double voltage);
void update_component_voltage(component_t *comp, double voltage);
double compute_resistor_current(component_t *comp);
double compute_capacitor_current(component_t *comp, double dt);
double compute_inductor_current(component_t *comp, double dt);
double compute_diode_current(component_t *comp, double voltage, double dt);
double compute_voltage_source_current(component_t *comp);

int main(void) {
  circuit_t circuit;
  int n1, n2;

  /* Add resistors */
  add_resistor(&circuit, "R1", 470, 1, 2);
  add_resistor(&circuit, "R2", 220, 2, 0);
  add_resistor(&circuit, "R3", 1000, 1, 0);

  /* Add capacitors */
  add_capacitor(&circuit, "C1", 10e-6, 1, 2);
  add_capacitor(&circuit, "C2", 1e-6, 2, 0);

  /* Add diode */
  add_diode(&circuit, "D1", 0.7, 2, 0);

  /* Add voltage sources */
  add_voltage_source(&circuit, "V1", 10, 1, 0);

  /* Simulation time and step size */
  double t = 0, t_end = 0.1, dt = 0.0001;

  /* Simulation loop */
  while (t < t_end) {
    /* Compute component currents */
    for (int i = 0; i < circuit.num_components; i++) {
      component_t *comp = circuit.components[i];
      switch (comp->type) {
        case RESISTOR:
          comp->current = compute_resistor_current(comp);
          break;
        case CAPACITOR:
          comp->current = compute_capacitor_current(comp, dt);
          break;
        case INDUCTOR:
          comp->current = compute_inductor_current(comp, dt);
          break;
        case DIODE:
          comp->current = compute_diode_current(comp, comp->voltage, dt);
          break;
        case VOLTAGE_SOURCE:
          comp->current = compute_voltage_source_current(comp);
          break;
        case CURRENT_SOURCE:
          /* Do nothing */
          break;
      }
    }

    /* Update node voltages */
    for (int i = 0; i < circuit.num_components; i++) {
      component_t *comp = circuit.components[i];
      for (int j = 0; j < comp->num_conn; j++) {
        int node = comp->conn[j];
        update_node_voltage(&circuit, node, comp->voltage);
      }
    }

    /* Update component voltages */
    for (int i = 0; i < circuit.num_components; i++) {
      component_t *comp = circuit.components[i];
      for (int j = 0; j < comp->num_conn; j++) {
        int node = comp->conn[j];
        if (node != 0) {
          comp->voltage -= circuit.components[node]->voltage;
        }
      }
    }

    /* Update component currents */
    for (int i = 0; i < circuit.num_components; i++) {
      component_t *comp = circuit.components[i];
      for (int j = 0; j < comp->num_conn; j++) {
        int node = comp->conn[j];
        if (node != 0) {
          comp->current += circuit.components[node]->current;
        }
      }
    }

    /* Advance simulation time */
    t += dt;
  }

  return 0;
}

/* Add a resistor to the circuit */
void add_resistor(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = RESISTOR;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = 0;
  comp->current = 0;
  circuit->components[circuit->num_components++] = comp;
}

/* Add a capacitor to the circuit */
void add_capacitor(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = CAPACITOR;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = 0;
  comp->current = 0;
  circuit->components[circuit->num_components++] = comp;
}

/* Add an inductor to the circuit */
void add_inductor(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = INDUCTOR;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = 0;
  comp->current = 0;
  circuit->components[circuit->num_components++] = comp;
}

/* Add a voltage source to the circuit */
void add_voltage_source(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = VOLTAGE_SOURCE;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = value;
  comp->current = 0;
  circuit->components[circuit->num_components++] = comp;
}

/* Add a current source to the circuit */
void add_current_source(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = CURRENT_SOURCE;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = 0;
  comp->current = value;
  circuit->components[circuit->num_components++] = comp;
}

/* Add a diode to the circuit */
void add_diode(circuit_t *circuit, char *name, double value, int n1, int n2) {
  component_t *comp = (component_t*) malloc(sizeof(component_t));
  comp->type = DIODE;
  strncpy(comp->name, name, MAX_NAME_LEN);
  comp->value = value;
  comp->conn[0] = n1;
  comp->conn[1] = n2;
  comp->num_conn = 2;
  comp->voltage = 0;
  comp->current = 0;
  circuit->components[circuit->num_components++] = comp;
}

/* Update the voltage of a node in the circuit */
void update_node_voltage(circuit_t *circuit, int node, double voltage) {
  for (int i = 0; i < circuit->num_components; i++) {
    component_t *comp = circuit->components[i];
    for (int j = 0; j < comp->num_conn; j++) {
      if (comp->conn[j] == node) {
        update_component_voltage(comp, voltage);
      }
    }
  }
}

/* Update the voltage of a component in the circuit */
void update_component_voltage(component_t *comp, double voltage) {
  comp->voltage = voltage;
}

/* Compute the current through a resistor */
double compute_resistor_current(component_t *comp) {
  return comp->voltage / comp->value;
}

/* Compute the current through a capacitor */
double compute_capacitor_current(component_t *comp, double dt) {
  return comp->value * (comp->voltage - comp->current * dt) / dt;
}

/* Compute the current through an inductor */
double compute_inductor_current(component_t *comp, double dt) {
  return comp->current + (comp->voltage / (comp->value * dt));
}

/* Compute the current through a diode */
double compute_diode_current(component_t *comp, double voltage, double dt) {
  if (voltage > 0) {
    return comp->value * exp(voltage / (comp->value * dt));
  } else {
    return 0;
  }
}

/* Compute the current through a voltage source */
double compute_voltage_source_current(component_t *comp) {
  return comp->current;
}