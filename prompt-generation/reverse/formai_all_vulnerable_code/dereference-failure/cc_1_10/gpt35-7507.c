//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 50
#define DICTIONARY_PATH "/usr/share/dict/words"
#define MEM_ERROR_MSG "Memory Allocation Error!"

char **words_dictionary = NULL;
int dictionary_size = 0;

void cleanup() {
    if(words_dictionary != NULL) {
        for(int i = 0; i < dictionary_size; i++) {
            free(words_dictionary[i]);
        }
        free(words_dictionary);
    }
}

void load_dictionary() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(DICTIONARY_PATH, "r");
    if(fp == NULL) {
        printf("Error opening dictionary file!");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        line[read-1] = '\0';
        words_dictionary = realloc(words_dictionary, sizeof(char*) * (dictionary_size+1));
        if(words_dictionary == NULL) {
            printf(MEM_ERROR_MSG);
            exit(1);
        }
        words_dictionary[dictionary_size] = malloc(sizeof(char) * (strlen(line) + 1));
        if(words_dictionary[dictionary_size] == NULL) {
            printf(MEM_ERROR_MSG);
            exit(1);
        }
        strcpy(words_dictionary[dictionary_size], line);
        dictionary_size++;
    }
    fclose(fp);
}

int is_word_in_dict(char *word) {
    for(int i = 0; i < dictionary_size; i++) {
        if(strcmp(words_dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_valid_word(char *word) {
    for(int i=0;i<strlen(word);i++) {
        if(!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void check_spellings(char *input_string) {
    char *token;
    token = strtok(input_string, " ");
    while(token != NULL) {
        if(is_valid_word(token)) {
            if(!is_word_in_dict(token)) {
                printf("[SPELL-MISSING]: %s\n", token);
            }
        }
        else {
            printf("[INVALID-WORD]: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    atexit(cleanup);
    load_dictionary();
    char input_string[MAX_SIZE];
    printf("Enter a string to check spellings: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';
    check_spellings(input_string);
    return 0;
}