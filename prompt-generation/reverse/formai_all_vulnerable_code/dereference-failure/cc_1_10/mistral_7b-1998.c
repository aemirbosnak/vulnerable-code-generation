//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    struct WordNode *next;
} WordNode;

typedef struct Bucket {
    WordNode *head;
} Bucket;

Bucket *buckets;
int num_words;

void add_word(char *word) {
    int index = toupper(*word) - 'A';
    WordNode *new_node = malloc(sizeof(WordNode));
    strcpy(new_node->word, word);
    new_node->next = buckets[index].head;
    buckets[index].head = new_node;
    num_words++;
}

void check_spell(char *word) {
    int index = toupper(*word) - 'A';
    WordNode *current = buckets[index].head;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            printf("Word '%s' is spelled correctly.\n", word);
            return;
        }
        current = current->next;
    }
    printf("Word '%s' is not spelled correctly.\n", word);
}

int main() {
    int i;
    char *words[10] = {
        "survival",
        "post-apocalyptic",
        "radiation",
        "mutant",
        "scavenger",
        "ruins",
        "desolate",
        "irradiated",
        "fallout",
        "wasteland"
    };

    buckets = calloc(NUM_BUCKETS, sizeof(Bucket));

    for (i = 0; i < 10; i++) {
        add_word(words[i]);
    }

    char user_input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to check: ");
        scanf("%s", user_input);
        check_spell(user_input);
    }

    for (i = 0; i < NUM_BUCKETS; i++) {
        WordNode *current = buckets[i].head;
        while (current != NULL) {
            free(current);
            current = current->next;
        }
        buckets[i].head = NULL;
    }
    free(buckets);

    return 0;
}