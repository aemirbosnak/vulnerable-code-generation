//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_WORDS 1000000 //maximum number of words
#define NUM_THREADS 4 //number of threads
#define PORT 8080 //port number

struct word_count {
    char word[50];
    int count;
};

struct word_count *word_list; //pointer to the word count list

void *count_words(void *arg) {
    int i, j;
    char *line;
    char *word;
    FILE *file;
    file = fopen("spam.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    word_list = (struct word_count *)malloc(MAX_WORDS * sizeof(struct word_count));
    if (word_list == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    for (i = 0; i < MAX_WORDS; i++) {
        word_list[i].count = 0;
    }
    while ((line = fgets(line, 1000, file))!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (j = 0; j < i; j++) {
                if (strcmp(word, word_list[j].word) == 0) {
                    word_list[j].count++;
                    break;
                }
            }
            if (j == i) {
                strcpy(word_list[i].word, word);
                word_list[i].count++;
                i++;
                if (i == MAX_WORDS) {
                    break;
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
    pthread_exit(0);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, count_words, NULL);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}