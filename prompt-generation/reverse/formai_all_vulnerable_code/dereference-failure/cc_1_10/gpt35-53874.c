//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[100];
    char author[100];
    int pages;
};

struct node {
    struct book data;
    struct node *next;
};

typedef struct node NODE;
typedef NODE *PNODE;

PNODE push(PNODE top, struct book b) {
    PNODE new_node = (PNODE) malloc(sizeof(NODE));
    new_node->data = b;
    new_node->next = top;
    top = new_node;
    return top;
}

PNODE pop(PNODE top) {
    if(top == NULL) {
        printf("The stack is empty");
        return top;
    }
    printf("%s by %s has been removed from the stack", top->data.title, top->data.author);
    PNODE temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(PNODE top) {
    if(top == NULL) {
        printf("The stack is empty");
        return;
    }
    PNODE current = top;
    while(current != NULL) {
        printf("%s by %s | Pages: %d\n", current->data.title, current->data.author, current->data.pages);
        current = current->next;
    }
}

int main() {
    PNODE top = NULL;
    int choice;
    while(1) {
        printf("\n1. Add book to stack\n2. Remove book from stack\n3. Display stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            {
                struct book b;
                printf("Enter the book title: ");
                scanf("%s", b.title);
                printf("Enter the book author: ");
                scanf("%s", b.author);
                printf("Enter the number of pages: ");
                scanf("%d", &b.pages);
                top = push(top, b);
                break;
            }
            case 2:
            {
                top = pop(top);
                break;
            }
            case 3:
            {
                display(top);
                break;
            }
            case 4:
            {
                printf("Exiting the program");
                exit(0);
            }
            default:
            {
                printf("Please enter a valid choice");
            }
        }
    }
    return 0;
}