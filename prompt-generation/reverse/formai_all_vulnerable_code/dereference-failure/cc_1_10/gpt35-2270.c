//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} node;

node* head = NULL;
node* tail = NULL;

void addEmail() {
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter email: ");
    scanf("%s", temp->email);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }

    printf("Email added successfully!\n");
}

void viewList() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        node* temp = head;
        printf("Emails in the list:\n");
        while (temp != NULL) {
            printf("%s\n", temp->email);
            temp = temp->next;
        }
    }
}

void deleteEmail() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        char email[50];
        printf("Enter email to delete: ");
        scanf("%s", email);

        node* temp = head;
        node* prev = NULL;
        int found = 0;

        while (temp != NULL) {
            if (strcmp(temp->email, email) == 0) {
                found = 1;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!found) {
            printf("Email not found!\n");
        } else {
            if (temp == head) {
                head = head->next;
            } else if (temp == tail) {
                tail = prev;
            }
            
            if (prev != NULL) {
                prev->next = temp->next;
            }
            free(temp);
            printf("Email deleted successfully!\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add email\n2. View list\n3. Delete email\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                viewList();
                break;
            case 3:
                deleteEmail();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again\n");
                break;
        }
    } while (choice != 4);

    return 0;
}