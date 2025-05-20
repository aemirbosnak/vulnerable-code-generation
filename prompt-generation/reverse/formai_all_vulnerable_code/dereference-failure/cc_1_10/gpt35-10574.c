//FormAI DATASET v1.0 Category: Text Summarizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define DELIMITERS " \t\n"

bool is_sentence_boundary(char c) {
    if (c == '.' || c == '?' || c == '!') {
        return true;    
    }
    return false;
}

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }

    size_t length = 0;
    size_t capacity = BUFFER_SIZE;

    int c;
    while ((c = fgetc(file)) != EOF) {    
        if (length + 1 == capacity) {
            capacity += BUFFER_SIZE;
            char *new_buffer = realloc(buffer, capacity * sizeof(char));
            if (new_buffer == NULL) {
                free(buffer);
                fclose(file);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[length++] = c;
    }

    if (ferror(file)) {
        free(buffer);
        fclose(file);
        return NULL;
    }

    char *new_buffer = realloc(buffer, (length + 1) * sizeof(char));
    if (new_buffer == NULL) {
        fclose(file);
        free(buffer);
        return NULL;
    }

    new_buffer[length] = '\0';

    fclose(file);
    return new_buffer;
}

typedef struct {
    size_t start_offset;
    size_t end_offset;
    int score;
} sentence_t;

sentence_t *summarize(const char *text, size_t max_sentences, size_t max_length) {
    char *copy = strdup(text);
    if (copy == NULL) {
        return NULL;
    }

    sentence_t *sentences = malloc(max_sentences * sizeof(sentence_t));
    if (sentences == NULL) {
        free(copy);
        return NULL;
    }

    size_t num_sentences = 0;

    char *token = strtok(copy, DELIMITERS);
    size_t sentence_start_offset = 0;

    while (token != NULL && num_sentences < max_sentences) {
        if (is_sentence_boundary(token[strlen(token) - 1])) {
            size_t sentence_end_offset = token - copy + strlen(token) + 1;
            sentence_t sentence = {sentence_start_offset, sentence_end_offset, 0};
            for (size_t i = sentence_start_offset; i < sentence_end_offset; i++) {
                if (isalpha(copy[i])) {
                    sentence.score++;
                }
            }
            sentences[num_sentences++] = sentence;

            sentence_start_offset = sentence_end_offset;
        }
        token = strtok(NULL, DELIMITERS);
    }

    free(copy);

    sentence_t *summary = malloc(max_sentences * sizeof(sentence_t));
    if (summary == NULL) {
        free(sentences);
        return NULL;
    }

    size_t num_summary_sentences = 0;
    size_t summary_length = 0;

    for (size_t i = 0; i < num_sentences && summary_length < max_length; i++) {
        bool skip_sentence = false;
        for (size_t j = 0; j < num_summary_sentences; j++) {
            if (sentences[i].start_offset >= summary[j].start_offset && sentences[i].end_offset <= summary[j].end_offset) {
                skip_sentence = true;
                break;
            }
        }
        if (!skip_sentence) {
            summary[num_summary_sentences++] = sentences[i];
            summary_length += sentences[i].end_offset - sentences[i].start_offset;
        }
    }

    free(sentences);

    if (num_summary_sentences < max_sentences ) {
        sentence_t empty = {0, 0, 0};
        summary[num_summary_sentences++] = empty;
    }

    return summary;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <max_sentences> <max_length>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    size_t max_sentences = atoi(argv[3]);
    if (max_sentences < 1) {
        fprintf(stderr, "Error: max_sentences must be a positive integer\n");
        return EXIT_FAILURE;
    }

    size_t max_length = atoi(argv[4]);
    if (max_length < 1) {
        fprintf(stderr, "Error: max_length must be a positive integer\n");
        return EXIT_FAILURE;
    }

    char *text = read_file(input_file);
    if (text == NULL) {
        fprintf(stderr, "Error: Could not read input file '%s': %s\n", input_file, strerror(errno));
        return EXIT_FAILURE;
    }

    sentence_t *summary = summarize(text, max_sentences, max_length);
    if (summary == NULL) {
        free(text);
        fprintf(stderr, "Error: Could not summarize text\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        free(text);
        free(summary);
        fprintf(stderr, "Error: Could not open output file '%s': %s\n", output_file, strerror(errno));
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < max_sentences && summary[i].start_offset != 0; i++) {
        fwrite(text + summary[i].start_offset, 1, summary[i].end_offset - summary[i].start_offset, file);
    }

    fclose(file);
    free(text);
    free(summary);
    return EXIT_SUCCESS;
}