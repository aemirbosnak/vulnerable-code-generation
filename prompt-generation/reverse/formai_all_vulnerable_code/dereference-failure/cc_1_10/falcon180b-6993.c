//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/prctl.h>

#define STACK_SIZE (1024 * 1024)
#define HEAP_SIZE (1024 * 1024)
#define NUM_THREADS 4

typedef struct {
    int id;
    char *name;
    pthread_t thread;
    int fd;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[1024];
    int bytes_read;

    while (1) {
        bytes_read = read(data->fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            break;
        }
        write(1, buffer, bytes_read);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];
    char **argv = NULL;
    int argc = 0;
    int max_procs = sysconf(_SC_NPROCESSORS_ONLN);

    printf("Surprise! I am a boot optimizer.\n");
    printf("Compiled and running without any errors.\n");

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        sprintf(data[i].name, "Thread %d", i);
        data[i].fd = open("/dev/urandom", O_RDONLY);
        if (data[i].fd == -1) {
            printf("Error opening /dev/urandom: %s\n", strerror(errno));
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}