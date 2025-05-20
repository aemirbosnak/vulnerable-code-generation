//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    // Dynamic memory allocation for name and age
    char *name = malloc(MAX_NAME_LENGTH * sizeof(char));
    int age = malloc(sizeof(int));

    // Get the user's name and age
    printf("What's your name? ");
    scanf("%19s", name);
    printf("How old are you? ");
    scanf("%d", age);

    // Check for errors
    if (name == NULL || age == NULL) {
        printf("Error: unable to allocate memory for name or age\n");
        return 1;
    }

    // Check if the name is too long
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Error: name too long (maximum %d characters)\n", MAX_NAME_LENGTH);
        free(name);
        free(age);
        return 2;
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Error: age must be between 0 and %d\n", MAX_AGE);
        free(name);
        free(age);
        return 3;
    }

    // Print a success message
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Free the memory
    free(name);
    free(age);

    return 0;
}