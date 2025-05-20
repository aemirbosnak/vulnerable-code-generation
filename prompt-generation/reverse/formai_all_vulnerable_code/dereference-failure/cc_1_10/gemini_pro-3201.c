//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
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

// Create a new performance-critical component
PerformanceCriticalComponent *new_performance_critical_component(int id, char *name, double value) {
    PerformanceCriticalComponent *component = malloc(sizeof(PerformanceCriticalComponent));
    component->id = id;
    component->name = strdup(name);
    component->value = value;
    return component;
}

// Destroy a performance-critical component
void destroy_performance_critical_component(PerformanceCriticalComponent *component) {
    free(component->name);
    free(component);
}

// Print the performance-critical component
void print_performance_critical_component(PerformanceCriticalComponent *component) {
    printf("Performance-critical component %d: %s (%.2f)\n", component->id, component->name, component->value);
}

// Compare two performance-critical components
int compare_performance_critical_components(PerformanceCriticalComponent *a, PerformanceCriticalComponent *b) {
    return strcmp(a->name, b->name);
}

// Sort an array of performance-critical components
void sort_performance_critical_components(PerformanceCriticalComponent **components, int num_components) {
    qsort(components, num_components, sizeof(PerformanceCriticalComponent *), compare_performance_critical_components);
}

// Find a performance-critical component by name
PerformanceCriticalComponent *find_performance_critical_component_by_name(PerformanceCriticalComponent **components, int num_components, char *name) {
    int low = 0;
    int high = num_components - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(components[mid]->name, name);
        if (comparison == 0) {
            return components[mid];
        } else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL;
}

// Main function
int main() {
    // Create an array of performance-critical components
    PerformanceCriticalComponent *components[] = {
        new_performance_critical_component(1, "CPU", 3.0),
        new_performance_critical_component(2, "Memory", 16.0),
        new_performance_critical_component(3, "Disk", 1.0),
        new_performance_critical_component(4, "Network", 100.0),
    };
    int num_components = sizeof(components) / sizeof(components[0]);

    // Sort the array of performance-critical components
    sort_performance_critical_components(components, num_components);

    // Print the sorted array of performance-critical components
    for (int i = 0; i < num_components; i++) {
        print_performance_critical_component(components[i]);
    }

    // Find a performance-critical component by name
    PerformanceCriticalComponent *component = find_performance_critical_component_by_name(components, num_components, "Memory");
    if (component != NULL) {
        printf("Found performance-critical component: %s (%.2f)\n", component->name, component->value);
    } else {
        printf("Performance-critical component not found.\n");
    }

    // Destroy the array of performance-critical components
    for (int i = 0; i < num_components; i++) {
        destroy_performance_critical_component(components[i]);
    }

    return 0;
}