//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE 1024
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 1024
#define MAX_BODY_LENGTH 10240

typedef struct {
    char *email;
    char *subject;
    char *body;
    time_t timestamp;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    char *subject_start = strchr(line, ':');
    if (subject_start == NULL) {
        return NULL;
    }
    *subject_start = '\0';
    email->subject = strdup(subject_start + 1);
    char *body_start = strchr(email->subject, ':');
    if (body_start == NULL) {
        return NULL;
    }
    *body_start = '\0';
    email->body = strdup(body_start + 1);
    char *timestamp_start = strchr(email->body, ':');
    if (timestamp_start == NULL) {
        return NULL;
    }
    *timestamp_start = '\0';
    email->timestamp = strtoll(timestamp_start + 1, NULL, 10);
    return email;
}

void print_email(Email *email) {
    printf("From: %s\n", email->email);
    printf("Subject: %s\n", email->subject);
    printf("Timestamp: %ld\n", email->timestamp);
    printf("Body:\n%s\n", email->body);
}

int main() {
    FILE *inbox_file = fopen("inbox", "r");
    if (inbox_file == NULL) {
        printf("Error opening inbox\n");
        return 1;
    }
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, inbox_file)!= NULL) {
        Email *email = parse_email(line);
        if (email!= NULL) {
            print_email(email);
        }
    }
    fclose(inbox_file);
    return 0;
}