//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

// Define the Romeo and Juliet structures
typedef struct {
    char *name;
    int age;
    bool is_male;
} Romeo;

typedef struct {
    char *name;
    int age;
    bool is_female;
} Juliet;

// Define the functions to create Romeo and Juliet objects
Romeo *create_romeo(char *name, int age) {
    Romeo *romeo = malloc(sizeof(Romeo));
    romeo->name = strdup(name);
    romeo->age = age;
    romeo->is_male = true;
    return romeo;
}

Juliet *create_juliet(char *name, int age) {
    Juliet *juliet = malloc(sizeof(Juliet));
    juliet->name = strdup(name);
    juliet->age = age;
    juliet->is_female = true;
    return juliet;
}

// Define the functions to free Romeo and Juliet objects
void free_romeo(Romeo *romeo) {
    free(romeo->name);
    free(romeo);
}

void free_juliet(Juliet *juliet) {
    free(juliet->name);
    free(juliet);
}

// Define the main function
int main() {
    // Create Romeo and Juliet objects
    Romeo *romeo = create_romeo("Romeo", 16);
    Juliet *juliet = create_juliet("Juliet", 14);

    // Print the Romeo and Juliet objects
    printf("Romeo:\n");
    printf("  Name: %s\n", romeo->name);
    printf("  Age: %d\n", romeo->age);
    printf("  Is male: %d\n", romeo->is_male);

    printf("Juliet:\n");
    printf("  Name: %s\n", juliet->name);
    printf("  Age: %d\n", juliet->age);
    printf("  Is female: %d\n", juliet->is_female);

    // Free the Romeo and Juliet objects
    free_romeo(romeo);
    free_juliet(juliet);

    return 0;
}