//Falcon-180B DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 1000
#define MAX_PARAGRAPH_LEN 10000

typedef struct {
    char *text;
    int length;
} String;

String newString(char *text) {
    String s;
    s.text = text;
    s.length = strlen(text);
    return s;
}

String catStrings(String a, String b) {
    String result;
    result.text = malloc(a.length + b.length + 1);
    strcpy(result.text, a.text);
    strcat(result.text, b.text);
    result.length = a.length + b.length;
    return result;
}

int countWords(String paragraph) {
    int count = 0;
    char *word = strtok(paragraph.text, ",.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    return count;
}

int countSentences(String paragraph) {
    int count = 0;
    char *sentence = strtok(paragraph.text, ".?!");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".?!");
    }
    return count;
}

int main() {
    FILE *inputFile;
    String filename, paragraph;
    char ch;

    printf("Enter the name of the file: ");
    scanf("%s", filename.text);

    inputFile = fopen(filename.text, "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    paragraph = newString("");
    while ((ch = fgetc(inputFile))!= EOF) {
        if (ch == '\n' || ch == '.' || ch == '!' || ch == '?') {
            if (paragraph.length > 0) {
                printf("%s\n", paragraph.text);
                paragraph = newString("");
            }
        } else {
            paragraph = catStrings(paragraph, newString(&ch));
        }
    }

    if (paragraph.length > 0) {
        printf("%s\n", paragraph.text);
    }

    fclose(inputFile);

    return 0;
}