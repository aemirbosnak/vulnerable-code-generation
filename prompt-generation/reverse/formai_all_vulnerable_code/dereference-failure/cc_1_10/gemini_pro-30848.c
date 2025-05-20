//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node representing a resume
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    struct Resume *next;
} Resume;

// Database of resumes
Resume *database;

// Hash table for quick lookup by name
char **hashTable;

// Initialize the system
void initialize() {
    // Initialize the database
    database = NULL;

    // Initialize the hash table
    hashTable = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        hashTable[i] = NULL;
    }
}

// Destroy the system
void destroy() {
    // Free the database
    Resume *node = database;
    while (node != NULL) {
        Resume *next = node->next;
        free(node->name);
        free(node->email);
        free(node->phone);
        free(node->skills);
        free(node);
        node = next;
    }

    // Free the hash table
    for (int i = 0; i < 100; i++) {
        free(hashTable[i]);
    }
    free(hashTable);
}

// Add a resume to the database
void addResume(char *name, char *email, char *phone, char *skills) {
    // Create a new resume
    Resume *newResume = malloc(sizeof(Resume));
    newResume->name = strdup(name);
    newResume->email = strdup(email);
    newResume->phone = strdup(phone);
    newResume->skills = strdup(skills);
    newResume->next = NULL;

    // Insert the resume into the database
    if (database == NULL) {
        database = newResume;
    } else {
        Resume *node = database;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = newResume;
    }

    // Add the resume to the hash table
    int index = hash(name);
    if (hashTable[index] == NULL) {
        hashTable[index] = strdup(name);
    } else {
        char *newEntry = malloc(strlen(hashTable[index]) + strlen(name) + 2);
        strcpy(newEntry, hashTable[index]);
        strcat(newEntry, ",");
        strcat(newEntry, name);
        free(hashTable[index]);
        hashTable[index] = newEntry;
    }
}

// Get a resume by name
Resume *getResume(char *name) {
    // Look up the name in the hash table
    int index = hash(name);
    char *names = hashTable[index];

    // Find the resume in the database
    Resume *node = database;
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            return node;
        }
        node = node->next;
    }

    // Resume not found
    return NULL;
}

// Print the resume
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
}

// Hash function
int hash(char *string) {
    int hash = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        hash += string[i];
    }
    return hash % 100;
}

// Main function
int main() {
    // Initialize the system
    initialize();

    // Add some resumes to the database
    addResume("John Doe", "johndoe@email.com", "123-456-7890", "C, C++, Java, Python");
    addResume("Jane Doe", "janedoe@email.com", "123-456-7891", "C, C++, Java, Python");
    addResume("John Smith", "johnsmith@email.com", "123-456-7892", "C, C++, Java, Python");

    // Get a resume by name
    Resume *resume = getResume("John Doe");

    // Print the resume
    printResume(resume);

    // Destroy the system
    destroy();

    return 0;
}