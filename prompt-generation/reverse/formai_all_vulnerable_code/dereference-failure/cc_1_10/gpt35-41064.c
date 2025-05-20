//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5 // threshold above which a message is classified as spam

int main(int argc, char **argv) {
    int num_messages = atoi(argv[1]); // number of messages to analyze
    double spam_count = 0; // count of messages classified as spam
    char *messages[num_messages]; // array to store the messages

    // read in the messages from command line arguments
    for (int i = 0; i < num_messages; i++) {
        messages[i] = argv[i+2];
    }

    // analyze each message to determine if it is spam
    for (int i = 0; i < num_messages; i++) {
        char *message = messages[i];
        int length = strlen(message);
        int num_words = 0;
        int num_spam_words = 0;

        // count the number of words and spam words in the message
        for (int j = 0; j < length; j++) {
            if (message[j] == ' ') {
                num_words++;
            }
            if (strstr(&message[j], "make money fast") == &message[j]) {
                num_spam_words++;
            } else if (strstr(&message[j], "buy now") == &message[j]) {
                num_spam_words++;
            }
        }

        // calculate the spam score for the message
        double spam_score = (double)num_spam_words / (double)num_words;

        // if the spam score exceeds the threshold, classify the message as spam
        if (spam_score > SPAM_THRESHOLD) {
            spam_count++;
            printf("Message %d is spam with a spam score of %f\n", i+1, spam_score);
        } else {
            printf("Message %d is not spam with a spam score of %f\n", i+1, spam_score);
        }
    }

    // print out the spam statistics
    double spam_percentage = (spam_count / num_messages) * 100;
    printf("\n%d out of %d messages (%f%%) were classified as spam.\n\n", (int)spam_count, num_messages, spam_percentage);

    return 0;
}