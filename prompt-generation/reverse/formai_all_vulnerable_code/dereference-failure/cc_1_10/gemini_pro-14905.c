//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *education;
    char *experience;
    char *skills;
} Resume;

typedef struct ResumeList {
    Resume *resume;
    struct ResumeList *next;
} ResumeList;

// Function prototypes
Resume *create_resume(char *name, char *email, char *phone, char *education, char *experience, char *skills);
ResumeList *insert_resume(ResumeList *list, Resume *resume);
void print_resume(Resume *resume);
void print_resume_list(ResumeList *list);

// Main function
int main() {
    // Create a resume
    Resume *resume = create_resume("John Doe", "johndoe@example.com", "123-456-7890", "BS in Computer Science from Stanford University", "5 years of experience as a software engineer", "Java, C++, Python");

    // Insert the resume into a resume list
    ResumeList *list = insert_resume(NULL, resume);

    // Print the resume list
    print_resume_list(list);

    return 0;
}

// Function definitions
Resume *create_resume(char *name, char *email, char *phone, char *education, char *experience, char *skills) {
    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));

    // Copy the data into the resume
    resume->name = strdup(name);
    resume->email = strdup(email);
    resume->phone = strdup(phone);
    resume->education = strdup(education);
    resume->experience = strdup(experience);
    resume->skills = strdup(skills);

    // Return the resume
    return resume;
}

ResumeList *insert_resume(ResumeList *list, Resume *resume) {
    // Create a new resume list node
    ResumeList *node = malloc(sizeof(ResumeList));

    // Set the resume list node's resume
    node->resume = resume;

    // Set the resume list node's next pointer
    node->next = list;

    // Return the resume list node
    return node;
}

void print_resume(Resume *resume) {
    // Print the resume's data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("\n");
}

void print_resume_list(ResumeList *list) {
    // Print the resume list
    while (list != NULL) {
        print_resume(list->resume);
        list = list->next;
    }
}