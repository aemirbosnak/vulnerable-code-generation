//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* get_process_info(void* arg) {
    pid_t pid = *((pid_t*)arg);
    char buf[1024];
    FILE* pipe = popen("ps -o pid,args -p " + pid, "r");
    if (pipe == NULL) {
        perror("popen");
        return NULL;
    }
    fgets(buf, sizeof(buf), pipe);
    pclose(pipe);
    pthread_mutex_lock(&mutex);
    printf("Process %d: %s\n", pid, buf);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[5];
    pid_t pids[5];
    int i;
    for (i = 0; i < 5; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork");
            return 1;
        } else if (pids[i] == 0) {
            // child process
            exit(0);
        } else {
            // parent process
            pids[i] = waitpid(pids[i], NULL, 0);
            if (pids[i] < 0) {
                perror("waitpid");
                return 1;
            }
            pthread_create(&threads[i], NULL, get_process_info, &pids[i]);
        }
    }
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}