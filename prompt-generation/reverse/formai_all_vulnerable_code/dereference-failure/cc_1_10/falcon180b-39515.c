//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000

typedef struct {
    char *username;
    char *password;
    char *website;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char *username = (char *) malloc(100);
    char *password = (char *) malloc(100);
    char *website = (char *) malloc(100);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter website: ");
    scanf("%s", website);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].website, website);

    num_passwords++;
}

void delete_password() {
    int i;
    char *username = (char *) malloc(100);

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            free(passwords[i].website);
            memmove(&passwords[i], &passwords[i + 1], sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    int i;

    printf("Username\tPassword\tWebsite\n");

    for (i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].username, passwords[i].password, passwords[i].website);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            delete_password();
            break;
        case 3:
            print_passwords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}