//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_RESUMES 8
#define MAX_BUFFER 256

// Struct for storing Resume Information
typedef struct {
    char name[MAX_BUFFER];
    char email[MAX_BUFFER];
    char phone[MAX_BUFFER];
    char experience[MAX_BUFFER];
} Resume;

// Struct for storing Thread Information
typedef struct {
    int thread_id;
    int start_index;
    int end_index;
} ThreadInfo;

// Global Variables
Resume resumes[MAX_RESUMES];
int resume_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function Declarations
void* parseResume(void* arg);
void readResumesFromFile(const char* filename);
void printResume(Resume resume);
void writeResumesToFile(const char* filename);

// Main Function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    readResumesFromFile(input_file);

    pthread_t threads[MAX_THREADS];
    ThreadInfo thread_info[MAX_THREADS];

    int start_index = 0;
    int end_index = 0;
    int resumes_per_thread = MAX_RESUMES / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        start_index = end_index;
        end_index += resumes_per_thread;
        if (i == MAX_THREADS - 1) {
            end_index = MAX_RESUMES;
        }

        thread_info[i].thread_id = i;
        thread_info[i].start_index = start_index;
        thread_info[i].end_index = end_index;

        pthread_create(&threads[i], NULL, parseResume, (void *) &thread_info[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    writeResumesToFile(output_file);
    
    return 0;
}

void* parseResume(void* arg) {
    ThreadInfo thread_info = *((ThreadInfo*) arg);
    int thread_id = thread_info.thread_id;
    int start_index = thread_info.start_index;
    int end_index = thread_info.end_index;

    for (int i = start_index; i < end_index; i++) {
        Resume resume = resumes[i];
        printf("Thread %d is parsing the resume of %s.\n", thread_id, resume.name);

        // Parsing logic goes here...
        // For example, extracting information from the resume text using regular expressions

        // Simulate some processing time
        usleep(100 * 1000);

        // Update the shared resumes array
        pthread_mutex_lock(&mutex);
        resumes[i] = resume;
        resume_count++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void readResumesFromFile(const char* filename) {
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    char* token;

    while (fgets(buffer, MAX_BUFFER, input)) {
        token = strtok(buffer, ",");
        strncpy(resumes[resume_count].name, token, MAX_BUFFER);
        token = strtok(NULL, ",");
        strncpy(resumes[resume_count].email, token, MAX_BUFFER);
        token = strtok(NULL, ",");
        strncpy(resumes[resume_count].phone, token, MAX_BUFFER);
        token = strtok(NULL, ",");
        strncpy(resumes[resume_count].experience, token, MAX_BUFFER);
        resume_count++;
    }

    fclose(input);
}

void writeResumesToFile(const char* filename) {
    FILE *output = fopen(filename, "w");
    if (output == NULL) {
        printf("Failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_RESUMES; i++) {
        Resume resume = resumes[i];
        if (strlen(resume.name) > 0) {
            fprintf(output, "%s,%s,%s,%s\n", resume.name, resume.email, resume.phone, resume.experience);
        }
    }

    fclose(output);
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Experience: %s\n", resume.experience);
}