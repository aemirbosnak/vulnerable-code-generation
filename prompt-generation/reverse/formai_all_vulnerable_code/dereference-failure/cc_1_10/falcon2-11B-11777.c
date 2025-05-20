//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_MSG_SIZE 100

typedef struct {
    char msg[MAX_MSG_SIZE];
    char *sender;
    int sender_id;
} message_t;

int compare_messages(const void *a, const void *b) {
    message_t *m1 = (message_t *)a;
    message_t *m2 = (message_t *)b;
    if (strcmp(m1->msg, m2->msg) < 0)
        return -1;
    else if (strcmp(m1->msg, m2->msg) > 0)
        return 1;
    else
        return 0;
}

void *send_message(void *data) {
    message_t *m = (message_t *)data;
    int fd = open("message_queue", O_WRONLY);
    if (fd < 0) {
        perror("open");
        return NULL;
    }
    char *msg = m->msg;
    write(fd, msg, strlen(msg));
    close(fd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <sender_id> <message>\n", argv[0]);
        return 1;
    }

    int sender_id = atoi(argv[1]);
    char *message = argv[2];

    message_t *m = malloc(sizeof(message_t));
    if (!m) {
        perror("malloc");
        return 1;
    }
    strncpy(m->msg, message, MAX_MSG_SIZE - 1);
    m->sender = strdup(argv[1]);
    m->sender_id = sender_id;

    qsort(m, 1, sizeof(message_t), compare_messages);

    pthread_t tid[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&tid[i], NULL, send_message, (void *)m);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(tid[i], NULL);
    }

    free(m);
    return 0;
}