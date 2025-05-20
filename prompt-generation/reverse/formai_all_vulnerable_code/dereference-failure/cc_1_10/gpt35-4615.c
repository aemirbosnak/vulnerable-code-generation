//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESUME_DB "resume_db.txt"

struct resume {
    char name[64];
    char email[64];
    char phone[16];
    char skills[256];
    char education[256];
};

void parse_resume(struct resume *r, char *resume_str) {
    char *token;

    // Extract the name
    token = strtok(resume_str, ",");
    strncpy(r->name, token, sizeof(r->name) - 1);

    // Extract the email
    token = strtok(NULL, ",");
    strncpy(r->email, token, sizeof(r->email) - 1);

    // Extract the phone
    token = strtok(NULL, ",");
    strncpy(r->phone, token, sizeof(r->phone) - 1);

    // Extract the skills
    token = strtok(NULL, ",");
    strncpy(r->skills, token, sizeof(r->skills) - 1);

    // Extract the education
    token = strtok(NULL, ",");
    strncpy(r->education, token, sizeof(r->education) - 1);
}

int match_resume(char *search_term, struct resume *r) {
    if (strstr(r->skills, search_term) != NULL) {
        return 1;
    }

    if (strstr(r->education, search_term) != NULL) {
        return 1;
    }

    return 0;
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct resume r;
    int matches = 0;

    // Open the resume database file
    fp = fopen(RESUME_DB, "r");
    if (fp == NULL) {
        perror("Error opening resume database file");
        exit(EXIT_FAILURE);
    }

    // Parse each line of the database
    while ((read = getline(&line, &len, fp)) != -1) {
        parse_resume(&r, line);

        // Check if this resume matches the search term
        if (match_resume("C programming", &r)) {
            printf("----------------------\n");
            printf("Name: %s\n", r.name);
            printf("Email: %s\n", r.email);
            printf("Phone: %s\n", r.phone);
            printf("Skills: %s\n", r.skills);
            printf("Education: %s\n", r.education);

            matches++;
        }
    }

    if (matches == 0) {
        printf("No matching resumes found.\n");
    }

    // Clean up
    fclose(fp);
    if (line) {
        free(line);
    }

    return 0;
}