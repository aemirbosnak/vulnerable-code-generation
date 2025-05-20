//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct {
    char *data;
    char *job_title;
    char *skills;
} Resume;

typedef struct {
    Resume resumes[MAX_RESUMES];
    int count;
} ResumeDatabase;

ResumeDatabase resumeDB;
pthread_mutex_t mutex;

void *parse_resume(void *arg) {
    char *resume_data = (char *)arg;
    Resume resume;
    resume.data = malloc(MAX_LENGTH);
    strcpy(resume.data, resume_data);
    
    // Simulating parsing job title and skills from the resume
    char *token = strtok(resume.data, "\n");
    resume.job_title = malloc(MAX_TAG_LENGTH);
    if (token != NULL) {
        strcpy(resume.job_title, token); // Assume the first line is job title
    }

    token = strtok(NULL, "\n");
    resume.skills = malloc(MAX_TAG_LENGTH);
    if (token != NULL) {
        strcpy(resume.skills, token); // Assume the second line is skills
    }

    // Save the resume in the database
    pthread_mutex_lock(&mutex);
    if (resumeDB.count < MAX_RESUMES) {
        resumeDB.resumes[resumeDB.count++] = resume;
    } else {
        printf("Resume database is full!\n");
        free(resume.job_title);
        free(resume.skills);
        free(resume.data);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *display_resumes(void *arg) {
    sleep(1); // Wait for resumes to be parsed
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < resumeDB.count; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Job Title: %s\n", resumeDB.resumes[i].job_title);
        printf("Skills: %s\n", resumeDB.resumes[i].skills);
        printf("\n");
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void cleanup() {
    for (int i = 0; i < resumeDB.count; i++) {
        free(resumeDB.resumes[i].job_title);
        free(resumeDB.resumes[i].skills);
        free(resumeDB.resumes[i].data);
    }
}

int main() {
    pthread_t threads[MAX_RESUMES];
    pthread_t display_thread;
    const char *resumes[] = {
        "Software Engineer\nC, C++, Java",
        "Data Scientist\nPython, SQL, TensorFlow",
        "Web Developer\nHTML, CSS, JavaScript",
        // More resumes can be added here
    };
    
    resumeDB.count = 0;
    pthread_mutex_init(&mutex, NULL);

    // Parsing resumes asynchronously
    for (int i = 0; i < sizeof(resumes)/sizeof(resumes[0]); i++) {
        if (pthread_create(&threads[i], NULL, parse_resume, (void *)resumes[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Create a thread to display resumes
    if (pthread_create(&display_thread, NULL, display_resumes, NULL) != 0) {
        fprintf(stderr, "Error creating display thread\n");
        return 1;
    }

    // Wait for all parsing threads to complete
    for (int i = 0; i < sizeof(resumes)/sizeof(resumes[0]); i++) {
        pthread_join(threads[i], NULL);
    }

    // Wait for display thread to complete
    pthread_join(display_thread, NULL);

    cleanup();
    pthread_mutex_destroy(&mutex);
    return 0;
}