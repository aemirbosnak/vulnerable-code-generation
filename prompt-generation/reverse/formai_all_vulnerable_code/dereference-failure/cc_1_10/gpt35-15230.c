//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_CHARS 1000 
#define MAX_WORDS 100 

void get_input(char* str); 
int count_words(char* str); 
int analyze_sentiment(char* str[], int n); 

int main() 
{ 
    char str[MAX_CHARS]; 
    char* words[MAX_WORDS]; 
    
    get_input(str); 
    
    int num_words = count_words(str); 
    
    // Tokenize the string
    char* token = strtok(str, " "); 
    int i = 0;
    while (token != NULL && i < num_words) 
    { 
        words[i++] = token; 
        token = strtok(NULL, " "); 
    } 
    
    int sentiment = analyze_sentiment(words, num_words); 
    
    printf("Sentiment Analysis:\n"); 
    if(sentiment > 0) 
    { 
        printf("Positive\n"); 
    } 
    else if(sentiment < 0) 
    { 
        printf("Negative\n"); 
    } 
    else 
    { 
        printf("Neutral\n"); 
    } 
    
    return 0; 
} 

void get_input(char* str) 
{ 
    printf("Enter text to analyze:\n"); 
    fgets(str, MAX_CHARS, stdin); 
    
    // Remove '\n' from end of string
    str[strcspn(str, "\n")] = 0;
} 

int count_words(char* str) 
{ 
    int count = 0; 
    
    // Count number of words in string
    for(int i = 0; i < strlen(str); i++) 
    { 
        if(str[i] == ' ') 
        { 
            count++; 
        } 
    } 
    
    // Add one for the last word
    count++; 
    
    return count; 
} 

int analyze_sentiment(char* str[], int n) 
{ 
    int score = 0; 
    
    // Add points for positive words
    char* positive_words[] = {"great", "excellent", "amazing", "awesome", "fantastic", "love", "like", "happy", "good", "positive"}; 
    int num_positive_words = sizeof(positive_words) / sizeof(positive_words[0]); 
    
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < num_positive_words; j++) 
        { 
            if(strcmp(str[i], positive_words[j]) == 0) 
            { 
                score++; 
            } 
        } 
    } 
    
    // Subtract points for negative words 
    char* negative_words[] = {"terrible", "awful", "poor", "bad", "negative", "hate", "dislike", "sad", "unhappy", "disappointed"}; 
    int num_negative_words = sizeof(negative_words) / sizeof(negative_words[0]); 
    
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < num_negative_words; j++) 
        { 
            if(strcmp(str[i], negative_words[j]) == 0) 
            { 
                score--; 
            } 
        } 
    } 
    
    return score; 
}