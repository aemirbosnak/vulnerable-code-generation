//Gemma-7B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_password(Password *p) {
    p->name = malloc(20);
    p->password = malloc(20);
    p->used = 0;

    printf("Enter password name: ");
    scanf("%s", p->name);

    printf("Enter password: ");
    scanf("%s", p->password);
}

void list_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].used) {
            printf("%s: %s\n", passwords[i].name, passwords[i].password);
        }
    }
}

int main() {
    int choice;
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
        passwords[i].used = 0;
    }

    while (1) {
        printf("1. Generate Password\n");
        printf("2. List Passwords\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_password(passwords);
                break;
            case 2:
                list_passwords();
                break;
            default:
                exit(1);
        }
    }

    return 0;
}