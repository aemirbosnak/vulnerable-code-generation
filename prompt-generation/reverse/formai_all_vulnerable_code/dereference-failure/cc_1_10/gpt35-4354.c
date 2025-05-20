//FormAI DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000
#define MAX_LENGTH 500

char punc[] = ".,;:'\"?!()\n";

void removePunct(char *buf) {
    int n = strlen(buf);

    for (int i = 0; i < n; i++) {
        if (strchr(punc, buf[i]))
            buf[i] = ' ';
    }
}

int countWords(char *buf) {
    int count = 0;
    char *token = strtok(buf, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int countSentences(char *buf) {
    int count = 0;
    int n = strlen(buf);

    for (int i = 0; i < n; i++) {
        if (strchr(".?!", buf[i]) && i > 0 && !isdigit(buf[i - 1])) {
            count++;
        }
    }
    return count;
}

int countChars(char *buf) {
    int count = 0;
    int n = strlen(buf);

    for (int i = 0; i < n; i++) {
        if (isalpha(buf[i])) {
            count++;
        }
    }
    return count;
}

float calculateFlesch(int words, int sentences, int chars) {
    float index = 0.0;
    index = (0.39 * ((float) words / (float) sentences)) +
            (11.8 * ((float) chars / (float) words)) - 15.59;
    return index;
}

int main() {
    // read input file
    FILE *fptr;
    char filename[100];

    printf("Enter the filename of the text document to summarize: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error reading file %s.", filename);
        return 0;
    }

    // allocate memory for text
    char *text = (char *) malloc(MAX * sizeof(char));
    if (text == NULL) {
        printf("Error: Out of memory.");
        return 0;
    }

    // read text from file to string variable
    fgets(text, MAX, fptr);
    fclose(fptr);

    // remove punctuation from text
    removePunct(text);

    // convert text to lowercase
    int n = strlen(text);
    for (int i = 0; i < n; i++) {
        text[i] = tolower(text[i]);
    }

    // count number of words, sentences and characters in text
    int words = countWords(text);
    int sentences = countSentences(text);
    int chars = countChars(text);

    // calculate Flesch Index
    float flesch_index = calculateFlesch(words, sentences, chars);

    // print summary
    printf("The Flesch Index of the text is %.2f\n", flesch_index);
    printf("The text has %d words, %d sentences and %d characters.\n", words, sentences, chars);

    // free memory
    free(text);

    return 0;
}