//FormAI DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 50

void print_errors();
int is_word_mispelled(char* word, char** dictionary, int dict_size);
int compare_words(char* word1, char* word2);
void to_lower(char* word);

char* dictionary[MAX_WORDS];
int dict_size = 0;
char* mispellings[MAX_WORDS];
int num_mispellings = 0;

int main() {
    FILE* dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Load dictionary
    char* word = malloc(sizeof(char) * MAX_WORD_SIZE);
    while (fscanf(dict_file, "%s", word) == 1) {
        char* new_word = malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(new_word, word);
        dictionary[dict_size] = new_word;
        dict_size++;
    }
    fclose(dict_file);
    free(word);

    printf("Enter a sentence to check spelling:\n");
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    int sentence_length = strlen(sentence);
    if (sentence[sentence_length - 1] == '\n') {
        sentence[sentence_length - 1] = '\0';
        sentence_length--;
    }

    char* word_start = sentence;
    for (int i = 0; i < sentence_length; i++) {
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            if (is_word_mispelled(word_start, dictionary, dict_size)) {
                mispellings[num_mispellings] = word_start;
                num_mispellings++;
            }
            word_start = sentence + i + 1;
        }
    }
    if (is_word_mispelled(word_start, dictionary, dict_size)) {
        mispellings[num_mispellings] = word_start;
        num_mispellings++;
    }

    print_errors();

    // Free memory
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    for (int i = 0; i < num_mispellings; i++) {
        char* mispelling = mispellings[i];
        *mispelling = toupper(*mispelling);
    }

    return 0;
}

void print_errors() {
    if (num_mispellings == 0) {
        printf("No spelling errors found.\n");
    } else {
        printf("The following words are possibly misspelled:\n");
        for (int i = 0; i < num_mispellings; i++) {
            printf("%s\n", mispellings[i]);
        }
    }
}

int is_word_mispelled(char* word, char** dictionary, int dict_size) {
    to_lower(word);
    for (int i = 0; i < dict_size; i++) {
        if (compare_words(word, dictionary[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int compare_words(char* word1, char* word2) {
    to_lower(word1);
    to_lower(word2);
    return strcmp(word1, word2);
}

void to_lower(char* word) {
    int word_length = strlen(word);
    for (int i = 0; i < word_length; i++) {
        word[i] = tolower(word[i]);
    }
}