//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

//Function to get a substring from a given string
void substring(char s[], int start, int end, char result[]) {
    int j = 0;
    for (int i = start; i < end; i++) {
        result[j++] = s[i];
    }
    result[j] = '\0';
}

int main() {
    char input_string[100], sub_string[50];
    long long int count = 0;
  
    //User input
    printf("Enter a sentence: ");
    fgets(input_string, 100, stdin);
  
    //Count the number of words in the sentence
    for (int i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == ' ') {
            count++;
        }
    }
    count++; //Add one to include the last word
  
    //Get the first word in the sentence
    substring(input_string, 0, strchr(input_string, ' ') - input_string, sub_string);
    printf("First word: %s\n", sub_string);
  
    //Get the last word in the sentence
    substring(input_string, strlen(input_string) - strlen(strrchr(input_string, ' ')) + 1, strlen(input_string), sub_string);
    printf("Last word: %s\n", sub_string);
  
    //Get the middle word(s) in the sentence
    printf("Middle word(s): ");
    if (count > 2) { //If there are more than two words
        int start = strlen(sub_string) + 2; //Start after the first word and space
        for (int i = 2; i < count; i++) { //Loop through all the middle words
            substring(input_string, start, strchr(input_string + start, ' ') - input_string, sub_string); //Get the word
            printf("%s ", sub_string); //Print the word
            start += strlen(sub_string) + 1; //Update the starting index
        }
    }
    printf("\n");
  
    return 0;
}