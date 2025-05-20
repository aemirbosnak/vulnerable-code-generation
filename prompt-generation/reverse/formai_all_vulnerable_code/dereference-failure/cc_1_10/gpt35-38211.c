//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
// A knight's stable of horses.

#include <stdio.h>
#include <stdlib.h>

// The struct for a horse.
struct horse {
    char* name;
    struct horse* next;
};

// Function to add a new horse to the stable.
void addHorse(struct horse** stable, char* name) {
    struct horse* newHorse = (struct horse*)malloc(sizeof(struct horse));
    newHorse->name = name;
    newHorse->next = *stable;
    *stable = newHorse;
    printf("A new horse named %s has been added to the stable!\n", name);
}

// Function to remove a horse from the stable.
void removeHorse(struct horse** stable, char* name) {
    struct horse* prev = NULL;
    struct horse* curr = *stable;
    while (curr != NULL) {
        if (curr->name == name) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                *stable = curr->next;
            }
            free(curr);
            printf("%s has ridden off into the sunset!\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("%s isn't in the stable!\n", name);
}

// Function to display the horses in the stable.
void displayStable(struct horse* stable) {
    if (stable == NULL) {
        printf("The stable is empty!\n");
    } else {
        printf("The horses in the stable are: \n");
        while (stable != NULL) {
            printf("%s\n", stable->name);
            stable = stable->next;
        }
    }
}

int main() {
    struct horse* myStable = NULL;

    addHorse(&myStable, "Pegasus");
    addHorse(&myStable, "Thunderbolt");
    addHorse(&myStable, "Shadowfax");

    displayStable(myStable);

    removeHorse(&myStable, "Thunderbolt");

    displayStable(myStable);

    removeHorse(&myStable, "Bucephalus");

    return 0;
}