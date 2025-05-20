//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct Password {
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];
} Password;

void printPassword(Password *p) {
    printf("%s: %s\n", p->name, p->value);
}

void printPasswords(Password **passwords, int count) {
    printf("Passwords:\n");
    for (int i = 0; i < count; i++) {
        printPassword(passwords[i]);
    }
}

void addPassword(Password **passwords, int *count) {
    printf("Enter password name: ");
    char name[MAX_LENGTH];
    scanf("%s", name);

    printf("Enter password value: ");
    char value[MAX_LENGTH];
    scanf("%s", value);

    Password *newPass = malloc(sizeof(Password));
    strcpy(newPass->name, name);
    strcpy(newPass->value, value);

    passwords[*count] = newPass;
    (*count)++;
}

void removePassword(Password **passwords, int *count) {
    printf("Enter password name to remove: ");
    char name[MAX_LENGTH];
    scanf("%s", name);

    int indexToRemove = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Password not found.\n");
        return;
    }

    free(passwords[indexToRemove]);

    for (int i = indexToRemove; i < *count - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    (*count)--;
}

int main() {
    Password *passwords[MAX_LENGTH];
    int count = 0;

    while (1) {
        printf("\n1. Show passwords\n2. Add password\n3. Remove password\n4. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printPasswords(passwords, count);
                break;
            case 2:
                addPassword(passwords, &count);
                break;
            case 3:
                removePassword(passwords, &count);
                break;
            case 4:
                for (int i = 0; i < count; i++) {
                    free(passwords[i]);
                }
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}