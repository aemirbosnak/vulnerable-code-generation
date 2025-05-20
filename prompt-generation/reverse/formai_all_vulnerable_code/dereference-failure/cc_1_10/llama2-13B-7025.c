//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum size of the email message
#define MAX_MESSAGE_SIZE 1000

// Define the structure to store the email message
typedef struct {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
    int size;
} email_t;

// Function to parse the email message from the input stream
email_t* parse_email(FILE* stream) {
    // Define the email message structure
    email_t* email = malloc(sizeof(email_t));

    // Read the sender name
    fscanf(stream, "%s", email->sender);

    // Read the recipient name
    fscanf(stream, "%s", email->recipient);

    // Read the subject line
    fscanf(stream, "%s", email->subject);

    // Read the email body
    int c;
    char buffer[100];
    int i = 0;
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') {
            i++;
            if (i == 10) {
                break;
            }
        }
        buffer[i] = c;
        i++;
    }
    email->body = malloc(i * sizeof(char));
    strcpy(email->body, buffer);

    // Calculate the message size
    email->size = i;

    return email;
}

// Function to send the email message
void send_email(email_t* email) {
    // Calculate the distance between the sender and the recipient
    int distance = pow(strlen(email->sender) + strlen(email->recipient), 2);

    // Calculate the time it takes for the email to reach the recipient
    int time = distance / 50;

    // Print the email message
    printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n", email->sender, email->recipient, email->subject, email->body);

    // Wait for the email to reach the recipient
    sleep(time);
}

int main() {
    // Open the email file
    FILE* file = fopen("email.txt", "r");

    // Parse the email message from the file
    email_t* email = parse_email(file);

    // Send the email message
    send_email(email);

    // Close the email file
    fclose(file);

    return 0;
}