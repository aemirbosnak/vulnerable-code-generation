//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *education;
    char *experience;
    char *skills;
    char *awards;
    char *certifications;
    char *references;
} Resume;

Resume *new_resume() {
    Resume *resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->education = NULL;
    resume->experience = NULL;
    resume->skills = NULL;
    resume->awards = NULL;
    resume->certifications = NULL;
    resume->references = NULL;
    return resume;
}

void free_resume(Resume *resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->education);
    free(resume->experience);
    free(resume->skills);
    free(resume->awards);
    free(resume->certifications);
    free(resume->references);
    free(resume);
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("Awards: %s\n", resume->awards);
    printf("Certifications: %s\n", resume->certifications);
    printf("References: %s\n", resume->references);
}

int main() {
    // Create a new resume
    Resume *resume = new_resume();

    // Set the resume's fields
    resume->name = "John Doe";
    resume->email = "john.doe@example.com";
    resume->phone = "123-456-7890";
    resume->address = "123 Main Street, Anytown, CA 12345";
    resume->education = "Bachelor of Science in Computer Science, University of California, Berkeley";
    resume->experience = "Software Engineer, Google";
    resume->skills = "Java, Python, C++, JavaScript";
    resume->awards = "Dean's List, President's List";
    resume->certifications = "Certified Java Programmer, Certified Python Programmer";
    resume->references = "Available upon request";

    // Print the resume
    print_resume(resume);

    // Free the resume
    free_resume(resume);

    return 0;
}