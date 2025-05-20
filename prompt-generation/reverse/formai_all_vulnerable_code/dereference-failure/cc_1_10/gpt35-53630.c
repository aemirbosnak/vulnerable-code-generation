//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Define a struct to hold resume information */
struct resume {
    char name[64];
    char email[64];
    char phone[16];
    char education[256];
    char experience[1024];
};

/* Function to parse the resume text */
int parse_resume(char *text, struct resume *r) {
    char *token;
    char buffer[BUFFER_SIZE];

    /* Parse the name */
    token = strtok(text, "\n");
    if (token == NULL) {
        return 0;
    }
    strncpy(r->name, token, 63);

    /* Parse the email */
    token = strtok(NULL, "\n");
    if (token == NULL) {
        return 0;
    }
    strncpy(r->email, token, 63);

    /* Parse the phone number */
    token = strtok(NULL, "\n");
    if (token == NULL) {
        return 0;
    }
    strncpy(r->phone, token, 15);

    /* Parse the education */
    buffer[0] = '\0';
    while ((token = strtok(NULL, "\n")) != NULL) {
        strcat(buffer, token);
        strcat(buffer, "\n");
    }
    strncpy(r->education, buffer, 255);

    /* Parse the experience */
    buffer[0] = '\0';
    while ((token = strtok(NULL, "\n")) != NULL) {
        strcat(buffer, token);
        strcat(buffer, "\n");
    }
    strncpy(r->experience, buffer, 1023);

    return 1;
}

int main(int argc, char **argv) {
    struct resume r;
    char *text;
    FILE *fp;
    long size;

    /* Open the resume file */
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open resume file\n");
        exit(1);
    }

    /* Get the size of the file */
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Allocate memory for the resume text */
    text = (char *) malloc(size);
    if (text == NULL) {
        printf("Error: Cannot allocate memory for resume text\n");
        exit(1);
    }

    /* Read the resume text */
    fread(text, 1, size, fp);

    /* Parse the resume text */
    if (parse_resume(text, &r)) {
        printf("Name: %s\n", r.name);
        printf("Email: %s\n", r.email);
        printf("Phone: %s\n", r.phone);
        printf("Education: %s\n", r.education);
        printf("Experience: %s\n", r.experience);
    } else {
        printf("Error: Cannot parse resume\n");
    }

    /* Free memory */
    free(text);
    fclose(fp);

    return 0;
}