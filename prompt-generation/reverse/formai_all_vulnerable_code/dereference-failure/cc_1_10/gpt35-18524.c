//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000000
#define MAXWORD 50

int get_word(char *word, int limit) {
    int c, i = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
            if (i == limit - 1) {
                word[i] = '\0';
                return i;
            }
        } else if (i > 0) {
            word[i] = '\0';
            return i;
        }
    }
    return 0;
}

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *find_word(struct node *list, char *word) {
    while (list != NULL) {
        if (strcmp(list->word, word) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct node *add_word(struct node *list, char *word) {
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->word = strdup(word);
    ptr->count = 1;
    ptr->next = list;
    list = ptr;
    return list;
}

void print_list(struct node *list) {
    while (list != NULL) {
        printf("%-15s %d\n", list->word, list->count);
        list = list->next;
    }
}

void free_list(struct node *list) {
    struct node *ptr;
    while (list != NULL) {
        ptr = list;
        list = list->next;
        free(ptr->word);
        free(ptr);
    }
}

int main() {
    char word[MAXWORD];
    struct node *list = NULL;
    int n = 0;

    while (n < MAXSIZE && get_word(word, MAXWORD) > 0) {
        struct node *ptr = find_word(list, word);
        if (ptr == NULL) {
            list = add_word(list, word);
        } else {
            ptr->count++;
        }
        n++;
    }

    print_list(list);
    free_list(list);

    return 0;
}