//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4 // number of threads to be used

// define the structure of a resume
typedef struct {
    char name[50];
    int age;
    char education[100];
    char skills[500];
    char experience[1000];
} Resume;

// define the queue data structure
typedef struct {
    Resume* resumes;
    int num_resumes;
    int head;
    int tail;
    int size;
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} ResumeQueue;

// create a new empty resume queue
ResumeQueue* new_resume_queue(int size) {
    ResumeQueue* queue = malloc(sizeof(ResumeQueue));
    queue->resumes = malloc(sizeof(Resume) * size);
    queue->num_resumes = 0;
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_full, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    return queue;
}

// add a new resume to the queue
void enqueue_resume(ResumeQueue* queue, Resume* resume) {
    pthread_mutex_lock(&queue->lock);
    while (queue->num_resumes == queue->size) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    queue->resumes[queue->tail] = *resume;
    queue->tail = (queue->tail + 1) % queue->size;
    queue->num_resumes++;
    pthread_cond_broadcast(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

// remove a resume from the queue
Resume* dequeue_resume(ResumeQueue* queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->num_resumes == 0) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    Resume* resume = &queue->resumes[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->num_resumes--;
    pthread_cond_broadcast(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);
    return resume;
}

// a worker thread that processes resumes
void* worker_thread(void* arg) {
    ResumeQueue* queue = (ResumeQueue*) arg;
    while (1) {
        Resume* resume = dequeue_resume(queue);
        printf("Processing resume of %s\n", resume->name);
        // TODO: add resume parsing functionality here
        free(resume);
    }
    return NULL;
}

int main() {
    // create the resume queue
    ResumeQueue* queue = new_resume_queue(100);

    // create the worker threads
    pthread_t threads[THREADS];
    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, worker_thread, queue);
    }

    // add resumes to the queue
    for (int i = 0; i < 1000; i++) {
        Resume* resume = malloc(sizeof(Resume));
        sprintf(resume->name, "Applicant #%d", i);
        resume->age = rand() % 30 + 20; // random age between 20 and 50
        sprintf(resume->education, "Degree from XYZ University");
        sprintf(resume->skills, "Programming, Marketing, Sales");
        sprintf(resume->experience, "3 years at ABC Company as a Sales Representative");
        enqueue_resume(queue, resume);
    }

    // wait for the worker threads to finish
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // free the resume queue and all its contents
    free(queue->resumes);
    free(queue);
    
    return 0;
}