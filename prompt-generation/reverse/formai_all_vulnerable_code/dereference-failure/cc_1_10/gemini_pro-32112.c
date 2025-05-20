//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex;
struct resume {
  char *name;
  char *email;
  char *skills;
};

struct resume *resumes;
int num_resumes;

void *parse_resume(void *arg) {
  int index = (int)arg;

  pthread_mutex_lock(&mutex);
  struct resume *resume = &resumes[index];
  pthread_mutex_unlock(&mutex);

  // Parse the resume.
  char skills[100] = "";
  // ...

  // Update the resume with the parsed data.
  pthread_mutex_lock(&mutex);
  resume->skills = strdup(skills);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  // Initialize the mutex.
  pthread_mutex_init(&mutex, NULL);

  // Load the resumes from a file or database.
  resumes = malloc(sizeof(struct resume) * 100);
  num_resumes = 100;

  // Create a thread pool.
  pthread_t threads[num_resumes];
  for (int i = 0; i < num_resumes; i++) {
    pthread_create(&threads[i], NULL, parse_resume, (void *)i);
  }

  // Join all the threads.
  for (int i = 0; i < num_resumes; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the parsed resumes.
  for (int i = 0; i < num_resumes; i++) {
    printf("Name: %s\n", resumes[i].name);
    printf("Email: %s\n", resumes[i].email);
    printf("Skills: %s\n\n", resumes[i].skills);
  }

  // Deallocate the memory.
  for (int i = 0; i < num_resumes; i++) {
    free(resumes[i].name);
    free(resumes[i].email);
    free(resumes[i].skills);
  }
  free(resumes);

  // Destroy the mutex.
  pthread_mutex_destroy(&mutex);

  return 0;
}