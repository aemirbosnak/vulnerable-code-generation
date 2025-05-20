//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define NUM_FILTERS 10

// Email filter structures
typedef struct {
    char keyword[10];
    int threshold;
} Filter;

Filter filters[NUM_FILTERS] = {
    {"love", 5},
    {"money", 3},
    {"free", 4},
    {"viagra", 1},
    {"prize", 2},
    {"lottery", 2},
    {"win", 2},
    {"offer", 2},
    {"sweepstakes", 2},
    {"sex", 1}
};

void process_email(char email[MAX_EMAIL_LENGTH]) {
    int email_length = strlen(email);
    int spam_score = 0;

    // Process the email word by word
    for (int i = 0; i < email_length; i++) {
        // Increment spam score for each filter match
        for (int j = 0; j < NUM_FILTERS; j++) {
            int filter_length = strlen(filters[j].keyword);
            if (i + filter_length <= email_length && strncmp(email + i, filters[j].keyword, filter_length) == 0) {
                if (tolower(email[i - 1]) != ' ') {
                    spam_score += filters[j].threshold;
                    break;
                }
            }
        }
    }

    // Print email with spam score
    printf("Email: %s\n", email);
    printf("Spam Score: %d\n", spam_score);

    // Mark email as spam if score exceeds threshold
    if (spam_score > 10) {
        printf("This email is SPAM.\n");
    } else {
        printf("This email is NOT SPAM.\n");
    }
}

int main() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter your email:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    process_email(email);

    return 0;
}