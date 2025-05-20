//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element {
    char name[20];
    int atomic_number;
    double mass;
    struct Element* next;
} Element;

Element* insert_element(Element* head, char* name, int atomic_number, double mass) {
    Element* new_element = (Element*)malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->mass = mass;
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        Element* last_element = head;
        while (last_element->next != NULL) {
            last_element = last_element->next;
        }
        last_element->next = new_element;
    }

    return head;
}

void print_period_table(Element* head) {
    Element* current_element = head;
    printf("<table>\n");
    printf("  <thead>\n");
    printf("    <tr>\n");
    printf("      <th>Name</th>\n");
    printf("      <th>Atomic Number</th>\n");
    printf("      <th>Mass</th>\n");
    printf("    </tr>\n");
    printf("  </thead>\n");
    printf("  <tbody>\n");
    while (current_element) {
        printf("    <tr>\n");
        printf("      <td>%s</td>\n", current_element->name);
        printf("      <td>%d</td>\n", current_element->atomic_number);
        printf("      <td>%.2lf</td>\n", current_element->mass);
        printf("    </tr>\n");
        current_element = current_element->next;
    }
    printf("  </tbody>\n");
    printf("</table>\n");
}

int main() {
    Element* head = NULL;

    insert_element(head, "Hydrogen", 1, 1.008);
    insert_element(head, "Helium", 2, 4.0026);
    insert_element(head, "Lithium", 3, 6.940);
    insert_element(head, "Sodium", 11, 22.989);

    print_period_table(head);

    return 0;
}