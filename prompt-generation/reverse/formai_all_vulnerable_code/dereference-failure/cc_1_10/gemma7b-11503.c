//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the periodic table structure
typedef struct Element {
    char name[20];
    int atomicNumber;
    float atomicMass;
    struct Element* nextElement;
} Element;

// Create a linked list of elements
Element* createElementList() {
    Element* head = NULL;
    Element* tail = NULL;

    // Allocate memory for the first element
    head = (Element*)malloc(sizeof(Element));
    tail = head;

    // Initialize the element's name, atomic number, and atomic mass
    tail->name[0] = 'H';
    tail->atomicNumber = 1;
    tail->atomicMass = 1.00784;

    // Create the rest of the elements
    for (int i = 2; i <= 118; i++) {
        tail->nextElement = (Element*)malloc(sizeof(Element));
        tail = tail->nextElement;

        tail->name[0] = 'A' + i - 1;
        tail->atomicNumber = i;
        tail->atomicMass = (float)i + 0.0001;
    }

    return head;
}

// Print the periodic table
void printPeriodicTable(Element* head) {
    printf("<table>\n");
    printf("<thead>\n");
    printf("<tr>\n");
    printf("<th>Name</th>\n");
    printf("<th>Atomic Number</th>\n");
    printf("<th>Atomic Mass</th>\n");
    printf("</tr>\n");
    printf("</thead>\n");
    printf("<tbody>\n");

    Element* currentElement = head;
    while (currentElement) {
        printf("<tr>\n");
        printf("<td>%s</td>\n", currentElement->name);
        printf("<td>%d</td>\n", currentElement->atomicNumber);
        printf("<td>%.3f</td>\n", currentElement->atomicMass);
        printf("</tr>\n");

        currentElement = currentElement->nextElement;
    }

    printf("</tbody>\n");
    printf("</table>\n");
}

int main() {
    Element* head = createElementList();
    printPeriodicTable(head);

    return 0;
}