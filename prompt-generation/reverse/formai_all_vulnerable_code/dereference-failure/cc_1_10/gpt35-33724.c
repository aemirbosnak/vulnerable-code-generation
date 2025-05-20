//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct thread_data {
  int start_index;
  int end_index;
};

int *log_data;
int *result;
pthread_mutex_t lock;

void *analyze_logs(void *thread_arg) {
  struct thread_data *data;
  data = (struct thread_data *) thread_arg;
  int index, logs_analyzed = 0, errors_found = 0;

  for(index = data->start_index; index <= data->end_index; index++) {
    logs_analyzed++;
    if(log_data[index] < 0) {
      errors_found++;
    }
  }

  pthread_mutex_lock(&lock);
  result[0] += logs_analyzed;
  result[1] += errors_found;
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main() {
  int num_logs = 1000, num_threads = 10, i;
  pthread_t threads[num_threads];
  struct thread_data thread_data_array[num_threads];

  log_data = (int *)malloc(sizeof(int) * num_logs);
  result = (int *)malloc(sizeof(int) * 2);

  for(i = 0; i < num_logs; i++) {
    log_data[i] = rand() % 100 - 50;
  }

  pthread_mutex_init(&lock, NULL);
  result[0] = 0;
  result[1] = 0;

  for(i = 0; i < num_threads; i++) {
    thread_data_array[i].start_index = i * num_logs/num_threads;
    thread_data_array[i].end_index = thread_data_array[i].start_index + num_logs/num_threads - 1;
    pthread_create(&threads[i], NULL, analyze_logs, (void *) &thread_data_array[i]);
  }

  for(i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&lock);

  printf("Total logs analyzed: %d\n", result[0]);
  printf("Number of errors found: %d\n", result[1]);

  free(log_data);
  free(result);
  return 0;
}