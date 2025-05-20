//FormAI DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100        // Maximum passwords that can be stored
#define MAX_PASSWORD_LENGTH 50   // Maximum length of a password

struct node {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct node* next;
};

int count = 0;
struct node* head = NULL;

// Function declarations
void addPassword();
void printPasswords();
void searchPassword();
void deletePassword();

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n\n");
        printf("C Password Manager by Ken Thompson\n");
        printf("=================================\n");
        printf("1. Add a password\n");
        printf("2. Print all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            printPasswords();
            break;
        case 3:
            searchPassword();
            break;
        case 4:
            deletePassword();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a password to the linked list
void addPassword() {
    if (count >= MAX_PASSWORDS) {
        printf("Maximum passwords reached. Delete some passwords to add more.\n");
        return;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter website: ");
    scanf("%s", temp->website);
    printf("Enter username: ");
    scanf("%s", temp->username);

    // Encrypting password using XOR encryption
    char key[] = "passwordkey";
    printf("Enter password: ");
    scanf("%s", temp->password);
    for (int i = 0; i < strlen(temp->password); i++) {
        temp->password[i] = temp->password[i] ^ key[i % strlen(key)];
    }

    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    count++;
    printf("\nPassword added successfully!\n");
}

// Function to print all passwords in the linked list
void printPasswords() {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }

    struct node* ptr = head;

    printf("\n%-20s%-20s%-20s\n", "Website", "Username", "Password");
    while (ptr != NULL) {
        printf("%-20s%-20s", ptr->website, ptr->username);

        // Decrypting password using XOR encryption
        char key[] = "passwordkey";
        char decryptedPassword[MAX_PASSWORD_LENGTH];
        for (int i = 0; i < strlen(ptr->password); i++) {
            decryptedPassword[i] = ptr->password[i] ^ key[i % strlen(key)];
        }
        printf("%-20s\n", decryptedPassword);

        ptr = ptr->next;
    }
}

// Function to search for a password in the linked list
void searchPassword() {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }

    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter website to search for: ");
    scanf("%s", website);

    struct node* ptr = head;
    int found = 0;

    while (ptr != NULL) {
        if (strcmp(ptr->website, website) == 0) {
            found = 1;
            printf("\n%-20s%-20s", "Website", "Username");

            // Decrypting password using XOR encryption
            char key[] = "passwordkey";
            char decryptedPassword[MAX_PASSWORD_LENGTH];
            for (int i = 0; i < strlen(ptr->password); i++) {
                decryptedPassword[i] = ptr->password[i] ^ key[i % strlen(key)];
            }
            printf("%-20s\n", decryptedPassword);
        }

        ptr = ptr->next;
    }

    if (!found) {
        printf("\nPassword not found for website '%s'.\n", website);
    }
}

// Function to delete a password from the linked list
void deletePassword() {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }

    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter website to delete password for: ");
    scanf("%s", website);

    struct node* temp = head;
    struct node* prev = NULL;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->website, website) == 0) {
            found = 1;

            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            count--;
            printf("\nPassword deleted successfully!\n");
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("\nPassword not found for website '%s'.\n", website);
    }
}