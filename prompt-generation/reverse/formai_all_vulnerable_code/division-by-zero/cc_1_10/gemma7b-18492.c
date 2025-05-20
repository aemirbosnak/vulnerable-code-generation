//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    int i, sentiment_score = 0, positive_words = 0, negative_words = 0;
    FILE *fp;

    // Open the sentiment analysis dictionary file
    fp = fopen("sentiment_analysis_dictionary.txt", "r");

    // Read the user input
    printf("Enter a text: ");
    fgets(str, 1000, stdin);

    // Tokenize the user input
    char *token = strtok(str, " ");

    // Iterate over the tokens
    while (token)
    {
        // Check if the token is in the sentiment analysis dictionary
        if (fp)
        {
            while (fscanf(fp, "%s", token) != EOF)
            {
                if (strcmp(token, token) == 0)
                {
                    // Increment the sentiment score
                    sentiment_score++;

                    // Increment the positive words count if the token is positive
                    if (strcmp(token, "positive") == 0)
                        positive_words++;

                    // Increment the negative words count if the token is negative
                    if (strcmp(token, "negative") == 0)
                        negative_words++;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    // Close the sentiment analysis dictionary file
    fclose(fp);

    // Calculate the sentiment score percentage
    int sentiment_score_percentage = (sentiment_score * 100) / (positive_words + negative_words);

    // Print the sentiment score
    printf("The sentiment score is: %d%%", sentiment_score_percentage);

    return 0;
}