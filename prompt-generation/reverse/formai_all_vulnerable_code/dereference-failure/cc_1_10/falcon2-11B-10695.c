//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    char education[500];
    char experience[500];
} Resume;

int main() {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    if (resume == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for resume.\n");
        return 1;
    }
    
    char* line = NULL;
    int line_length = 0;
    int line_count = 0;
    int resume_length = 0;
    
    while ((line = getline(&line_length, &line_count, stdin))!= NULL) {
        resume_length += strlen(line);
        if (resume_length >= MAX_RESUME_LENGTH) {
            fprintf(stderr, "Error: Resume exceeds maximum length.\n");
            free(resume);
            return 1;
        }
        
        strncpy(resume->name, line, line_length);
        line = line + line_length;
        line_length = 0;
        
        while ((line = getline(&line_length, &line_count, stdin))!= NULL) {
            if (strstr(line, "email: ")!= NULL) {
                strncpy(resume->email, line + strlen("email: "), line_length);
                line = line + line_length;
                line_length = 0;
            }
            else if (strstr(line, "phone: ")!= NULL) {
                strncpy(resume->phone, line + strlen("phone: "), line_length);
                line = line + line_length;
                line_length = 0;
            }
            else if (strstr(line, "address: ")!= NULL) {
                strncpy(resume->address, line + strlen("address: "), line_length);
                line = line + line_length;
                line_length = 0;
            }
            else if (strstr(line, "education: ")!= NULL) {
                strncpy(resume->education, line + strlen("education: "), line_length);
                line = line + line_length;
                line_length = 0;
            }
            else if (strstr(line, "experience: ")!= NULL) {
                strncpy(resume->experience, line + strlen("experience: "), line_length);
                line = line + line_length;
                line_length = 0;
            }
        }
    }
    
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    
    free(resume);
    return 0;
}