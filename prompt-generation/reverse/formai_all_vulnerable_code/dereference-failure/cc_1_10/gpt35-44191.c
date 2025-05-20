//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_CHARACTERS_PER_SENTENCE 200

char* read_text_file(const char* file_path) {
    FILE* file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        return NULL;
    }

    fseek(file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    rewind(file_pointer);

    char* text = (char*) malloc(sizeof(char) * file_size);
    fread(text, 1, file_size, file_pointer);
    fclose(file_pointer);

    return text;
}

char** split_into_sentences(char* text) {
    char** sentences = (char**) malloc(sizeof(char*) * MAX_SENTENCES);

    int sentence_count = 0;
    char* sentence = strtok(text, ".!?");
    while (sentence != NULL && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count++] = sentence;
        sentence = strtok(NULL, ".!?");
    }

    return sentences;
}

int calc_sentence_score(char* sentence) {
    const char* keywords[] = {"the", "a", "an", "is", "was", "were", "are", "has", "have", "had"};
    const int keyword_count = sizeof(keywords) / sizeof(keywords[0]);

    int score = 0;
    char* word = strtok(sentence, " ,.-");
    while (word != NULL) {
        for (int i = 0; i < keyword_count; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                score++;
            }
        }
        word = strtok(NULL, " ,.-");
    }

    return score;
}

int compare_sentences(const void* a, const void* b) {
    char** sa = (char**) a;
    char** sb = (char**) b;

    int score_a = calc_sentence_score(*sa);
    int score_b = calc_sentence_score(*sb);

    return score_b - score_a;
}

void summarize_text(char* file_path) {
    char* text = read_text_file(file_path);
    if (text == NULL) {
        printf("Failed to read text file\n");
        return;
    }

    char** sentences = split_into_sentences(text);
    int sentence_count = 0;
    while (sentences[sentence_count] != NULL) {
        sentence_count++;
    }

    qsort(sentences, sentence_count, sizeof(char*), compare_sentences);

    int summary_sentence_count = sentence_count / 5;
    if (summary_sentence_count == 0) {
        summary_sentence_count = 1;
    }

    printf("\nSUMMARY:\n\n");
    for (int i = 0; i < summary_sentence_count; i++) {
        printf("%s", sentences[i]);
    }

    printf("\n");

    free(text);
    free(sentences);
}

int main() {
    summarize_text("example_text.txt");
    return 0;
}