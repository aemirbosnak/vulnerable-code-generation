//FormAI DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_EBOOK_PAGES 10000
#define MAX_THREADS 10

int ebook_pages[MAX_EBOOK_PAGES];
int current_page = 0;
int num_threads;
pthread_mutex_t mutex;

void* reader(void* tid) {
    int thread_id = *(int*)tid;
    int pages_per_thread = MAX_EBOOK_PAGES / num_threads;
    int start_page = thread_id * pages_per_thread;
    int end_page = start_page + pages_per_thread;
    if(thread_id == num_threads - 1) end_page = MAX_EBOOK_PAGES;
    for(int i = start_page; i < end_page; i++) {
        pthread_mutex_lock(&mutex);
        int page_data = ebook_pages[i];
        current_page++;
        pthread_mutex_unlock(&mutex);
        // Do something with the page data (e.g. display it to the user)
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }
    num_threads = atoi(argv[1]);
    if(num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d\n", MAX_THREADS);
        return 1;
    }
    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < MAX_EBOOK_PAGES; i++) {
        ebook_pages[i] = i;
    }
    for(int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, reader, (void*)&thread_ids[i]);
    }
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("Finished reading ebook. Current page: %d\n", current_page);
    return 0;
}