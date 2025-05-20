//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_RESUMES 10

typedef struct {
    char *filePath;
    char *name;
    char *email;
    char *skills;
    // You can add more fields as needed
} Resume;

typedef struct {
    Resume *resumes[MAX_RESUMES];
    int count;
    pthread_mutex_t lock;
} ResumeCollection;

void* parseResume(void* arg) {
    FILE *file = fopen((char *)arg, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    char buffer[BUFFER_SIZE];
    resume->name = NULL;
    resume->email = NULL;
    resume->skills = NULL;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            resume->name = strdup(buffer + 5);
        } else if (strncmp(buffer, "Email:", 6) == 0) {
            resume->email = strdup(buffer + 6);
        } else if (strncmp(buffer, "Skills:", 7) == 0) {
            resume->skills = strdup(buffer + 7);
        }
    }

    fclose(file);
    return resume;
}

void addResume(ResumeCollection *collection, Resume *resume) {
    pthread_mutex_lock(&collection->lock);
    if (collection->count < MAX_RESUMES) {
        collection->resumes[collection->count++] = resume;
    }
    pthread_mutex_unlock(&collection->lock);
}

void printResumes(ResumeCollection *collection) {
    for (int i = 0; i < collection->count; i++) {
        Resume *r = collection->resumes[i];
        printf("Resume #%d:\n", i + 1);
        printf("Name: %sEmail: %sSkills: %s\n", r->name, r->email, r->skills);
        printf("----------------------------------\n");
        free(r->name);
        free(r->email);
        free(r->skills);
        free(r);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_file1> <resume_file2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    ResumeCollection collection;
    collection.count = 0;
    pthread_mutex_init(&collection.lock, NULL);
    pthread_t threads[argc - 1];

    // Start asynchronous parsing
    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, parseResume, argv[i]);
    }

    // Collect resumes
    for (int i = 1; i < argc; i++) {
        Resume *resume;
        pthread_join(threads[i - 1], (void**)&resume);
        if (resume) {
            addResume(&collection, resume);
        }
    }

    // Print all resumes
    printResumes(&collection);
    pthread_mutex_destroy(&collection.lock);

    return EXIT_SUCCESS;
}