//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* skills;
    char* experience;
    char* education;
} Resume;

bool is_valid_email(char* email) {
    if (strstr(email, "@") == NULL) {
        return false;
    }
    if (strstr(email, ".") == NULL) {
        return false;
    }
    return true;
}

bool is_valid_phone(char* phone) {
    int len = strlen(phone);
    if (len != 10) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }
    return true;
}

Resume* parse_resume(char* resume_text) {
    Resume* resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    char* line;
    while ((line = strtok(resume_text, "\n")) != NULL) {
        if (strstr(line, "Name:")) {
            resume->name = strdup(line + strlen("Name:"));
        } else if (strstr(line, "Email:")) {
            if (is_valid_email(line + strlen("Email:"))) {
                resume->email = strdup(line + strlen("Email:"));
            }
        } else if (strstr(line, "Phone:")) {
            if (is_valid_phone(line + strlen("Phone:"))) {
                resume->phone = strdup(line + strlen("Phone:"));
            }
        } else if (strstr(line, "Skills:")) {
            resume->skills = strdup(line + strlen("Skills:"));
        } else if (strstr(line, "Experience:")) {
            resume->experience = strdup(line + strlen("Experience:"));
        } else if (strstr(line, "Education:")) {
            resume->education = strdup(line + strlen("Education:"));
        }
    }

    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main() {
    char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 1234567890\nSkills: Python, Java, C++\nExperience: Software Engineer at Google\nEducation: BS in Computer Science from Stanford University";

    Resume* resume = parse_resume(resume_text);
    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}