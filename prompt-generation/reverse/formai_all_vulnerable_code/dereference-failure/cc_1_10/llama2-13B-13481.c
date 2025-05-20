//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GUESTS 10

// Structure to store information about a guest
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} guest_t;

// Function to generate a random name for a guest
void generate_name(guest_t *g) {
    int i;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        g->name[i] = 'a' + (rand() % 26);
    }
}

// Function to generate a random age for a guest
void generate_age(guest_t *g) {
    int age = rand() % 100 + 1;
    g->age = age;
}

// Function to add a guest to the party
void add_guest(guest_t **guests, int *num_guests) {
    int i;
    for (i = 0; i < *num_guests; i++) {
        if (strcmp(guests[i]->name, "") == 0) {
            // If the slot is empty, add the new guest
            guests[i] = (guest_t *) malloc(sizeof(guest_t));
            generate_name(guests[i]);
            generate_age(guests[i]);
            break;
        } else {
            // If the slot is not empty, keep looking
            continue;
        }
    }
    if (i == *num_guests) {
        // If all slots are full, print an error message
        printf("The party is full! No more guests can be added.\n");
    }
    (*num_guests)++;
}

// Function to print the list of guests
void print_guests(guest_t **guests, int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("%d. %s (%d years old)\n", i + 1, guests[i]->name, guests[i]->age);
    }
}

int main() {
    int num_guests = 0;
    guest_t *guests = (guest_t *) malloc(sizeof(guest_t) * MAX_GUESTS);

    // Add guests to the party
    add_guest(&guests, &num_guests);
    add_guest(&guests, &num_guests);
    add_guest(&guests, &num_guests);

    // Print the list of guests
    print_guests(guests, num_guests);

    return 0;
}