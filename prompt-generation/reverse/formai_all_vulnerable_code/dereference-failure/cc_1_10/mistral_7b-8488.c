//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *word = strtok(line, " \t\n");
        int sentiment = 0;

        while (*word && num_words < MAX_WORDS) {
            strcpy(dictionary[num_words].word, word);

            for (int i = 0; i < strlen(word); i++)
                word[i] = tolower(word[i]);

            if (strstr(word, "happy") || strstr(word, "joy"))
                sentiment = 1;
            else if (strstr(word, "sad") || strstr(word, "miserable"))
                sentiment = -1;
            else
                sentiment = 0;

            dictionary[num_words].sentiment = sentiment;
            num_words++;

            word = strtok(NULL, " \t\n");
        }

        if (num_words >= MAX_WORDS) {
            printf("Warning: Maximum number of words reached in dictionary.\n");
            break;
        }
    }

    fclose(fp);
}

int analyze_sentiment(const char *text) {
    int total_sentiment = 0;
    int num_words_in_text = 0;

    char *token = strtok(strdup(text), " .,?!-");
    while (token) {
        for (int i = 0; i < num_words; i++) {
            if (strstr(token, dictionary[i].word) && strlen(token) <= WORD_LENGTH) {
                total_sentiment += dictionary[i].sentiment;
                num_words_in_text++;
                break;
            }
        }
        token = strtok(NULL, " .,?!-");
    }

    return total_sentiment / num_words_in_text;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dictionary_file> <text_to_analyze>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);

    if (argc != 3) {
        printf("Error: Missing text_to_analyze argument.\n");
        exit(1);
    }

    int sentiment = analyze_sentiment(argv[2]);
    printf("Text sentiment: %s\n", sentiment > 0 ? "Positive" : "Negative");

    return 0;
}