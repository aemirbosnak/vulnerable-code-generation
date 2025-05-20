//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char name[30];
    char email[50];
    char phone[15];
    char education[50];
    char skills[200];
    char experience[300];
} Resume;

Resume* parse_resume(char* resume_text);

int main() {
    char* resume_text = "John Doe\njohndoe@email.com\n123-456-7890\n\
    Master's Degree in Computer Science\nC++, Java, Python\n\
    Software Engineer at ABC Company for 2 years";

    Resume* res = parse_resume(resume_text);

    printf("Name: %s\n", res->name);
    printf("Email: %s\n", res->email);
    printf("Phone: %s\n", res->phone);
    printf("Education: %s\n", res->education);
    printf("Skills: %s\n", res->skills);
    printf("Experience: %s\n", res->experience);

    // Free memory
    free(res);

    return 0;
}

Resume* parse_resume(char* resume_text) {
    Resume* res = (Resume*) malloc(sizeof(Resume));

    // Parse name
    char* start = resume_text;
    char* end = strchr(start, '\n');
    strncpy(res->name, start, end-start);
    res->name[end-start] = '\0';

    // Parse email
    start = end+1;
    end = strchr(start, '\n');
    strncpy(res->email, start, end-start);
    res->email[end-start] = '\0';

    // Parse phone
    start = end+1;
    end = strchr(start, '\n');
    strncpy(res->phone, start, end-start);
    res->phone[end-start] = '\0';

    // Parse education
    start = end+1;
    end = strchr(start, '\n');
    strncpy(res->education, start, end-start);
    res->education[end-start] = '\0';

    // Parse skills
    start = end+1;
    end = strchr(start, '\n');
    strncpy(res->skills, start, end-start);
    res->skills[end-start] = '\0';

    // Parse experience
    start = end+1;
    end = strchr(start, '\0');
    strncpy(res->experience, start, end-start);
    res->experience[end-start] = '\0';

    return res;
}