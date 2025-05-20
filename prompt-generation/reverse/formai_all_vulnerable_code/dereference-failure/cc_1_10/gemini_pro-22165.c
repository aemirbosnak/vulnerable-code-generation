//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure of a performance-critical component
typedef struct {
  int id;
  char *name;
  double value;
} PerformanceCriticalComponent;

// Define the function to create a new performance-critical component
PerformanceCriticalComponent *createPerformanceCriticalComponent(int id, char *name, double value) {
  PerformanceCriticalComponent *component = malloc(sizeof(PerformanceCriticalComponent));
  component->id = id;
  component->name = strdup(name);
  component->value = value;
  return component;
}

// Define the function to destroy a performance-critical component
void destroyPerformanceCriticalComponent(PerformanceCriticalComponent *component) {
  free(component->name);
  free(component);
}

// Define the function to print a performance-critical component
void printPerformanceCriticalComponent(PerformanceCriticalComponent *component) {
  printf("Performance-critical component %d: %s (%.2f)\n",
         component->id, component->name, component->value);
}

// Define the function to compare two performance-critical components
int comparePerformanceCriticalComponents(PerformanceCriticalComponent *a, PerformanceCriticalComponent *b) {
  return a->value - b->value;
}

// Define the main function
int main() {
  // Create an array of performance-critical components
  PerformanceCriticalComponent *components[] = {
    createPerformanceCriticalComponent(1, "CPU", 100.0),
    createPerformanceCriticalComponent(2, "Memory", 50.0),
    createPerformanceCriticalComponent(3, "Disk", 25.0),
    createPerformanceCriticalComponent(4, "Network", 10.0),
  };

  // Sort the array of performance-critical components
  qsort(components, sizeof(components) / sizeof(PerformanceCriticalComponent *),
        sizeof(PerformanceCriticalComponent *), comparePerformanceCriticalComponents);

  // Print the array of performance-critical components
  for (int i = 0; i < sizeof(components) / sizeof(PerformanceCriticalComponent *); i++) {
    printPerformanceCriticalComponent(components[i]);
  }

  // Destroy the array of performance-critical components
  for (int i = 0; i < sizeof(components) / sizeof(PerformanceCriticalComponent *); i++) {
    destroyPerformanceCriticalComponent(components[i]);
  }

  return 0;
}