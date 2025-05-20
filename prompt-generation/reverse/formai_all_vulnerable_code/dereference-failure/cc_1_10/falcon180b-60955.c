//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Struct to hold element information
typedef struct {
    char symbol[3];
    char name;
    int atomic_number;
    char category[20];
} Element;

// Function prototypes
void generateElements(Element elements[]);
void printElement(Element element);
int compareElements(const void *a, const void *b);

// Main function
int main() {
    srand(time(NULL));

    Element elements[MAX_ELEMENTS];
    generateElements(elements);

    // Sort elements by atomic number
    qsort(elements, MAX_ELEMENTS, sizeof(Element), compareElements);

    // Print table header
    printf("+-----------------+-----------------+\n");
    printf("| Symbol           | Name             |\n");
    printf("+-----------------+-----------------+\n");

    // Print elements
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printElement(elements[i]);
    }

    return 0;
}

// Generate random elements
void generateElements(Element elements[]) {
    const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char categories[] = "Metal Nonmetal Metalloid Gas Noble gas Lanthanide Actinide Transition metal Post-transition metal Other metal Metalloid Other nonmetal";

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        elements[i].symbol[0] = symbols[rand() % 26];
        elements[i].symbol[1] = symbols[rand() % 26];
        elements[i].symbol[2] = '\0';

        elements[i].name = rand() % 2? 'A' : 'a';
        elements[i].atomic_number = rand() % 100 + 1;

        int category_index = rand() % 18;
        strncpy(elements[i].category, categories + category_index * 20, 20);
        elements[i].category[19] = '\0';
    }
}

// Print element information
void printElement(Element element) {
    printf("| %-3s | %-14s | %4d |\n", element.symbol, element.name, element.atomic_number);
}

// Compare function for qsort
int compareElements(const void *a, const void *b) {
    const Element *element_a = a;
    const Element *element_b = b;

    return element_a->atomic_number - element_b->atomic_number;
}