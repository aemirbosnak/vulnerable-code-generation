//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TOKENS 1024

typedef struct SentimentAnalysis
{
    char **tokens;
    int numTokens;
    double sentimentScore;
} SentimentAnalysis;

SentimentAnalysis *sentimentAnalysis_init(char *text)
{
    SentimentAnalysis *sa = malloc(sizeof(SentimentAnalysis));
    sa->tokens = malloc(MAX_TOKENS * sizeof(char *));
    sa->numTokens = 0;
    sa->sentimentScore = 0.0;

    sa->tokens[0] = strdup(text);
    sa->numTokens++;

    return sa;
}

void sentimentAnalysis_addToken(SentimentAnalysis *sa, char *token)
{
    sa->tokens[sa->numTokens++] = strdup(token);
}

double sentimentAnalysis_getSentimentScore(SentimentAnalysis *sa)
{
    return sa->sentimentScore;
}

void sentimentAnalysis_setSentimentScore(SentimentAnalysis *sa, double score)
{
    sa->sentimentScore = score;
}

int main()
{
    char *text = "I am happy and I am excited about this new project.";

    SentimentAnalysis *sa = sentimentAnalysis_init(text);

    sentimentAnalysis_addToken(sa, "happy");
    sentimentAnalysis_addToken(sa, "excited");
    sentimentAnalysis_addToken(sa, "new");
    sentimentAnalysis_addToken(sa, "project");

    sentimentAnalysis_setSentimentScore(sa, 8.5);

    printf("Sentiment score: %.2f\n", sentimentAnalysis_getSentimentScore(sa));

    free(sa->tokens);
    free(sa);

    return 0;
}