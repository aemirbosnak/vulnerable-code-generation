//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TextData {
    int num_sentences;
    char** sentences;
} TextData;

TextData* loadText(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    char* text = NULL;
    size_t text_size = 0;
    while (!feof(file)) {
        size_t new_size = text_size + 1024;
        text = realloc(text, new_size);
        text_size = new_size;
        fread(text + text_size - 1024, sizeof(char), 1024, file);
    }
    fclose(file);

    TextData* text_data = malloc(sizeof(TextData));
    text_data->num_sentences = 0;
    text_data->sentences = NULL;

    char* sentence_start = text;
    while (*sentence_start != '\0') {
        char* sentence_end = sentence_start;
        while (*sentence_end != '.' && *sentence_end != '!' && *sentence_end != '?') {
            sentence_end++;
        }
        *sentence_end = '\0';
        text_data->num_sentences++;
        text_data->sentences = realloc(text_data->sentences, sizeof(char*) * text_data->num_sentences);
        text_data->sentences[text_data->num_sentences - 1] = sentence_start;
        sentence_start = sentence_end + 1;
    }

    return text_data;
}

void freeText(TextData* text_data) {
    if (!text_data) {
        return;
    }

    for (int i = 0; i < text_data->num_sentences; i++) {
        free(text_data->sentences[i]);
    }
    free(text_data->sentences);
    free(text_data);
}

char* summarizeText(TextData* text_data, int max_sentences) {
    if (!text_data) {
        return NULL;
    }

    int num_sentences = text_data->num_sentences;
    if (max_sentences > num_sentences) {
        max_sentences = num_sentences;
    }

    char* summary = malloc(1024);
    int summary_length = 0;

    for (int i = 0; i < max_sentences; i++) {
        int sentence_length = strlen(text_data->sentences[i]);
        if (summary_length + sentence_length + 2 > 1024) {
            break;
        }

        if (i > 0) {
            strcat(summary, " ");
        }
        strcat(summary, text_data->sentences[i]);
        summary_length += sentence_length + 1;
    }

    return summary;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <max_sentences>\n", argv[0]);
        return -1;
    }

    TextData* text_data = loadText(argv[1]);
    if (!text_data) {
        printf("Error loading text file.\n");
        return -2;
    }

    int max_sentences = atoi(argv[2]);
    char* summary = summarizeText(text_data, max_sentences);
    if (!summary) {
        printf("Error summarizing text.\n");
        freeText(text_data);
        return -3;
    }

    printf("Summary:\n%s\n", summary);
    free(summary);
    freeText(text_data);
    return 0;
}