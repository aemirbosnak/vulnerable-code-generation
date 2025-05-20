//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 20
#define MAX_RESUME_LENGTH 1024

struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_NAME_LENGTH];
    int skill_count;
};

// Function to parse a single resume input string
void parse_resume(const char *input, struct Resume *resume) {
    char *token;
    char *input_copy = strdup(input);
    if (!input_copy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize skill count
    resume->skill_count = 0;

    // Parse name
    token = strtok(input_copy, "\n");
    if (token) {
        strncpy(resume->name, token, MAX_NAME_LENGTH);
    }

    // Parse email
    token = strtok(NULL, "\n");
    if (token) {
        strncpy(resume->email, token, MAX_EMAIL_LENGTH);
    }

    // Parse phone number
    token = strtok(NULL, "\n");
    if (token) {
        strncpy(resume->phone, token, MAX_PHONE_LENGTH);
    }

    // Parse skills
    while ((token = strtok(NULL, ",")) != NULL && resume->skill_count < MAX_SKILLS) {
        strncpy(resume->skills[resume->skill_count], token, MAX_NAME_LENGTH);
        resume->skill_count++;
    }

    free(input_copy);
}

// Function to print the parsed resume
void print_resume(const struct Resume *resume) {
    printf("------- Resume -------\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf(" - %s\n", resume->skills[i]);
    }
    printf("----------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open the file");
        return EXIT_FAILURE;
    }

    struct Resume resume;
    char buffer[MAX_RESUME_LENGTH];

    // Read the resume data line by line and parse it
    while (fgets(buffer, sizeof(buffer), file)) {
        parse_resume(buffer, &resume);
        print_resume(&resume);
        printf("\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}