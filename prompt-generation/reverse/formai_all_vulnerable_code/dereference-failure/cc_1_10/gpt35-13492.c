//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float calculate_sentiment(char *text);

int main(int argc, char *argv[])
{
    char *text = argv[1];
    float sentiment = calculate_sentiment(text);

    printf("The sentiment of the text is: %.2f", sentiment);

    return 0;
}

float calculate_sentiment(char *text)
{
    int length = strlen(text);
    int positive_count = 0;
    int negative_count = 0;
    char positive_words[20][20] = {"happy", "joy", "love", "great", "amazing", "fantastic", "wonderful", "excellent", "good", "pleased", "satisfied", "delighted", "excited", "ecstatic", "superb", "awesome", "brilliant", "fabulous", "magnificent", "terrific"};
    char negative_words[20][20] = {"sad", "depressed", "hate", "horrible", "terrible", "awful", "disgusting", "horrid", "bad", "miserable", "unhappy", "upset", "disappointed", "frustrated", "angry", "annoyed", "irritated", "furious", "hurt", "offended"};

    for(int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            char current_word[20];
            int j = 0;
            while(isalpha(text[i]))
            {
                current_word[j] = tolower(text[i]);
                i++;
                j++;
            }
            current_word[j] = '\0';

            for(int k = 0; k < 20; k++)
            {
                if(strcmp(current_word, positive_words[k]) == 0)
                {
                    positive_count++;
                    break;
                }
                else if(strcmp(current_word, negative_words[k]) == 0)
                {
                    negative_count++;
                    break;
                }
            }
        }
    }

    float sentiment = (float)(positive_count - negative_count) / (positive_count + negative_count);
    return sentiment;
}