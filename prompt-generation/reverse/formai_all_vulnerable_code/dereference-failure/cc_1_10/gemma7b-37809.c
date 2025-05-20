//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <string.h>

typedef struct TextNode {
    char *text;
    struct TextNode *next;
} TextNode;

void summarizeText(TextNode *head) {
    int wordCount = 0;
    TextNode *current = head;

    while (current) {
        char *text = current->text;
        wordCount += countWords(text);
        current = current->next;
    }

    int summaryLength = wordCount / 3;
    char *summary = malloc(summaryLength);

    current = head;
    int i = 0;

    while (current) {
        char *text = current->text;
        if (wordCount / 3 - i > 0) {
            strcat(summary, text);
            i++;
        }
        current = current->next;
    }

    printf("%s", summary);
    free(summary);
}

int countWords(char *text) {
    int wordCount = 0;
    char *word = strtok(text, " ");

    while (word) {
        wordCount++;
        word = strtok(NULL, " ");
    }

    return wordCount;
}

int main() {
    TextNode *head = malloc(sizeof(TextNode));
    head->text = "This is a long text that I will summarize.";
    head->next = malloc(sizeof(TextNode));
    head->next->text = "It has many words and I will remove some of them.";

    summarizeText(head);

    return 0;
}