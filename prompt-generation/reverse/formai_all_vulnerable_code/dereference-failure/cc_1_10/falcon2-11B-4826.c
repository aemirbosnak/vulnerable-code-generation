//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* education;
    char* experience;
} Resume;

Resume* parse_resume(char* resume_string) {
    Resume* resume = malloc(sizeof(Resume));
    char* token;
    char* field;
    int i = 0;
    while ((token = strsep(&resume_string, " "))!= NULL) {
        if (i == 0) {
            resume->name = token;
            i++;
        } else if (i == 1) {
            resume->email = token;
            i++;
        } else if (i == 2) {
            resume->phone = token;
            i++;
        } else if (i == 3) {
            resume->address = token;
            i++;
        } else if (i == 4) {
            resume->education = token;
            i++;
        } else if (i == 5) {
            resume->experience = token;
            i = 0;
        } else {
            // Invalid field, skip
        }
    }
    return resume;
}

int main() {
    char* resume_string = "John Doe\njdoe@email.com\n(123)456-7890\n123 Main St\nB.S. in Computer Science\nSoftware Engineer at Acme Corp";
    Resume* resume = parse_resume(resume_string);
    printf("Name: %s\nEmail: %s\nPhone: %s\nAddress: %s\nEducation: %s\nExperience: %s\n\n",
           resume->name, resume->email, resume->phone, resume->address, resume->education, resume->experience);
    free(resume);
    return 0;
}