//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 3

struct word {
    char *word;
    int count;
};

int compare(const void *a, const void *b) {
    struct word *word1 = (struct word *)a;
    struct word *word2 = (struct word *)b;
    return strcmp(word1->word, word2->word);
}

int is_spam(char *email) {
    FILE *fp;
    char ch;
    int spam_count = 0;
    char word[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(word, tolower(ch));
        } else if (num_words == MAX_WORDS) {
            break;
        } else if (isalpha(ch)) {
            num_words++;
            strcpy(word, "");
            strcat(word, tolower(ch));
        }
    }

    fclose(fp);

    words[num_words].word = strdup(word);
    words[num_words].count = 0;
    num_words++;

    qsort(words, num_words, sizeof(struct word), compare);

    for (int i = 0; i < num_words; i++) {
        if (strstr(email, words[i].word)!= NULL) {
            spam_count++;
        }
    }

    if (spam_count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORD_LENGTH];
    printf("Enter email: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}