//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100
#define MAX_PHONE_SIZE 15

struct contact {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    char phone[MAX_PHONE_SIZE];
    struct contact *next;
};

struct list {
   struct contact *head;
   int count;
};

void print_menu();
void add_contact(struct list *mailing_list);
void delete_contact(struct list *mailing_list);
void search_contact(struct list *mailing_list);
void display_list(struct list *mailing_list);
void save_list(struct list *mailing_list);
void load_list(struct list *mailing_list);

int main() {
    struct list mailing_list = {NULL, 0};
    int choice;

    printf("Welcome to the Mailing List Manager\n\n");

    while (1) {
        print_menu();
        printf("Enter a choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                add_contact(&mailing_list);
                break;
            case 2:
                delete_contact(&mailing_list);
                break;
            case 3:
                search_contact(&mailing_list);
                break;
            case 4:
                display_list(&mailing_list);
                break;
            case 5:
                save_list(&mailing_list);
                break;
            case 6:
                load_list(&mailing_list);
                break;
            case 7:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("1. Add a contact\n");
    printf("2. Delete a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Display the entire list\n");
    printf("5. Save list to file\n");
    printf("6. Load list from file\n");
    printf("7. Exit\n");
}

void add_contact(struct list *mailing_list) {
    char name[MAX_NAME_SIZE], email[MAX_EMAIL_SIZE], phone[MAX_PHONE_SIZE];
    struct contact *new_contact = (struct contact*) malloc(sizeof(struct contact));

    printf("Enter the new contact's name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the new contact's email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter the new contact's phone number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    strncpy(new_contact->name, name, sizeof(new_contact->name));
    strncpy(new_contact->email, email, sizeof(new_contact->email));
    strncpy(new_contact->phone, phone, sizeof(new_contact->phone));
    new_contact->next = NULL;

    if (mailing_list->head == NULL) {
        mailing_list->head = new_contact;
    } else {
        struct contact *current_contact = mailing_list->head;
        while (current_contact->next != NULL) {
            current_contact = current_contact->next;
        }
        current_contact->next = new_contact;
    }

    mailing_list->count++;
    printf("%s has been added to the mailing list.\n", name);
}

void delete_contact(struct list *mailing_list) {
    char name[MAX_NAME_SIZE];
    struct contact *current_contact = mailing_list->head;
    struct contact *previous_contact = current_contact;

    printf("Enter the name of the contact to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (current_contact != NULL) {
        if (strcasecmp(current_contact->name, name) == 0) {
            if (current_contact == mailing_list->head) {
                mailing_list->head = current_contact->next;
            } else {
                previous_contact->next = current_contact->next;
            }
            free(current_contact);
            mailing_list->count--;
            printf("%s has been deleted from the mailing list.\n", name);
            return;
        }
        previous_contact = current_contact;
        current_contact = current_contact->next;
    }

    printf("%s was not found in the mailing list.\n", name);
}

void search_contact(struct list *mailing_list) {
    char name[MAX_NAME_SIZE];
    struct contact *current_contact = mailing_list->head;

    printf("Enter the name of the contact to search for: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (current_contact != NULL) {
        if (strcasestr(current_contact->name, name) != NULL) {
            printf("%s\nEmail: %s\nPhone: %s\n\n", current_contact->name, current_contact->email, current_contact->phone);
            return;
        }
        current_contact = current_contact->next;
    }

    printf("%s was not found in the mailing list.\n", name);
}

void display_list(struct list *mailing_list) {
    struct contact *current_contact = mailing_list->head;

    if (current_contact == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Mailing List:\n\n");

    while (current_contact != NULL) {
        printf("%s\nEmail: %s\nPhone: %s\n\n", current_contact->name, current_contact->email, current_contact->phone);
        current_contact = current_contact->next;
    }
}

void save_list(struct list *mailing_list) {
    char filename[100];
    FILE *f = NULL;

    printf("Enter filename to save: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((f = fopen(filename, "w")) == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct contact *current_contact = mailing_list->head;

    while (current_contact != NULL) {
        fprintf(f, "%s,%s,%s\n", current_contact->name, current_contact->email, current_contact->phone);
        current_contact = current_contact->next;
    }

    fclose(f);
}

void load_list(struct list *mailing_list) {
    char filename[100];
    FILE *f = NULL;

    printf("Enter filename to load: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((f = fopen(filename, "r")) == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char buf[256], *str;
    struct contact new_contact;
    memset(&new_contact, 0, sizeof(new_contact));

    while (fgets(buf, sizeof(buf), f) != NULL) {
        str = strtok(buf, ",\n");
        if (str != NULL) strncpy(new_contact.name, str, sizeof(new_contact.name));

        str = strtok(NULL, ",\n");
        if (str != NULL) strncpy(new_contact.email, str, sizeof(new_contact.email));

        str = strtok(NULL, ",\n");
        if (str != NULL) strncpy(new_contact.phone, str, sizeof(new_contact.phone));

        add_contact(mailing_list);

        memset(&new_contact, 0, sizeof(new_contact));
    }

    fclose(f);
}