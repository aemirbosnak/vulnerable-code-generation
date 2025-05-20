//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 50
#define MAX_NAME_LEN 30
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int num_contacts = 0;
Contact contact_list[MAX_LIST_SIZE];

void add_contact() {
    if (num_contacts >= MAX_LIST_SIZE) {
        printf("Error: Contact list is full\n");
        return;
    }

    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    strncpy(contact_list[num_contacts].name, name, strlen(name) - 1);

    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    strncpy(contact_list[num_contacts].email, email, strlen(email) - 1);

    num_contacts++;
}

void delete_contact() {
    if (num_contacts == 0) {
        printf("Error: Contact list is empty\n");
        return;
    }

    char name[MAX_NAME_LEN];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);

    int index = -1;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contact_list[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Contact not found\n");
        return;
    }

    for (int i = index; i < num_contacts - 1; i++) {
        strncpy(contact_list[i].name, contact_list[i+1].name, MAX_NAME_LEN);
        strncpy(contact_list[i].email, contact_list[i+1].email, MAX_EMAIL_LEN);
    }

    num_contacts--;
}

void print_list() {
    if (num_contacts == 0) {
        printf("Contact list is empty");
        return;
    }

    printf("Name\t\t\tEmail\n");
    printf("----\t\t\t-----\n");
    
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", contact_list[i].name, contact_list[i].email);
    }
}

void save_list() {
    if (num_contacts == 0) {
        printf("Contact list is empty");
        return;
    }

    FILE *fptr;

    fptr = fopen("contact_list.txt", "w");

    if (fptr == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    for (int i = 0; i < num_contacts; i++) {
        fprintf(fptr, "%s,%s\n", contact_list[i].name, contact_list[i].email);
    }

    fclose(fptr);
}

void load_list() {
    FILE *fptr;

    fptr = fopen("contact_list.txt", "r");

    if (fptr == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    char line[MAX_NAME_LEN + MAX_EMAIL_LEN + 1];
    char *name;
    char *email;

    while (fgets(line, MAX_NAME_LEN + MAX_EMAIL_LEN + 1, fptr)) {
        name = strtok(line, ",");
        email = strtok(NULL, ",");
        strncpy(contact_list[num_contacts].name, name, MAX_NAME_LEN);
        strncpy(contact_list[num_contacts].email, email, MAX_EMAIL_LEN);
        num_contacts++;
    }

    fclose(fptr);
}

int main() {
    int choice = 0;

    while (choice != 6) {
        printf("\n1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print list\n");
        printf("4. Save list\n");
        printf("5. Load list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                print_list();
                break;
            case 4:
                save_list();
                break;
            case 5:
                load_list();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}