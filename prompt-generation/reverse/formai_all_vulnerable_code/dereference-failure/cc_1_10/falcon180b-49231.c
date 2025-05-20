//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000

typedef struct {
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int body_length;
} email;

void read_email_file(const char* filename, email* email_list, int* num_emails);
void send_email(const char* to, const char* subject, const char* body);

int main() {
    email email_list[100];
    int num_emails = 0;

    read_email_file("emails.txt", email_list, &num_emails);

    for (int i = 0; i < num_emails; i++) {
        send_email(email_list[i].to, email_list[i].subject, email_list[i].body);
    }

    return 0;
}

void read_email_file(const char* filename, email* email_list, int* num_emails) {
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[MAX_LINE];
    int email_index = 0;

    while (fgets(line, MAX_LINE, file)) {
        char* to = strtok(line, ":");
        char* subject = strtok(NULL, ":");
        char* body = strtok(NULL, "\n");

        if (email_index >= *num_emails) {
            printf("Too many emails\n");
            exit(1);
        }

        strcpy(email_list[email_index].to, to);
        strcpy(email_list[email_index].subject, subject);
        strcpy(email_list[email_index].body, body);
        email_list[email_index].body_length = strlen(body);

        email_index++;
    }

    fclose(file);
}

void send_email(const char* to, const char* subject, const char* body) {
    FILE* file = fopen("email.txt", "w");

    if (!file) {
        printf("Error creating email file\n");
        exit(1);
    }

    fprintf(file, "To: %s\n", to);
    fprintf(file, "Subject: %s\n", subject);
    fprintf(file, "Body: %s\n", body);

    fclose(file);

    system("mail -s \"Subject\" email.txt");
}