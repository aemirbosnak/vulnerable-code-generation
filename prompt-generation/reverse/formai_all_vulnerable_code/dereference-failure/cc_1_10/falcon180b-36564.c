//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 1024
#define MAX_FROM 1024
#define MAX_TO 1024
#define MAX_BODY 1024

typedef struct {
    char from[MAX_FROM];
    char to[MAX_TO];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} email;

int main() {
    FILE *fp;
    email email;
    char line[MAX_LINE];
    char *token;
    int in_header = 1;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read email header
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (line[0] == '\n') {
            in_header = 0;
            continue;
        }
        if (in_header) {
            token = strtok(line, ":");
            if (token == NULL) {
                printf("Error parsing header\n");
                exit(1);
            }
            strcpy(email.from, token);
        }
    }

    // Read email body
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (line[0] == '\n') {
            break;
        }
        strcat(email.body, line);
    }

    // Close input file
    fclose(fp);

    // Open output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Write email header
    fprintf(fp, "From: %s\n", email.from);
    fprintf(fp, "To: %s\n", email.to);
    fprintf(fp, "Subject: %s\n", email.subject);

    // Write email body
    fprintf(fp, "%s\n", email.body);

    // Close output file
    fclose(fp);

    printf("Email client example program completed successfully.\n");
    return 0;
}