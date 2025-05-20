//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to remove '\n' character from end of string
void remove_newline(char *str) {
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

//function to convert string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

//function to calculate sentiment score for a sentence
float calculate_sentiment_score(char *sentence, char *positive_words[], int num_pos_words, char *negative_words[], int num_neg_words ) {
    //initialize score to zero
    float score = 0.0;
    
    //remove '\n' from end of sentence
    remove_newline(sentence);
    
    //convert sentence to lowercase
    to_lowercase(sentence);
    
    //split sentence into words
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        int is_positive = 0;
        int is_negative = 0;
        
        //check if word is positive or negative
        for (int i = 0; i < num_pos_words; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                is_positive = 1;
                break;
            }
        }
        
        for (int i = 0; i < num_neg_words; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                is_negative = 1;
                break;
            }
        }
        
        //update score based on word sentiment
        if (is_positive) {
            score += 1.0;
        } else if (is_negative) {
            score -= 1.0;
        }
        
        //get next word
        word = strtok(NULL, " ");
    }
    
    return score;
}

int main() {
    //positive words list
    char *positive_words[] = {"good", "great", "excellent", "fantastic", "wonderful", "amazing", "awesome", "love", "happy", "joyful"};
    int num_pos_words = 10;
    
    //negative words list
    char *negative_words[] = {"bad", "terrible", "awful", "depressing", "horrible", "disappointing", "sad", "angry", "hate", "melancholy"};
    int num_neg_words = 10;
    
    //input sentence
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    
    //calculate sentiment score
    float score = calculate_sentiment_score(sentence, positive_words, num_pos_words, negative_words, num_neg_words);
    
    //output sentiment score
    if (score > 0) {
        printf("Positive Sentiment: %.2f\n", score);
    } else if (score < 0) {
        printf("Negative Sentiment: %.2f\n", score);
    } else {
        printf("Neutral Sentiment\n");
    }
    
    return 0;
}