//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t write_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t read_cond = PTHREAD_COND_INITIALIZER;

char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                "...","-","..-","...-",".--","-..-","-.--","--.."};

char* alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                    "j", "k", "l", "m", "n", "o", "p", "q", "r",
                    "s", "t", "u", "v", "w", "x", "y", "z"};

char* buffer;
int write_ptr = 0;
int read_ptr = 0;
int buf_size;

void *write_chars(void *arg) {
    int i = 0;
    while (i < strlen(buffer)) {
        pthread_mutex_lock(&mutex);
        while ((write_ptr+1)%buf_size == read_ptr%buf_size) {
            pthread_cond_wait(&write_cond, &mutex);
        }
        buffer[write_ptr] = buffer[i];
        write_ptr = (write_ptr + 1) % buf_size;
        i++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&read_cond);
    }
    return NULL;
}

void *convert_morse(void *arg) {
    char *sentence = (char*) arg;
    for (int i = 0; i < strlen(sentence); i++) {
        pthread_mutex_lock(&mutex);
        while (write_ptr == read_ptr) {
            pthread_cond_wait(&read_cond, &mutex);
        }
        char c = buffer[read_ptr];
        read_ptr = (read_ptr + 1) % buf_size;
        pthread_mutex_unlock(&mutex);
        for (int j = 0; j < 26; j++) {
            if (c == alphabet[j][0]) {
                printf("%s ", morse[j]);
            }
        }
        fflush(stdout);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: ./morse <string to convert>\n");
        return 1;
    }
    buf_size = strlen(argv[1]) + 1;
    buffer = (char*) malloc(buf_size);
    pthread_t writer_tid;
    pthread_t convert_tid;
    pthread_create(&writer_tid, NULL, write_chars, NULL);
    pthread_create(&convert_tid, NULL, convert_morse, argv[1]);
    pthread_join(writer_tid, NULL);
    pthread_join(convert_tid, NULL);
    printf("\n");
    return 0;
}