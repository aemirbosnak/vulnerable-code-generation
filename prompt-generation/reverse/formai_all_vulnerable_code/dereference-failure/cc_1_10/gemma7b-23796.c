//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    scanf("Enter name: ", newNode->name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    while (1) {
        char choice;

        printf("Enter choice: (I/P/Q) ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'I':
                InsertAtTail(head);
                break;
            case 'P':
                PrintList(head);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}