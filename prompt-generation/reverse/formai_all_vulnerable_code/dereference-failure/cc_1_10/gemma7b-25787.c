//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the periodic table
#define MAX_ELEMENTS 118

struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    char block_number;
    struct Element* next;
};

// Create the first element
struct Element* create_element(char* name, int atomic_number, float atomic_mass, char* symbol, char block_number) {
    struct Element* element = malloc(sizeof(struct Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    strcpy(element->symbol, symbol);
    element->block_number = block_number;
    element->next = NULL;
    return element;
}

// Print the periodic table
void print_periodic_table(struct Element* element) {
    printf("<table>\n");
    printf("<thead>\n");
    printf("<tr>\n");
    printf("<th>Name</th>\n");
    printf("<th>Atomic Number</th>\n");
    printf("<th>Atomic Mass</th>\n");
    printf("<th>Symbol</th>\n");
    printf("<th>Block Number</th>\n");
    printf("</tr>\n");
    printf("</thead>\n");
    printf("<tbody>\n");

    while (element) {
        printf("<tr>\n");
        printf("<td>%s</td>\n", element->name);
        printf("<td>%d</td>\n", element->atomic_number);
        printf("<td>%.2f</td>\n", element->atomic_mass);
        printf("<td>%s</td>\n", element->symbol);
        printf("<td>%c</td>\n", element->block_number);
        printf("</tr>\n");
        element = element->next;
    }

    printf("</tbody>\n");
    printf("</table>\n");
}

int main() {
    // Create the periodic table
    struct Element* hydrogen = create_element("Hydrogen", 1, 1.00784, "H", '1');
    struct Element* helium = create_element("Helium", 2, 4.002602, "He", '2');
    struct Element* sodium = create_element("Sodium", 11, 22.989769, "Na", '1' );

    // Print the periodic table
    print_periodic_table(hydrogen);
    print_periodic_table(helium);
    print_periodic_table(sodium);

    return 0;
}