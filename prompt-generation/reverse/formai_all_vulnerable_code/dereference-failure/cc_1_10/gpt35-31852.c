//FormAI DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defines a struct to hold email information */
typedef struct {
    char from[50];
    char to[50];
    char subject[100];
    char message[500];
} Email;

int main() {

    /* Welcome the user to the email client */
    printf("Welcome to the Curious Email Client!\n\n");

    /* Prompt the user to enter email information */
    printf("Please enter the email information below:\n");
    
    /* Allocate memory for a new email */
    Email* new_email = (Email*) malloc(sizeof(Email));

    /* Get the email sender */
    printf("From: ");
    fgets(new_email->from, 50, stdin);

    /* Get the email recipient */
    printf("To: ");
    fgets(new_email->to, 50, stdin);

    /* Get the email subject */
    printf("Subject: ");
    fgets(new_email->subject, 100, stdin);

    /* Get the email message */
    printf("Message: ");
    fgets(new_email->message, 500, stdin);

    /* Confirm the email information */
    printf("\nEmail information:\n");
    printf("From: %sTo: %sSubject: %sMessage: %s\n\n", new_email->from, new_email->to, new_email->subject, new_email->message);

    /* Ask the user if they want to send the email */
    char choice[5];
    printf("Are you sure you want to send this email? (y/n) ");
    fgets(choice, 5, stdin);

    /* If the user chooses to send the email */
    if (strcmp(choice, "y\n") == 0) {

        /* Send the email */
        printf("Sending email...\n");

        /* Free the memory allocated for the email */
        free(new_email);

        /* Display a confirmation message */
        printf("Email sent successfully!\n");

    } 
    /* If the user chooses not to send the email */
    else if (strcmp(choice, "n\n") == 0) {

        /* Free the memory allocated for the email */
        free(new_email);

        /* Display a message to the user */
        printf("Email not sent.\n");

    }
    /* If the user input is invalid */
    else {

        /* Display an error message */
        printf("Invalid choice. Please enter 'y' to send or 'n' to cancel.\n");

    }

    /* Exit the email client */
    return 0;
}