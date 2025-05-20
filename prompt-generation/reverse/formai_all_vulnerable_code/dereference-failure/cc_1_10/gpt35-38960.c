//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 0.8    // Spam threshold value
#define HISTORY_SIZE 10       // Size of the history buffer

// Spam detection function
float spam_detect(char* msg, char history[][100], int size) {
    int i, count = 0;
    float spam_score = 0.0;

    // Check for similarity with the history
    for (i = 0; i < size; i++) {
        char* hmsg = history[i];
        if (strcmp(msg, hmsg) == 0) {
            spam_score += 0.5;
            count++;
            continue;
        }

        // Check for common words
        char word[100];
        char* saveptr;
        char* token = strtok_r(hmsg, " .,!?", &saveptr);
        while (token != NULL) {
            if (strstr(msg, token) != NULL) {
                spam_score += 0.1;
                count++;
            }
            token = strtok_r(NULL, " .,!?", &saveptr);
        }

        // Check for similarity percentage
        char* longer, * shorter;
        if (strlen(msg) > strlen(hmsg)) {
            longer = msg;
            shorter = hmsg;
        } else {
            longer = hmsg;
            shorter = msg;
        }
        int common_len = strlen(longer) - strspn(longer, shorter);
        int percentage = (common_len * 100) / strlen(longer);
        if (percentage >= 50) {
            spam_score += 0.4;
            count++;
        }
    }

    // Update the history buffer
    memmove(history[1], history[0], (size - 1) * sizeof(*history));
    strcpy(history[0], msg);

    // Calculate the spam probability
    if (count > 0) {
        spam_score /= count;
    }
    return spam_score;
}

int main() {
    int i;
    char history[HISTORY_SIZE][100];
    memset(history, 0, sizeof(history));

    // Test with some messages
    char* messages[] = {
        "Hello World!",
        "I am a Nigerian prince",
        "You have won a lottery",
        "Viagra, Cialis, and more!",
        "Hi there!",
        "Hey, this is a great deal!",
        "How are you?",
        "Hi, can you help me?",
        "Your account has been compromised",
        "Buy this product now!"
    };

    int n_messages = sizeof(messages) / sizeof(messages[0]);
    for (i = 0; i < n_messages; i++) {
        float score = spam_detect(messages[i], history, HISTORY_SIZE);
        printf("Message: %s | Score: %.2f | Spam: %s\n", messages[i], score, score > SPAM_THRESHOLD ? "Yes" : "No");
    }

    return 0;
}