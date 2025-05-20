//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1024
#define MAX_FIELD_LENGTH 64

typedef struct {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
} Resume;

Resume* parse_resume(char* resume_str) {
    Resume* resume = malloc(sizeof(Resume));
    char* token = strtok(resume_str, ",");
    int field_count = 0;

    while (token!= NULL) {
        if (field_count == 0) {
            strcpy(resume->name, token);
        } else if (field_count == 1) {
            strcpy(resume->email, token);
        } else if (field_count == 2) {
            strcpy(resume->phone, token);
        } else if (field_count == 3) {
            strcpy(resume->address, token);
        } else if (field_count == 4) {
            strcpy(resume->experience, token);
        } else if (field_count == 5) {
            strcpy(resume->education, token);
        }

        field_count++;
        token = strtok(NULL, ",");
    }

    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main() {
    char resume_str[MAX_RESUME_LENGTH];
    printf("Enter resume string: ");
    fgets(resume_str, MAX_RESUME_LENGTH, stdin);

    Resume* resume = parse_resume(resume_str);
    print_resume(resume);

    free(resume);
    return 0;
}