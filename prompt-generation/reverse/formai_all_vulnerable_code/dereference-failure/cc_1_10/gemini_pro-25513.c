//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char address[MAX_LENGTH];
    char skills[MAX_LENGTH];
    char experience[MAX_LENGTH];
    char education[MAX_LENGTH];
} Resume;

Resume resumes[MAX_LINES];
int num_resumes = 0;

void parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        if (line_num >= MAX_LINES) {
            printf("Error: Too many resumes in file\n");
            return;
        }

        // Parse the name
        char *name = strtok(line, " \n");
        if (name == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].name, name);

        // Parse the email
        char *email = strtok(NULL, " \n");
        if (email == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].email, email);

        // Parse the phone
        char *phone = strtok(NULL, " \n");
        if (phone == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].phone, phone);

        // Parse the address
        char *address = strtok(NULL, " \n");
        if (address == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].address, address);

        // Parse the skills
        char *skills = strtok(NULL, " \n");
        if (skills == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].skills, skills);

        // Parse the experience
        char *experience = strtok(NULL, " \n");
        if (experience == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].experience, experience);

        // Parse the education
        char *education = strtok(NULL, " \n");
        if (education == NULL) {
            printf("Error: Invalid resume format\n");
            return;
        }
        strcpy(resumes[line_num].education, education);

        line_num++;
    }

    fclose(fp);

    num_resumes = line_num;
}

void print_resume(int index) {
    if (index < 0 || index >= num_resumes) {
        printf("Error: Invalid resume index\n");
        return;
    }

    Resume resume = resumes[index];

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    parse_resume(argv[1]);

    for (int i = 0; i < num_resumes; i++) {
        print_resume(i);
    }

    return 0;
}