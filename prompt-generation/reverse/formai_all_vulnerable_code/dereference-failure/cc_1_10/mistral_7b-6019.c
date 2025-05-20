//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 10
#define KEYWORD_LENGTH 20

char *keywords[MAX_KEYWORDS];

void load_keywords() {
    FILE *fp;
    char filename[] = "keywords.txt";
    char line[KEYWORD_LENGTH + 1];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open keywords file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';
        keywords[i] = malloc(len + 1);
        strcpy(keywords[i], line);
        i++;
    }

    fclose(fp);
}

int contains_keyword(char *message, char *keyword) {
    size_t message_len = strlen(message);
    size_t keyword_len = strlen(keyword);

    for (int i = 0; i < message_len - keyword_len + 1; i++) {
        if (strncmp(&message[i], keyword, keyword_len) == 0) {
            return 1;
        }
    }

    return 0;
}

int is_spam(char *message) {
    int num_keywords = 0;

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (keywords[i] != NULL && contains_keyword(message, keywords[i])) {
            num_keywords++;
        }
    }

    return num_keywords > 2;
}

int main() {
    char message[100];
    load_keywords();

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("Warning: Possible spam detected!\n");
    } else {
        printf("Message is safe.\n");
    }

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (keywords[i] != NULL) {
            free(keywords[i]);
        }
    }

    return 0;
}