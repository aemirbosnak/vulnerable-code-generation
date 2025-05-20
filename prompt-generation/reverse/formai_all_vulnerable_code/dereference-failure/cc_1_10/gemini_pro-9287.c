//GEMINI-pro DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some funny constants
#define PIE 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define TAU 2 * PIE
#define E 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274

// Define a funny struct
typedef struct {
    char *name;
    int age;
    float height;
    double weight;
} FunnyPerson;

// Define a funny function
FunnyPerson *createFunnyPerson(char *name, int age, float height, double weight) {
    FunnyPerson *fp = malloc(sizeof(FunnyPerson));
    fp->name = name;
    fp->age = age;
    fp->height = height;
    fp->weight = weight;
    return fp;
}

// Print a funny person
void printFunnyPerson(FunnyPerson *fp) {
    printf("Name: %s\n", fp->name);
    printf("Age: %d\n", fp->age);
    printf("Height: %.2f\n", fp->height);
    printf("Weight: %.2f\n", fp->weight);
}

// Free a funny person
void freeFunnyPerson(FunnyPerson *fp) {
    free(fp->name);
    free(fp);
}

// Main function
int main() {
    // Create a funny person
    FunnyPerson *fp = createFunnyPerson("John Doe", 42, 1.80, 80.0);

    // Print the funny person
    printFunnyPerson(fp);

    // Free the funny person
    freeFunnyPerson(fp);

    return 0;
}