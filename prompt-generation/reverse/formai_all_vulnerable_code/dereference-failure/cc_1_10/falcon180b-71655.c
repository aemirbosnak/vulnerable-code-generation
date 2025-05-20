//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: distributed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 10

struct v {
    int i;
    char *s;
};

void *runner(void *param);

int main() {
    pthread_t workers[MAX];
    int i;
    struct v *data;

    // Initialize data
    data = (struct v *) malloc(MAX * sizeof(struct v));
    for (i = 0; i < MAX; i++) {
        data[i].i = i;
        data[i].s = (char *) malloc(10 * sizeof(char));
        sprintf(data[i].s, "Thread %d", i);
    }

    // Create threads
    for (i = 0; i < MAX; i++) {
        pthread_create(&workers[i], NULL, runner, &data[i]);
    }

    // Join threads
    for (i = 0; i < MAX; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    struct v *data = param;

    // Do some string manipulation
    char *s = data->s;
    int i = data->i;
    int len = strlen(s);
    s[len - 1] = '!';
    s[len] = '\0';

    // Print result
    printf("Thread %d processed string: %s\n", i, s);

    return NULL;
}