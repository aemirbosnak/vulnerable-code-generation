//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Struct to hold resume data
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    int experience;
    char skills[200];
} Resume;

// Struct to hold parsed resume data
typedef struct ParsedResume {
    char* name;
    char* email;
    char* phone;
    char* address;
    int experience;
    char* skills[20];
    int numSkills;
} ParsedResume;

// Function to parse resume data and return a ParsedResume struct
void parseResume(Resume* resume, ParsedResume* parsedResume) {
    // Copy name field
    parsedResume->name = strdup(resume->name);

    // Find and copy email field
    char* atSymbol = strchr(resume->email, '@');
    parsedResume->email = malloc(atSymbol - resume->email + 1);
    strncpy(parsedResume->email, resume->email, atSymbol - resume->email);
    parsedResume->email[atSymbol - resume->email] = '\0';

    // Copy phone field
    parsedResume->phone = strdup(resume->phone);

    // Copy address field
    parsedResume->address = strdup(resume->address);

    // Copy experience field
    parsedResume->experience = resume->experience;

    // Split skill field into array of skills
    char* skillToken;
    for (skillToken = strtok(resume->skills, ","); skillToken != NULL; skillToken = strtok(NULL, ",")) {
        parsedResume->skills[parsedResume->numSkills++] = strdup(skillToken);
    }
}

// Function to print a ParsedResume struct to console
void printParsedResume(ParsedResume* parsedResume) {
    printf("Name: %s\n", parsedResume->name);
    printf("Email: %s\n", parsedResume->email);
    printf("Phone: %s\n", parsedResume->phone);
    printf("Address: %s\n", parsedResume->address);
    printf("Experience: %d years\n", parsedResume->experience);
    printf("Skills:\n");
    for (int i = 0; i < parsedResume->numSkills; i++) {
        printf("- %s\n", parsedResume->skills[i]);
    }
}

// Function to free memory allocated for a ParsedResume struct
void freeParsedResume(ParsedResume* parsedResume) {
    free(parsedResume->name);
    free(parsedResume->email);
    free(parsedResume->phone);
    free(parsedResume->address);
    for (int i = 0; i < parsedResume->numSkills; i++) {
        free(parsedResume->skills[i]);
    }
}

// Function to be called by thread
void* threadFunction(void* arg) {
    // Cast input argument to Resume*
    Resume* resume = (Resume*) arg;

    // Allocate memory for ParsedResume struct
    ParsedResume* parsedResume = malloc(sizeof(ParsedResume));

    // Parse the resume
    parseResume(resume, parsedResume);

    // Print the parsed resume
    printParsedResume(parsedResume);

    // Free memory allocated for ParsedResume struct
    freeParsedResume(parsedResume);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Create some sample resume data
    Resume resume1 = {
        .name = "John Doe",
        .email = "johndoe@gmail.com",
        .phone = "555-555-5555",
        .address = "123 Main St, Anytown USA",
        .experience = 5,
        .skills = "C++,Java,Python"
    };
    Resume resume2 = {
        .name = "Jane Smith",
        .email = "janesmith@yahoo.com",
        .phone = "777-777-7777",
        .address = "456 Elm St, Othertown USA",
        .experience = 3,
        .skills = "JavaScript,Ruby,HTML"
    };

    // Create thread IDs
    pthread_t thread1, thread2;

    // Create threads and pass in resume data as input arguments
    pthread_create(&thread1, NULL, threadFunction, &resume1);
    pthread_create(&thread2, NULL, threadFunction, &resume2);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}