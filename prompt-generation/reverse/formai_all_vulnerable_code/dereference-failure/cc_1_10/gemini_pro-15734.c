//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUMMARY_LENGTH 250

struct sentence {
    char text[MAX_LINE_LENGTH];
    int length;
};

struct summary {
    struct sentence sentences[MAX_SUMMARY_LENGTH];
    int num_sentences;
};

// Read a line of text from the given file into the given sentence struct.
// Return 1 on success, 0 on EOF, and -1 on error.
int read_line(FILE *fp, struct sentence *sentence) {
    int ch;
    int i = 0;

    while ((ch = fgetc(fp)) != EOF && ch != '\n') {
        if (i < MAX_LINE_LENGTH) {
            sentence->text[i++] = ch;
        }
    }

    sentence->length = i;

    if (ch == EOF) {
        return 0;
    } else {
        return 1;
    }
}

// Write the given summary to the given file.
void write_summary(FILE *fp, struct summary *summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        fprintf(fp, "%s", summary->sentences[i].text);
        if (i < summary->num_sentences - 1) {
            fprintf(fp, " ");
        }
    }
}

// Summarize the given text.
struct summary summarize(const char *text) {
    struct summary summary;
    summary.num_sentences = 0;

    // Tokenize the text into sentences.
    char *token = strtok((char *)text, ".");
    while (token != NULL) {
        // Remove any leading or trailing whitespace.
        while (*token == ' ' || *token == '\t' || *token == '\n') {
            token++;
        }
        while (token[strlen(token) - 1] == ' ' || token[strlen(token) - 1] == '\t' || token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }

        // Add the sentence to the summary.
        if (strlen(token) > 0) {
            strcpy(summary.sentences[summary.num_sentences].text, token);
            summary.sentences[summary.num_sentences].length = strlen(token);
            summary.num_sentences++;
        }

        // Get the next token.
        token = strtok(NULL, ".");
    }

    // Sort the sentences by length.
    qsort(summary.sentences, summary.num_sentences, sizeof(struct sentence),
          (int (*)(const void *, const void *))strcmp);

    // Select the top N sentences for the summary.
    int num_sentences_to_select = summary.num_sentences;
    if (num_sentences_to_select > MAX_SUMMARY_LENGTH) {
        num_sentences_to_select = MAX_SUMMARY_LENGTH;
    }

    summary.num_sentences = num_sentences_to_select;

    return summary;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s textfile\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the text from the file.
    char text[MAX_LINE_LENGTH];
    int num_lines = 0;
    while (read_line(fp, &(text)) == 1) {
        num_lines++;
    }
    fclose(fp);

    // Summarize the text.
    struct summary summary = summarize(text);

    // Write the summary to stdout.
    write_summary(stdout, &summary);
    printf("\n");

    return 0;
}