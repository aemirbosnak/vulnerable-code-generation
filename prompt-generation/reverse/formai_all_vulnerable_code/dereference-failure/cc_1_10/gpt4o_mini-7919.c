//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 512
#define MAX_TEXT_LENGTH 2048
#define MAX_WORDS 200

char* get_word(char* text, int* start) {
    while (text[*start] == ' ' || text[*start] == '\n' || text[*start] == '\t') {
        (*start)++;
    }

    if (text[*start] == '\0') {
        return NULL;
    }

    int end = *start;
    while (text[end] != ' ' && text[end] != '\n' && text[end] != '\t' && text[end] != '\0') {
        end++;
    }

    int word_len = end - *start;
    char* word = (char*)malloc((word_len + 1) * sizeof(char));
    strncpy(word, &text[*start], word_len);
    word[word_len] = '\0';

    *start = end;
    return word;
}

void summarize_text(const char* text, char* summary) {
    char* words[MAX_WORDS];
    int word_count = 0, i = 0, start = 0;

    while (word_count < MAX_WORDS && (words[word_count] = get_word((char*)text, &start)) != NULL) {
        word_count++;
    }

    int summary_index = 0;
    for (i = 0; i < word_count && summary_index < MAX_SUMMARY_LENGTH - 1; i++) {
        if (i % 2 == 0) {
            strncpy(&summary[summary_index], words[i], MAX_SUMMARY_LENGTH - summary_index - 1);
            summary_index += strlen(words[i]);
            if (summary_index < MAX_SUMMARY_LENGTH - 1) {
                summary[summary_index++] = ' ';
            }
        }
        free(words[i]);
    }

    if (summary_index > 0) {
        summary[summary_index - 1] = '\0'; // remove last space
    } else {
        summary[0] = '\0'; // empty summary
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Welcome to the C Text Summarizer!\n");
    printf("Please enter text to summarize (type 'END' on a new line to finish):\n");

    int index = 0;
    while (1) {
        char buffer[256];
        fgets(buffer, 256, stdin);

        if (strncmp(buffer, "END", 3) == 0) {
            break;
        }

        int len = strlen(buffer);
        if (index + len < MAX_TEXT_LENGTH - 1) {
            strncpy(&text[index], buffer, len);
            index += len;
        } else {
            printf("Input too long! Unable to store all text.\n");
            break;
        }
    }
    text[index] = '\0'; // null-terminate the text string

    printf("\nOriginal Text:\n%s\n", text);
    summarize_text(text, summary);
    printf("\nSummary:\n%s\n", summary);

    return 0;
}