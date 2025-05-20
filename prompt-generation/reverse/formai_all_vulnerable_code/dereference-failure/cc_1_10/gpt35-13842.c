//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100000

// function declarations
int strcasecmp(const char *s1, const char *s2);
int get_word(char *word, FILE *fp);
void insert_word(char *word, int count);
void print_word_count(FILE *fp);

// global variables
char *words[MAX_WORDS];
int counts[MAX_WORDS];
int num_words = 0;

int main(int argc, char **argv) {
    // check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // read words from file
    char word[MAX_WORD_LENGTH];
    while (get_word(word, fp)) {
        // convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // update word count
        insert_word(word, 1);
    }
    // print word count
    char *output_filename = "wordcount.txt";
    FILE *output_fp = fopen(output_filename, "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: cannot open file \"%s\"\n", output_filename);
        exit(EXIT_FAILURE);
    }
    print_word_count(output_fp);
    printf("Word count saved to file \"%s\"\n", output_filename);
    fclose(fp);
    fclose(output_fp);
    exit(EXIT_SUCCESS);
}

int strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

int get_word(char *word, FILE *fp) {
    char c = fgetc(fp);
    while (c != EOF && !isalpha(c)) {
        c = fgetc(fp);
    }
    if (c == EOF) {
        return 0;
    }
    int i = 0;
    while (isalpha(c)) {
        word[i++] = c;
        c = fgetc(fp);
    }
    word[i] = '\0';
    return 1;
}

void insert_word(char *word, int count) {
    for (int i = 0; i < num_words; i++) {
        if (strcasecmp(word, words[i]) == 0) {
            counts[i] += count;
            return;
        }
    }
    if (num_words < MAX_WORDS) {
        words[num_words] = strdup(word);
        counts[num_words] = count;
        num_words++;
    }
}

void print_word_count(FILE *fp) {
    fprintf(fp, "Word\tCount\n");
    fprintf(fp, "====\t=====\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s\t%d\n", words[i], counts[i]);
    }
}