//GEMINI-pro DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet types
typedef struct {
    char *name;
    int age;
    char *family;
} Romeo;

typedef struct {
    char *name;
    int age;
    char *family;
} Juliet;

// Define the function to create a Romeo
Romeo *createRomeo(char *name, int age, char *family) {
    Romeo *romeo = malloc(sizeof(Romeo));
    romeo->name = name;
    romeo->age = age;
    romeo->family = family;
    return romeo;
}

// Define the function to create a Juliet
Juliet *createJuliet(char *name, int age, char *family) {
    Juliet *juliet = malloc(sizeof(Juliet));
    juliet->name = name;
    juliet->age = age;
    juliet->family = family;
    return juliet;
}

// Define the function to print a Romeo
void printRomeo(Romeo *romeo) {
    printf("Romeo: %s, %d, %s\n", romeo->name, romeo->age, romeo->family);
}

// Define the function to print a Juliet
void printJuliet(Juliet *juliet) {
    printf("Juliet: %s, %d, %s\n", juliet->name, juliet->age, juliet->family);
}

// Define the main function
int main() {
    // Create Romeo and Juliet
    Romeo *romeo = createRomeo("Romeo Montague", 16, "Montague");
    Juliet *juliet = createJuliet("Juliet Capulet", 14, "Capulet");

    // Print Romeo and Juliet
    printRomeo(romeo);
    printJuliet(juliet);

    // Free Romeo and Juliet
    free(romeo);
    free(juliet);

    return 0;
}