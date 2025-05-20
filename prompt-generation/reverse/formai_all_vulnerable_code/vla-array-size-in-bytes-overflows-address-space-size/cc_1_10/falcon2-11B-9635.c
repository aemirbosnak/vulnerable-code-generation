//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

int main() {
    int numContacts;
    char choice;

    printf("How many contacts do you want to add? ");
    scanf("%d", &numContacts);

    Contact contacts[numContacts];

    for (int i = 0; i < numContacts; i++) {
        printf("Enter contact name: ");
        fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
        contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;

        printf("Enter contact phone number: ");
        fgets(contacts[i].phone, sizeof(contacts[i].phone), stdin);
        contacts[i].phone[strcspn(contacts[i].phone, "\n")] = 0;
    }

    printf("\nPhone Book:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }

    printf("\nEnter your choice: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'a':
            for (int i = 0; i < numContacts; i++) {
                printf("Enter contact name: ");
                fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
                contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;

                printf("Enter contact phone number: ");
                fgets(contacts[i].phone, sizeof(contacts[i].phone), stdin);
                contacts[i].phone[strcspn(contacts[i].phone, "\n")] = 0;
            }
            break;

        case 'd':
            for (int i = 0; i < numContacts; i++) {
                printf("%s: %s\n", contacts[i].name, contacts[i].phone);
            }
            break;

        case 'q':
            exit(0);
    }

    return 0;
}