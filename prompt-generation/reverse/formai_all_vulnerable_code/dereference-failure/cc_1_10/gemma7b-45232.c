//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char text[MAX_BUFFER_SIZE];
    char summary[MAX_BUFFER_SIZE];
    int text_length, summary_length;
    FILE *fp;

    // Open the text file
    fp = fopen("novel.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the text from the file
    text_length = read_text(text, fp);

    // Summarize the text
    summary_length = summarize(text, summary, text_length);

    // Print the summary
    printf("%s", summary);

    fclose(fp);
    return 0;
}

int read_text(char *text, FILE *fp) {
    int i = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        text[i++] = ch;
    }

    text[i] = '\0';
    return i;
}

int summarize(char *text, char *summary, int text_length) {
    int i = 0, j = 0, summary_length = 0;
    char *words[MAX_BUFFER_SIZE];

    // Split the text into words
    words[i] = strtok(text, " ");
    while (words[i] != NULL) {
        i++;
        words[i] = strtok(NULL, " ");
    }

    // Count the frequency of each word
    for (i = 0; i < text_length; i++) {
        for (j = 0; words[j] != NULL; j++) {
            if (strcmp(words[j], text[i]) == 0) {
                summary[summary_length++] = text[i];
            }
        }
    }

    summary[summary_length] = '\0';
    return summary_length;
}