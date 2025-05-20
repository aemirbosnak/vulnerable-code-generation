//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_SENTENCE_LEN], output_filename[MAX_SENTENCE_LEN];
    char sentence[MAX_SENTENCE_LEN];
    int num_words;
    WordFreq words[MAX_WORDS];

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", sentence)!= EOF) {
        num_words = 0;
        memset(words, 0, sizeof(words));

        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].freq++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: maximum number of words exceeded.\n");
                    exit(1);
                }
                strcpy(words[num_words].word, token);
                words[num_words].freq = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }

        for (int i = 0; i < num_words; i++) {
            fprintf(output_file, "%s %d\n", words[i].word, words[i].freq);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}