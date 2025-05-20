//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Define the structure of a performance-critical component
struct component {
    char *name;
    uint32_t id;
    float value;
    bool active;
};

// Create a new performance-critical component
struct component *create_component(char *name, uint32_t id, float value, bool active) {
    struct component *component = malloc(sizeof(struct component));
    component->name = strdup(name);
    component->id = id;
    component->value = value;
    component->active = active;
    return component;
}

// Destroy a performance-critical component
void destroy_component(struct component *component) {
    free(component->name);
    free(component);
}

// Update the value of a performance-critical component
void update_component(struct component *component, float value) {
    component->value = value;
}

// Get the value of a performance-critical component
float get_component_value(struct component *component) {
    return component->value;
}

// Get the ID of a performance-critical component
uint32_t get_component_id(struct component *component) {
    return component->id;
}

// Get the name of a performance-critical component
char *get_component_name(struct component *component) {
    return component->name;
}

// Get the active flag of a performance-critical component
bool get_component_active(struct component *component) {
    return component->active;
}

// Set the active flag of a performance-critical component
void set_component_active(struct component *component, bool active) {
    component->active = active;
}

// Print the details of a performance-critical component
void print_component(struct component *component) {
    printf("Component name: %s\n", get_component_name(component));
    printf("Component ID: %u\n", get_component_id(component));
    printf("Component value: %f\n", get_component_value(component));
    printf("Component active: %s\n", get_component_active(component) ? "true" : "false");
}

// Main function
int main(int argc, char **argv) {
    // Create a new performance-critical component
    struct component *component = create_component("MyComponent", 12345, 3.14159, true);

    // Print the details of the component
    print_component(component);

    // Update the value of the component
    update_component(component, 2.71828);

    // Print the details of the component again
    print_component(component);

    // Destroy the component
    destroy_component(component);

    return 0;
}