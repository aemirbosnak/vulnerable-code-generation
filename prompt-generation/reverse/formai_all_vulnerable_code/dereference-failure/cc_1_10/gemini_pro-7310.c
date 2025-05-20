//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *description;
    int value;
} Class;

Class classes[] = {
    {"A", "This is the first class.", 1},
    {"B", "This is the second class.", 2},
    {"C", "This is the third class.", 3}
};

int main() {
    // Get the user's input.
    printf("Enter your name: ");
    char *name = malloc(100);
    scanf("%s", name);

    printf("Enter your class: ");
    char *class = malloc(100);
    scanf("%s", class);

    // Find the user's class.
    Class *userClass = NULL;
    for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
        if (strcmp(class, classes[i].name) == 0) {
            userClass = &classes[i];
            break;
        }
    }

    // If the user's class is not found, then print an error message.
    if (userClass == NULL) {
        printf("Invalid class.\n");
        return 1;
    }

    // Print the user's information.
    printf("Name: %s\n", name);
    printf("Class: %s\n", userClass->name);
    printf("Description: %s\n", userClass->description);
    printf("Value: %d\n", userClass->value);

    // Free the memory that was allocated.
    free(name);
    free(class);

    return 0;
}