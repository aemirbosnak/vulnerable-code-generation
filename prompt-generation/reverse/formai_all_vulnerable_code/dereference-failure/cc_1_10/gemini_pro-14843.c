//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _tracker {
    int steps;
    double distance;
    double calories;
    time_t timestamp;
    struct _tracker *next;
} tracker;

tracker *new_tracker(int steps, double distance, double calories, time_t timestamp) {
    tracker *t = malloc(sizeof(tracker));
    t->steps = steps;
    t->distance = distance;
    t->calories = calories;
    t->timestamp = timestamp;
    t->next = NULL;
    return t;
}

void add_to_tracker(tracker **head, int steps, double distance, double calories, time_t timestamp) {
    tracker *new_node = new_tracker(steps, distance, calories, timestamp);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    add_to_tracker(&(*head)->next, steps, distance, calories, timestamp);
}

void print_tracker(tracker *head) {
    if (head == NULL) {
        return;
    }
    printf("Steps: %d, Distance: %.2f, Calories: %.2f, Timestamp: %s", head->steps, head->distance,
           head->calories, ctime(&head->timestamp));
    print_tracker(head->next);
}

void free_tracker(tracker *head) {
    if (head == NULL) {
        return;
    }
    free_tracker(head->next);
    free(head);
}

int main() {
    tracker *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        add_to_tracker(&head, rand() % 10000, (double)rand() / RAND_MAX * 10, (double)rand() / RAND_MAX * 100,
                      time(NULL));
    }
    print_tracker(head);
    free_tracker(head);
    return 0;
}