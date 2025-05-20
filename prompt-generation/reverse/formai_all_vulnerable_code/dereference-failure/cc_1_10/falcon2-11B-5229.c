//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *email;
    bool is_spam;
} Email;

int main(int argc, char *argv[]) {
    // Create a vector to store email data
    Email emails[100];

    // Get the number of emails
    int num_emails;
    scanf("%d", &num_emails);

    // Read email data from the user
    for (int i = 0; i < num_emails; i++) {
        char email[100];
        scanf("%s", email);
        emails[i].email = email;
    }

    // Sort the emails based on their length
    for (int i = 0; i < num_emails - 1; i++) {
        for (int j = 0; j < num_emails - i - 1; j++) {
            if (strlen(emails[j].email) > strlen(emails[j + 1].email)) {
                Email temp = emails[j];
                emails[j] = emails[j + 1];
                emails[j + 1] = temp;
            }
        }
    }

    // Calculate the average length of the emails
    int sum = 0;
    for (int i = 0; i < num_emails; i++) {
        sum += strlen(emails[i].email);
    }
    float avg_length = (float)sum / num_emails;

    // Check if the emails are spam
    bool is_spam = false;
    for (int i = 0; i < num_emails; i++) {
        if (strlen(emails[i].email) > avg_length * 1.5) {
            is_spam = true;
            break;
        }
    }

    // Print the results
    for (int i = 0; i < num_emails; i++) {
        if (emails[i].is_spam) {
            printf("Email %d is spam\n", i + 1);
        } else {
            printf("Email %d is not spam\n", i + 1);
        }
    }

    return 0;
}