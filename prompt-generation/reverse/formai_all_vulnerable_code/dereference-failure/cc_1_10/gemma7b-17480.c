//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
#define MAX_ELEMENTS 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char block;
    struct Element* next;
} Element;

Element* head = NULL;

void insertElement(char* name, int atomic_number, float atomic_mass, char block) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    newElement->block = block;
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        Element* currentElement = head;
        while (currentElement->next) {
            currentElement = currentElement->next;
        }
        currentElement->next = newElement;
    }
}

void printElements() {
    Element* currentElement = head;
    printf("<table>");
    printf("<thead>\n");
    printf("<tr>\n");
    printf("<th>Name</th>\n");
    printf("<th>Atomic Number</th>\n");
    printf("<th>Atomic Mass</th>\n");
    printf("<th>Block</th>\n");
    printf("</tr>\n");
    printf("</thead>\n");
    printf("<tbody>\n");
    while (currentElement) {
        printf("<tr>\n");
        printf("<td>%s</td>\n", currentElement->name);
        printf("<td>%d</td>\n", currentElement->atomic_number);
        printf("<td>%.2f</td>\n", currentElement->atomic_mass);
        printf("<td>%c</td>\n", currentElement->block);
        printf("</tr>\n");
        currentElement = currentElement->next;
    }
    printf("</tbody>\n");
    printf("</table>\n");
}

int main() {
    insertElement("Hydrogen", 1, 1.008, 'I');
    insertElement("Helium", 2, 4.0026, 'II');
    insertElement("Lithium", 3, 6.940, 'I');
    insertElement("Sodium", 11, 22.989, 'I');

    printElements();

    return 0;
}