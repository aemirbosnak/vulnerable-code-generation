//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_node {
    char word[50];
    struct word_node* next;
} word_node;

word_node* create_word_node(char* word) {
    word_node* node = (word_node*)malloc(sizeof(word_node));
    strcpy(node->word, word);
    node->next = NULL;
    return node;
}

void insert_node(word_node** head, char* word) {
    if (*head == NULL) {
        *head = create_word_node(word);
        return;
    }
    word_node* curr_node = *head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = create_word_node(word);
}

word_node* load_dictionary(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return NULL;
    }
    word_node* head = NULL;
    char word[50];
    while (fscanf(file, "%s", word) == 1) {
        insert_node(&head, word);
    }
    fclose(file);
    return head;
}

void strip_punctuations(char* word) {
    int len = strlen(word);
    int i, j;
    for (i = 0; i < len; i++) {
        if (ispunct(word[i])) {
            for (j = i; j < len - 1; j++) {
                word[j] = word[j+1];
            }
            word[len - 1] = '\0';
            len--;
            i--;
        }
    }
}

void to_lowercase(char* word) {
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int spell_check(word_node* dictionary, char* word) {
    strip_punctuations(word);
    to_lowercase(word);
    word_node* curr_node = dictionary;
    while (curr_node != NULL) {
        if (strcmp(curr_node->word, word) == 0) {
            return 1;
        }
        curr_node = curr_node->next;
    }
    return 0;
}

void spell_check_input(word_node* dictionary) {
    char input[500];
    printf("Enter your text:\n");
    fgets(input, sizeof(input), stdin);
    char* word = strtok(input, " \t\r\n");
    while (word != NULL) {
        if (!spell_check(dictionary, word)) {
            printf("Mispelled word: %s\n", word);
        }
        word = strtok(NULL, " \t\r\n");
    }
}

int main() {
    word_node* dictionary = load_dictionary("dictionary.txt");
    if (dictionary == NULL) {
        return 1;
    }
    spell_check_input(dictionary);
    return 0;
}