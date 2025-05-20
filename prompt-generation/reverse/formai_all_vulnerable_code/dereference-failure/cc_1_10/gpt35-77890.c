//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* date;
    char* from;
    char* subject;
} Email;

void display_email(Email* email) {
    printf("Date: %s\n", email->date);
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
}

void receive_emails(FILE* inbox, Email** emails) {
    const int email_max_chars = 100;
    char buffer[email_max_chars];
    int i = 0;
    
    while (fgets(buffer, email_max_chars, inbox)) {
        int j = 0;
        char* date = malloc(sizeof(char) * email_max_chars);
        char* from = malloc(sizeof(char) * email_max_chars);
        char* subject = malloc(sizeof(char) * email_max_chars);
        while (buffer[j] != '\n') {
            if (buffer[j] == ',') {
                j++;
                continue;
            }
            switch (j % 3) {
                case 0:
                    strncat(date, &buffer[j], 1);
                    break;
                case 1:
                    strncat(from, &buffer[j], 1);
                    break;
                case 2:
                    strncat(subject, &buffer[j], 1);
                    break;
            }
            j++;
        }
        emails[i] = malloc(sizeof(Email));
        emails[i]->date = date;
        emails[i]->from = from;
        emails[i]->subject = subject;
        i++;
    }
}

int main() {
    FILE* inbox = fopen("inbox.csv", "r");
    if (!inbox) {
        printf("Error opening inbox.csv: file not found\n");
        return 1;
    }

    const int max_emails = 10;
    Email** emails = malloc(sizeof(Email*) * max_emails);
    receive_emails(inbox, emails);

    for (int i = 0; i < max_emails && emails[i] != NULL; i++) {
        display_email(emails[i]);
    }
    fclose(inbox);
    return 0;
}