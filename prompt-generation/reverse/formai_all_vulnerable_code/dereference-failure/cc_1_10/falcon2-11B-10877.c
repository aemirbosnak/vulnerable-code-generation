//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* address;
    char* phone;
    char* email;
    char* education;
    char* experience;
} Resume;

Resume* parse_resume(char* resume_data) {
    Resume* resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        return NULL;
    }

    char* token = strtok(resume_data, "\n");
    while (token!= NULL) {
        char* endptr;
        char* value = strsep(&token, ":");
        resume->name = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        value = strsep(&token, ":");
        resume->address = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        value = strsep(&token, ":");
        resume->phone = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        value = strsep(&token, ":");
        resume->email = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        value = strsep(&token, ":");
        resume->education = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        value = strsep(&token, ":");
        resume->experience = value;
        endptr = strchr(value, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }

        token = strtok(NULL, "\n");
    }

    return resume;
}

int main() {
    char* resume_data = "John Doe\n123 Main Street\n(555) 555-5555\njohn.doe@email.com\nBachelor of Science in Computer Science\nSoftware Developer at ABC Inc.";
    Resume* resume = parse_resume(resume_data);
    if (resume!= NULL) {
        printf("Name: %s\nAddress: %s\nPhone: %s\nEmail: %s\nEducation: %s\nExperience: %s\n", resume->name, resume->address, resume->phone, resume->email, resume->education, resume->experience);
        free(resume);
    } else {
        printf("Failed to parse resume\n");
    }
    return 0;
}