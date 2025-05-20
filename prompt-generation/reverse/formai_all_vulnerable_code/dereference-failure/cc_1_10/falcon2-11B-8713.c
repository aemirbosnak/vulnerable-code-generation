//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
} User;

typedef struct {
    int count;
    User *users;
} MailingList;

MailingList createMailingList(int size) {
    MailingList list;
    list.count = 0;
    list.users = malloc(size * sizeof(User));
    return list;
}

void addUser(MailingList *list, User *user) {
    if (list->count >= list->users) {
        printf("Mailing list is full!\n");
        return;
    }

    list->users[list->count] = *user;
    list->count++;
}

void displayMailingList(MailingList list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list.count; i++) {
        printf("User %d: %s - %s - %s - %s\n", i + 1, list.users[i].name, list.users[i].email, list.users[i].phone, list.users[i].address);
    }
}

int main() {
    MailingList list = createMailingList(5);

    User user1 = {"John Doe", "johndoe@example.com", "1234567890", "123 Main St"};
    User user2 = {"Jane Smith", "janesmith@example.com", "0987654321", "456 Elm St"};
    User user3 = {"Bob Johnson", "bobjohnson@example.com", "5555555555", "789 Oak St"};

    addUser(&list, &user1);
    addUser(&list, &user2);
    addUser(&list, &user3);

    displayMailingList(list);

    return 0;
}