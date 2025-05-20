//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[20];
    int balance;
    struct account *next;
};

struct account *head = NULL;

void add_account(char name[], int balance) {
    struct account *new_account = malloc(sizeof(struct account));
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = NULL;

    if (head == NULL) {
        head = new_account;
    } else {
        struct account *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_account;
    }
}

void display_accounts() {
    struct account *current = head;
    printf("Accounts:\n");
    while (current!= NULL) {
        printf("%s - %d\n", current->name, current->balance);
        current = current->next;
    }
}

int main() {
    char name1[] = "John Doe";
    int balance1 = 1000;
    add_account(name1, balance1);

    char name2[] = "Jane Doe";
    int balance2 = 500;
    add_account(name2, balance2);

    display_accounts();

    return 0;
}