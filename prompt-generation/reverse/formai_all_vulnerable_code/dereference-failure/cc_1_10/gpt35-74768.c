//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_STRING_LEN 100

typedef struct {
    char name[MAX_STRING_LEN];
    char email[MAX_STRING_LEN];
    char phone[MAX_STRING_LEN];
    char education[MAX_STRING_LEN];
    char skills[MAX_STRING_LEN];
} Resume;

int num_resumes;
Resume resumes[MAX_RESUMES];

void parse_resume(char *resume_text, Resume *r) {
    // parse name
    sscanf(resume_text, "Name: %[^\n]", r->name);
    // parse email
    sscanf(resume_text, "Email: %[^\n]", r->email);
    // parse phone
    sscanf(resume_text, "Phone: %[^\n]", r->phone);
    // parse education
    sscanf(resume_text, "Education: %[^\n]", r->education);
    // parse skills
    sscanf(resume_text, "Skills: %[^\n]", r->skills);
}

void read_resume_file(char *filename) {
    FILE *fp;
    char buffer[MAX_STRING_LEN], *resume_text;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open resume file '%s'\n", filename);
        exit(1);
    }
    num_resumes = 0;
    while (fgets(buffer, MAX_STRING_LEN, fp) != NULL) {
        // allocate memory for resume text
        resume_text = (char*) malloc(strlen(buffer) + 1);
        strcpy(resume_text, buffer);
        // parse resume and add to array
        parse_resume(resume_text, &resumes[num_resumes]);
        num_resumes++;
        // free memory
        free(resume_text);
    }
    fclose(fp);
}

void print_resume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Education: %s\n", r->education);
    printf("Skills: %s\n", r->skills);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s resume_file\n", argv[0]);
        exit(1);
    }
    read_resume_file(argv[1]);
    printf("Parsed %d resumes from file '%s'\n", num_resumes, argv[1]);
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        print_resume(&resumes[i]);
    }
    return 0;
}