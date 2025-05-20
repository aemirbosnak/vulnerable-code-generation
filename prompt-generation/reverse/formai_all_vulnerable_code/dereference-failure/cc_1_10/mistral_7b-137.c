//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 13

typedef struct {
    char email[50];
} Subscriber;

typedef struct HashNode {
    Subscriber data;
    struct HashNode *next;
} HashNode;

unsigned long hash(const char *str, unsigned long size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % size;
}

HashNode *create_node(Subscriber subscriber) {
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = subscriber;
    new_node->next = NULL;

    return new_node;
}

void add_subscriber(HashNode **table, Subscriber subscriber) {
    unsigned long index = hash(subscriber.email, TABLE_SIZE);

    if (table[index] == NULL) {
        table[index] = create_node(subscriber);
    } else {
        HashNode *current = table[index];

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = create_node(subscriber);
    }
}

void remove_subscriber(HashNode **table, const char *email) {
    unsigned long index = hash(email, TABLE_SIZE);
    HashNode *current = table[index];
    HashNode *previous = NULL;

    while (current != NULL && strcmp(current->data.email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found\n");
        return;
    }

    if (previous == NULL) {
        HashNode *temp = table[index];
        table[index] = current->next;
        free(temp);
    } else {
        previous->next = current->next;
    }

    free(current);
}

void display_subscribers(HashNode **table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] != NULL) {
            printf("Index %d:\n", i);
            HashNode *current = table[i];

            while (current != NULL) {
                printf("- %s\n", current->data.email);
                current = current->next;
            }
        }
    }
}

int main() {
    HashNode *subscribers_list[TABLE_SIZE] = {NULL};

    add_subscriber(subscribers_list, (Subscriber) {"john.doe@example.com"});
    add_subscriber(subscribers_list, (Subscriber) {"jane.doe@example.com"});
    add_subscriber(subscribers_list, (Subscriber) {"jim.brown@example.com"});

    printf("Initial list:\n");
    display_subscribers(subscribers_list);

    remove_subscriber(subscribers_list, "jane.doe@example.com");

    printf("\nList after removing 'jane.doe@example.com':\n");
    display_subscribers(subscribers_list);

    return 0;
}