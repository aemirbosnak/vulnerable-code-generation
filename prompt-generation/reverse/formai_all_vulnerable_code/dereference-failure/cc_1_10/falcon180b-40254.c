//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DIC_FILE "dictionary.txt"
#define MAX_WORD_LEN 30

struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node *next;
};

struct node *head = NULL;

void add_word(char *word) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = head;
    head = new_node;
}

int search_word(char *word) {
    struct node *curr_node = head;

    while (curr_node!= NULL) {
        if (strcmp(curr_node->word, word) == 0) {
            return 1;
        }
        curr_node = curr_node->next;
    }

    return 0;
}

void load_dict() {
    FILE *fp;
    char line[MAX_WORD_LEN];

    fp = fopen(DIC_FILE, "r");

    if (fp == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        add_word(line);
    }

    fclose(fp);
}

int main() {
    char word[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    int i, j, len;
    FILE *fp;

    load_dict();

    printf("Enter the filename to check:\n");
    scanf("%s", line);

    fp = fopen(line, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(word, MAX_WORD_LEN, fp)!= NULL) {
        len = strlen(word);

        for (i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }

        if (search_word(word)) {
            printf("%s is a correct word.\n", word);
        } else {
            printf("%s is not a correct word.\n", word);
        }
    }

    fclose(fp);

    return 0;
}