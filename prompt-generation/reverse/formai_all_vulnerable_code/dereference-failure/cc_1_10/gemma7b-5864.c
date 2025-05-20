//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float mass;
    char symbol[2];
    struct Element* next;
} Element;

Element* head = NULL;

void insert_element(char* name, int atomic_number, float mass, char* symbol) {
    Element* new_element = (Element*)malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->mass = mass;
    strcpy(new_element->symbol, symbol);
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        Element* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_elements() {
    Element* current = head;
    printf("<table>\n");
    printf("<tr>\n");
    printf("<th>Name</th>\n");
    printf("<th>Atomic Number</th>\n");
    printf("<th>Mass</th>\n");
    printf("<th>Symbol</th>\n");
    printf("</tr>\n");
    while (current) {
        printf("<tr>\n");
        printf("<td>%s</td>\n", current->name);
        printf("<td>%d</td>\n", current->atomic_number);
        printf("<td>%.2f</td>\n", current->mass);
        printf("<td>%s</td>\n", current->symbol);
        printf("</tr>\n");
        current = current->next;
    }
    printf("</table>\n");
}

int main() {
    insert_element("Hydrogen", 1, 1.008, "H");
    insert_element("Helium", 2, 4.0026, "He");
    insert_element("Lithium", 3, 6.940, "Li");
    insert_element("Sodium", 11, 22.989, "Na");
    insert_element("Gold", 79, 196.966, "Au");

    print_elements();

    return 0;
}