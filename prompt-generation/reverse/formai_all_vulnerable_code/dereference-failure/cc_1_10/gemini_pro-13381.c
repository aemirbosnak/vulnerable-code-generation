//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the knight's fitness tracker
struct fitness_tracker {
    char *name;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};

// Create a new knight's fitness tracker
struct fitness_tracker *create_fitness_tracker(char *name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma) {
    struct fitness_tracker *tracker = malloc(sizeof(struct fitness_tracker));
    tracker->name = strdup(name);
    tracker->strength = strength;
    tracker->dexterity = dexterity;
    tracker->constitution = constitution;
    tracker->intelligence = intelligence;
    tracker->wisdom = wisdom;
    tracker->charisma = charisma;
    return tracker;
}

// Print the knight's fitness tracker
void print_fitness_tracker(struct fitness_tracker *tracker) {
    printf("%s\n", tracker->name);
    printf("Strength: %d\n", tracker->strength);
    printf("Dexterity: %d\n", tracker->dexterity);
    printf("Constitution: %d\n", tracker->constitution);
    printf("Intelligence: %d\n", tracker->intelligence);
    printf("Wisdom: %d\n", tracker->wisdom);
    printf("Charisma: %d\n", tracker->charisma);
}

// Free the knight's fitness tracker
void free_fitness_tracker(struct fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker);
}

// Main function
int main(int argc, char **argv) {
    // Create a new knight's fitness tracker
    struct fitness_tracker *tracker = create_fitness_tracker("Sir Lancelot", 18, 16, 14, 12, 10, 8);

    // Print the knight's fitness tracker
    print_fitness_tracker(tracker);

    // Free the knight's fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}