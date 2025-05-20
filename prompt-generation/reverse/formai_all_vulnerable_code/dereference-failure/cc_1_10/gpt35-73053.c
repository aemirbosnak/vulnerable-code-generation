//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define CHUNK_SIZE 1024

typedef struct _thread_data_t {
  int thread_id;
  unsigned char *data;
  unsigned long chunk_size;
  unsigned long *checksum;
} thread_data_t;

void *calc_checksum(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
  int i;

  unsigned long sum = 0;
  for (i = 0; i < data->chunk_size; i++) {
    sum += data->data[i];
  }
  *(data->checksum) = sum;

  pthread_exit(NULL);
}

int main(void) {
  FILE *fp;
  int i, rv;

  fp = fopen("file.data", "rb");
  if (fp == NULL) {
    printf("Error: Unable to open file\n");
    exit(1);
  }

  // determine file size
  fseek(fp, 0, SEEK_END);
  unsigned long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // allocate memory for file data
  unsigned char *file_data = (unsigned char*) malloc(file_size);
  if (file_data == NULL) {
    printf("Error: Unable to allocate memory\n");
    fclose(fp);
    exit(1);
  }

  // read file data into memory
  fread(file_data, 1, file_size, fp);
  fclose(fp);

  // allocate memory for thread data
  thread_data_t thread_data[MAX_THREADS];
  pthread_t threads[MAX_THREADS];
  unsigned long chunk_size = file_size / MAX_THREADS;
  for (i = 0; i < MAX_THREADS; i++) {
    thread_data[i].thread_id = i;
    thread_data[i].data = file_data + (chunk_size * i);
    thread_data[i].checksum = (unsigned long*) malloc(sizeof(unsigned long));
    *(thread_data[i].checksum) = 0;
    if (i == MAX_THREADS - 1) {
      thread_data[i].chunk_size = file_size - (chunk_size * i);
    } else {
      thread_data[i].chunk_size = chunk_size;
    }
  }

  // start threads
  for (i = 0; i < MAX_THREADS; i++) {
    rv = pthread_create(&threads[i], NULL, calc_checksum, (void *)&thread_data[i]);
    if (rv) {
      printf("Error: Unable to create thread %d\n", i);
      exit(1);
    }
  }

  // join threads and sum checksums
  unsigned long checksum = 0;
  for (i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
    checksum += *(thread_data[i].checksum);
    free(thread_data[i].checksum);
  }

  printf("Checksum: %lu\n", checksum);
  free(file_data);

  return 0;
}