//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
struct knight {
    char name[50];
    int strength;
    int intelligence;
};

// Define the functions
void add_knight(struct knight* knights, int num_knights, char* name, int strength, int intelligence);
void remove_knight(struct knight* knights, int num_knights, char* name);
struct knight* find_knight(struct knight* knights, int num_knights, char* name);

// Define the main function
int main() {
    // Initialize the database
    struct knight knights[5];
    int num_knights = 0;

    // Add some knights
    add_knight(knights, num_knights, "Sir Lancelot", 100, 150);
    add_knight(knights, num_knights, "Sir Gawain", 80, 120);
    add_knight(knights, num_knights, "Sir Percival", 70, 110);

    // Remove a knight
    remove_knight(knights, num_knights, "Sir Gawain");

    // Find a knight
    struct knight* found_knight = find_knight(knights, num_knights, "Sir Lancelot");
    if (found_knight != NULL) {
        printf("Found Sir Lancelot with strength %d and intelligence %d\n", found_knight->strength, found_knight->intelligence);
    } else {
        printf("Sir Lancelot not found\n");
    }

    return 0;
}

// Function to add a knight
void add_knight(struct knight* knights, int num_knights, char* name, int strength, int intelligence) {
    struct knight* new_knight = (struct knight*) malloc(sizeof(struct knight));
    strcpy(new_knight->name, name);
    new_knight->strength = strength;
    new_knight->intelligence = intelligence;
    knights[num_knights] = *new_knight;
    num_knights++;
}

// Function to remove a knight
void remove_knight(struct knight* knights, int num_knights, char* name) {
    int i;
    for (i = 0; i < num_knights; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            break;
        }
    }
    if (i < num_knights) {
        memmove(knights + i, knights + i + 1, (num_knights - i - 1) * sizeof(struct knight));
        num_knights--;
    }
}

// Function to find a knight
struct knight* find_knight(struct knight* knights, int num_knights, char* name) {
    int i;
    for (i = 0; i < num_knights; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            return &knights[i];
        }
    }
    return NULL;
}