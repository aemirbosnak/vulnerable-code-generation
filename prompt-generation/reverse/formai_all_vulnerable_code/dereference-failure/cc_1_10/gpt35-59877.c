//FormAI DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNIT_NAME_LENGTH 20

/* A unit of measurement */
struct unit {
    char name[MAX_UNIT_NAME_LENGTH];
    double conversion_ratio;
};

/* A linked list node to store a unit */
struct unit_node {
    struct unit data;
    struct unit_node* next;
};

/* The head of the linked list */
struct unit_node* head = NULL;

/* Add a unit to the linked list */
void add_unit(char* name, double conversion_ratio) {
    struct unit_node* new_node = (struct unit_node*) malloc(sizeof(struct unit_node));
    struct unit new_unit;
    strcpy(new_unit.name, name);
    new_unit.conversion_ratio = conversion_ratio;
    new_node->data = new_unit;
    new_node->next = head;
    head = new_node;
}

/* Find a unit with the given name */
struct unit* find_unit(char* name) {
    struct unit_node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0)
            return &(current->data);
        current = current->next;
    }
    return NULL;
}

/* Convert a value from one unit to another */
void convert(double value, struct unit* from, struct unit* to) {
    double converted_value = value * from->conversion_ratio / to->conversion_ratio;
    printf("%.2f %s = %.2f %s\n", value, from->name, converted_value, to->name);
}

/* Display a list of available units */
void display_units() {
    struct unit_node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data.name);
        current = current->next;
    }
}

int main() {
    add_unit("meter", 1.0);
    add_unit("centimeter", 0.01);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    
    printf("Available units:\n");
    display_units();
    
    printf("\nEnter the value to convert: ");
    double value;
    scanf("%lf", &value);
    
    printf("Enter the input unit: ");
    char from_name[MAX_UNIT_NAME_LENGTH];
    scanf("%s", from_name);
    struct unit* from = find_unit(from_name);
    if (from == NULL) {
        printf("Error: unit %s not found\n", from_name);
        return 1;
    }
    
    printf("Enter the output unit: ");
    char to_name[MAX_UNIT_NAME_LENGTH];
    scanf("%s", to_name);
    struct unit* to = find_unit(to_name);
    if (to == NULL) {
        printf("Error: unit %s not found\n", to_name);
        return 1;
    }
    
    convert(value, from, to);
    
    return 0;
}