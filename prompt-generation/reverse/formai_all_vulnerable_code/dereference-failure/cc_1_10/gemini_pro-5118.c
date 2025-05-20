//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char *text;
    struct _Node *next;
} Node;

typedef struct _Summary {
    int num_sentences;
    Node *head;
} Summary;

Summary* create_summary(char *text) {
    Summary *summary = malloc(sizeof(Summary));
    summary->num_sentences = 0;
    summary->head = NULL;

    char *token;
    char *rest = text;
    while ((token = strtok_r(rest, ".!?", &rest))) {
        Node *node = malloc(sizeof(Node));
        node->text = strdup(token);
        node->next = summary->head;
        summary->head = node;
        summary->num_sentences++;
    }

    return summary;
}

void print_summary(Summary *summary) {
    Node *node = summary->head;
    while (node) {
        printf("%s\n", node->text);
        node = node->next;
    }
}

void free_summary(Summary *summary) {
    Node *node = summary->head;
    while (node) {
        Node *next = node->next;
        free(node->text);
        free(node);
        node = next;
    }

    free(summary);
}

int main() {
    char *text = "This is a sample text. It has multiple sentences. We will summarize this text and print the summary.";

    Summary *summary = create_summary(text);
    print_summary(summary);
    free_summary(summary);

    return 0;
}