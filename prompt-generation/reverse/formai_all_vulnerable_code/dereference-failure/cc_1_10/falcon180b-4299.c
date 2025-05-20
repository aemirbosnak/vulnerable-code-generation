//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int index;
} Word;

void read_text(FILE *file, Word *words) {
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            if (i >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            words[i].word[words[i].length] = tolower(c);
            words[i].length++;
        } else {
            if (words[i].length > 0) {
                words[i].word[words[i].length] = '\0';
                i++;
            }
        }
    }
    if (i > 0) {
        words[i-1].word[words[i-1].length] = '\0';
    }
}

void print_sentence(const char *sentence) {
    printf("\"%s\"\n", sentence);
}

int main() {
    FILE *input_file, *output_file;
    Word words[MAX_WORDS];
    int num_words = 0;
    char filename[MAX_WORD_LENGTH];
    char sentence[MAX_WORD_LENGTH];
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    read_text(input_file, words);
    num_words = i;

    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    output_file = fopen(filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        if (i > 0) {
            strcpy(sentence, " ");
        }
        strcat(sentence, words[i].word);
        if (i < num_words - 1) {
            strcat(sentence, ", ");
        }
        print_sentence(sentence);
        fprintf(output_file, "%s\n", sentence);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}