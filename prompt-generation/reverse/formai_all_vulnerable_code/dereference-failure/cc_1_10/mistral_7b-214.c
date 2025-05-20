//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define MAX_CHAR 256

typedef struct {
    char name[MAX_CHAR];
    int value;
    struct element *next;
} element;

element *head = NULL;

void add_element(char *name, int value) {
    element *new_element = (element *) malloc(sizeof(element));
    strcpy(new_element->name, name);
    new_element->value = value;
    new_element->next = head;
    head = new_element;
}

void print_list() {
    element *current = head;
    printf("Surrealist Art Piece:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->value);
        current = current->next;
    }
}

void generate_element() {
    char name[MAX_CHAR];
    int value;
    int random_char, random_digit;

    printf("Enter a name for your new element (up to %d characters): ", MAX_CHAR);
    scanf("%s", name);

    name[strcspn(name, "\n")] = '\0'; // remove newline character

    value = rand() % 100 + 1; // generate random value between 1 and 100

    add_element(name, value);
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int choice;

    printf("Welcome to the Surrealist Art Piece Creator!\n");
    printf("Choose an action:\n1. Generate a new element\n2. Print the current art piece\n3. Quit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_element();
                break;
            case 2:
                print_list();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}