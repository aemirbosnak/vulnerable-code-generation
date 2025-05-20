//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024

typedef struct {
    char* subject;
    char* body;
} Email;

int main() {
    Email email;
    char input[1024];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int subject_length = 0;
    int body_length = 0;

    printf("Welcome to Ada Lovelace's Email Client!\n");

    while (1) {
        printf("Enter your email: ");
        fgets(input, 1024, stdin);
        email.subject = strtok(input, "\n");

        // Check if subject is too long
        while (subject_length < MAX_SUBJECT_LENGTH && email.subject[subject_length]!= '\0') {
            subject[subject_length++] = tolower(email.subject[subject_length]);
        }
        subject[subject_length] = '\0';

        // Check if body is too long
        body_length = 0;
        while (body_length < MAX_BODY_LENGTH && input[strlen(email.subject) + body_length + 2]!= '\0') {
            body[body_length++] = input[strlen(email.subject) + body_length + 2];
        }
        body[body_length] = '\0';

        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);

        printf("Do you want to send this email? (y/n): ");
        char send_choice = tolower(fgetc(stdin));

        if (send_choice == 'y') {
            printf("Email sent!\n");
        } else {
            printf("Email discarded.\n");
        }
    }

    return 0;
}