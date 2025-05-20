//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
  int id;
  char* message;
} thread_args;

void* print_message(void* arg) {
  thread_args* args = (thread_args*) arg;
  printf("Thread %d says: %s\n", args->id, args->message);
  free(args->message);
  free(args);
  return NULL;
}

int main() {
  pthread_t thread1, thread2;
  thread_args* args1 = malloc(sizeof(thread_args));
  thread_args* args2 = malloc(sizeof(thread_args));
  
  args1->id = 1;
  args1->message = malloc(sizeof(char) * 20);
  strcpy(args1->message, "Hello World!");
  
  args2->id = 2;
  args2->message = malloc(sizeof(char) * 30);
  strcpy(args2->message, "This is a unique program!");

  if (pthread_create(&thread1, NULL, &print_message, args1) != 0) {
    perror("pthread_create error");
    return 1;
  }

  if (pthread_create(&thread2, NULL, &print_message, args2) != 0) {
    perror("pthread_create error");
    return 1;
  }

  if (pthread_join(thread1, NULL) != 0) {
    perror("pthread_join error");
    return 1;
  }

  if (pthread_join(thread2, NULL) != 0) {
    perror("pthread_join error");
    return 1;
  }

  printf("Threads ended successfully!\n");
  
  return 0;
}