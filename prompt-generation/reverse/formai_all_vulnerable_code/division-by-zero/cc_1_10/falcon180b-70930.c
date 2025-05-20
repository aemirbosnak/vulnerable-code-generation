//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random sentence
void generateSentence(char sentence[], int length) {
    const char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yacht", "zebra"};
    const int numWords = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sentence[i] = words[rand() % numWords][rand() % strlen(words[rand() % numWords])];
    }
    sentence[length] = '\0';
}

// Function to check if a typed sentence is correct
int checkSentence(char typed[], char correct[]) {
    int length = strlen(correct);
    if (strlen(typed)!= length) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (typed[i]!= correct[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char sentence[100];
    char typed[100];
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int wordsPerMinute = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following sentence: ");
    generateSentence(sentence, strlen(sentence));
    printf("\n");

    while (fgets(typed, sizeof(typed), stdin)) {
        total++;
        if (checkSentence(typed, sentence)) {
            correct++;
        } else {
            incorrect++;
        }
    }

    wordsPerMinute = (total - incorrect) / (5.0 * total);

    printf("\nResults:\n");
    printf("Correct sentences: %d\n", correct);
    printf("Incorrect sentences: %d\n", incorrect);
    printf("Total sentences: %d\n", total);
    printf("Words per minute: %.2f\n", wordsPerMinute);

    return 0;
}