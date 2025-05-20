//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: genious
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256
#define POSITIVE_WORDS {"good", "great", "awesome", "excellent", "fantastic"}
#define NEUTRAL_WORDS {"okay", "fine", "normal", "average", "satisfactory"}
#define NEGATIVE_WORDS {"bad", "awful", "terrible", "poor", "disappointing"}

typedef enum {
    POSITIVE,
    NEUTRAL,
    NEGATIVE
} Sentiment;

char *get_word(char *input, int *position) {
    char *word = malloc(MAX_INPUT);
    int i = 0;
    
    if (input[(*position)] == '\0') {
        return NULL;
    }
    
    while (input[(*position)] != ' ' && input[(*position)] != '\0') {
        word[i++] = input[(*position)++];
    }
    word[i] = '\0';
    
    return word;
}

Sentiment analyze_sentiment(char *input) {
    char *positive_words[] = POSITIVE_WORDS;
    char *neutral_words[] = NEUTRAL_WORDS;
    char *negative_words[] = NEGATIVE_WORDS;
    int positive_count = sizeof(positive_words) / sizeof(char *);
    int neutral_count = sizeof(neutral_words) / sizeof(char *);
    int negative_count = sizeof(negative_words) / sizeof(char *);
    int positive_score = 0;
    int neutral_score = 0;
    int negative_score = 0;
    char *word;
    int position = 0;
    
    while ((word = get_word(input, &position)) != NULL) {
        for (int i = 0; i < positive_count; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_score++;
            }
        }
        for (int i = 0; i < neutral_count; i++) {
            if (strcmp(word, neutral_words[i]) == 0) {
                neutral_score++;
            }
        }
        for (int i = 0; i < negative_count; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                negative_score++;
            }
        }
        free(word);
    }
    
    if (positive_score > neutral_score && positive_score > negative_score) {
        return POSITIVE;
    }
    else if (neutral_score > positive_score && neutral_score > negative_score) {
        return NEUTRAL;
    }
    else {
        return NEGATIVE;
    }
}

int main() {
    char input[MAX_INPUT];
    Sentiment sentiment;
    
    printf("Enter your text to analyze: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    
    sentiment = analyze_sentiment(input);
    
    switch (sentiment) {
        case POSITIVE:
            printf("Your text has a positive sentiment.\n");
            break;
        case NEUTRAL:
            printf("Your text has a neutral sentiment.\n");
            break;
        case NEGATIVE:
            printf("Your text has a negative sentiment.\n");
            break;
    }
    
    return 0;
}