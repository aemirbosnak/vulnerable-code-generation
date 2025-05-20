//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A hash table for storing phone book entries.
struct hash_table {
    char *name;
    char *phone;
    struct hash_table *next;
};

int hash(const char *key) {
    return key[0] % 10;
}

int main(int argc, char **argv) {
    FILE *fp = fopen("phonebook.txt", "r");
    struct hash_table *head = NULL, *tail = NULL, *curr;

    if (fp == NULL) {
        fprintf(stderr, "Could not open file.\n");
        exit(1);
    }

    char buf[100], name[20], phone[20];
    char *c;

    while (fscanf(fp, "%s %s %s", buf, name, phone)!= EOF) {
        curr = (struct hash_table *)malloc(sizeof(struct hash_table));
        curr->name = strdup(name);
        curr->phone = strdup(phone);
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }

    fclose(fp);

    // Print all entries in the phone book
    printf("Phone Book:\n");
    curr = head;
    while (curr!= NULL) {
        printf("%s - %s\n", curr->name, curr->phone);
        curr = curr->next;
    }

    // Search for an entry in the phone book
    printf("\nEnter a name to search: ");
    fgets(buf, 100, stdin);
    c = strchr(buf, '\n');
    c[0] = '\0';

    curr = head;
    while (curr!= NULL && strcmp(curr->name, buf)) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("No such entry in the phone book.\n");
    } else {
        printf("%s - %s\n", curr->name, curr->phone);
    }

    printf("\n");
    return 0;
}