//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a performance-critical component.
typedef struct {
  int id;
  char *name;
  double value;
} PerformanceCriticalComponent;

// Create a new performance-critical component.
PerformanceCriticalComponent* create_performance_critical_component(int id, char *name, double value) {
  PerformanceCriticalComponent *component = malloc(sizeof(PerformanceCriticalComponent));
  component->id = id;
  component->name = strdup(name);
  component->value = value;
  return component;
}

// Destroy a performance-critical component.
void destroy_performance_critical_component(PerformanceCriticalComponent *component) {
  free(component->name);
  free(component);
}

// Get the ID of a performance-critical component.
int get_performance_critical_component_id(PerformanceCriticalComponent *component) {
  return component->id;
}

// Get the name of a performance-critical component.
char *get_performance_critical_component_name(PerformanceCriticalComponent *component) {
  return component->name;
}

// Get the value of a performance-critical component.
double get_performance_critical_component_value(PerformanceCriticalComponent *component) {
  return component->value;
}

// Set the value of a performance-critical component.
void set_performance_critical_component_value(PerformanceCriticalComponent *component, double value) {
  component->value = value;
}

// Print the information about a performance-critical component.
void print_performance_critical_component(PerformanceCriticalComponent *component) {
  printf("Performance-critical component:\n");
  printf("  ID: %d\n", component->id);
  printf("  Name: %s\n", component->name);
  printf("  Value: %f\n", component->value);
}

// Main function.
int main() {
  // Create a new performance-critical component.
  PerformanceCriticalComponent *component = create_performance_critical_component(1, "Example component", 1.23);

  // Print the information about the component.
  print_performance_critical_component(component);

  // Destroy the component.
  destroy_performance_critical_component(component);

  return 0;
}