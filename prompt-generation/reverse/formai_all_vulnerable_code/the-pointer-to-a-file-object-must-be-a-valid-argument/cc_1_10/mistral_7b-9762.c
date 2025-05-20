//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int score;
} Word;

Word dictionary[MAX_WORDS];

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    int i = 0;
    char line[1024];
    char word[WORD_LENGTH];
    int score;

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d", word, &score);
        strcpy(dictionary[i].word, word);
        dictionary[i].score = score;
        i++;
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int i, j, total_score = 0;
    char word[WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    char *words = strtok(text, " ,.-");

    while (words != NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strncmp(words, dictionary[i].word, strlen(words)) == 0) {
                total_score += dictionary[i].score;
                break;
            }
        }

        words = strtok(NULL, " ,.-");
    }

    return total_score;
}

int main() {
    char *text = "Lord, I am filled with joy and gratitude. Thy kindness is a balm to my soul.";
    int sentiment_score;

    load_dictionary("dictionary.txt");

    sentiment_score = analyze_sentiment(text);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}