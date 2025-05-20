//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LEN 20

struct word_t {
    char word[WORD_LEN];
    int sentiment;
};

struct word_t dictionary[MAX_WORDS];

void load_dictionary() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("sentiment_dictionary.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d", dictionary[i].word, &dictionary[i].sentiment);
        i++;
    }
    fclose(fp);
}

int main() {
    char input[100];
    char words[MAX_WORDS][WORD_LEN];
    int num_words = 0;
    int sentiment = 0;

    load_dictionary();

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", input); // remove newline character

    // tokenize input into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        strcpy(words[num_words], token);
        num_words++;
        token = strtok(NULL, " ");
    }

    // calculate sentiment based on words in the input
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], dictionary[j].word) == 0) {
                sentiment += dictionary[j].sentiment;
                break;
            }
        }
    }

    // print sentiment
    if (sentiment > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}