//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a spam message.
#define MAX_SPAM_SIZE 1024

// Define the number of different Bayesian classifiers.
#define NUM_CLASSIFIERS 3

// Define the probability thresholds for each classifier.
#define P_SPAM_THRESHOLD 0.7
#define P_HAM_THRESHOLD 0.3

// Define the training data.
char *training_data[] = {
    "This is a spam message.",
    "This is a ham message.",
    "This is another spam message.",
    "This is another ham message.",
    "This is a spam message with some ham words.",
    "This is a ham message with some spam words."
};

// Define the number of training data.
#define NUM_TRAINING_DATA 6

// Define the vocabulary.
char *vocabulary[] = {
    "this",
    "is",
    "a",
    "spam",
    "message",
    "ham",
    "with",
    "some",
    "words"
};

// Define the number of words in the vocabulary.
#define NUM_WORDS 9

// Define the Bayesian classifiers.
typedef struct {
    double p_spam;
    double p_ham;
    double p_words[NUM_WORDS];
} BayesianClassifier;

BayesianClassifier classifiers[NUM_CLASSIFIERS] = {
    {0.5, 0.5, {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}},
    {0.7, 0.3, {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2}},
    {0.9, 0.1, {0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3}}
};

// Train the Bayesian classifiers.
void train_classifiers() {
    for (int i = 0; i < NUM_CLASSIFIERS; i++) {
        for (int j = 0; j < NUM_TRAINING_DATA; j++) {
            char *message = training_data[j];
            int is_spam = (j % 2 == 0);

            // Tokenize the message.
            char *tokens[MAX_SPAM_SIZE];
            int num_tokens = 0;
            char *token = strtok(message, " ");
            while (token != NULL) {
                tokens[num_tokens++] = token;
                token = strtok(NULL, " ");
            }

            // Update the probabilities.
            for (int k = 0; k < NUM_WORDS; k++) {
                char *word = vocabulary[k];
                int is_in_message = 0;

                // Check if the word is in the message.
                for (int l = 0; l < num_tokens; l++) {
                    if (strcmp(tokens[l], word) == 0) {
                        is_in_message = 1;
                        break;
                    }
                }

                // Update the probabilities.
                if (is_in_message) {
                    classifiers[i].p_words[k] += (is_spam ? classifiers[i].p_spam : classifiers[i].p_ham);
                } else {
                    classifiers[i].p_words[k] += (is_spam ? (1 - classifiers[i].p_spam) : (1 - classifiers[i].p_ham));
                }
            }
        }
    }
}

// Classify a message.
int classify_message(char *message) {
    // Tokenize the message.
    char *tokens[MAX_SPAM_SIZE];
    int num_tokens = 0;
    char *token = strtok(message, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Compute the probabilities for each classifier.
    double p_spam[NUM_CLASSIFIERS];
    double p_ham[NUM_CLASSIFIERS];
    for (int i = 0; i < NUM_CLASSIFIERS; i++) {
        p_spam[i] = classifiers[i].p_spam;
        p_ham[i] = classifiers[i].p_ham;

        for (int j = 0; j < num_tokens; j++) {
            char *word = tokens[j];

            // Find the index of the word in the vocabulary.
            int index = -1;
            for (int k = 0; k < NUM_WORDS; k++) {
                if (strcmp(vocabulary[k], word) == 0) {
                    index = k;
                    break;
                }
            }

            // If the word is in the vocabulary, update the probabilities.
            if (index != -1) {
                p_spam[i] *= classifiers[i].p_words[index];
                p_ham[i] *= (1 - classifiers[i].p_words[index]);
            }
        }
    }

    // Determine the most likely class.
    int most_likely_class = -1;
    double max_probability = -1;
    for (int i = 0; i < NUM_CLASSIFIERS; i++) {
        double probability = p_spam[i] / (p_spam[i] + p_ham[i]);
        if (probability > max_probability) {
            most_likely_class = i;
            max_probability = probability;
        }
    }

    // Return the most likely class.
    return most_likely_class;
}

// Test the spam detection system.
void test_system() {
    // Load the test data.
    char *test_data[] = {
        "This is a spam message.",
        "This is a ham message.",
        "This is another spam message.",
        "This is another ham message.",
        "This is a spam message with some ham words.",
        "This is a ham message with some spam words."
    };

    // Test the spam detection system.
    int num_correct = 0;
    int num_incorrect = 0;
    for (int i = 0; i < NUM_TRAINING_DATA; i++) {
        char *message = test_data[i];
        int is_spam = (i % 2 == 0);
        int predicted_class = classify_message(message);

        if (predicted_class == (is_spam ? 0 : 1)) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    // Print the results.
    printf("Number of correct classifications: %d\n", num_correct);
    printf("Number of incorrect classifications: %d\n", num_incorrect);
}

// Main function.
int main() {
    // Train the Bayesian classifiers.
    train_classifiers();

    // Test the spam detection system.
    test_system();

    return 0;
}