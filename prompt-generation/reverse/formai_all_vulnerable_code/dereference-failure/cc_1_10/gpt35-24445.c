//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1000

// Struct for each sentence in the summarized text
typedef struct Sentence {
    char sentence[MAX_STR_SIZE];
    int frequency;
    struct Sentence *next;
} Sentence;

// Function to add a new sentence to the linked list of sentences
void addSentenceToList(Sentence **head, char *sentence) {
    if (*head == NULL) {
        Sentence *newSentence = (Sentence *)malloc(sizeof(Sentence));
        strcpy(newSentence->sentence, sentence);
        newSentence->frequency = 1;
        newSentence->next = NULL;
        *head = newSentence;
    } else {
        Sentence *current = *head;
        while (current != NULL) {
            if (strcmp(current->sentence, sentence) == 0) {
                current->frequency++;
                return;
            }
            current = current->next;
        }
        Sentence *newSentence = (Sentence *)malloc(sizeof(Sentence));
        strcpy(newSentence->sentence, sentence);
        newSentence->frequency = 1;
        newSentence->next = *head;
        *head = newSentence;
    }
}

// Function to print the sentence list
void printSentences(Sentence *head) {
    while (head != NULL) {
        printf("%s\n", head->sentence);
        head = head->next;
    }
}

// Main function that performs the summarization
int main() {
    // Read the input string from the user
    char input[MAX_STR_SIZE], sentence[MAX_STR_SIZE];
    printf("Enter the original text:\n");
    fgets(input, MAX_STR_SIZE, stdin);

    // Break the input into separate sentences and store them in a linked list
    Sentence *sentenceList = NULL;
    int inputLen = strlen(input);
    int sentenceLen = 0;
    for (int i = 0; i < inputLen; i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentence[sentenceLen++] = input[i];
            sentence[sentenceLen] = '\0';
            addSentenceToList(&sentenceList, sentence);
            sentenceLen = 0;
        } else {
            sentence[sentenceLen++] = input[i];
        }
    }

    // Print the list of sentences
    printf("List of sentences in the original text:\n");
    printSentences(sentenceList);

    // Perform the summarization by selecting the top 3 most frequent sentences
    Sentence *mostFrequent[3] = {NULL, NULL, NULL};
    Sentence *current = sentenceList;
    while (current != NULL) {
        if (mostFrequent[0] == NULL || current->frequency > mostFrequent[0]->frequency) {
            mostFrequent[2] = mostFrequent[1];
            mostFrequent[1] = mostFrequent[0];
            mostFrequent[0] = current;
        } else if (mostFrequent[1] == NULL || current->frequency > mostFrequent[1]->frequency) {
            mostFrequent[2] = mostFrequent[1];
            mostFrequent[1] = current;
        } else if (mostFrequent[2] == NULL || current->frequency > mostFrequent[2]->frequency) {
            mostFrequent[2] = current;
        }
        current = current->next;
    }

    // Print the list of most frequent sentences
    printf("List of most frequent sentences in the original text:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", mostFrequent[i]->sentence);
    }

    return 0;
}