//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct _FitnessTracker {
    char name[MAX_SIZE];
    int age;
    float weight;
    float height;
    int steps_taken;
    int calories_burned;
    struct _FitnessTracker* next;
} FitnessTracker;

void insert_fitness_tracker(FitnessTracker** head, char* name, int age, float weight, float height, int steps_taken, int calories_burned) {
    FitnessTracker* new_node = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->weight = weight;
    new_node->height = height;
    new_node->steps_taken = steps_taken;
    new_node->calories_burned = calories_burned;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void print_fitness_tracker(FitnessTracker* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Weight: %.2f\n", head->weight);
        printf("Height: %.2f\n", head->height);
        printf("Steps Taken: %d\n", head->steps_taken);
        printf("Calories Burned: %d\n", head->calories_burned);
        printf("\n");
        head = head->next;
    }
}

int main() {
    FitnessTracker* head = NULL;

    insert_fitness_tracker(&head, "John Doe", 25, 80.0, 1.75, 10000, 2000);
    insert_fitness_tracker(&head, "Jane Doe", 30, 60.0, 1.60, 8000, 1500);
    insert_fitness_tracker(&head, "Peter Pan", 12, 50.0, 1.50, 6000, 1200);

    print_fitness_tracker(head);

    return 0;
}