//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Element struct
typedef struct Element {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
} Element;

// Function to display element information
void displayElementInfo(Element element) {
    printf("Element Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Atomic Mass: %f\n", element.atomicMass);
    printf("\n");
}

// Function to compare two elements based on atomic number
int compareAtomicNumber(const void* a, const void* b) {
    Element* elementA = (Element*)a;
    Element* elementB = (Element*)b;
    if (elementA->atomicNumber < elementB->atomicNumber) return -1;
    else if (elementA->atomicNumber == elementB->atomicNumber) return 0;
    else return 1;
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");

    // Create an array of elements
    Element elements[118];

    // Read element information from file
    FILE* file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }
    char line[100];
    int index = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        strcpy(elements[index].symbol, token);

        token = strtok(NULL, ",");
        strcpy(elements[index].name, token);

        token = strtok(NULL, ",");
        elements[index].atomicNumber = atoi(token);

        token = strtok(NULL, ",");
        elements[index].atomicMass = atof(token);

        index++;
    }
    fclose(file);

    // Sort elements by atomic number
    qsort(elements, 118, sizeof(Element), compareAtomicNumber);

    // Display element information and prompt user for input
    int i;
    char input[3];
    for (i = 0; i < 118; i++) {
        displayElementInfo(elements[i]);
        printf("Enter the symbol of the above element (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) break;
        else if (strcmp(input, elements[i].symbol) == 0) printf("Correct!\n");
        else printf("Incorrect. The correct symbol is %s.\n", elements[i].symbol);
    }

    printf("Thanks for playing!\n");
    return 0;
}