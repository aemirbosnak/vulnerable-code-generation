//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Text;

Text *read_text(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *text = malloc(length + 1);
    if (text == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(text, 1, length, fp);
    text[length] = '\0';

    fclose(fp);

    Text *t = malloc(sizeof(Text));
    if (t == NULL) {
        free(text);
        return NULL;
    }

    t->text = text;
    t->length = length;

    return t;
}

void free_text(Text *t) {
    if (t == NULL) {
        return;
    }

    free(t->text);
    free(t);
}

char *summarize_text(const Text *t) {
    if (t == NULL) {
        return NULL;
    }

    // Tokenize the text.
    char **tokens = malloc(sizeof(char *) * t->length);
    if (tokens == NULL) {
        return NULL;
    }

    int num_tokens = 0;
    char *token = strtok(t->text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Find the most frequent token.
    int max_count = 0;
    char *most_frequent_token = NULL;
    for (int i = 0; i < num_tokens; i++) {
        int count = 0;
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            most_frequent_token = tokens[i];
        }
    }

    // Generate the summary.
    char *summary = malloc(strlen(most_frequent_token) + 1);
    if (summary == NULL) {
        free(tokens);
        return NULL;
    }

    strcpy(summary, most_frequent_token);

    // Free the memory.
    free(tokens);

    return summary;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    Text *t = read_text(argv[1]);
    if (t == NULL) {
        fprintf(stderr, "Error reading text file.\n");
        return 1;
    }

    char *summary = summarize_text(t);
    if (summary == NULL) {
        fprintf(stderr, "Error summarizing text.\n");
        free_text(t);
        return 1;
    }

    printf("Summary: %s\n", summary);

    free_text(t);
    free(summary);

    return 0;
}