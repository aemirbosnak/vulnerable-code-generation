//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_info {
	int id;
	int *array;
	int size;
};

void *thread_fn(void *arg)
{
	struct thread_info *info = (struct thread_info *)arg;
	int sum = 0;
	for (int i = 0; i < info->size; i++) {
		sum += info->array[i];
	}
	printf("Thread %d: sum = %d\n", info->id, sum);
	return NULL;
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <size> <num_threads>\n", argv[0]);
		exit(1);
	}

	int size = atoi(argv[1]);
	int num_threads = atoi(argv[2]);

	int array[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10;
	}

	pthread_t threads[num_threads];
	struct thread_info info[num_threads];

	for (int i = 0; i < num_threads; i++) {
		info[i].id = i;
		info[i].array = array;
		info[i].size = size / num_threads;
		pthread_create(&threads[i], NULL, thread_fn, &info[i]);
	}

	for (int i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	int total_sum = 0;
	for (int i = 0; i < size; i++) {
		total_sum += array[i];
	}
	printf("Total sum: %d\n", total_sum);

	return 0;
}