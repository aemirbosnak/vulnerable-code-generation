//FormAI DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BOOKS 10
#define MAX_THREADS 3

int book_index = 0;
int library[MAX_BOOKS];
int reader_flag[MAX_THREADS] = {0, 0, 0};
pthread_mutex_t lock;

void add_book(int *book_count)
{
    pthread_mutex_lock(&lock);
    if (*book_count < MAX_BOOKS)
    {
        printf("Book %d added to the library.\n", *book_count + 1);
        library[*book_count] = *book_count + 1;
        (*book_count)++;
    }
    pthread_mutex_unlock(&lock);
}

void* read_book(void *arg)
{
    int reader_id = *((int *)arg);
    printf("Reader %d is waiting for a book to be available...\n", reader_id + 1);

    while (book_index < MAX_BOOKS)
    {
        pthread_mutex_lock(&lock);
        if (reader_flag[reader_id] == 0 && book_index < MAX_BOOKS)
        {
            reader_flag[reader_id] = 1;
            printf("Reader %d is reading book %d...\n", reader_id + 1, library[book_index]);
            book_index++;
            reader_flag[reader_id] = 0;
        }
        pthread_mutex_unlock(&lock);
    }

    printf("All books have been read. Reader %d is exiting.\n", reader_id + 1);
    pthread_exit(NULL);
}

int main()
{
    int i = 0;
    int book_count = 0;

    pthread_t readers[MAX_THREADS];

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < MAX_THREADS; i++)
    {
        int *reader_id = (int *)malloc(sizeof(int));
        *reader_id = i;
        pthread_create(&readers[i], NULL, read_book, (void*)reader_id);
    }

    while (book_count < MAX_BOOKS)
    {
        sleep(1);
        add_book(&book_count);
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(readers[i], NULL);
    }

    printf("All readers have finished reading all the books. The program has ended.\n");

    pthread_mutex_destroy(&lock);

    return 0;
}