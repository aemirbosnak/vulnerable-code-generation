//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the CSV file path
#define CSV_FILE "data.csv"

// Define the number of threads
#define NUM_THREADS 4

// Define the maximum line length
#define MAX_LINE_LENGTH 1024

// Define the maximum number of fields per line
#define MAX_FIELDS_PER_LINE 10

// Define the delimiter
#define DELIMITER ","

// Define the thread data structure
typedef struct thread_data {
  int thread_id;
  int start_line;
  int end_line;
  char **lines;
  int num_lines;
} thread_data;

// Define the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to read a line from a file
char *read_line(FILE *file) {
  char *line = NULL;
  size_t len = 0;
  if (getline(&line, &len, file) != -1) {
    // Remove the newline character
    line[strcspn(line, "\n")] = '\0';
  }
  return line;
}

// Function to split a line into fields
char **split_line(char *line, int *num_fields) {
  char **fields = NULL;
  *num_fields = 0;
  char *field = strtok(line, DELIMITER);
  while (field != NULL) {
    fields = realloc(fields, (*num_fields + 1) * sizeof(char *));
    fields[*num_fields] = field;
    (*num_fields)++;
    field = strtok(NULL, DELIMITER);
  }
  return fields;
}

// Function to read the CSV file
char **read_csv(int *num_lines) {
  // Open the CSV file
  FILE *file = fopen(CSV_FILE, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the first line to get the number of fields
  char *line = read_line(file);
  int num_fields;
  char **fields = split_line(line, &num_fields);
  free(line);

  // Allocate memory for the lines
  char **lines = malloc(MAX_LINE_LENGTH * sizeof(char *));

  // Read the rest of the lines
  int i = 0;
  while ((line = read_line(file)) != NULL) {
    lines[i] = line;
    i++;
  }

  // Close the CSV file
  fclose(file);

  *num_lines = i;

  return lines;
}

// Function to process a line of the CSV file
void process_line(char **fields, int num_fields) {
  // Do something with the fields
  for (int i = 0; i < num_fields; i++) {
    printf("%s ", fields[i]);
  }
  printf("\n");
}

// Function to be executed by each thread
void *thread_function(void *arg) {
  // Get the thread data
  thread_data *data = (thread_data *)arg;

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Process the lines assigned to this thread
  for (int i = data->start_line; i < data->end_line; i++) {
    char **fields;
    int num_fields;
    fields = split_line(data->lines[i], &num_fields);
    process_line(fields, num_fields);
    free(fields);
  }

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  // Read the CSV file
  char **lines;
  int num_lines;
  lines = read_csv(&num_lines);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_data *data = malloc(sizeof(thread_data));
    data->thread_id = i;
    data->start_line = i * (num_lines / NUM_THREADS);
    data->end_line = (i + 1) * (num_lines / NUM_THREADS);
    data->lines = lines;
    data->num_lines = num_lines;
    pthread_create(&threads[i], NULL, thread_function, data);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Free the memory
  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }
  free(lines);

  return 0;
}