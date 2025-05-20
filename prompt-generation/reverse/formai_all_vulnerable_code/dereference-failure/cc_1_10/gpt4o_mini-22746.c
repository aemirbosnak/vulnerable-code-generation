//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the polynomial linked list.
struct PolyNode {
    int coefficient;      // Coefficient of the term
    int exponent;        // Exponent of the term
    struct PolyNode* next; // Pointer to the next term
};

// Function to create a new polynomial node.
struct PolyNode* createPolyNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in the polynomial linked list.
void insertTerm(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createPolyNode(coeff, exp);
    if (*head == NULL || (*head)->exponent < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct PolyNode* current = *head;
        while (current->next != NULL && current->next->exponent > exp) {
            current = current->next;
        }
        if (current->exponent == exp) {
            current->coefficient += coeff; // Combine like terms
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to delete a term from the polynomial linked list.
void deleteTerm(struct PolyNode** head, int exp) {
    struct PolyNode* current = *head;
    struct PolyNode* previous = NULL;

    while (current != NULL && current->exponent != exp) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to evaluate the polynomial for a given value of x.
int evaluatePolynomial(struct PolyNode* head, int x) {
    int result = 0;
    struct PolyNode* current = head;
    while (current != NULL) {
        result += current->coefficient * (int)pow(x, current->exponent);
        current = current->next;
    }
    return result;
}

// Function to print the polynomial in human-readable form.
void printPolynomial(struct PolyNode* head) {
    struct PolyNode* current = head;
    while (current != NULL) {
        if (current != head && current->coefficient > 0) {
            printf(" + ");
        }
        if (current->coefficient != 1 || current->exponent == 0) {
            printf("%d", current->coefficient);
        }
        if (current->exponent > 0) {
            printf("x");
            if (current->exponent > 1) {
                printf("^%d", current->exponent);
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the polynomial linked list operations.
int main() {
    struct PolyNode* poly = NULL;

    // Inserting terms into the polynomial: 3x^2 + 2x^1 + 1
    insertTerm(&poly, 3, 2);
    insertTerm(&poly, 2, 1);
    insertTerm(&poly, 1, 0);

    // Print the polynomial
    printf("Polynomial: ");
    printPolynomial(poly);

    // Evaluate the polynomial at x = 2
    int x = 2;
    int result = evaluatePolynomial(poly, x);
    printf("The polynomial evaluated at x = %d is: %d\n", x, result);

    // Deleting term x^1 (2x^1)
    deleteTerm(&poly, 1);
    printf("After deleting 2x^1, the polynomial: ");
    printPolynomial(poly);

    // Freeing the allocated memory
    struct PolyNode* current = poly;
    while (current != NULL) {
        struct PolyNode* toDelete = current;
        current = current->next;
        free(toDelete);
    }

    return 0;
}