//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spam_detection_system {
    char *rules[100];
    int num_rules;
} spam_detection_system_t;

int main() {
    // Create a new spam detection system
    spam_detection_system_t *sds = malloc(sizeof(spam_detection_system_t));
    sds->num_rules = 0;

    // Add some rules to the spam detection system
    sds->rules[sds->num_rules++] = "Viagra";
    sds->rules[sds->num_rules++] = "Cialis";
    sds->rules[sds->num_rules++] = "Levitra";
    sds->rules[sds->num_rules++] = "Free";
    sds->rules[sds->num_rules++] = "Money";
    sds->rules[sds->num_rules++] = "Click here";
    sds->rules[sds->num_rules++] = "Dear friend";
    sds->rules[sds->num_rules++] = "You won";
    sds->rules[sds->num_rules++] = "Congratulations";

    // Get the email from the user
    char *email = malloc(1024);
    printf("Enter the email: ");
    gets(email);

    // Check if the email is spam
    int is_spam = 0;
    for (int i = 0; i < sds->num_rules; i++) {
        if (strstr(email, sds->rules[i]) != NULL) {
            is_spam = 1;
            break;
        }
    }

    // Print the result
    if (is_spam) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    // Free the memory allocated for the email
    free(email);

    // Free the memory allocated for the spam detection system
    free(sds);

    return 0;
}