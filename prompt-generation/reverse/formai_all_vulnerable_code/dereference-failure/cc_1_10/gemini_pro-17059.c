//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct home_device {
    char *name;
    int state;
    struct home_device *next;
} home_device;

home_device *create_device(char *name, int state) {
    home_device *device = malloc(sizeof(home_device));
    device->name = name;
    device->state = state;
    device->next = NULL;
    return device;
}

void add_device(home_device **head, char *name, int state) {
    if (*head == NULL) {
        *head = create_device(name, state);
    } else {
        add_device(&(*head)->next, name, state);
    }
}

void print_devices(home_device *head) {
    if (head == NULL) {
        printf("No devices\n");
    } else {
        printf("%s: %s\n", head->name, head->state == 1 ? "on" : "off");
        print_devices(head->next);
    }
}

void toggle_device(home_device *head, char *name) {
    if (head == NULL) {
        printf("Device not found\n");
    } else if (strcmp(head->name, name) == 0) {
        head->state = !head->state;
        printf("%s is now %s\n", head->name, head->state == 1 ? "on" : "off");
    } else {
        toggle_device(head->next, name);
    }
}

void free_devices(home_device *head) {
    if (head == NULL) {
        return;
    } else {
        free_devices(head->next);
        free(head);
    }
}

int main() {
    home_device *head = NULL;
    add_device(&head, "light", 0);
    add_device(&head, "fan", 0);
    add_device(&head, "tv", 0);

    print_devices(head);

    toggle_device(head, "light");
    toggle_device(head, "tv");

    print_devices(head);

    free_devices(head);

    return 0;
}