//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the number of words in a string
int word_count(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to remove punctuation marks from a string
void remove_punct(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (!ispunct(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to convert a string to lowercase
void to_lower(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[1000], summary[1000], temp[1000], *word_array[1000];
    int i = 0, j = 0, k = 0, m = 0, n = 0, word_count_input, word_count_summary;
    float match_percentage[1000], max_percentage;
    
    // Prompt user for input
    printf("Enter the text to be summarized:\n");
    fgets(input, 1000, stdin);
    
    // Calculate the number of words in the input
    word_count_input = word_count(input);
    
    // Split the input into an array of words
    char *token = strtok(input, " ");
    while (token != NULL) {
        word_array[i++] = token;
        token = strtok(NULL, " ");
    }
    
    //Prompt user for number of sentences required in summary
    printf("\nEnter the number of sentences required in the summary:\n");
    scanf("%d", &word_count_summary);
    
    // Loop through the array of words and calculate the match percentage of each sentence with respect to the input
    for (i = 0; i < word_count_input; i++) {
        j = i + 1;
        strcpy(temp, word_array[i]);
        to_lower(temp);
        remove_punct(temp);
        match_percentage[m] = 0;
        
        while (j < word_count_input && word_array[j][0] != '\n') {
            strcat(temp, " ");
            strcat(temp, word_array[j]);
            to_lower(word_array[j]);
            remove_punct(word_array[j]);
            
            // Compare the sentence with the input and calculate the matching percentage
            int match_count = 0;
            for (k = 0; k < strlen(temp); k++) {
                if (strchr(input, temp[k]) != NULL) {
                    match_count++;
                }
            }
            match_percentage[m] = (float) match_count / strlen(temp);
            j++;
            m++;
        }
    }
    
    // Find the maximum match percentage and corresponding sentence(s)
    while (n < word_count_summary) {
        max_percentage = 0;
        for (i = 0; i < m; i++) {
            if (match_percentage[i] > max_percentage) {
                max_percentage = match_percentage[i];
                j = i;
            }
        }
        strcat(summary, word_array[j]);
        strcat(summary, " ");
        n++;
        match_percentage[j] = 0;
    }
    
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}