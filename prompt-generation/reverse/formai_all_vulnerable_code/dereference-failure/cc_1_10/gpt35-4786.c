//FormAI DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[100];
    char to[100];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email_t;

typedef struct {
    email_t emails[MAX_EMAILS];
    int count;
} mailing_list_t;

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

mailing_list_t *create_mailing_list() {
    mailing_list_t *mailing_list = (mailing_list_t *) malloc(sizeof(mailing_list_t));
    mailing_list->count = 0;
    return mailing_list;
}

void add_email_to_list(mailing_list_t *mailing_list, email_t email) {
    if (mailing_list->count >= MAX_EMAILS) {
        printf("Mailing list is full.\n");
        return;
    }

    mailing_list->emails[mailing_list->count++] = email;
}

void print_email(email_t email) {
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

void print_mailing_list(mailing_list_t *mailing_list) {
    printf("Total emails in mailing list: %d\n", mailing_list->count);
    for (int i = 0; i < mailing_list->count; i++) {
        printf("\nEmail %d:\n", i + 1);
        print_email(mailing_list->emails[i]);
    }
}

void save_mailing_list_to_file(mailing_list_t *mailing_list) {
    int fd = open("mailing_list.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        handle_error("Error opening file for writing");
    }

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < mailing_list->count; i++) {
        email_t email = mailing_list->emails[i];

        // Write email metadata to file
        int n = sprintf(buffer, "From: %s\nTo: %s\nSubject: %s\n", email.from, email.to, email.subject);
        if (write(fd, buffer, n) != n) {
            handle_error("Error writing to file");
        }

        // Write email body to file
        if (write(fd, email.body, strlen(email.body)) != strlen(email.body)) {
            handle_error("Error writing to file");
        }

        // Add separator between emails
        if (write(fd, "\n---\n", 5) != 5) {
            handle_error("Error writing to file");
        }
    }

    close(fd);
}

void read_email_from_buffer(char *buffer, email_t *email) {
    char *from = strtok(buffer, "\n");
    strncpy(email->from, from + strlen("From: "), sizeof(email->from) - 1);

    char *to = strtok(NULL, "\n");
    strncpy(email->to, to + strlen("To: "), sizeof(email->to) - 1);

    char *subject = strtok(NULL, "\n");
    strncpy(email->subject, subject + strlen("Subject: "), sizeof(email->subject) - 1);

    char *body = strtok(NULL, "\0");
    strncpy(email->body, body, sizeof(email->body) - 1);
}

int parse_emails_from_file(mailing_list_t *mailing_list) {
    int fd = open("mailing_list.txt", O_RDONLY);
    if (fd == -1) {
        handle_error("Error opening file for reading");
    }

    char buffer[BUFFER_SIZE];
    char *saveptr;
    while (1) {
        int n = read(fd, buffer, BUFFER_SIZE);
        if (n == -1) {
            handle_error("Error reading from file");
        } else if (n == 0) {
            break; // End of file
        }

        buffer[n] = '\0'; // Null-terminate buffer
        email_t email;
        read_email_from_buffer(buffer, &email);
        add_email_to_list(mailing_list, email);

        // Skip to next email
        char *next_email = strtok_r(NULL, "\n---\n", &saveptr);
        if (next_email == NULL) {
            break; // End of file
        } else {
            strncpy(buffer, next_email, sizeof(buffer) - 1);
        }
    }

    close(fd);
    return 0;
}

void send_email(email_t *email) {
    // Simulate sending email
    printf("Sending email...\n");
    sleep(1); // Wait for 1 second
    printf("Email sent successfully.\n");
}

void send_emails_from_list(mailing_list_t *mailing_list) {
    for (int i = 0; i < mailing_list->count; i++) {
        email_t *email = &mailing_list->emails[i];
        printf("Sending email %d\n", i + 1);
        print_email(*email);
        send_email(email);
    }
}

int main() {
    mailing_list_t *mailing_list = create_mailing_list();

    email_t email1 = {"alice@example.com", "bob@example.com", "Hello Bob", "How are you?"};
    email_t email2 = {"bob@example.com", "alice@example.com", "Re: Hello Bob", "I am doing well, thanks!"};
    email_t email3 = {"charlie@example.com", "alice@example.com", "Re: Hello", "Can I join the conversation?"};

    add_email_to_list(mailing_list, email1);
    add_email_to_list(mailing_list, email2);
    add_email_to_list(mailing_list, email3);

    print_mailing_list(mailing_list);

    save_mailing_list_to_file(mailing_list);

    mailing_list_t *new_mailing_list = create_mailing_list();
    parse_emails_from_file(new_mailing_list);

    print_mailing_list(new_mailing_list);

    send_emails_from_list(new_mailing_list);

    return 0;
}