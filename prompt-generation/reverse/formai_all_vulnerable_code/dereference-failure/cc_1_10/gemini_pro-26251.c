//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to represent an email
typedef struct email {
    char *sender;
    char *subject;
    char *body;
    int probability;
} email;

// Function to calculate the probability of an email being spam
int calculate_probability(email *email) {
    // Calculate the probability based on the sender, subject, and body of the email
    int probability = 0;

    // Check if the sender is in the spammers list
    if (strcmp(email->sender, "spammer1@example.com") == 0 || strcmp(email->sender, "spammer2@example.com") == 0) {
        probability += 50;
    }

    // Check if the subject contains any spam keywords
    if (strstr(email->subject, "free") != NULL || strstr(email->subject, "win") != NULL || strstr(email->subject, "money") != NULL) {
        probability += 25;
    }

    // Check if the body contains any spam keywords
    if (strstr(email->body, "click here") != NULL || strstr(email->body, "unsubscribe") != NULL || strstr(email->body, "viagra") != NULL) {
        probability += 25;
    }

    // Return the probability
    return probability;
}

// Function to classify an email as spam or not
int classify_email(email *email) {
    // Calculate the probability of the email being spam
    int probability = calculate_probability(email);

    // Check if the email is spam or not
    if (probability >= 50) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read an email from a file
email *read_email(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        return NULL;
    }

    // Read the email
    email *email = malloc(sizeof(email));
    email->sender = malloc(100);
    email->subject = malloc(100);
    email->body = malloc(1000);
    fscanf(file, "%s %s %s", email->sender, email->subject, email->body);

    // Close the file
    fclose(file);

    // Return the email
    return email;
}

// Function to test the spam detection system
void test_system() {
    // Read the emails from the file
    email *emails[100];
    for (int i = 0; i < 100; i++) {
        char filename[100];
        sprintf(filename, "email%d.txt", i);
        emails[i] = read_email(filename);
    }

    // Classify the emails as spam or not
    int results[100];
    for (int i = 0; i < 100; i++) {
        results[i] = classify_email(emails[i]);
    }

    // Print the results
    for (int i = 0; i < 100; i++) {
        printf("Email %d: %s\n", i, results[i] ? "spam" : "not spam");
    }
}

// Main function
int main() {
    // Test the spam detection system
    test_system();

    return 0;
}