//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* education;
    char* experience;
} Resume;

Resume* createResume() {
    Resume* r = (Resume*)malloc(sizeof(Resume));
    r->name = NULL;
    r->email = NULL;
    r->phone = NULL;
    r->education = NULL;
    r->experience = NULL;
    return r;
}

void freeResume(Resume* r) {
    if (r == NULL) return;
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->education);
    free(r->experience);
    free(r);
}

Resume* parseResume(char* data) {
    Resume* r = createResume();
    char* line = strtok(data, "\n");
    while (line!= NULL) {
        if (strstr(line, "Name:")!= NULL) {
            r->name = strtok(line, ":");
        } else if (strstr(line, "Email:")!= NULL) {
            r->email = strtok(line, ":");
        } else if (strstr(line, "Phone:")!= NULL) {
            r->phone = strtok(line, ":");
        } else if (strstr(line, "Education:")!= NULL) {
            r->education = strtok(line, ":");
        } else if (strstr(line, "Experience:")!= NULL) {
            r->experience = strtok(line, ":");
        }
        line = strtok(NULL, "\n");
    }
    return r;
}

void printResume(Resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

int main() {
    char* data = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 555-555-5555\nEducation: B.S. in Computer Science\nExperience: 5 years in software development\n";
    Resume* r = parseResume(data);
    printResume(r);
    freeResume(r);
    return 0;
}