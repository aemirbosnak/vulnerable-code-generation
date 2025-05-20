//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 1000
#define SPAM_THRESHOLD 0.7

/* This is a spam detection system program written in C language using basic machine learning algorithms */

// Structure to store the data for each message
typedef struct Message {
    int is_spam;
    char text[MAX_INPUT];
} Message;

// Function to train the spam detection system by computing the probability of a word appearing in a spam message
void train_spam_detection_system(char* training_data_filename, double* spam_probabilities, double* non_spam_probabilities) {
    int num_spam_messages = 0, num_non_spam_messages = 0, num_spam_words = 0, num_non_spam_words = 0;
    char line[MAX_INPUT], *word;
    Message messages[MAX_INPUT];
    FILE *file = fopen(training_data_filename, "r");

    // Read all the messages from the file and store them in an array of Message structures
    while (fgets(line, MAX_INPUT, file) != NULL) {
        word = strtok(line, " \n\t");
        messages[num_spam_messages + num_non_spam_messages].is_spam = atoi(word);
        strcpy(messages[num_spam_messages + num_non_spam_messages].text, "");
        while (word != NULL) {
            strcat(messages[num_spam_messages + num_non_spam_messages].text, word);
            strcat(messages[num_spam_messages + num_non_spam_messages].text, " ");
            if (messages[num_spam_messages + num_non_spam_messages].is_spam == 1)
                num_spam_words++;
            else
                num_non_spam_words++;
            word = strtok(NULL, " \n\t");
        }
        if (messages[num_spam_messages + num_non_spam_messages].is_spam == 1)
            num_spam_messages++;
        else
            num_non_spam_messages++;
    }
    fclose(file);

    // Compute the probability of each word appearing in a spam and non-spam message
    char* words = (char*)malloc((num_spam_words + num_non_spam_words) * MAX_INPUT); // allocate memory for all the words in all the messages
    int word_index = 0, i, j;
    for (i = 0; i < num_spam_messages + num_non_spam_messages; i++) {
        word = strtok(messages[i].text, " \n\t");
        while (word != NULL) {
            strcpy(&words[word_index * MAX_INPUT], word);
            word_index++;
            word = strtok(NULL, " \n\t");
        }
    }
    int num_words = word_index;
    spam_probabilities = (double*)malloc(num_words * sizeof(double));
    non_spam_probabilities = (double*)malloc(num_words * sizeof(double));
    for (i = 0; i < num_words; i++) {
        spam_probabilities[i] = 0.0; // initialize the probabilities to zero
        non_spam_probabilities[i] = 0.0;
        for (j = 0; j < num_spam_messages + num_non_spam_messages; j++) {
            word = strtok(messages[j].text, " \n\t");
            while (word != NULL) {
                if (strcmp(&words[i * MAX_INPUT], word) == 0) { // if the word matches
                    if (messages[j].is_spam == 1)
                        spam_probabilities[i] += 1.0;
                    else
                        non_spam_probabilities[i] += 1.0;
                }
                word = strtok(NULL, " \n\t");
            }
        }
        spam_probabilities[i] /= num_spam_words; // compute the percentage of spam messages that contain the word
        non_spam_probabilities[i] /= num_non_spam_words; // compute the percentage of non-spam messages that contain the word
    }
    free(words); // free the memory allocated for the words
}

// Function to detect spam in a message by computing the product of the probabilities of each word appearing in a spam or non-spam message
// and comparing the result to a threshold value
int is_spam(char* message, double* spam_probabilities, double* non_spam_probabilities) {
    char* word;
    double product = 1.0;
    int num_words = 0;
    word = strtok(message, " \n\t");
    while (word != NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(&message[i * MAX_INPUT], word) == 0) { // if the word has already been counted, skip it
                word = strtok(NULL, " \n\t");
                break;
            }
        }
        if (i < num_words)
            continue;
        num_words++;
        for (i = 0; i < num_words; i++) {
            if (strcmp(&message[i * MAX_INPUT], word) == 0) // if the word has already been counted, skip it
                break;
        }
        if (i >= num_words) { // if the word has not been counted yet, compute its probabilities
            for (i = 0; i < num_words; i++) {
                if (spam_probabilities[i] > 0.0 && non_spam_probabilities[i] > 0.0) { // if both probabilities are zero, skip the word
                    if (strcmp(&message[i * MAX_INPUT], word) == 0) // if the word matches
                        product *= spam_probabilities[i] / non_spam_probabilities[i]; // compute the product of probabilities
                }
            }
            word = strtok(NULL, " \n\t");
        }
    }
    return (product >= SPAM_THRESHOLD); // return true if the product is greater than or equal to the spam threshold
}

int main() {
    double* spam_probabilities, *non_spam_probabilities;
    char message[MAX_INPUT];
    printf("Enter the filename containing the training data: ");
    fgets(message, MAX_INPUT, stdin);
    message[strlen(message) - 1] = '\0';
    train_spam_detection_system(message, spam_probabilities, non_spam_probabilities);
    printf("Enter a message to check for spam: ");
    fgets(message, MAX_INPUT, stdin);
    message[strlen(message) - 1] = '\0';
    if (is_spam(message, spam_probabilities, non_spam_probabilities))
        printf("The message is spam\n");
    else
        printf("The message is not spam\n");
    free(spam_probabilities);
    free(non_spam_probabilities);
    return 0;
}