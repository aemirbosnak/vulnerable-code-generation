//FormAI DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Creating a retro-style data structure visualization using ASCII art
    printf("                 _______                        \n");
    printf("               /         \\                      \n");
    printf("      _______/           \\________             \n");
    printf("     /                            \\            \n");
    printf("    /                              \\           \n");
    printf("   /                                \\          \n");
    printf("  /                                  \\         \n");
    printf(" /                                    \\        \n");
    printf(" \\                                    /        \n");
    printf("  \\                                  /         \n");
    printf("   \\                                /          \n");
    printf("    \\                              /           \n");
    printf("     \\__________________________/            \n");
    printf("\n");

    // Creating a linked list using C data structures
    typedef struct Node {
        int data;
        struct Node* next;
    } Node;

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Traversing the linked list
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}