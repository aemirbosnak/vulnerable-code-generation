//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORD_LEN 100
#define MAX_SUMMARY_LEN 500

typedef struct {
    char* text;
    double score;
} Sentence;

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* text = (char*) malloc(sizeof(char) * (file_size + 1));
    if (text == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    fread(text, sizeof(char), file_size, file);
    text[file_size] = '\0';

    fclose(file);

    return text;
}

double score_sentence(const char* sentence, const char* keywords[]) {
    double score = 0.0;

    char* word = strtok((char*) sentence, " ");
    while (word != NULL) {
        for (int i = 0; keywords[i] != NULL; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                score += 1.0;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    return score;
}

void summarize(const char* text, const char* keywords[], char* summary) {
    int num_sentences = 0;

    Sentence sentences[MAX_SENTENCES];
    char buffer[MAX_SUMMARY_LEN] = "";

    char* sentence = strtok((char*) text, ".\n");
    while (sentence != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences].text = sentence;
        sentences[num_sentences].score = score_sentence(sentence, keywords);
        num_sentences++;
        sentence = strtok(NULL, ".\n");
    }

    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentences[j].score > sentences[i].score) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    for (int i = 0; i < num_sentences && strlen(buffer) < MAX_SUMMARY_LEN - MAX_WORD_LEN; i++) {
        strcat(buffer, sentences[i].text);
        strcat(buffer, ". ");
    }

    strcpy(summary, buffer);
}

int main() {
    const char* filename = "input.txt";
    const char* keywords[] = {"computer", "programming", "software", "algorithm", NULL};

    char* text = read_file(filename);
    char summary[MAX_SUMMARY_LEN] = "";

    summarize(text, keywords, summary);

    printf("Input text:\n%s\n", text);
    printf("Keywords: ");
    for (int i = 0; keywords[i] != NULL; i++) {
        printf("%s ", keywords[i]);
    }
    printf("\n");
    printf("Summary:\n%s\n", summary);

    free(text);

    return 0;
}