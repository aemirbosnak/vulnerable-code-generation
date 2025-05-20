//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define DELAY 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void generate_list(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = rand() % MAX_SIZE;
        newNode->next = *head;
        *head = newNode;
    }
}

int main() {
    Node* head = NULL;
    generate_list(&head);

    printf("Welcome to the Mind-Bending Game!\n");
    printf("Enter 'q' to quit, or any number to interact with the list:\n");

    char input[10];
    scanf("%s", input);

    while (strcmp(input, "q") != 0) {
        int number = atoi(input);
        Node* current = head;

        while (current) {
            if (current->data == number) {
                printf("Found! Data: %d\n", current->data);
                break;
            } else if (current->next) {
                current = current->next;
            } else {
                printf("No such data found.\n");
                break;
            }
        }

        printf("Enter 'q' to quit, or any number to interact with the list:\n");
        scanf("%s", input);
    }

    printf("Thank you for playing. Goodbye.\n");
    return 0;
}