//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE* file, struct word* words, int* num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].count = 1;
            i++;
        }
    }
    *num_words = i;
}

void translate_words(struct word* words, int num_words, FILE* output_file) {
    int i;
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s -> ", words[i].word);
        if (words[i].count > 1) {
            fprintf(output_file, "%s\n", "multiple meanings");
        } else {
            fprintf(output_file, "%s\n", "no translation found");
        }
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    struct word words[MAX_WORDS];
    int num_words;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    read_file(input_file, words, &num_words);

    translate_words(words, num_words, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}