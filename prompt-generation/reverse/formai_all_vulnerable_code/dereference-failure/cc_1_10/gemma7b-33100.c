//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct _performance_critical_component {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int state;
} performance_critical_component_t;

performance_critical_component_t* create_performance_critical_component() {
    performance_critical_component_t* component = malloc(sizeof(performance_critical_component_t));
    component->position = 0;
    component->state = 0;
    return component;
}

void destroy_performance_critical_component(performance_critical_component_t* component) {
    free(component);
}

void write_to_performance_critical_component(performance_critical_component_t* component, char* data, int size) {
    if (size > MAX_BUFFER_SIZE) {
        return;
    }

    memcpy(component->buffer + component->position, data, size);
    component->position += size;

    if (component->position >= MAX_BUFFER_SIZE) {
        component->position = 0;
        component->state++;
    }
}

int read_from_performance_critical_component(performance_critical_component_t* component, char* data, int size) {
    int available_size = component->position - component->state * MAX_BUFFER_SIZE;

    if (size > available_size) {
        return 0;
    }

    memcpy(data, component->buffer, size);
    component->position -= size;

    if (component->position < MAX_BUFFER_SIZE) {
        component->state--;
    }

    return size;
}

int main() {
    performance_critical_component_t* component = create_performance_critical_component();

    char* data = "Hello, world!";
    write_to_performance_critical_component(component, data, strlen(data));

    char* read_data = malloc(MAX_BUFFER_SIZE);
    read_from_performance_critical_component(component, read_data, MAX_BUFFER_SIZE);

    printf("%s\n", read_data);

    destroy_performance_critical_component(component);

    return 0;
}