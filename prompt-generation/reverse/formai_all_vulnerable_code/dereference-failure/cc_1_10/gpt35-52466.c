//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 15
#define HASH_TABLE_SIZE 100

struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    struct Contact *next;
};

struct HashTable {
    struct Contact *table[HASH_TABLE_SIZE];
};

unsigned int hashString(char *str) {
    unsigned int hash = 5381;

    while (*str) {
        hash = ((hash << 5) + hash) + (*str++);
    }

    return hash % HASH_TABLE_SIZE;
}

void insertContact(struct HashTable *ht, struct Contact *ct) {
    unsigned int hash = hashString(ct->name);
    ct->next = ht->table[hash];
    ht->table[hash] = ct;
}

struct Contact *findContact(struct HashTable *ht, char *name) {
    unsigned int hash = hashString(name);
    struct Contact *ct = ht->table[hash];

    while (ct) {
        if (strcmp(ct->name, name) == 0) {
            return ct;
        }
        ct = ct->next;
    }

    return NULL;
}

void displayContacts(struct HashTable *ht) {
    printf("\n--------------------------------------\n");
    printf("               CONTACTS                \n");
    printf("--------------------------------------\n\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct Contact *ct = ht->table[i];

        while (ct) {
            printf("Name: %s\nPhone: %s\n\n", ct->name, ct->phone);
            ct = ct->next;
        }
    }
}

int main() {
    struct HashTable ht = {0};
    char option;

    do {
        printf("\n1) Add contact\n2) Search contact\n3) Display contacts\n4) Quit\n\nEnter option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1': {
                struct Contact *ct = (struct Contact*) malloc(sizeof(struct Contact));
                printf("\nEnter name: ");
                scanf("%s", ct->name);
                printf("Enter phone: ");
                scanf("%s", ct->phone);

                insertContact(&ht, ct);
                printf("\nContact added successfully!\n");

                break;
            }
            case '2': {
                char name[MAX_NAME_LEN];
                printf("\nEnter name to search: ");
                scanf("%s", name);

                struct Contact *ct = findContact(&ht, name);

                if (ct) {
                    printf("Name: %s\nPhone: %s\n", ct->name, ct->phone);
                } else {
                    printf("\nContact not found.\n");
                }

                break;
            }
            case '3': {
                displayContacts(&ht);
                break;
            }
            case '4': {
                return 0;
            }
            default: {
                printf("\nInvalid option. Please try again.\n");
            }
        }
    } while (option != '4');

    return 0;
}