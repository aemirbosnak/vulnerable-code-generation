//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 10000

struct word_node {
    char *word;
    int count;
    struct word_node *next;
};

struct word_list {
    struct word_node *head;
    pthread_mutex_t lock;
};

struct spell_checker {
    struct word_list *word_list;
    pthread_t *threads;
    int num_threads;
};

void init_word_list(struct word_list *list) {
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
}

void insert_word(struct word_list *list, char *word) {
    struct word_node *new_node = malloc(sizeof(struct word_node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    pthread_mutex_lock(&list->lock);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct word_node *current_node = list->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    pthread_mutex_unlock(&list->lock);
}

int find_word(struct word_list *list, char *word) {
    pthread_mutex_lock(&list->lock);
    struct word_node *current_node = list->head;
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            current_node->count++;
            pthread_mutex_unlock(&list->lock);
            return 1;
        }
        current_node = current_node->next;
    }
    pthread_mutex_unlock(&list->lock);
    return 0;
}

void *spell_check_thread(void *args) {
    struct spell_checker *checker = (struct spell_checker *)args;
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, "\n");
        if (word != NULL) {
            if (!find_word(checker->word_list, word)) {
                insert_word(checker->word_list, word);
            }
        }
    }

    fclose(fp);
    return NULL;
}

void init_spell_checker(struct spell_checker *checker, int num_threads) {
    checker->word_list = malloc(sizeof(struct word_list));
    init_word_list(checker->word_list);

    checker->threads = malloc(sizeof(pthread_t) * num_threads);
    checker->num_threads = num_threads;
}

void start_spell_checking(struct spell_checker *checker) {
    for (int i = 0; i < checker->num_threads; i++) {
        pthread_create(&checker->threads[i], NULL, spell_check_thread, checker);
    }

    for (int i = 0; i < checker->num_threads; i++) {
        pthread_join(checker->threads[i], NULL);
    }
}

void free_spell_checker(struct spell_checker *checker) {
    struct word_node *current_node = checker->word_list->head;
    while (current_node != NULL) {
        struct word_node *next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    free(checker->word_list);
    free(checker->threads);
}

int main() {
    struct spell_checker checker;
    init_spell_checker(&checker, 4);
    start_spell_checking(&checker);

    char word[1024];
    while (scanf("%s", word) != EOF) {
        if (!find_word(checker.word_list, word)) {
            printf("%s is not in the dictionary.\n", word);
        }
    }

    free_spell_checker(&checker);
    return 0;
}