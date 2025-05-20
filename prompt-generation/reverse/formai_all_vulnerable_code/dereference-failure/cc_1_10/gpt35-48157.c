//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 256

// struct declaration for passing to thread function
typedef struct thread_data {
  char* input_str;
} thread_data_t;

// cleans input string by removing new line characters.
void clean_input_str(char* input_str) {
  int i = 0;
  while(input_str[i] != '\0') {
    if(input_str[i] == '\n') {
      input_str[i] = '\0';
      return;
    }
    i++;
  }
}

// thread function to prompt user for input
void* get_input(void* arg) {
  thread_data_t* td = (thread_data_t*)arg;
  printf("Enter a string: ");
  fgets(td->input_str, MAX_INPUT_LENGTH, stdin);
  clean_input_str(td->input_str); //clean input string
  pthread_exit(NULL);
}

int main() {
  // initialize and set thread attributes
  pthread_t input_thread;
  thread_data_t td;
  td.input_str = (char*)malloc(sizeof(char)*MAX_INPUT_LENGTH);
  
  pthread_attr_t thread_attr;
  pthread_attr_init(&thread_attr);
  pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);

  // create and join thread
  if(pthread_create(&input_thread, &thread_attr, get_input, (void*)&td) != 0) {
    fprintf(stderr, "Error creating input thread\n");
    exit(1);
  }
  pthread_join(input_thread, NULL);

  // print sanitized input string
  printf("Sanitized Input String: %s\n", td.input_str);
  
  // clean up memory and destroy thread attributes object
  free(td.input_str);
  pthread_attr_destroy(&thread_attr);
  return 0;
}