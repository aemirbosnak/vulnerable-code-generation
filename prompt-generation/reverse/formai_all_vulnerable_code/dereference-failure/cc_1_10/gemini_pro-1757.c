//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    int num_sentences;
    Text *sentences;
} Summary;

Text *tokenize(char *text) {
    char *token = strtok(text, " .!?");
    int num_tokens = 0;
    Text *tokens = NULL;

    while (token != NULL) {
        tokens = realloc(tokens, (num_tokens + 1) * sizeof(Text));
        tokens[num_tokens].text = token;
        tokens[num_tokens].length = strlen(token);
        num_tokens++;
        token = strtok(NULL, " .!?");
    }

    return tokens;
}

Summary summarize(Text *tokens, int num_tokens) {
    Summary summary;
    summary.num_sentences = 0;
    summary.sentences = NULL;

    int current_sentence = 0;
    summary.sentences = realloc(summary.sentences, (current_sentence + 1) * sizeof(Text));
    summary.sentences[current_sentence].text = tokens[0].text;
    summary.sentences[current_sentence].length = tokens[0].length;
    summary.num_sentences++;

    for (int i = 1; i < num_tokens; i++) {
        if (tokens[i].text[0] == '.' || tokens[i].text[0] == '!' || tokens[i].text[0] == '?') {
            current_sentence++;
            summary.sentences = realloc(summary.sentences, (current_sentence + 1) * sizeof(Text));
            summary.sentences[current_sentence].text = tokens[i].text;
            summary.sentences[current_sentence].length = tokens[i].length;
            summary.num_sentences++;
        } else {
            summary.sentences[current_sentence].text = realloc(summary.sentences[current_sentence].text, summary.sentences[current_sentence].length + tokens[i].length + 1);
            strcat(summary.sentences[current_sentence].text, " ");
            strcat(summary.sentences[current_sentence].text, tokens[i].text);
            summary.sentences[current_sentence].length += tokens[i].length + 1;
        }
    }

    return summary;
}

void print_summary(Summary summary) {
    for (int i = 0; i < summary.num_sentences; i++) {
        printf("%s\n", summary.sentences[i].text);
    }
}

int main() {
    char *text = "This is a sample text. This text is about summarization. Summarization is the process of reducing a text to a shorter version while preserving the main points. This can be done manually or automatically. Automatic summarization is a challenging task, but it can be very useful. Summarization can be used for a variety of purposes, such as news articles, research papers, and marketing materials.";
    Text *tokens = tokenize(text);
    int num_tokens = 0;
    while (tokens[num_tokens].text != NULL) {
        num_tokens++;
    }
    Summary summary = summarize(tokens, num_tokens);
    print_summary(summary);

    return 0;
}