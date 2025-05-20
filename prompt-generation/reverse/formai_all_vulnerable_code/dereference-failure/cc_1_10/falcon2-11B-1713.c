//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// function to count the frequency of words in a sentence
int count_words(const char* sentence) {
    // initialize the frequency array with zeros
    int frequency[100];
    memset(frequency, 0, sizeof(frequency));

    // split the sentence into words
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        // increase the frequency count of the word
        frequency[word[0] - 'a']++;

        // get the next word
        word = strtok(NULL, " ");
    }

    return frequency;
}

// function to print the frequency of each word
void print_frequency(int frequency[]) {
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", (char)('a' + i), frequency[i]);
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // get a random sentence from a file
    FILE* file = fopen("sentences.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), file)!= NULL) {
        // count the frequency of words in the sentence
        int frequency = count_words(sentence);

        // print the frequency of each word
        print_frequency(frequency);

        // print a newline
        printf("\n");
    }

    fclose(file);

    return 0;
}