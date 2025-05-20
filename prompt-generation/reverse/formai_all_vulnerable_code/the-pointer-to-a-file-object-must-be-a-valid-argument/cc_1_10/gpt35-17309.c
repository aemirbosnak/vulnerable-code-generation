//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Struct to hold parsed data
typedef struct Resume { 
    char name[50]; 
    char email[50];
    int age;
    char degree[50];
    char skills[1000];
} Resume;

int main() {

    char resume_text[5000];
    Resume parsed_resume;

    // Read text from resume file
    FILE* resume_file = fopen("resume.txt", "r");
    fgets(resume_text, 5000, resume_file);
    fclose(resume_file);

    // Get name from resume
    char* name_start_ptr = strstr(resume_text, "Name: ") + strlen("Name: ");
    char* name_end_ptr = strchr(name_start_ptr, '\n');
    int name_length = name_end_ptr - name_start_ptr;
    strncpy(parsed_resume.name, name_start_ptr, name_length);
    parsed_resume.name[name_length] = '\0';

    // Get email from resume
    char* email_start_ptr = strstr(resume_text, "Email: ") + strlen("Email: ");
    char* email_end_ptr = strchr(email_start_ptr, '\n');
    int email_length = email_end_ptr - email_start_ptr;
    strncpy(parsed_resume.email, email_start_ptr, email_length);
    parsed_resume.email[email_length] = '\0';

    // Get age from resume
    char* age_start_ptr = strstr(resume_text, "Age: ") + strlen("Age: ");
    char* age_end_ptr = strchr(age_start_ptr, '\n');
    char age_string[3];
    int age_length = age_end_ptr - age_start_ptr;
    strncpy(age_string, age_start_ptr, age_length);
    age_string[age_length] = '\0';
    parsed_resume.age = atoi(age_string);

    // Get degree from resume
    char* degree_start_ptr = strstr(resume_text, "Degree: ") + strlen("Degree: ");
    char* degree_end_ptr = strchr(degree_start_ptr, '\n');
    int degree_length = degree_end_ptr - degree_start_ptr;
    strncpy(parsed_resume.degree, degree_start_ptr, degree_length);
    parsed_resume.degree[degree_length] = '\0';

    // Get skills from resume
    char* skills_start_ptr = strstr(resume_text, "Skills: ") + strlen("Skills: ");
    char* skills_end_ptr = strchr(skills_start_ptr, '\n');
    int skills_length = skills_end_ptr - skills_start_ptr;
    strncpy(parsed_resume.skills, skills_start_ptr, skills_length);
    parsed_resume.skills[skills_length] = '\0';

    // Print parsed data
    printf("Name: %s\n", parsed_resume.name);
    printf("Email: %s\n", parsed_resume.email);
    printf("Age: %d\n", parsed_resume.age);
    printf("Degree: %s\n", parsed_resume.degree);
    printf("Skills: %s\n", parsed_resume.skills);

    return 0;
}