//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct node_t {
    Word word;
    struct node_t *left;
    struct node_t *right;
} Node;

Node *create_node(Word w) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->word = w;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_word(Node *node, Word w) {
    if (node == NULL) {
        node = create_node(w);
    } else if (strcmp(node->word.word, w.word) > 0) {
        insert_word(node->left, w);
    } else {
        node->word.count++;
    }
}

void print_words(Node *node, int indent) {
    if (node == NULL) {
        return;
    }

    print_words(node->right, indent + 4);

    for (int i = 0; i < indent; i++) {
        printf(" ");
    }

    printf("%s (%d)\n", node->word.word, node->word.count);

    print_words(node->left, indent + 4);
}

int main() {
    FILE *fp;
    char ch;
    Word word;
    Node *root = NULL;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(word.word, "");
            ungetc(ch, fp);

            while ((ch = fgetc(fp))!= EOF && isalpha(ch)) {
                strcat(word.word, ch);
            }

            word.count = 1;
            insert_word(root, word);
        }
    }

    fclose(fp);

    print_words(root, 0);

    return 0;
}