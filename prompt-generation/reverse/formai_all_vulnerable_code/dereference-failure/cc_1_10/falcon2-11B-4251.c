//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DICT_SIZE 10000

typedef struct {
    char* word;
    int index;
} DictionaryEntry;

DictionaryEntry dictionary[DICT_SIZE];
int num_dictionary = 0;

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[1024];
    int i, j;
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#')
            continue;

        DictionaryEntry* entry = (DictionaryEntry*)malloc(sizeof(DictionaryEntry));
        sscanf(line, "%s %d", entry->word, &entry->index);
        for (i = 0; i < num_dictionary; i++) {
            if (strcmp(entry->word, dictionary[i].word) == 0) {
                fprintf(stderr, "Duplicate word: %s\n", entry->word);
                break;
            }
        }
        if (i == num_dictionary) {
            strcpy(dictionary[num_dictionary].word, entry->word);
            dictionary[num_dictionary].index = entry->index;
            num_dictionary++;
        } else {
            free(entry);
            continue;
        }
    }
    fclose(fp);
}

void shuffle_words(char* words[]) {
    srand(time(NULL));
    for (int i = 0; i < DICT_SIZE; i++) {
        int j = rand() % (i + 1);
        char* temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void translate_string(char* str, char* words[]) {
    char* output = (char*)malloc(strlen(str) * sizeof(char));
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < num_dictionary; j++) {
            if (strcmp(str + i, words[j]) == 0) {
                strcpy(output + i, dictionary[j].word);
                break;
            }
        }
    }
    printf("%s\n", output);
    free(output);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    char* input_file = argv[1];
    char* output_file = strcat(input_file, ".alien");

    load_dictionary(input_file);
    load_dictionary(output_file);

    char* words[] = {"hello", "world", "how", "are", "you"};
    shuffle_words(words);

    char* str = "hello world how are you";
    translate_string(str, words);

    return 0;
}