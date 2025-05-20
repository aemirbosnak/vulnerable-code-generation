//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct _C_Fitness_Tracker {
    char name[MAX];
    int age;
    float weight;
    int steps_taken;
    float distance_covered;
    struct _C_Fitness_Tracker* next;
} C_Fitness_Tracker;

void add_fitness_tracker(C_Fitness_Tracker** head, char* name, int age, float weight, int steps_taken, float distance_covered) {
    C_Fitness_Tracker* new_tracker = malloc(sizeof(C_Fitness_Tracker));
    strcpy(new_tracker->name, name);
    new_tracker->age = age;
    new_tracker->weight = weight;
    new_tracker->steps_taken = steps_taken;
    new_tracker->distance_covered = distance_covered;
    new_tracker->next = NULL;

    if (*head == NULL) {
        *head = new_tracker;
    } else {
        (*head)->next = new_tracker;
    }
}

void print_fitness_tracker(C_Fitness_Tracker* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Weight: %.2f\n", head->weight);
        printf("Steps taken: %d\n", head->steps_taken);
        printf("Distance covered: %.2f\n", head->distance_covered);
        printf("\n");
        head = head->next;
    }
}

int main() {
    C_Fitness_Tracker* head = NULL;

    add_fitness_tracker(&head, "John Doe", 25, 80.0, 10000, 2.5);
    add_fitness_tracker(&head, "Jane Doe", 30, 60.0, 8000, 1.8);
    add_fitness_tracker(&head, "Peter Pan", 12, 70.0, 12000, 3.2);

    print_fitness_tracker(head);

    return 0;
}