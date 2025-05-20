//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

#define BUF_SIZE 10

typedef struct {
    int data;
    time_t timestamp;
    struct node *next;
} node_t;

node_t buffer[BUF_SIZE];
node_t *head = NULL;

void add_to_buffer(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->timestamp = time(NULL);
    new_node->next = head;
    head = new_node;
    if (head >= &buffer[BUF_SIZE]) head = buffer;
}

void travel_back(int steps) {
    node_t *current = head;
    int travel_distance = steps % BUF_SIZE;

    if (!travel_distance) {
        printf("You are already at the earliest time.\n");
        return;
    }

    for (int i = 0; i < travel_distance; i++) {
        if (!current->next) {
            printf("You have traveled too far back in time.\n");
            return;
        }
        current = current->next;
    }

    printf("You are now at time: %s", ctime(&(current->timestamp)));
    printf("Variable value: %d\n", current->data);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 15; i++) {
        add_to_buffer(rand() % 100);
        sleep(1);
    }

    travel_back(3);

    return 0;
}