//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Joy", 1},
    {"Sadness", -1},
    {"Anger", -1},
    {"Fear", -1},
    {"Surprise", 1},
    {"Disgust", -1}
};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(char *sentence) {
    int length = strlen(sentence);
    int i;
    int sentiment_value = 0;

    for (i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            int index = tolower(sentence[i]) - 'a';
            sentiment_value += sentiments[index].value;
        }
    }

    return sentiment_value;
}

int main() {
    char input_file[MAX_SENTENCE_LENGTH];
    char output_file[MAX_SENTENCE_LENGTH];
    FILE *input;
    FILE *output;
    char sentence[MAX_SENTENCE_LENGTH];
    int sentiment_value;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, input)!= NULL) {
        sentiment_value = analyze_sentiment(sentence);
        fprintf(output, "%s -> %d\n", sentence, sentiment_value);
    }

    fclose(input);
    fclose(output);

    return 0;
}