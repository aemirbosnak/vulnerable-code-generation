//LLAMA2-13B DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define CATS 5
#define DOGS 3

// Define a struct for our curious creatures
struct creature {
    char name[20];
    int age;
    float height;
    float weight;
    int likes_catnip;
};

// Function to generate a random creature
struct creature *create_creature(void) {
    struct creature *c = malloc(sizeof(struct creature));
    c->name[0] = 'A' + (rand() % 26); // Generate a random name
    c->age = rand() % 10 + 1; // Generate a random age
    c->height = (float)rand() / RAND_MAX * 10 + 2; // Generate a random height
    c->weight = (float)rand() / RAND_MAX * 10 + 2; // Generate a random weight
    c->likes_catnip = (rand() % 2) ? 1 : 0; // Generate a random likes catnip
    return c;
}

// Function to print a curious creature
void print_creature(struct creature *c) {
    printf("I am a %s, I am %d years old, and I weigh %f pounds.\n", c->name, c->age, c->weight);
    if (c->likes_catnip) {
        printf("I love catnip! 🐱\n");
    } else {
        printf("I don't like catnip. 😠\n");
    }
}

int main(void) {
    // Create some curious creatures
    struct creature *creatures[CATS + DOGS];
    for (int i = 0; i < CATS; i++) {
        creatures[i] = create_creature();
    }
    for (int i = CATS; i < CATS + DOGS; i++) {
        creatures[i] = create_creature();
    }

    // Print our curious creatures
    for (int i = 0; i < CATS + DOGS; i++) {
        print_creature(creatures[i]);
    }

    // Play with our curious creatures
    for (int i = 0; i < CATS + DOGS; i++) {
        struct creature *c = creatures[i];
        if (c->likes_catnip) {
            printf("I gave %s some catnip, and now they're happy! 🐱\n", c->name);
        } else {
            printf("I gave %s some catnip, but they didn't like it. 😠\n", c->name);
        }
    }

    return 0;
}