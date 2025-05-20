//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_EMAIL_SIZE 256
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 10

// Struct to hold email data
typedef struct {
    char email[MAX_EMAIL_SIZE];
    int spam_score;
} Email;

// Struct to hold word data
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} Word;

// Global variables
Email emails[100];
Word words[MAX_WORDS] = {{"viagra", 10}, {"credit", 8}, {"money", 7}, {"free", 6}, {"prize", 5}, {"offer", 4}, {"win", 3}, {"buy", 2}, {"click", 1}, {"order", 1}};
int num_emails = 0;
int num_words = 0;
int num_scanned = 0;
int email_file;

// Function to read email file
void read_emails() {
    char filename[MAX_EMAIL_SIZE] = "emails.txt";
    int i = 0;
    char line[MAX_EMAIL_SIZE];

    email_file = open(filename, O_RDONLY);

    if (email_file < 0) {
        printf("Error opening email file!\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_EMAIL_SIZE, email_file) != NULL) {
        strcpy(emails[i].email, line);
        num_emails++;
        i++;

        if (i == 100) {
            break;
        }
    }

    close(email_file);
}

// Function to detect spam
int detect_spam(char *email) {
    int i, j, word_count = 0, score = 0;
    char *token;
    char line_copy[MAX_EMAIL_SIZE];

    strcpy(line_copy, email);

    token = strtok(line_copy, " ");

    while (token != NULL) {
        for (i = 0; i < num_words; i++) {
            if (strstr(token, words[i].word) != NULL) {
                score += words[i].score;
                word_count++;
            }
        }

        token = strtok(NULL, " ");
    }

    if (word_count > 5) {
        score += 5;
    }

    return score;
}

// Function to process emails and print results
void process_emails() {
    int i;
    Email current_email;

    for (i = 0; i < num_emails && num_scanned < 10; i++) {
        strcpy(current_email.email, emails[i].email);
        current_email.spam_score = detect_spam(current_email.email);

        printf("Email %d: %s\n", num_scanned + 1, current_email.email);
        printf("Spam score: %d\n", current_email.spam_score);

        if (current_email.spam_score > 10) {
            printf("SPAM DETECTED! 🚫\n");
        } else {
            printf("This email is safe! 🔒\n");
        }

        num_scanned++;
    }
}

int main() {
    read_emails();
    process_emails();

    return 0;
}

// The end