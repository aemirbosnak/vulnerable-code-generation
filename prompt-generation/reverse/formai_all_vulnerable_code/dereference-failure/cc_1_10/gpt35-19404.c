//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[15];
};

struct PhoneBook {
    int num_contacts;
    struct Contact contacts[MAX_CONTACTS];
};

void add_contact(struct PhoneBook *book, const char *name, const char *phone_number) {
    if (book->num_contacts >= MAX_CONTACTS) {
        printf("Sorry, phone book is full!\n");
        return;
    }
    struct Contact contact;
    strcpy(contact.name, name);
    strcpy(contact.phone_number, phone_number);
    book->contacts[book->num_contacts++] = contact;
    printf("Contact added successfully!\n");
}

void search_contact(const struct PhoneBook *book, const char *name) {
    int found_contact = 0;
    for (int i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            printf("%s | %s\n", book->contacts[i].name, book->contacts[i].phone_number);
            found_contact = 1;
        }
    }
    if (!found_contact) {
        printf("Contact not found!\n");
    }
}

void save_to_file(const struct PhoneBook *book, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < book->num_contacts; i++) {
        fprintf(file, "%s|%s\n", book->contacts[i].name, book->contacts[i].phone_number);
    }
    fclose(file);
    printf("Phone book successfully saved to file!\n");
}

void load_from_file(struct PhoneBook *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    char input[100];
    while (fgets(input, 100, file) != NULL) {
        char *name = strtok(input, "|");
        char *phone_number = strtok(NULL, "|");
        add_contact(book, name, phone_number);
    }
    fclose(file);
    printf("Phone book successfully loaded from file!\n");
}

void print_menu() {
    printf("\n");
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Save to file\n");
    printf("4. Load from file\n");
    printf("5. Exit\n");
}

int main() {
    struct PhoneBook book = { 0 };
    int quit = 0;
    while (!quit) {
        print_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter name and phone number separated by a space: ");
                char name[50];
                char phone_number[15];
                scanf("%s %s", name, phone_number);
                getchar();
                add_contact(&book, name, phone_number);
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                getchar();
                search_contact(&book, search_name);
                break;
            case 3:
                printf("Enter filename to save to: ");
                char save_filename[100];
                scanf("%s", save_filename);
                getchar();
                save_to_file(&book, save_filename);
                break;
            case 4:
                printf("Enter filename to load from: ");
                char load_filename[100];
                scanf("%s", load_filename);
                getchar();
                load_from_file(&book, load_filename);
                break;
            case 5:
                quit = 1;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}