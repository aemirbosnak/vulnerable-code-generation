//FormAI DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} Node;

Node* create_node(char* name, char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    memcpy(new_node->name, name, strlen(name) + 1);
    memcpy(new_node->email, email, strlen(email) + 1);
    new_node->next = NULL;
    return new_node;
}

int add_node(Node** head, char* name, char* email) {
    Node* new_node = create_node(name, email);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    return 1;
}

int remove_node(Node** head, int index) {
    if (*head == NULL) {
        return 0;
    }
    Node* cur = *head;
    Node* prev = NULL;
    int i = 0;
    while (cur != NULL && i < index) {
        prev = cur;
        cur = cur->next;
        i++;
    }
    if (cur == NULL) {
        return 0;
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
    return 1;
}

Node* search_node(Node* head, char* name) {
    Node* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int print_list(Node* head) {
    Node* cur = head;
    int i = 1;
    while (cur != NULL) {
        printf("%d. %s <%s>\n", i, cur->name, cur->email);
        cur = cur->next;
        i++;
    }
    return i - 1;
}

void clear_list(Node** head) {
    Node* cur = *head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;
    int choice = 0, index = 0;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH], search_name[MAX_NAME_LENGTH];
    do {
        printf("\n\n--- Mailing List Manager ---\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Search Contact\n");
        printf("4. Print List\n");
        printf("5. Clear List\n");
        printf("6. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                printf("\nEnter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter Email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                if (add_node(&head, name, email)) {
                    printf("\nContact Added!\n");
                } else {
                    printf("\nFailed to add contact\n");
                }
                break;
            case 2:
                printf("\nEnter index of contact to remove: ");
                scanf("%d", &index);
                if (remove_node(&head, index - 1)) {
                    printf("\nContact Removed!\n");
                } else {
                    printf("\nFailed to remove contact\n");
                }
                break;
            case 3:
                printf("\nEnter name to search: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = 0;
                Node* search_result = search_node(head, search_name);
                if (search_result) {
                    printf("\nContact Found: %s <%s>\n", search_result->name, search_result->email);
                } else {
                    printf("\nCould not find contact\n");
                }
                break;
            case 4:
                printf("\n--- Contact List ---\n");
                int count = print_list(head);
                if (count == 0) {
                    printf("Your list is empty\n");
                }
                break;
            case 5:
                clear_list(&head);
                printf("\nContact List Cleared!\n");
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again\n");
        }
        printf("\nPress enter to continue...");
        getchar();
    } while (choice != 6);
    return 0;
}