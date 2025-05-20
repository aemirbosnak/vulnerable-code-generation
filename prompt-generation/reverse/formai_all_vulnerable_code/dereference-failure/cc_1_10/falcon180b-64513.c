//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a character in the play
typedef struct {
    char *name;
    int age;
    char *role;
} Character;

// Define a structure for a scene in the play
typedef struct {
    int act;
    int scene;
    Character *characters;
    int num_characters;
} Scene;

// Function to print a character's information
void print_character(Character *c) {
    printf("Name: %s\n", c->name);
    printf("Age: %d\n", c->age);
    printf("Role: %s\n", c->role);
}

// Function to print a scene's information
void print_scene(Scene *s) {
    printf("Act %d, Scene %d:\n", s->act, s->scene);
    for (int i = 0; i < s->num_characters; i++) {
        print_character(s->characters + i);
    }
}

// Main function to demonstrate the use of structures
int main() {
    // Define the characters in the play
    Character romeo = {"Romeo", 18, "Protagonist"};
    Character juliet = {"Juliet", 14, "Protagonist"};
    Character tybalt = {"Tybalt", 20, "Antagonist"};
    Character mercutio = {"Mercutio", 25, "Supporting"};

    // Define the scenes in the play
    Scene balcony_scene = {1, 5, (Character []) {&juliet, &romeo}, 2};
    Scene fight_scene = {3, 1, (Character []) {&tybalt, &mercutio, &romeo}, 3};

    // Print information about the balcony scene
    print_scene(&balcony_scene);

    // Print information about the fight scene
    print_scene(&fight_scene);

    return 0;
}