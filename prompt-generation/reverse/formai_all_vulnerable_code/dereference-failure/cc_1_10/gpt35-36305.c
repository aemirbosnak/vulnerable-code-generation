//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform sentiment analysis */
void sentiment_analysis(char **sentences, int num_sentences)
{
    int positive_count = 0, negative_count = 0, neutral_count = 0;

    /* List of positive and negative words*/
    char positive_words[20][20] = {"good", "great", "excellent", "amazing", "fantastic", "outstanding", "superb", "wonderful", "happy", "love", "like", "joy", "success", "win", "positive", "beneficial", "perfect", "admirable", "commendable", "splendid"};

    char negative_words[20][20] = {"bad", "poor", "terrible", "awful", "horrible", "lousy", "disgusting", "hate", "pain", "sorrow", "failure", "lose", "negative", "harmful", "imperfect", "abominable", "deplorable", "reprehensible", "substandard"};

    for (int i = 0; i < num_sentences; i++)
    {
        /* Split the sentence into words */
        char *word;
        word = strtok(sentences[i], " ");

        /* Check if each word is positive or negative */
        while (word != NULL)
        {
            for (int j = 0; j < 20; j++)
            {
                if (strcmp(word, positive_words[j]) == 0)
                {
                    positive_count++;
                }
                else if (strcmp(word, negative_words[j]) == 0)
                {
                    negative_count++;
                }
            }
            word = strtok(NULL, " ");
        }

        /* Determine the sentiment of the sentence */
        if (positive_count > negative_count)
        {
            printf("Positive Sentiment\n");
        }
        else if (negative_count > positive_count)
        {
            printf("Negative Sentiment\n");
        }
        else
        {
            printf("Neutral Sentiment\n");
        }

        positive_count = 0;
        negative_count = 0;
    }
}

int main()
{
    int num_sentences;

    printf("Enter number of sentences: ");
    scanf("%d", &num_sentences);

    /* Allocate memory for the sentences */
    char **sentences = (char **)malloc(num_sentences * sizeof(char *));

    printf("Enter the sentences: \n");
    /* Read in the sentences */
    for (int i = 0; i < num_sentences; i++)
    {
        sentences[i] = (char *)malloc(100 * sizeof(char));
        scanf(" %[^\n]s", sentences[i]); // Reading in the entire line as a string
    }

    /* Perform sentiment analysis */
    sentiment_analysis(sentences, num_sentences);

    /* Free the memory */
    for (int i = 0; i < num_sentences; i++)
    {
        free(sentences[i]);
    }
    free(sentences);

    return 0;
}