//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int sentiment_analysis(char *input_text){
    int pos_count = 0, neg_count = 0, pos_len = 0, neg_len = 0;
 
    char *pos_words[10] = {"happy", "excited", "amazing", "great", "love", "wonderful", "awesome", "fantastic", "pleased", "joyful"};
    char *neg_words[10] = {"sad", "angry", "hate", "disgusted", "regretful", "disappointed", "depressed", "frustrated", "annoyed", "miserable"};
    
    char *temp = (char*)malloc(strlen(input_text)+1);
    strcpy(temp, input_text);

    char *token = strtok(temp, " ");
    while( token != NULL ) {
        for(int i=0;i<10;i++)
        {
            if(strcmp(token, pos_words[i]) == 0)
            {
                pos_count++;
                pos_len+=strlen(token);
            }
            else if(strcmp(token, neg_words[i]) == 0)
            {
                neg_count++;
                neg_len+=strlen(token);
            }
        }
        token = strtok(NULL, " ");
    }
    int pos_avg_len = pos_len/pos_count;
    int neg_avg_len = neg_len/neg_count;

    if(pos_count > neg_count){
        if(pos_avg_len > neg_avg_len) return 1;
        else return 0;
    }
    else if(neg_count > pos_count){
        if(neg_avg_len > pos_avg_len) return -1;
        else return 0;
    }
    else return 0;
}

int main(){
    char input_text[1000];
    printf("Enter the text for sentiment analysis:\n");
    fgets(input_text, 1000, stdin);

    int sentiment = sentiment_analysis(input_text);

    if(sentiment == 1)
        printf("Positive Sentiment Detected\n");
    if(sentiment == 0)
        printf("Neutral Sentiment Detected\n");
    if(sentiment == -1)
        printf("Negative Sentiment Detected\n");

    return 0;
}