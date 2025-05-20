//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int coefficient, int exponent);
void insert(Node** head, int coefficient, int exponent);
void display(Node* head);
Node* addPolynomials(Node* p1, Node* p2);
void freeList(Node* head);

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    
    // Polynomial 1: 3x^2 + 5x + 2
    insert(&poly1, 3, 2);
    insert(&poly1, 5, 1);
    insert(&poly1, 2, 0);
    
    // Polynomial 2: 4x^3 + 2x^2 + 3x + 1
    insert(&poly2, 4, 3);
    insert(&poly2, 2, 2);
    insert(&poly2, 3, 1);
    insert(&poly2, 1, 0);
    
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    
    // Adding the two polynomials
    Node* result = addPolynomials(poly1, poly2);
    
    printf("Resultant Polynomial after Addition: ");
    display(result);
    
    // Free the allocated memory
    freeList(poly1);
    freeList(poly2);
    freeList(result);
    
    return 0;
}

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial linked list
void insert(Node** head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (!(*head) || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next && current->next->exponent > exponent) {
            current = current->next;
        }
        if (current->exponent == exponent) {
            current->coefficient += coefficient; // Combine coefficients if exponents are the same
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to display the polynomial
void display(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    
    Node* current = head;
    while (current) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials represented by linked lists
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    
    while (p1 || p2) {
        int coefficient = 0;
        int exponent = 0;

        if (p1 && (!p2 || p1->exponent > p2->exponent)) {
            coefficient = p1->coefficient;
            exponent = p1->exponent;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->exponent > p1->exponent)) {
            coefficient = p2->coefficient;
            exponent = p2->exponent;
            p2 = p2->next;
        } else { // p1->exponent == p2->exponent
            coefficient = p1->coefficient + p2->coefficient;
            exponent = p1->exponent;
            p1 = p1->next;
            p2 = p2->next;
        }

        insert(&result, coefficient, exponent);
    }
    
    return result;
}

// Function to free the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}