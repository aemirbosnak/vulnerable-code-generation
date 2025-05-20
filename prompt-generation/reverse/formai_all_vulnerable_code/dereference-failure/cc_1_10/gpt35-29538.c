//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password {
    char account[20];
    char username[20];
    char password[20];
    struct password *next;
} password_t;

password_t* head = NULL;

void create_password() {
    password_t *new_password = (password_t*) malloc(sizeof(password_t));

    printf("Enter account name: ");
    scanf("%s", new_password->account);

    printf("Enter username: ");
    scanf("%s", new_password->username);

    printf("Enter password: ");
    scanf("%s", new_password->password);

    new_password->next = head;
    head = new_password;
}

void view_passwords() {
    password_t *ptr = head;
    if (ptr == NULL) {
        printf("No passwords to show.\n");
        return;
    }
    printf("Account\tUsername\tPassword\n");
    while (ptr != NULL) {
        printf("%s\t%s\t%s\n", ptr->account, ptr->username, ptr->password);
        ptr = ptr->next;
    }
}

void delete_password() {
    char account[20];
    printf("Enter account name to delete: ");
    scanf("%s", account);

    password_t *current = head;
    password_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->account, account) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Password deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Password not found.\n");
}

void menu() {
    printf("1. Create password\n");
    printf("2. View passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Thank you for using this program!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;

}