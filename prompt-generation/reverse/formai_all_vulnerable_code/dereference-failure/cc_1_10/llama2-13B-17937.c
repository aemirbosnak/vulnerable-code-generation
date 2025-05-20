//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a unicorn, with properties such as name, color, and horn length
typedef struct {
    char *name;
    char *color;
    int horn_length;
} unicorn;

// Function to create a new unicorn
unicorn *create_unicorn(char *name, char *color, int horn_length) {
    unicorn *new_unicorn = (unicorn *)malloc(sizeof(unicorn));
    new_unicorn->name = name;
    new_unicorn->color = color;
    new_unicorn->horn_length = horn_length;
    return new_unicorn;
}

// Function to print a unicorn's information
void print_unicorn(unicorn *unicorn) {
    printf("Name: %s\n", unicorn->name);
    printf("Color: %s\n", unicorn->color);
    printf("Horn Length: %d\n", unicorn->horn_length);
}

// Function to make a unicorn happy
void make_unicorn_happy(unicorn *unicorn) {
    // Increase horn length by 10%
    unicorn->horn_length += (unicorn->horn_length * 10) / 100;
    // Print a happy message
    printf("Unicorn is now happy! :D\n");
}

// Function to main function
int main() {
    // Create a new unicorn
    unicorn *unicorn = create_unicorn("Rainbow", "Purple", 10);

    // Print the unicorn's information
    print_unicorn(unicorn);

    // Make the unicorn happy
    make_unicorn_happy(unicorn);

    // Print the unicorn's updated information
    print_unicorn(unicorn);

    // Free the unicorn
    free(unicorn);

    return 0;
}