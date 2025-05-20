//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void read_file(FILE *fp, char *text);
void process_word(char *word);
void print_results(void);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char text[1000000]; // Buffer to store the text from the file
    read_file(fp, text);
    fclose(fp);

    process_word(text);
    print_results();

    return 0;
}

void read_file(FILE *fp, char *text) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(text, &ch);
        }
    }
}

void process_word(char *word) {
    int length = strlen(word);
    if (length > 3) {
        if (word[length - 1] == '.' || word[length - 1] == '?' || word[length - 1] == '!') {
            word[length - 1] = '\0';
        }
        if (isupper(word[0])) {
            printf("Thou art speaking with great enthusiasm!\n");
        } else if (islower(word[0])) {
            printf("Thou art speaking with sorrowful heart.\n");
        } else {
            printf("Thou art speaking with neutral tone.\n");
        }
    }
}

void print_results(void) {
    printf("Sentiment analysis complete.\n");
}