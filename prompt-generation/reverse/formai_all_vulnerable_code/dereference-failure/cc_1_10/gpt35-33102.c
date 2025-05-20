//FormAI DATASET v1.0 Category: Text Summarizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_LINES 100

typedef struct {
    char* line;
    int num_words;
} LineInfo;

int count_words(char* line) {
    int word_count = 0;
    char* word = strtok(line, " \n");
    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " \n");
    }
    return word_count;
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    char* buffer = (char*) malloc(MAX_LINE_SIZE * MAX_NUM_LINES * sizeof(char));
    char line[MAX_LINE_SIZE];
    int num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        strcat(buffer, line);
        num_lines++;
    }
    fclose(fp);
    printf("Read %d lines from file \"%s\"\n", num_lines, filename);
    return buffer;
}

void tokenize_lines(char* buffer, LineInfo* lines, int* num_lines) {
    char* line = strtok(buffer, "\n");
    int i = 0;
    while (line != NULL) {
        lines[i].line = line;
        lines[i].num_words = count_words(line);
        (*num_lines)++;
        line = strtok(NULL, "\n");
        i++;
    }
    printf("Tokenized %d lines\n", *num_lines);
}

void summarize(char* input_filename, int num_sentences) {
    char* buffer = read_file(input_filename);
    LineInfo lines[MAX_NUM_LINES];
    int num_lines = 0;
    tokenize_lines(buffer, lines, &num_lines);

    int sentence_count = 0;
    int n = num_lines;
    while (sentence_count < num_sentences && n > 0) {
        int max_score = -1;
        int max_score_line = -1;
        for (int i = 0; i < num_lines; i++) {
            if (lines[i].num_words == 0) continue;
            int score = 0;
            char* word = strtok(lines[i].line, " \n");
            while (word != NULL) {
                if (isdigit(word[0])) {
                    word = strtok(NULL, " \n");
                    continue;
                }
                int len = strlen(word);
                if (len > 1 && ispunct(word[len-1])) {
                    word[len-1] = '\0';
                }
                if (strcmp(word, "the") == 0 ||
                    strcmp(word, "a") == 0 ||
                    strcmp(word, "an") == 0) {
                    score++;
                }
                word = strtok(NULL, " \n");
            }
            if (score > max_score) {
                max_score = score;
                max_score_line = i;
            }
        }
        if (max_score_line >= 0) {
            for (int i = 0; i < strlen(lines[max_score_line].line); i++) {
                if (lines[max_score_line].line[i] == '\n' ||
                    lines[max_score_line].line[i] == '\r') {
                    lines[max_score_line].line[i] = ' ';
                }
            }
            printf("%s\n", lines[max_score_line].line);
            sentence_count++;
            lines[max_score_line].num_words = 0;
        }
        n--;
    }
    free(buffer);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input-filename> <num-sentences>\n", argv[0]);
        return 0;
    }
    int num_sentences = atoi(argv[2]);
    summarize(argv[1], num_sentences);
    return 0;
}