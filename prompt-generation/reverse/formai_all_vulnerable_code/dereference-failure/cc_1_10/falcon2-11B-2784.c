//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VECTOR_SIZE 100
#define MAX_NET_SIZE 10

struct net {
    int index;
    int type; // 0: resistor, 1: capacitor
    int R_or_C;
    int R_or_C_val;
    int R_or_C_val_1;
    int R_or_C_val_2;
    int R_or_C_val_3;
};

struct vector {
    int size;
    int voltage;
    struct net* net_array;
};

struct vector* create_vector(int size) {
    struct vector* new_vector = malloc(sizeof(struct vector));
    new_vector->size = size;
    new_vector->voltage = 0;
    new_vector->net_array = NULL;
    return new_vector;
}

void add_net(struct vector* vector, int type, int R_or_C, int R_or_C_val) {
    struct net* new_net = malloc(sizeof(struct net));
    new_net->index = vector->size;
    new_net->type = type;
    new_net->R_or_C = R_or_C;
    new_net->R_or_C_val = R_or_C_val;
    new_net->R_or_C_val_1 = 0;
    new_net->R_or_C_val_2 = 0;
    new_net->R_or_C_val_3 = 0;
    vector->net_array = realloc(vector->net_array, (vector->size + 1) * sizeof(struct net));
    vector->net_array[vector->size] = *new_net;
    vector->size++;
}

void set_net_value(struct vector* vector, int index, int value) {
    struct net* net = &vector->net_array[index];
    net->R_or_C_val_1 = value;
    net->R_or_C_val_2 = value;
    net->R_or_C_val_3 = value;
}

void update_voltage(struct vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        struct net* net = &vector->net_array[i];
        if (net->type == 0) { // resistor
            if (net->R_or_C_val_1!= 0 && net->R_or_C_val_2!= 0) {
                net->R_or_C_val_3 = net->R_or_C_val_1 * net->R_or_C_val_2 / net->R_or_C_val;
            } else if (net->R_or_C_val_2!= 0 && net->R_or_C_val_3!= 0) {
                net->R_or_C_val_1 = net->R_or_C_val_2 * net->R_or_C_val_3 / net->R_or_C_val;
            } else if (net->R_or_C_val_3!= 0) {
                net->R_or_C_val_1 = net->R_or_C_val_3 / net->R_or_C_val;
            } else if (net->R_or_C_val_1!= 0) {
                net->R_or_C_val_2 = net->R_or_C_val_1 / net->R_or_C_val;
            }
        } else if (net->type == 1) { // capacitor
            if (net->R_or_C_val_1!= 0) {
                net->R_or_C_val_3 = 1 / (net->R_or_C_val_1 * (1 / net->R_or_C_val - 1 / net->R_or_C_val_1));
            }
        }
    }
    vector->voltage = 0;
    for (int i = 0; i < vector->size; i++) {
        struct net* net = &vector->net_array[i];
        if (net->type == 0) { // resistor
            vector->voltage += net->R_or_C_val_1 * net->R_or_C_val_2 * net->R_or_C_val_3;
        } else if (net->type == 1) { // capacitor
            vector->voltage += net->R_or_C_val_1 * (net->R_or_C_val_2 * net->R_or_C_val_3 - net->R_or_C_val_3 * net->R_or_C_val_2);
        }
    }
}

int main() {
    struct vector* vector = create_vector(MAX_VECTOR_SIZE);
    add_net(vector, 0, 0, 1);
    add_net(vector, 0, 0, 2);
    add_net(vector, 1, 0, 100);
    set_net_value(vector, 0, 5);
    set_net_value(vector, 1, 3);
    update_voltage(vector);
    printf("voltage = %d\n", vector->voltage);
    return 0;
}