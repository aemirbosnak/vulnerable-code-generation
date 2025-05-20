//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_FILE "dictionary.txt"
#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

typedef struct word_node {
    char word[MAX_WORD_LENGTH];
    struct word_node *next;
} WordNode;

void read_dictionary(char *filename, WordNode **dictionary) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *word_token;
    WordNode *cur_word, *new_word;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        cur_word = *dictionary;
        new_word = malloc(sizeof(WordNode));
        if (new_word == NULL) {
            printf("Error: out of memory.\n");
            exit(1);
        }
        
        /* extract word from line */
        word_token = strtok(line, "\n");
        strncpy(new_word->word, word_token, MAX_WORD_LENGTH);
        new_word->next = NULL;
        
        /* add word to linked list */
        if (cur_word == NULL) {
            *dictionary = new_word;
        } else {
            while (cur_word->next != NULL) {
                cur_word = cur_word->next;
            }
            cur_word->next = new_word;
        }
    }
    fclose(fp);
}

int is_in_dictionary(char *word, WordNode *dictionary) {
    WordNode *cur_word = dictionary;
    while (cur_word != NULL) {
        if (strcmp(word, cur_word->word) == 0) {
            return 1;
        }
        cur_word = cur_word->next;
    }
    return 0;
}

void clean_word(char *word) {
    int len = strlen(word);
    int i, j;
    char cleaned_word[MAX_WORD_LENGTH];
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(word[i])) {
            cleaned_word[j] = tolower(word[i]);
            j++;
        }
    }
    cleaned_word[j] = '\0';
    strncpy(word, cleaned_word, MAX_WORD_LENGTH);
}

void spell_check_line(char *line, WordNode *dictionary) {
    char *word_token;
    char current_word[MAX_WORD_LENGTH];
    int i, j, len;
    int within_word = 0;
    
    /* iterate over each character in line */
    for (i = 0, j = 0, len = strlen(line); i < len; i++) {
        if (isalpha(line[i])) {
            current_word[j] = line[i];
            j++;
            within_word = 1;  /* flag that we are within a word */
        } else {
            /* we have reached the end of a word */
            if (within_word) {
                current_word[j] = '\0';
                clean_word(current_word);
                if (!is_in_dictionary(current_word, dictionary)) {
                    printf("Possible spelling mistake: %s\n", current_word);
                }
                within_word = 0;  /* reset the within_word flag */
                j = 0;  /* reset the index for the current word */
            }
        }
    }
}

int main(void) {
    WordNode *dictionary = NULL;
    char line[MAX_LINE_LENGTH];
    FILE *fp;
    
    /* read dictionary file into linked list */
    read_dictionary(DICTIONARY_FILE, &dictionary);
    
    /* spell check input from standard input */
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        spell_check_line(line, dictionary);
    }
    
    /* free memory used by linked list */
    WordNode *cur_word = dictionary;
    WordNode *next_word;
    while (cur_word != NULL) {
        next_word = cur_word->next;
        free(cur_word);
        cur_word = next_word;
    }
    
    return 0;
}