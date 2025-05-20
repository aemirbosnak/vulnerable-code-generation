//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 1024

int sentiment_analysis(char *sentence)
{
    int positive_words_count = 0;
    int negative_words_count = 0;
    int neutral_words_count = 0;

    char *positive_words[] = {"happy", "joy", "good", "excellent", "fine", "pleasant"};
    char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful", "horrible"};
    char *neutral_words[] = {"neutral", "indifferent", "unaffected", "okay", "meh"};

    for (int i = 0; i < MAX_SENTENCE_LENGTH; i++)
    {
        if (sentence[i] == '\0')
        {
            break;
        }

        for (int j = 0; j < 6; j++)
        {
            if (strcmp(sentence + i, positive_words[j]) == 0)
            {
                positive_words_count++;
            }
            else if (strcmp(sentence + i, negative_words[j]) == 0)
            {
                negative_words_count++;
            }
            else if (strcmp(sentence + i, neutral_words[j]) == 0)
            {
                neutral_words_count++;
            }
        }
    }

    int sentiment_score = (positive_words_count - negative_words_count) * 100 / (positive_words_count + negative_words_count + neutral_words_count);

    return sentiment_score;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH] = "I am happy today.";

    int sentiment_score = sentiment_analysis(sentence);

    printf("Sentiment score: %d%%", sentiment_score);

    return 0;
}