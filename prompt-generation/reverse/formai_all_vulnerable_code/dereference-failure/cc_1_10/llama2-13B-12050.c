//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a knight
struct knight {
    char name[50];
    int strength;
    int intelligence;
};

// Define the function to create a knight
struct knight *create_knight(char *name, int strength, int intelligence) {
    struct knight *new_knight = (struct knight *)malloc(sizeof(struct knight));
    strcpy(new_knight->name, name);
    new_knight->strength = strength;
    new_knight->intelligence = intelligence;
    return new_knight;
}

// Define the function to display a knight
void display_knight(struct knight *knight) {
    printf("Name: %s\n", knight->name);
    printf("Strength: %d\n", knight->strength);
    printf("Intelligence: %d\n", knight->intelligence);
}

// Define the function to add a knight to the kingdom
void add_knight(struct knight **knights, int num_knights, struct knight *new_knight) {
    int i;
    for (i = 0; i < num_knights; i++) {
        if (strcmp(knights[i]->name, new_knight->name) == 0) {
            printf("Error: Knight already exists in the kingdom.\n");
            return;
        }
    }
    knights[num_knights] = new_knight;
    num_knights++;
}

// Define the function to search for a knight in the kingdom
struct knight *search_knight(struct knight **knights, int num_knights, char *name) {
    int i;
    for (i = 0; i < num_knights; i++) {
        if (strcmp(knights[i]->name, name) == 0) {
            return knights[i];
        }
    }
    return NULL;
}

// Define the function to remove a knight from the kingdom
void remove_knight(struct knight **knights, int num_knights, char *name) {
    int i;
    for (i = 0; i < num_knights; i++) {
        if (strcmp(knights[i]->name, name) == 0) {
            memmove(&knights[i], &knights[i+1], (num_knights - i - 1) * sizeof(struct knight));
            num_knights--;
            return;
        }
    }
    printf("Error: Knight not found in the kingdom.\n");
}

int main() {
    struct knight *knights[10];
    int num_knights = 0;

    // Create knights
    knights[0] = create_knight("Sir Lancelot", 100, 80);
    knights[1] = create_knight("Sir Gawain", 80, 90);
    knights[2] = create_knight("Sir Percival", 90, 70);

    // Add knights to the kingdom
    add_knight(knights, num_knights, knights[0]);
    add_knight(knights, num_knights, knights[1]);
    add_knight(knights, num_knights, knights[2]);

    // Search for a knight in the kingdom
    struct knight *sir_lancelot = search_knight(knights, num_knights, "Sir Lancelot");
    if (sir_lancelot != NULL) {
        display_knight(sir_lancelot);
    } else {
        printf("Error: Knight not found in the kingdom.\n");
    }

    // Remove a knight from the kingdom
    remove_knight(knights, num_knights, "Sir Percival");

    return 0;
}