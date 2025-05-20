//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_SKILLS 5

typedef struct {
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char* skills[MAX_SKILLS];
    int num_skills;
} ResumeInfo;

int parse_resume(char* resume_text, ResumeInfo* resume) {
    // TODO: implement resume parsing logic
}

void add_skill(ResumeInfo* resume, char* skill) {
    if(resume->num_skills < MAX_SKILLS) {
        resume->skills[resume->num_skills] = skill;
        resume->num_skills++;
    }
}

int main(int argc, char** argv) {
    ResumeInfo resumes[MAX_RESUMES];
    int num_resumes = 0;
    char* resume_text;
    size_t resume_text_size = 1000;
    resume_text = (char*)malloc(resume_text_size * sizeof(char));

    printf("Welcome to the Resume Parsing System\n\n");

    while(1) {
        printf("Enter resume text or type 'exit' to quit:\n");
        getline(&resume_text, &resume_text_size, stdin);

        if(strcmp(resume_text, "exit\n") == 0) {
            break;
        }

        ResumeInfo current_resume;

        if(parse_resume(resume_text, &current_resume) == 0) {
            printf("Error parsing resume\n");
            continue;
        }

        resumes[num_resumes] = current_resume;
        num_resumes++;

        printf("Resume successfully parsed\n");
    }

    printf("\n%d resumes parsed.\n", num_resumes);
    printf("================================\n");

    for(int i=0; i<num_resumes; i++) {
        printf("Resume %d\n", i+1);
        printf("First Name: %s\n", resumes[i].first_name);
        printf("Last Name: %s\n", resumes[i].last_name);
        printf("Email: %s\n", resumes[i].email);
        printf("Skills:\n");

        for(int j=0; j<resumes[i].num_skills; j++) {
            printf("\t%s\n", resumes[i].skills[j]);
        }

        printf("================================\n");
    }

    return 0;
}