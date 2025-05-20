//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook {
    char name[50];
    char phone_number[20];
    struct phonebook* next;
} PhoneBook;

PhoneBook* create_node(char name[], char phone_number[]) {
    PhoneBook* node = (PhoneBook*) malloc(sizeof(PhoneBook));
    strcpy(node->name, name);
    strcpy(node->phone_number, phone_number);
    node->next = NULL;
    return node;
}

PhoneBook* insert_node(PhoneBook* head, PhoneBook* new_node) {
    if (head == NULL) {
        return new_node;
    }
    if (strcmp(new_node->name, head->name) < 0) {
        new_node->next = head;
        return new_node;
    }
    head->next = insert_node(head->next, new_node);
    return head;
}

void print_phonebook(PhoneBook* head) {
    if (head == NULL) {
        printf("Empty phone book.\n");
        return;
    }
    printf("%-20s %s\n", "Name", "Phone Number");
    while (head != NULL) {
        printf("%-20s %s\n", head->name, head->phone_number);
        head = head->next;
    }
}

PhoneBook* search_node(PhoneBook* head, char name[]) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->name, name) == 0) {
        return head;
    }
    return search_node(head->next, name);
}

PhoneBook* remove_node(PhoneBook* head, char name[]) {
    if (head == NULL) {
        printf("Contact not found.\n");
        return head;
    }
    if (strcmp(head->name, name) == 0) {
        PhoneBook* temp = head;
        head = head->next;
        free(temp);
        printf("Contact %s removed.\n", name);
        return head;
    }
    head->next = remove_node(head->next, name);
    return head;
}

int main() {
    PhoneBook* head = NULL;
    int choice;
    do {
        printf("\n***** C Phone Book *****\n");
        printf("1. Add Contact\n");
        printf("2. Print Phone Book\n");
        printf("3. Search Contact\n");
        printf("4. Remove Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], phone_number[20];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                PhoneBook* new_node = create_node(name, phone_number);
                head = insert_node(head, new_node);
                break;
            }
            case 2: {
                print_phonebook(head);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter name: ");
                scanf("%s", name);
                PhoneBook* node = search_node(head, name);
                if (node == NULL) {
                    printf("Contact not found.\n");
                    break;
                }
                printf("%s's phone number is %s.\n", node->name, node->phone_number);
                break;
            }
            case 4: {
                char name[50];
                printf("Enter name: ");
                scanf("%s", name);
                head = remove_node(head, name);
                break;
            }
            case 5: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 5);
    return 0;
}