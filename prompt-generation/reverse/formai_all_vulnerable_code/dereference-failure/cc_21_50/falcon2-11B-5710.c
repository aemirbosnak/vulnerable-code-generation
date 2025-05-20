//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MAILBOX 10

typedef struct {
    char name[50];
    char password[50];
} Mailbox;

int main() {
    Mailbox mailboxes[MAX_MAILBOX] = {
        {"user1", "password1"},
        {"user2", "password2"},
        {"user3", "password3"},
        {"user4", "password4"},
        {"user5", "password5"},
        {"user6", "password6"},
        {"user7", "password7"},
        {"user8", "password8"},
        {"user9", "password9"},
        {"user10", "password10"}
    };

    int i, j;

    printf("SMTP Client\n");
    printf("------------------------------\n");

    printf("Enter the username: ");
    scanf("%s", mailboxes[i].name);

    printf("Enter the password: ");
    scanf("%s", mailboxes[i].password);

    printf("\nAuthenticating...\n");

    if (strcmp(mailboxes[i].name, "user1") == 0 && strcmp(mailboxes[i].password, "password1") == 0) {
        printf("Welcome, user1!\n");
    }
    else if (strcmp(mailboxes[i].name, "user2") == 0 && strcmp(mailboxes[i].password, "password2") == 0) {
        printf("Welcome, user2!\n");
    }
    else if (strcmp(mailboxes[i].name, "user3") == 0 && strcmp(mailboxes[i].password, "password3") == 0) {
        printf("Welcome, user3!\n");
    }
    else if (strcmp(mailboxes[i].name, "user4") == 0 && strcmp(mailboxes[i].password, "password4") == 0) {
        printf("Welcome, user4!\n");
    }
    else if (strcmp(mailboxes[i].name, "user5") == 0 && strcmp(mailboxes[i].password, "password5") == 0) {
        printf("Welcome, user5!\n");
    }
    else if (strcmp(mailboxes[i].name, "user6") == 0 && strcmp(mailboxes[i].password, "password6") == 0) {
        printf("Welcome, user6!\n");
    }
    else if (strcmp(mailboxes[i].name, "user7") == 0 && strcmp(mailboxes[i].password, "password7") == 0) {
        printf("Welcome, user7!\n");
    }
    else if (strcmp(mailboxes[i].name, "user8") == 0 && strcmp(mailboxes[i].password, "password8") == 0) {
        printf("Welcome, user8!\n");
    }
    else if (strcmp(mailboxes[i].name, "user9") == 0 && strcmp(mailboxes[i].password, "password9") == 0) {
        printf("Welcome, user9!\n");
    }
    else if (strcmp(mailboxes[i].name, "user10") == 0 && strcmp(mailboxes[i].password, "password10") == 0) {
        printf("Welcome, user10!\n");
    }
    else {
        printf("Invalid username or password\n");
    }

    return 0;
}