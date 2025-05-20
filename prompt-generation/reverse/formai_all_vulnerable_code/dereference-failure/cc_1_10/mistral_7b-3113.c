//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------------
// Title: "The Wordsmith's Charterhouse of Calculation: A Programme for the Counting of Words"
//
// By: Brother Cadfael of Shrewsbury, Monk of the Abbey of Saint Peter and Saint Paul,
//     in the Year of Our Lord 1287, at the Abbey's Scriptorium
//
//-----------------------------------------------------------------------------------------------------

typedef struct _word_count {
    char *word;
    int count;
} word_count;

void count_words(char *input_text, word_count *word_list, int max_words) {
    int num_words = 0;
    char *token;
    char *input = strdup(input_text);

    token = strtok(input, " ,.!?\n\t");
    while (token != NULL && num_words < max_words) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, word_list[i].word) == 0) {
                word_list[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_list[num_words].word = strdup(token);
            word_list[num_words].count = 1;
            num_words++;
        }

        token = strtok(NULL, " ,.!?\n\t");
    }

    free(input);
}

void print_word_counts(word_count *word_list, int num_words) {
    printf("\n-------- The Wordsmith's Charterhouse of Calculation: A Report on the Counting of Words --------\n\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
        free(word_list[i].word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *input_text = NULL;
    size_t size = 0;
    ssize_t bytes_read;

    // Estimate the size of the text file
    while ((bytes_read = getline(&input_text, &size, file)) != EOF) {
        size += bytes_read;
    }
    rewind(file);

    word_count *word_list = malloc(256 * sizeof(word_count));

    count_words(input_text, word_list, 256);

    print_word_counts(word_list, 256);

    free(input_text);
    free(word_list);

    fclose(file);

    return 0;
}