//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int coefficient, int exponent) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node into the linked list
void insert_node(struct Node** head, int coefficient, int exponent) {
    struct Node* new_node = create_node(coefficient, exponent);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display the polynomial linked list
void display_polynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials represented by linked lists
struct Node* add_polynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coefficient = 0;
        int exponent = 0;
        
        if (poly1 != NULL && (poly2 == NULL || poly1->exponent > poly2->exponent)) {
            coefficient = poly1->coefficient;
            exponent = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->exponent > poly1->exponent)) {
            coefficient = poly2->coefficient;
            exponent = poly2->exponent;
            poly2 = poly2->next;
        } else {
            coefficient = poly1->coefficient + poly2->coefficient;
            exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        insert_node(&result, coefficient, exponent);
    }
    return result;
}

// Function to free the linked list
void free_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* polynomial1 = NULL;
    struct Node* polynomial2 = NULL;

    insert_node(&polynomial1, 5, 3);
    insert_node(&polynomial1, 4, 2);
    insert_node(&polynomial1, 2, 0);

    insert_node(&polynomial2, 3, 4);
    insert_node(&polynomial2, 1, 2);
    insert_node(&polynomial2, 2, 1);

    printf("Polynomial 1: ");
    display_polynomial(polynomial1);
    
    printf("Polynomial 2: ");
    display_polynomial(polynomial2);
    
    struct Node* result = add_polynomials(polynomial1, polynomial2);
    printf("Result of Addition: ");
    display_polynomial(result);

    // Free allocated memory
    free_list(polynomial1);
    free_list(polynomial2);
    free_list(result);

    return 0;
}