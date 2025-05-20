//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

struct Word {
    char word[WORD_LENGTH];
    int sentiment;
};

struct Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    char line[100];
    char word[WORD_LENGTH];
    int sentiment;

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s%d", word, &sentiment);
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].sentiment = sentiment;
        num_words++;
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int total_sentiment = 0;
    int num_words_in_text = 1;
    char current_word[WORD_LENGTH];

    strcpy(current_word, strtok(text, " "));

    while (current_word[0] != '\0') {
        int i;

        for (i = 0; i < num_words; i++) {
            if (strcasecmp(dictionary[i].word, current_word) == 0) {
                total_sentiment += dictionary[i].sentiment;
                num_words_in_text++;
                break;
            }
        }

        if (i == num_words) {
            // Unknown word, assume neutral sentiment
            total_sentiment += 0;
        }

        strcpy(current_word, strtok(NULL, " "));
    }

    return total_sentiment / num_words_in_text;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    load_dictionary();

    int sentiment = analyze_sentiment(argv[1]);

    if (sentiment > 0) {
        printf("Positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment.\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    return 0;
}