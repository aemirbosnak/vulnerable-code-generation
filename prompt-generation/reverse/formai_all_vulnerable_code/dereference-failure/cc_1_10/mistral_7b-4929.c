//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10000

typedef struct HashNode {
    char *word;
    struct HashNode *next;
} HashNode;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void add_to_hash_table(HashNode **hash_table, char *word) {
    unsigned long index = hash(word);
    HashNode *new_node = malloc(sizeof(HashNode));

    new_node->word = strdup(word);
    new_node->next = (*hash_table);
    (*hash_table) = new_node;
}

int check_email_for_spam(char *email, HashNode **hash_table) {
    char words[10][50];
    int i, j, word_count = 0, found_spam = 0;
    char *token;

    strcpy(words[0], email);

    token = strtok(words[0], " ");
    while (token != NULL && word_count < 9) {
        strcpy(words[++word_count], token);
        token = strtok(NULL, " ");
    }

    for (i = 0; i < word_count; i++) {
        for (HashNode *node = hash_table[hash(words[i]) % TABLE_SIZE]; node != NULL; node = node->next) {
            if (strcasecmp(node->word, words[i]) == 0) {
                found_spam = 1;
                break;
            }
        }
    }

    return found_spam;
}

int main() {
    HashNode *hash_table[TABLE_SIZE];
    char *known_spam[] = {
        "buy now",
        "free offer",
        "click here",
        "earn money",
        "get rich quick",
        "lowest price",
        "urgent action required",
        "limited time offer",
        "money back guarantee",
        "act now"
    };

    for (int i = 0; i < 10; i++) {
        add_to_hash_table(hash_table, known_spam[i]);
    }

    char email[100] = "Get rich quick. Buy now. Click here. Urgent action required.";

    int spam = check_email_for_spam(email, hash_table);

    printf("Email is %sspam%s.\n", spam ? "" : "not ", "");

    return 0;
}