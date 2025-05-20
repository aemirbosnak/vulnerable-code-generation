//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

/* Define a structure to hold details of a book */
struct Book {
    char title[50];
    char author[50];
    int pages;
};

/* Define a queue data structure using a linked list */
struct Node {
    struct Book book;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

/* Initialize the queue */
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

/* Check if queue is empty */
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

/* Add a book to the end of the queue */
void enqueue(struct Queue* q, struct Book book) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->book = book;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

/* Remove the first book in the queue */
struct Book dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        struct Book emptyBook;
        return emptyBook;
    } else {
        struct Node* temp = q->front;
        struct Book tempBook = temp->book;
        q->front = temp->next;
        free(temp);
        return tempBook;
    }
}

/* Function that adds books to the queue */
void* writer(void* q) {
    for (int i = 0; i < 10; i++) {
        struct Book newBook;
        sprintf(newBook.title, "Book %d", i);
        sprintf(newBook.author, "Author %d", i);
        newBook.pages = 200 + i*10;
        printf("Adding book '%s' to queue\n", newBook.title);
        enqueue((struct Queue*) q, newBook);
        sleep(1);
    }
}

/* Function that removes books from the queue */
void* reader(void* q) {
    for (int i = 0; i < 10; i++) {
        struct Book readBook = dequeue((struct Queue*) q);
        printf("Reading book '%s' by %s (%d pages)\n", readBook.title, readBook.author, readBook.pages);
        sleep(2);
    }
}

int main() {
    struct Queue bookQueue;
    initQueue(&bookQueue);

    pthread_t writerThread;
    pthread_t readerThread;

    pthread_create(&writerThread, NULL, writer, (void*) &bookQueue);
    pthread_create(&readerThread, NULL, reader, (void*) &bookQueue);

    pthread_join(writerThread, NULL);
    pthread_join(readerThread, NULL);

    return 0;
}