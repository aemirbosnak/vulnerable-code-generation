//FormAI DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_BOOKS 5
#define MAX_PAGES 20

int current_page[MAX_THREADS]; // Array to keep track of current page being read by each thread
int num_threads; // Number of threads to be created
char books[MAX_BOOKS][MAX_PAGES][100]; // Array to store books with their pages

// Thread function to read pages from a given book
void *read_book(void *arg) {
    int thread_id = *((int *)arg); // Get the thread ID
    int book_id = thread_id % MAX_BOOKS; // Calculate book ID for this thread based on its ID
    int page_num = 0; // Starting page number
    while (page_num < MAX_PAGES) {
        printf("Thread %d reading page %d of book %d: %s\n", thread_id, page_num+1, book_id+1, books[book_id][page_num]);
        current_page[thread_id] = page_num; // Update array with current page being read by this thread
        page_num++; // Move to the next page
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS]; // Array to store thread IDs
    int thread_args[MAX_THREADS]; // Array to store arguments for each thread
    int i;

    // Initialize books with some data
    for (i = 0; i < MAX_BOOKS; i++) {
        int j;
        for (j = 0; j < MAX_PAGES; j++) {
            sprintf(books[i][j], "Book %d, page %d", i+1, j+1);
        }
    }

    // Get number of threads to be created
    printf("Enter the number of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // Create threads and start reading books
    for (i = 0; i < num_threads; i++) {
        thread_args[i] = i; // Save thread ID as argument
        pthread_create(&threads[i], NULL, read_book, &thread_args[i]); // Create thread
    }

    // Wait for all threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}