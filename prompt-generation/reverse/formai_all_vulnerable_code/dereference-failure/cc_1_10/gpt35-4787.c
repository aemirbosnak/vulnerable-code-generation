//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 255
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact contacts[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("1. Add new contact\n");
    printf("2. Remove contact\n");
    printf("3. Edit contact\n");
    printf("4. View all contacts\n");
    printf("5. Save contacts to file\n");
    printf("6. Load contacts from file\n");
    printf("7. Exit\n");
}

void prompt_add_contact() {
    Contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(new_contact.email, MAX_EMAIL_LENGTH, stdin);
    printf("Enter phone: ");
    fgets(new_contact.phone, MAX_PHONE_LENGTH, stdin);

    contacts[num_entries] = new_contact;
    num_entries++;
}

void prompt_remove_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    int found_index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Contact not found.\n");
    } else {
        for (int i = found_index; i < num_entries - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        num_entries--;
        printf("Contact removed.\n");
    }
}

void prompt_edit_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to edit: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    int found_index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Contact not found.\n");
    } else {
        Contact updated_contact;
        printf("Enter new name (or press enter to keep old name): ");
        fgets(updated_contact.name, MAX_NAME_LENGTH, stdin);
        printf("Enter new email (or press enter to keep old email): ");
        fgets(updated_contact.email, MAX_EMAIL_LENGTH, stdin);
        printf("Enter new phone (or press enter to keep old phone): ");
        fgets(updated_contact.phone, MAX_PHONE_LENGTH, stdin);

        if (updated_contact.name[0] == '\n') {
            strcpy(updated_contact.name, contacts[found_index].name);
        }
        if (updated_contact.email[0] == '\n') {
            strcpy(updated_contact.email, contacts[found_index].email);
        }
        if (updated_contact.phone[0] == '\n') {
            strcpy(updated_contact.phone, contacts[found_index].phone);
        }

        contacts[found_index] = updated_contact;
        printf("Contact updated.\n");
    }
}

void view_all_contacts() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s", contacts[i].name);
        printf("Email: %s", contacts[i].email);
        printf("Phone: %s", contacts[i].phone);
        printf("\n");
    }
}

void save_contacts_to_file() {
    char filename[MAX_NAME_LENGTH];
    printf("Enter filename to save contacts to: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);

    FILE *file = fopen(filename, "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s,%s,%s", contacts[i].name, contacts[i].email, contacts[i].phone);
    }
    fclose(file);

    printf("Contacts saved to file.\n");
}

void load_contacts_from_file() {
    char filename[MAX_NAME_LENGTH];
    printf("Enter filename to load contacts from: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
    } else {
        char buffer[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2];
        while (fgets(buffer, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2, file)) {
            char *name = strtok(buffer, ",");
            char *email = strtok(NULL, ",");
            char *phone = strtok(NULL, ",");

            strcpy(contacts[num_entries].name, name);
            strcpy(contacts[num_entries].email, email);
            strcpy(contacts[num_entries].phone, phone);
            num_entries++;
        }
        fclose(file);
        printf("Contacts loaded from file.\n");
    }
}

int main() {
    int option = 0;
    while (option != 7) {
        print_menu();

        printf("Enter option: ");
        scanf("%d", &option);
        getchar(); // consume newline from scanf

        switch(option) {
            case 1:
                prompt_add_contact();
                break;
            case 2:
                prompt_remove_contact();
                break;
            case 3:
                prompt_edit_contact();
                break;
            case 4:
                view_all_contacts();
                break;
            case 5:
                save_contacts_to_file();
                break;
            case 6:
                load_contacts_from_file();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}