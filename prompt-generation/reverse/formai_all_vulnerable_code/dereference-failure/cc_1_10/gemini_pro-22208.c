//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SKILLS 10
#define MAX_EXPERIENCES 10
#define MAX_EDUCATIONS 10

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    char *skills[MAX_SKILLS];
    int num_skills;
    struct {
        char *title;
        char *company;
        char *start_date;
        char *end_date;
        char *description;
    } experiences[MAX_EXPERIENCES];
    int num_experiences;
    struct {
        char *degree;
        char *university;
        char *start_date;
        char *end_date;
        char *gpa;
    } educations[MAX_EDUCATIONS];
    int num_educations;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    char line[1024];
    while (fgets(line, 1024, fp)) {
        // Parse the name
        if (strstr(line, "Name:")) {
            resume->name = strdup(line + 6);
        }
        // Parse the email
        else if (strstr(line, "Email:")) {
            resume->email = strdup(line + 7);
        }
        // Parse the phone
        else if (strstr(line, "Phone:")) {
            resume->phone = strdup(line + 7);
        }
        // Parse the address
        else if (strstr(line, "Address:")) {
            resume->address = strdup(line + 9);
        }
        // Parse the summary
        else if (strstr(line, "Summary:")) {
            resume->summary = strdup(line + 9);
        }
        // Parse the skills
        else if (strstr(line, "Skills:")) {
            char *skill = strtok(line + 8, ",");
            while (skill != NULL) {
                resume->skills[resume->num_skills++] = strdup(skill);
                skill = strtok(NULL, ",");
            }
        }
        // Parse the experiences
        else if (strstr(line, "Experience:")) {
            char *title = strtok(line + 12, "\n");
            char *company = strtok(NULL, "\n");
            char *start_date = strtok(NULL, "\n");
            char *end_date = strtok(NULL, "\n");
            char *description = strtok(NULL, "\n");
            resume->experiences[resume->num_experiences].title = strdup(title);
            resume->experiences[resume->num_experiences].company = strdup(company);
            resume->experiences[resume->num_experiences].start_date = strdup(start_date);
            resume->experiences[resume->num_experiences].end_date = strdup(end_date);
            resume->experiences[resume->num_experiences].description = strdup(description);
            resume->num_experiences++;
        }
        // Parse the educations
        else if (strstr(line, "Education:")) {
            char *degree = strtok(line + 11, "\n");
            char *university = strtok(NULL, "\n");
            char *start_date = strtok(NULL, "\n");
            char *end_date = strtok(NULL, "\n");
            char *gpa = strtok(NULL, "\n");
            resume->educations[resume->num_educations].degree = strdup(degree);
            resume->educations[resume->num_educations].university = strdup(university);
            resume->educations[resume->num_educations].start_date = strdup(start_date);
            resume->educations[resume->num_educations].end_date = strdup(end_date);
            resume->educations[resume->num_educations].gpa = strdup(gpa);
            resume->num_educations++;
        }
    }

    fclose(fp);
    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Summary: %s\n", resume->summary);
    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("    - %s\n", resume->skills[i]);
    }
    printf("Experiences:\n");
    for (int i = 0; i < resume->num_experiences; i++) {
        printf("    - Title: %s\n", resume->experiences[i].title);
        printf("      - Company: %s\n", resume->experiences[i].company);
        printf("      - Start Date: %s\n", resume->experiences[i].start_date);
        printf("      - End Date: %s\n", resume->experiences[i].end_date);
        printf("      - Description: %s\n", resume->experiences[i].description);
    }
    printf("Educations:\n");
    for (int i = 0; i < resume->num_educations; i++) {
        printf("    - Degree: %s\n", resume->educations[i].degree);
        printf("      - University: %s\n", resume->educations[i].university);
        printf("      - Start Date: %s\n", resume->educations[i].start_date);
        printf("      - End Date: %s\n", resume->educations[i].end_date);
        printf("      - GPA: %s\n", resume->educations[i].gpa);
    }
}

int main() {
    Resume *resume = parse_resume("resume.txt");
    print_resume(resume);
    free(resume);
    return 0;
}