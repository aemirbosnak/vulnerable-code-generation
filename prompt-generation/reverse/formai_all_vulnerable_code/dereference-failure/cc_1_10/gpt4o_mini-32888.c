//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char **lines;
    int line_count;
} Document;

// Function Prototypes
Document *create_document();
void destroy_document(Document *doc);
void add_line(Document *doc, const char *line);
void summarize_document(Document *doc);
void extract_keywords(char *line, char keywords[][MAX_LINE_LENGTH], int *keyword_count);
int score_line(char *line, char keywords[][MAX_LINE_LENGTH], int keyword_count);
void sort_lines(Document *doc, int scores[]);

int main() {
    Document *doc = create_document();
    char input[MAX_LINE_LENGTH];

    printf("Welcome to the Text Summarizer!\n");
    printf("Please enter text line by line (enter 'END' to finish input):\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "END\n") == 0) {
            break;
        }
        add_line(doc, input);
    }

    printf("\nSummarizing your document...\n");
    summarize_document(doc);

    destroy_document(doc);
    return 0;
}

// Create a new Document
Document *create_document() {
    Document *new_doc = (Document *)malloc(sizeof(Document));
    new_doc->lines = (char **)malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++) {
        new_doc->lines[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    new_doc->line_count = 0;
    return new_doc;
}

// Destroy the Document and free memory
void destroy_document(Document *doc) {
    for (int i = 0; i < doc->line_count; i++) {
        free(doc->lines[i]);
    }
    free(doc->lines);
    free(doc);
}

// Add a line to the Document
void add_line(Document *doc, const char *line) {
    if (doc->line_count < MAX_LINES) {
        strcpy(doc->lines[doc->line_count], line);
        doc->line_count++;
    }
}

// Summarize the Document by extracting important lines
void summarize_document(Document *doc) {
    char line_keywords[MAX_LINES][MAX_LINE_LENGTH];
    int keyword_counts[MAX_LINES] = {0};
    int line_scores[MAX_LINES] = {0};

    // Extract keywords from each line
    for (int i = 0; i < doc->line_count; i++) {
        extract_keywords(doc->lines[i], line_keywords, &keyword_counts[i]);
    }

    // Score each line based on keyword occurrences
    for (int i = 0; i < doc->line_count; i++) {
        line_scores[i] = score_line(doc->lines[i], line_keywords, keyword_counts[i]);
    }

    // Sort lines based on scores
    sort_lines(doc, line_scores);

    // Print top 3 summarized lines
    printf("Summary of the document:\n");
    for (int i = 0; i < 3 && i < doc->line_count; i++) {
        printf("%s", doc->lines[i]);
    }
}

// Extract keywords from a line (simple logic for now)
void extract_keywords(char *line, char keywords[][MAX_LINE_LENGTH], int *keyword_count) {
    char *token = strtok(line, " ");
    *keyword_count = 0;

    while (token != NULL) {
        // Simple keyword extraction - for demo purposes, each word is a keyword
        if (*keyword_count < MAX_LINE_LENGTH) {
            strcpy(keywords[*keyword_count], token);
            (*keyword_count)++;
        }
        token = strtok(NULL, " ");
    }
}

// Score a line based on keywords
int score_line(char *line, char keywords[][MAX_LINE_LENGTH], int keyword_count) {
    int score = 0;
    for (int i = 0; i < keyword_count; i++) {
        // Simple scoring based on length of the line and existence of keywords
        if (strstr(line, keywords[i])) {
            score += strlen(keywords[i]);
        }
    }
    return score;
}

// Sort lines based on scores (simple selection sort)
void sort_lines(Document *doc, int scores[]) {
    for (int i = 0; i < doc->line_count - 1; i++) {
        for (int j = i + 1; j < doc->line_count; j++) {
            if (scores[i] < scores[j]) {
                // Swap scores
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                // Swap lines
                char temp_line[MAX_LINE_LENGTH];
                strcpy(temp_line, doc->lines[i]);
                strcpy(doc->lines[i], doc->lines[j]);
                strcpy(doc->lines[j], temp_line);
            }
        }
    }
}