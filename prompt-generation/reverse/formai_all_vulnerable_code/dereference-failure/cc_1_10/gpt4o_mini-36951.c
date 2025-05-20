//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_QUESTIONS 5
#define MAX_STUDENTS 10

typedef struct {
    int student_id;
    char answers[NUM_QUESTIONS];
    int score;
} Student;

char correct_answers[NUM_QUESTIONS] = {'A', 'B', 'C', 'D', 'A'};
Student students[MAX_STUDENTS];
pthread_mutex_t mutex;

void *take_exam(void *arg) {
    int id = *(int *)arg;
    free(arg);

    printf("Student %d: Starting the exam...\n", id);
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Student %d: Enter answer for question %d (A/B/C/D): ", id, i + 1);
        scanf(" %c", &students[id].answers[i]);
    }

    // Calculate score
    students[id].score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (students[id].answers[i] == correct_answers[i]) {
            students[id].score++;
        }
    }

    pthread_mutex_lock(&mutex);
    printf("Student %d: Finished. Score: %d out of %d\n", id, students[id].score, NUM_QUESTIONS);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_STUDENTS];
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].student_id = i;
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, take_exam, arg);
        sleep(1); // Let students start the exam with a slight delay
    }
    
    for (int i = 0; i < MAX_STUDENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}