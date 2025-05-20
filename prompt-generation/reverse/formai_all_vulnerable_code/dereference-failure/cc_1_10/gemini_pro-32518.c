//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATS 100

typedef struct cat {
    char *name;
    int age;
    char *breed;
} cat;

cat *cats[MAX_CATS];
int num_cats = 0;

void add_cat(char *name, int age, char *breed) {
    if (num_cats >= MAX_CATS) {
        printf("Error: Too many cats!\n");
        return;
    }

    cat *new_cat = malloc(sizeof(cat));
    new_cat->name = strdup(name);
    new_cat->age = age;
    new_cat->breed = strdup(breed);

    cats[num_cats++] = new_cat;
}

void print_cats() {
    for (int i = 0; i < num_cats; i++) {
        printf("Cat %d:\n", i + 1);
        printf("  Name: %s\n", cats[i]->name);
        printf("  Age: %d\n", cats[i]->age);
        printf("  Breed: %s\n", cats[i]->breed);
        printf("\n");
    }
}

void free_cats() {
    for (int i = 0; i < num_cats; i++) {
        free(cats[i]->name);
        free(cats[i]->breed);
        free(cats[i]);
    }
}

int main() {
    // Add some cats to the array
    add_cat("Whiskers", 5, "Domestic Shorthair");
    add_cat("Mittens", 3, "Siamese");
    add_cat("Garfield", 10, "Tabby");
    add_cat("Felix", 2, "Ragdoll");
    add_cat("Sylvester", 8, "Persian");

    // Print the cats
    print_cats();

    // Free the cats
    free_cats();

    return 0;
}