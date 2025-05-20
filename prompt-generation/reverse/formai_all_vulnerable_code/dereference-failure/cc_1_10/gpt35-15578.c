//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include<stdio.h>
#include<string.h>

// function to remove punctuations from the text
void removePunctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (!ispunct((unsigned char)str[i]))
            str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

// function to count the frequency of words in the text
void countWords(char* text, char* words[], int freq[], int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        freq[i] = 0;
        for (j = 0; text[j]; j++) {
            if (strstr(&text[j], words[i]) == &text[j]) {
                freq[i]++;
            }
        }
    }
}

int main() {
    char text[5000], * words[1000];
    int i, j, freq[1000], len = 0, maxIndex;

    printf("My darling, please write down the text you want me to summarize for you: \n");
    fgets(text, sizeof(text), stdin);

    printf("Give me some keywords to look for: \n");
    fgets(words[0], sizeof(words[0]), stdin);
    len++;
    while (strlen(words[len - 1]) > 2 && len < 1000) {
        fgets(words[len], sizeof(words[0]), stdin);
        len++;
    }

    removePunctuation(text);
    for (i = 0; i < len; i++) {
        removePunctuation(words[i]);
    }

    countWords(text, words, freq, len);
    maxIndex = 0;
    for (i = 1; i < len; i++) {
        if (freq[i] > freq[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("My love, I have summarized the text for you: \n");
    for (i = 0; text[i]; i++) {
        if (text[i] == '.') {
            printf(".\n");
            if (strstr(&text[i+1], words[maxIndex]) != NULL) {
                for (j = i + 1; j <= i + 30 && text[j]; j++) {
                    printf("%c", text[j]);
                }
                printf("...\n");
            }
        }
    }

    return 0;
}