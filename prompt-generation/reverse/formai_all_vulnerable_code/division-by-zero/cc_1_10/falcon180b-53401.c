//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 64
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact contacts[100];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter email: ");
    scanf("%s", contacts[num_contacts].email);

    num_contacts++;
}

void print_contacts() {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }
}

void send_mail(char* name, char* email) {
    printf("Sending email to %s (%s)...\n", name, email);
}

void main() {
    srand(time(NULL));
    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\n1. Add contact\n2. Print contacts\n3. Send email\n4. Exit\n");
        int choice = rand() % 4;

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                printf("Enter name of contact to send email to: ");
                scanf("%s", contacts[rand() % num_contacts].name);
                send_mail(contacts[rand() % num_contacts].name, contacts[rand() % num_contacts].email);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}