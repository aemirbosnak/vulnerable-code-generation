//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_CONTACTS 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct mailing_list {
    struct contact contacts[MAX_CONTACTS];
    int count;
};

void add_contact(struct mailing_list *list);
void print_contacts(struct mailing_list list);
void save_to_file(struct mailing_list list, char *filename);
struct mailing_list load_from_file(char *filename);

int main() {
    struct mailing_list list = {0};
    int choice;
    char filename[100];

    printf("Mailing List Manager\n");
    printf("====================\n");

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(&list);
            break;
        case 2:
            print_contacts(list);
            break;
        case 3:
            printf("Enter Filename: ");
            scanf("%s", filename);
            save_to_file(list, filename);
            break;
        case 4:
            printf("Enter Filename: ");
            scanf("%s", filename);
            list = load_from_file(filename);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

void add_contact(struct mailing_list *list) {
    struct contact new_contact;

    printf("Enter Name: ");
    scanf("%s", new_contact.name);

    printf("Enter Email: ");
    scanf("%s", new_contact.email);

    printf("Enter Phone: ");
    scanf("%s", new_contact.phone);

    list->contacts[list->count++] = new_contact;

    printf("Contact Added!\n");
}

void print_contacts(struct mailing_list list) {
    if (list.count == 0) {
        printf("No Contacts\n");
    } else {
        for (int i = 0; i < list.count; i++) {
            printf("%d. %s - %s - %s\n", i+1, list.contacts[i].name, list.contacts[i].email, list.contacts[i].phone);
        }
    }
}

void save_to_file(struct mailing_list list, char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Unable to Open %s\n", filename);
        return;
    }

    for (int i = 0; i < list.count; i++) {
        fprintf(file, "%s,%s,%s\n", list.contacts[i].name, list.contacts[i].email, list.contacts[i].phone);
    }

    fclose(file);

    printf("Mailing List Saved to %s\n", filename);
}

struct mailing_list load_from_file(char *filename) {
    struct mailing_list list = {0};
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to Open %s\n", filename);
        return list;
    }

    char buffer[200];
    char *name, *email, *phone;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        name = strtok(buffer, ",");
        email = strtok(NULL, ",");
        phone = strtok(NULL, ",");

        strcpy(list.contacts[list.count].name, name);
        strcpy(list.contacts[list.count].email, email);
        strcpy(list.contacts[list.count].phone, phone);

        list.count++;
    }

    fclose(file);

    printf("Mailing List Loaded from %s\n", filename);

    return list;
}