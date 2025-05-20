//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000

typedef struct {
    char username[100];
    char password[100];
    int length;
} Password;

int main() {
    FILE *fp;
    char line[1000];
    char *token;
    int count = 0;
    Password passwords[MAX_PASSWORDS];

    fp = fopen("passwords.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");

        strcpy(passwords[count].username, token);

        token = strtok(NULL, ":");
        strcpy(passwords[count].password, token);

        passwords[count].length = strlen(passwords[count].password);

        count++;
    }

    fclose(fp);

    int choice;
    char username[100];

    do {
        printf("Enter username: ");
        scanf("%s", username);

        int index = -1;

        for (int i = 0; i < count; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("User not found\n");
        } else {
            printf("Enter password: ");

            char password[100];
            scanf("%s", password);

            if (strcmp(passwords[index].password, password) == 0) {
                printf("Login successful\n");
            } else {
                printf("Incorrect password\n");
            }
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}