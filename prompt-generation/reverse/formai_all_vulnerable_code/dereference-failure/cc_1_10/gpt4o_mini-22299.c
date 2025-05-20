//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int coefficient; // Coefficient of the term
    int exponent;    // Exponent of the term
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
void insertTerm(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    
    // Special case for the head  
    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->exponent > exponent) {
            current = current->next;
        }
        if (current->next != NULL && current->next->exponent == exponent) {
            current->next->coefficient += coefficient; // Combine coefficients
            free(newNode); // Free the new node if we combine terms
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to print the polynomial linked list
void printPolynomial(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("0\n");
        return;
    }

    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials represented by linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coefficient = 0;
        int exponent;

        // If both polynomials are not finished
        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exponent == poly2->exponent) {
                coefficient = poly1->coefficient + poly2->coefficient;
                exponent = poly1->exponent;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->exponent > poly2->exponent) {
                coefficient = poly1->coefficient;
                exponent = poly1->exponent;
                poly1 = poly1->next;
            } else {
                coefficient = poly2->coefficient;
                exponent = poly2->exponent;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            coefficient = poly1->coefficient;
            exponent = poly1->exponent;
            poly1 = poly1->next;
        } else {
            coefficient = poly2->coefficient;
            exponent = poly2->exponent;
            poly2 = poly2->next;
        }

        // Insert the term into the result polynomial
        if (coefficient != 0) {
            insertTerm(&result, coefficient, exponent);
        }
    }

    return result;
}

// Function to free the linked list
void freePolynomial(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function to demonstrate polynomial operations
int main() {
    struct Node* polynomial1 = NULL;
    struct Node* polynomial2 = NULL;

    // Insert terms into the first polynomial: 3x^4 + 2x^2 + 5
    insertTerm(&polynomial1, 3, 4);
    insertTerm(&polynomial1, 2, 2);
    insertTerm(&polynomial1, 5, 0);
    
    // Insert terms into the second polynomial: 4x^3 + 2x^2 + 3
    insertTerm(&polynomial2, 4, 3);
    insertTerm(&polynomial2, 2, 2);
    insertTerm(&polynomial2, 3, 0);
    
    // Display polynomials
    printf("Polynomial 1: ");
    printPolynomial(polynomial1);
    
    printf("Polynomial 2: ");
    printPolynomial(polynomial2);
    
    // Add polynomials
    struct Node* result = addPolynomials(polynomial1, polynomial2);
    
    // Display the result
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    
    // Free memory
    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(result);
    
    return 0;
}