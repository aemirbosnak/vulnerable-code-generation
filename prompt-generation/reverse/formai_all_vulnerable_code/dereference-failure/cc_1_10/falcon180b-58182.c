//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* name;
    char* email;
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
} address_book;

void add_contact(address_book* book, char* name, char* email) {
    book->contacts = realloc(book->contacts, sizeof(contact) * ++book->num_contacts);
    book->contacts[book->num_contacts - 1].name = strdup(name);
    book->contacts[book->num_contacts - 1].email = strdup(email);
}

int main() {
    address_book book = {0};
    char input[1024];
    char* token;

    printf("Welcome to the medieval email client!\n");
    printf("Please enter your name: ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, "\n");
    strcpy(book.contacts[0].name, token);

    printf("Please enter your email address: ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, "\n");
    strcpy(book.contacts[0].email, token);

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add contact\n");
        printf("2. Send email\n");
        printf("3. Quit\n");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, "\n");

        switch (atoi(token)) {
            case 1:
                printf("Enter name of contact: ");
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                printf("Enter email of contact: ");
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                add_contact(&book, token, strtok(NULL, "\n"));
                printf("Contact added!\n");
                break;
            case 2:
                printf("Enter recipient's email: ");
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                printf("Enter subject: ");
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                printf("Enter message: ");
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                printf("Email sent to %s!\n", token);
                break;
            case 3:
                printf("Farewell, noble user!\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}