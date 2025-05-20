//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

char **tokenize(char *text) {
    char **tokens = NULL;
    int numTokens = 0;
    char *token = NULL;
    char *p = text;

    while (p) {
        token = strchr(p, ' ');
        if (token) {
            tokens = realloc(tokens, (numTokens + 1) * sizeof(char *));
            tokens[numTokens++] = strdup(p);
            p = token + 1;
        } else {
            tokens = realloc(tokens, (numTokens + 1) * sizeof(char *));
            tokens[numTokens++] = strdup(p);
            p = NULL;
        }
    }

    return tokens;
}

int sentiment_analysis(char *text) {
    char **tokens = tokenize(text);
    int sentiment = 0;
    int i = 0;

    for (i = 0; tokens[i] != NULL; i++) {
        if (tokens[i][0] == 'n' || tokens[i][0] == 'p' || tokens[i][0] == 'a') {
            sentiment++;
        } else if (tokens[i][0] == 'h' || tokens[i][0] == 'o' || tokens[i][0] == 's') {
            sentiment--;
        }
    }

    free(tokens);
    return sentiment;
}

int main() {
    char text[] = "I am happy today. I am very excited about the future.";
    int sentiment = sentiment_analysis(text);

    if (sentiment > 0) {
        printf("The text is positive.\n");
    } else if (sentiment < 0) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }

    return 0;
}