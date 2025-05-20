//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Our star-crossed lovers
typedef struct {
    char *name;
    int age;
} Lover;

// A function to handle our tragic errors
void handleError(char *message) {
    printf("Alas, fair Romeo, such a tragic day!\n");
    printf("%s\n", message);
    exit(1);
}

// A function to create our star-crossed lover
Lover *createLover(char *name, int age) {
    Lover *lover = malloc(sizeof(Lover));
    if (lover == NULL) {
        handleError("Could not allocate memory for our star-crossed lover");
    }
    lover->name = name;
    lover->age = age;
    return lover;
}

// A function to free our star-crossed lover
void destroyLover(Lover *lover) {
    if (lover == NULL) {
        handleError("Could not free our star-crossed lover");
    }
    free(lover);
}

int main(void) {
    // Our star-crossed lovers
    Lover *romeo = createLover("Romeo", 16);
    Lover *juliet = createLover("Juliet", 14);

    // Their forbidden love
    printf("Romeo and Juliet, their love a tragic play,\n");
    printf("A tale of woe, a cruel and bitter fray.\n\n");

    // But fate has other plans
    if (romeo->age < 18) {
        handleError("Romeo is too young, their love a forbidden plight");
    }
    if (juliet->age < 16) {
        handleError("Juliet is too young, their love a cruel delight");
    }

    // Their tragic end
    printf("Their love was doomed, a tragedy so grand,\n");
    printf("A tale of woe that still inspires the land.\n\n");

    // We bid farewell to our star-crossed lovers
    destroyLover(romeo);
    destroyLover(juliet);

    return 0;
}