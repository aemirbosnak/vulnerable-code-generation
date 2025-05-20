//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    char phone[16];
} Contact;

Contact *contacts;
int num_contacts;

void add_contact(char *name, char *phone) {
    if (num_contacts >= 100) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);
    num_contacts++;
}

void remove_contact(char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_contacts) {
        printf("Contact not found.\n");
        return;
    }
    for (; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    num_contacts--;
}

void find_contact(char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_contacts) {
        printf("Contact not found.\n");
        return;
    }
    printf("%s: %s\n", contacts[i].name, contacts[i].phone);
}

void list_contacts() {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    contacts = malloc(100 * sizeof(Contact));
    num_contacts = 0;
    while (1) {
        printf("(A)dd, (R)emove, (F)ind, (L)ist, (Q)uit: ");
        char cmd;
        scanf(" %c%*c", &cmd);
        char name[32], phone[16];
        switch (cmd) {
            case 'A':
                printf("Name: ");
                scanf("%s%*c", name);
                printf("Phone: ");
                scanf("%s%*c", phone);
                add_contact(name, phone);
                break;
            case 'R':
                printf("Name: ");
                scanf("%s%*c", name);
                remove_contact(name);
                break;
            case 'F':
                printf("Name: ");
                scanf("%s%*c", name);
                find_contact(name);
                break;
            case 'L':
                list_contacts();
                break;
            case 'Q':
                free(contacts);
                return 0;
        }
    }
    return 0;
}