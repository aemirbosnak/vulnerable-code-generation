//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_USERS 10

pthread_mutex_t mutex_books;
int available_books = MAX_BOOKS;

void *borrow_book(void *user_id) {
    int id = *((int *)user_id);
    printf("User %d trying to borrow a book...\n", id);

    pthread_mutex_lock(&mutex_books);
    if (available_books > 0) {
        available_books--;
        printf("User %d borrowed a book. Books left: %d\n", id, available_books);
    } else {
        printf("User %d couldn't borrow a book. No books available!\n", id);
    }
    pthread_mutex_unlock(&mutex_books);

    // Simulate the time taken to read the book
    sleep(rand() % 3 + 1);

    // Return the book
    pthread_mutex_lock(&mutex_books);
    available_books++;
    printf("User %d returned a book. Books left: %d\n", id, available_books);
    pthread_mutex_unlock(&mutex_books);
    
    free(user_id);
    return NULL;
}

int main() {
    pthread_t threads[MAX_USERS];
    srand(time(NULL));

    pthread_mutex_init(&mutex_books, NULL);

    printf("Welcome to the Library System!\n");
    
    for (int i = 0; i < MAX_USERS; i++) {
        int *user_id = malloc(sizeof(int));
        *user_id = i + 1;
        pthread_create(&threads[i], NULL, borrow_book, user_id);
    }

    for (int i = 0; i < MAX_USERS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex_books);
    printf("All operations complete. Closing Library System.\n");
    
    return 0;
}