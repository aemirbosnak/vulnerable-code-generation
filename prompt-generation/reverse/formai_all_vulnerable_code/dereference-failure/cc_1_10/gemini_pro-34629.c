//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    word_t *words;
    int num_words;
} dictionary_t;

dictionary_t *create_dictionary(char *filename);
void destroy_dictionary(dictionary_t *dict);
double calculate_spam_score(char *text, dictionary_t *dict);

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    dictionary_t *dict = create_dictionary(argv[1]);
    if (dict == NULL) {
        fprintf(stderr, "Error: could not create dictionary\n");
        return EXIT_FAILURE;
    }

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        fprintf(stderr, "Error: could not open text file\n");
        destroy_dictionary(dict);
        return EXIT_FAILURE;
    }

    char *text = malloc(1024);
    size_t text_size = 0;
    while (getline(&text, &text_size, text_file) != -1) {
        double spam_score = calculate_spam_score(text, dict);
        if (spam_score >= SPAM_THRESHOLD) {
            printf("This message is spam!\n");
        } else {
            printf("This message is not spam.\n");
        }
    }

    free(text);
    fclose(text_file);
    destroy_dictionary(dict);
    return EXIT_SUCCESS;
}

dictionary_t *create_dictionary(char *filename) {
    FILE *dict_file = fopen(filename, "r");
    if (dict_file == NULL) {
        return NULL;
    }

    dictionary_t *dict = malloc(sizeof(dictionary_t));
    if (dict == NULL) {
        fclose(dict_file);
        return NULL;
    }

    dict->num_words = 0;
    dict->words = NULL;

    char *word = malloc(1024);
    size_t word_size = 0;
    while (getline(&word, &word_size, dict_file) != -1) {
        word[strlen(word) - 1] = '\0';  // remove newline character
        dict->words = realloc(dict->words, (dict->num_words + 1) * sizeof(word_t));
        dict->words[dict->num_words].word = strdup(word);
        dict->words[dict->num_words].count = 0;
        dict->num_words++;
    }

    free(word);
    fclose(dict_file);
    return dict;
}

void destroy_dictionary(dictionary_t *dict) {
    for (int i = 0; i < dict->num_words; i++) {
        free(dict->words[i].word);
    }
    free(dict->words);
    free(dict);
}

double calculate_spam_score(char *text, dictionary_t *dict) {
    char *token = strtok(text, " ");
    double spam_score = 0.0;
    while (token != NULL) {
        for (int i = 0; i < dict->num_words; i++) {
            if (strcmp(token, dict->words[i].word) == 0) {
                spam_score += dict->words[i].count;
            }
        }
        token = strtok(NULL, " ");
    }

    return spam_score / dict->num_words;
}