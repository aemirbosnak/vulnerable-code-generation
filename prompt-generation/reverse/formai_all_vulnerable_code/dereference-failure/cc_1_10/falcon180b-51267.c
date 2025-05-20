//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 200

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int frequency;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void add_sentence(Text *text, char *sentence) {
    int i;
    for (i = 0; i < text->num_sentences; i++) {
        if (strcmp(text->sentences[i].sentence, sentence) == 0) {
            text->sentences[i].frequency++;
            return;
        }
    }
    if (text->num_sentences >= MAX_SENTENCE_LENGTH) {
        printf("Error: Maximum number of sentences reached.\n");
        exit(1);
    }
    strcpy(text->sentences[text->num_sentences].sentence, sentence);
    text->sentences[text->num_sentences].frequency = 1;
    text->num_sentences++;
}

void generate_summary(Text *text, char *summary) {
    int i, j;
    int total_frequency = 0;
    for (i = 0; i < text->num_sentences; i++) {
        total_frequency += text->sentences[i].frequency;
    }
    for (i = 0; i < text->num_sentences; i++) {
        for (j = i + 1; j < text->num_sentences; j++) {
            if (text->sentences[j].frequency > text->sentences[i].frequency) {
                Sentence temp = text->sentences[i];
                text->sentences[i] = text->sentences[j];
                text->sentences[j] = temp;
            }
        }
    }
    int summary_index = 0;
    for (i = 0; i < text->num_sentences; i++) {
        if (summary_index >= SUMMARY_LENGTH) {
            break;
        }
        strcat(summary, text->sentences[i].sentence);
        strcat(summary, " ");
        summary_index += strlen(text->sentences[i].sentence) + 1;
    }
    summary[summary_index - 1] = '\0';
}

int main() {
    Text text;
    text.sentences = NULL;
    text.num_sentences = 0;
    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        if (text.num_sentences >= MAX_SENTENCE_LENGTH) {
            printf("Error: Maximum number of sentences reached.\n");
            exit(1);
        }
        add_sentence(&text, sentence);
    }
    char summary[SUMMARY_LENGTH];
    generate_summary(&text, summary);
    printf("Summary:\n%s\n", summary);
    return 0;
}