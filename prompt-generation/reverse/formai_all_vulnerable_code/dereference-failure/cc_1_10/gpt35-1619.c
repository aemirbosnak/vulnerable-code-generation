//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LEN 1000
#define MAX_WORD_LEN 20

char *words[] = {
    "government", 
    "aliens", 
    "Illuminati", 
    "Freemasons", 
    "New World Order", 
    "Big Pharma", 
    "Chemtrails", 
    "HAARP", 
    "secret societies", 
    "fake moon landing"
}; //add your own words here

char *generate_conspiracy_theory() {
    char *conspiracy_theory = malloc(MAX_CONSPIRACY_LEN * sizeof(char));
    int word_count = rand()%10 + 3; //generate word count between 3 and 12
    int i, j, k;

    //Randomly pick words and concatenate them into a conspiracy theory
    for(i = 0; i < word_count; i++) {
        int word_len = rand()%MAX_WORD_LEN + 1; //generate word length between 1 and 20
        char *word = malloc(word_len * sizeof(char));
        for(j = 0; j < word_len-1; j++) {
            word[j] = 'a' + rand()%26; //generate a random lowercase letter
        }
        word[word_len-1] = ' '; //add a space after each word
        for(k = 0; k < word_len; k++) {
            conspiracy_theory[i*MAX_WORD_LEN + k] = word[k]; //copy the word into the conspiracy theory string
        }
    }

    conspiracy_theory[MAX_CONSPIRACY_LEN-1] = '\0'; //add null terminator to the end of string
    return conspiracy_theory;
}

int main() {
    srand(time(NULL)); //set random seed using time

    printf("Here are five random conspiracy theories:\n");

    int i;
    for(i = 0; i < 5; i++) {
        char *conspiracy_theory = generate_conspiracy_theory();
        printf("%d) The %s are using %s to control the %s and %s.\n", i+1, words[rand()%10], conspiracy_theory, words[rand()%10], words[rand()%10]);
        free(conspiracy_theory); //free the dynamically allocated memory
    }

    return 0;
}