//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct TrafficLight {
    int current_state;
    struct TrafficLight* next;
} TrafficLight;

void insert_at_tail(Node** head, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void simulate_traffic_flow(TrafficLight* traffic_light) {
    traffic_light->current_state = rand() % 3;

    switch (traffic_light->current_state) {
        case 0:
            printf("Red light is on.\n");
            break;
        case 1:
            printf("Yellow light is on.\n");
            break;
        case 2:
            printf("Green light is on.\n");
            break;
    }

    simulate_traffic_flow(traffic_light->next);
}

int main() {
    TrafficLight* traffic_light = malloc(sizeof(TrafficLight));
    traffic_light->current_state = 0;
    traffic_light->next = NULL;

    insert_at_tail(&traffic_light, 1);
    insert_at_tail(&traffic_light, 2);
    insert_at_tail(&traffic_light, 3);

    simulate_traffic_flow(traffic_light);

    return 0;
}