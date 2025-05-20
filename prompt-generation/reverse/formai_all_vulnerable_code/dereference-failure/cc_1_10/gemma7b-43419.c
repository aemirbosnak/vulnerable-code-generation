//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10

typedef struct HashNode {
    char *password;
    struct HashNode *next;
} HashNode;

HashNode **hashTable = NULL;

void insertPassword(char *password) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->password = strdup(password);
    newNode->next = NULL;

    if (hashTable == NULL) {
        hashTable = newNode;
    } else {
        HashNode *tempNode = hashTable;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

int checkPasswordStrength(char *password) {
    int strength = 0;
    int minLength = 8;

    if (strlen(password) < minLength) {
        strength++;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            strength++;
        }
    }

    return strength;
}

int main() {
    char password[256];

    printf("Enter your password: ");
    scanf("%s", password);

    insertPassword(password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 0:
            printf("Password is strong.\n");
            break;
        case 1:
            printf("Password is weak, please change it.\n");
            break;
        case 2:
            printf("Password is very weak, please change it.\n");
            break;
    }

    return 0;
}