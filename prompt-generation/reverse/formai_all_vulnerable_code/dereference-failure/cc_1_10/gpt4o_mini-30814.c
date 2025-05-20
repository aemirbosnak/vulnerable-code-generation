//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define PAGE_SIZE 1024
#define BUFFER_SIZE 2048

typedef struct {
    char *content;
    int currentPage;
    int totalPages;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} eBookReader;

void *displayPage(void *arg) {
    eBookReader *reader = (eBookReader *)arg;
    
    while (1) {
        pthread_mutex_lock(&reader->mutex);
        pthread_cond_wait(&reader->cond, &reader->mutex);
        
        if (reader->currentPage >= reader->totalPages) {
            pthread_mutex_unlock(&reader->mutex);
            break;
        }
        
        printf("\n--- Page %d of %d ---\n", reader->currentPage + 1, reader->totalPages);
        int start = reader->currentPage * PAGE_SIZE;
        int end = start + PAGE_SIZE < strlen(reader->content) ? start + PAGE_SIZE : strlen(reader->content);
        char buffer[BUFFER_SIZE];
        strncpy(buffer, reader->content + start, end - start);
        buffer[end - start] = '\0';
        printf("%s\n", buffer);
        
        pthread_mutex_unlock(&reader->mutex);
        sleep(2); // Simulate delay for reading
    }

    return NULL;
}

void loadBook(const char *filename, eBookReader *reader) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    
    reader->content = (char *)malloc(fileSize + 1);
    fread(reader->content, 1, fileSize, file);
    reader->content[fileSize] = '\0';
    
    reader->totalPages = (fileSize + PAGE_SIZE - 1) / PAGE_SIZE;
    reader->currentPage = 0;
    
    fclose(file);
}

void nextPage(eBookReader *reader) {
    pthread_mutex_lock(&reader->mutex);
    if (reader->currentPage < reader->totalPages) {
        reader->currentPage++;
        pthread_cond_signal(&reader->cond);
    }
    pthread_mutex_unlock(&reader->mutex);
}

void prevPage(eBookReader *reader) {
    pthread_mutex_lock(&reader->mutex);
    if (reader->currentPage > 0) {
        reader->currentPage--;
        pthread_cond_signal(&reader->cond);
    }
    pthread_mutex_unlock(&reader->mutex);
}

int main(void) {
    eBookReader reader;
    pthread_t displayThread;

    pthread_mutex_init(&reader.mutex, NULL);
    pthread_cond_init(&reader.cond, NULL);

    loadBook("book.txt", &reader);

    pthread_create(&displayThread, NULL, displayPage, &reader);

    char command;
    while (1) {
        printf("\nEnter 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        command = getchar();
        while (getchar() != '\n'); // clear buffer

        if (command == 'n') {
            nextPage(&reader);
        } else if (command == 'p') {
            prevPage(&reader);
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    pthread_mutex_lock(&reader.mutex);
    reader.currentPage = reader.totalPages; // Signal the display thread to finish
    pthread_cond_signal(&reader.cond);
    pthread_mutex_unlock(&reader.mutex);

    pthread_join(displayThread, NULL);
    free(reader.content);
    pthread_mutex_destroy(&reader.mutex);
    pthread_cond_destroy(&reader.cond);
    
    return 0;
}