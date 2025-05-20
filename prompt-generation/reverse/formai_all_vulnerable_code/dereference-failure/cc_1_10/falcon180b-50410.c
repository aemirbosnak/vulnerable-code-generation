//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20
#define WORD_LIST_FILE "word_list.txt"

typedef struct {
    char *words[MAX_CONSPIRACY_WORDS];
    int num_words;
} Conspiracy;

void load_word_list(char *filename, char **word_list, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading word list file.\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            word_list[i] = strdup(word);
            i++;
            word = strtok(NULL, " ");
        }
    }

    *num_words = i;
    fclose(file);
}

Conspiracy generate_conspiracy(char **word_list, int num_words) {
    Conspiracy conspiracy;
    conspiracy.num_words = 0;

    srand(time(NULL));
    int num_words_in_conspiracy = rand() % MAX_CONSPIRACY_WORDS + 1;

    for (int i = 0; i < num_words_in_conspiracy; i++) {
        int index = rand() % num_words;
        conspiracy.words[i] = word_list[index];
        conspiracy.num_words++;
    }

    return conspiracy;
}

void print_conspiracy(Conspiracy conspiracy) {
    printf("The conspiracy is: ");
    for (int i = 0; i < conspiracy.num_words; i++) {
        printf("%s ", conspiracy.words[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <word_list_file>\n", argv[0]);
        return 1;
    }

    char **word_list;
    int num_words;

    load_word_list(argv[1], &word_list, &num_words);

    Conspiracy conspiracy = generate_conspiracy(word_list, num_words);
    print_conspiracy(conspiracy);

    for (int i = 0; i < conspiracy.num_words; i++) {
        free(conspiracy.words[i]);
    }
    free(conspiracy.words);

    for (int i = 0; i < num_words; i++) {
        free(word_list[i]);
    }
    free(word_list);

    return 0;
}