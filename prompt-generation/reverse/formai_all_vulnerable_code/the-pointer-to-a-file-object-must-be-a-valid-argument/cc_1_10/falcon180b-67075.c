//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINES 1000
#define BUFFER_SIZE 80

typedef struct {
    char *text;
    int start;
    int end;
} Line;

Line lines[MAX_LINES];
int num_lines = 0;

void *print_line(void *arg) {
    int i = *(int *) arg;
    printf("%s", lines[i].text);
    pthread_exit(NULL);
}

void read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[BUFFER_SIZE];
    int i = 0;

    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (num_lines >= MAX_LINES) {
            printf("Error: Too many lines in file.\n");
            break;
        }
        lines[i].text = strdup(line);
        lines[i].start = i * 25;
        lines[i].end = (i + 1) * 25 - 1;
        if (i == 0) {
            lines[i].start = 0;
        }
        i++;
        num_lines++;
    }

    fclose(fp);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    read_file("example.txt");

    for (i = 0; i < num_lines; i++) {
        pthread_create(&threads[i], NULL, print_line, &i);
    }

    for (i = 0; i < num_lines; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}