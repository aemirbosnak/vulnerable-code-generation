//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 10000

struct word_info {
    char word[50];
    int count;
};

struct args {
    int start;
    int end;
};

pthread_mutex_t lock;
struct word_info words[MAX_WORDS];
int word_count = 0;

void *count_words(void *arg) {
    struct args *pos = (struct args *) arg;
    int start = pos->start;
    int end = pos->end;
    char buffer[1024];
    char *word;
    int i, j, len;

    for (i = start; i < end; ++i) {
        fgets(buffer, 1024, stdin);
        len = strlen(buffer);

        if (buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }

        for (j = 0; j < len; ++j) {
            if (buffer[j] >= 'A' && buffer[j] <= 'Z') {
                buffer[j] += 32;
            }
        }

        word = strtok(buffer, " ");

        while (word != NULL) {
            pthread_mutex_lock(&lock);

            for (j = 0; j < word_count; ++j) {
                if (strcmp(words[j].word, word) == 0) {
                    ++words[j].count;
                    break;
                }
            }

            if (j == word_count) {
                strcpy(words[j].word, word);
                words[j].count = 1;
                ++word_count;
            }

            pthread_mutex_unlock(&lock);
            word = strtok(NULL, " ");
        }
    }

    pthread_exit(NULL);
}

void merge_sort(int left, int right) {
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);

    struct word_info tmp[MAX_WORDS];
    int i = left;
    int j = mid+1;
    int k = 0;

    while (i <= mid || j <= right) {
        if (i > mid) {
            tmp[k++] = words[j++];
        } else if (j > right) {
            tmp[k++] = words[i++];
        } else if (words[i].count < words[j].count) {
            tmp[k++] = words[j++];
        } else {
            tmp[k++] = words[i++];
        }
    }

    for (i = 0; i < k; ++i) {
        words[left+i] = tmp[i];
    }
}

int main() {
    int num_threads, i;
    pthread_t *threads;
    struct args *positions;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    threads = (pthread_t *) malloc(num_threads * sizeof(pthread_t));
    positions = (struct args *) malloc(num_threads * sizeof(struct args));

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < num_threads; ++i) {
        positions[i].start = i * (MAX_WORDS / num_threads);
        positions[i].end = (i+1) * (MAX_WORDS / num_threads);
        pthread_create(&threads[i], NULL, count_words, &positions[i]);
    }

    for (i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    merge_sort(0, word_count-1);

    for (i = 0; i < word_count; ++i) {
        printf("%d %s\n", words[i].count, words[i].word);
    }

    free(threads);
    free(positions);

    return 0;
}