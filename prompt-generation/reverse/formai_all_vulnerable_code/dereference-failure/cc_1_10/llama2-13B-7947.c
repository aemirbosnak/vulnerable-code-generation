//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WEATHER_MAX_DEPTH 10
#define WEATHER_MAX_STEPS 100

typedef struct weather_node {
    char *name;
    int temperature;
    int humidity;
    int pressure;
    struct weather_node *next;
} weather_node_t;

weather_node_t *weather_tree = NULL;

void weather_init(void) {
    weather_tree = NULL;
}

void weather_add_node(char *name, int temperature, int humidity, int pressure) {
    weather_node_t *new_node = (weather_node_t *)malloc(sizeof(weather_node_t));
    new_node->name = name;
    new_node->temperature = temperature;
    new_node->humidity = humidity;
    new_node->pressure = pressure;
    new_node->next = NULL;
    if (weather_tree == NULL) {
        weather_tree = new_node;
    } else {
        weather_node_t *curr = weather_tree;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void weather_print_node(weather_node_t *node) {
    printf("%s: %d°C, %d%% humidity, %d hPa\n", node->name, node->temperature, node->humidity, node->pressure);
}

void weather_print_tree(weather_node_t *node) {
    if (node == NULL) {
        return;
    }
    weather_print_node(node);
    weather_print_tree(node->next);
}

void weather_simulate(int depth, int steps) {
    if (depth == 0 || steps == 0) {
        return;
    }
    weather_node_t *node = weather_tree;
    for (int i = 0; i < steps; i++) {
        if (depth == WEATHER_MAX_DEPTH) {
            break;
        }
        weather_add_node(node->name, node->temperature + (rand() % 5) - 2, node->humidity + (rand() % 5) - 2, node->pressure + (rand() % 5) - 2);
        weather_print_tree(node);
        node = node->next;
    }
}

int main(void) {
    srand(time(NULL));
    weather_init();
    weather_add_node("London", 22, 60, 1010);
    weather_add_node("Paris", 25, 70, 1005);
    weather_add_node("Berlin", 20, 50, 1015);
    weather_simulate(3, WEATHER_MAX_STEPS);
    return 0;
}