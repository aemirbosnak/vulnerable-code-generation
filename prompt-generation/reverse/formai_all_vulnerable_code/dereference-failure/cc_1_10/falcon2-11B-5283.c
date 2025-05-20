//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 256
#define MAX_FILES 1000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *scan_file(void *args) {
    struct stat buffer;
    int fd;
    char filename[BUF_SIZE];
    char *virus_list = (char *) args;

    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);

        if (pthread_equal(pthread_self(), args)) {
            strcpy(filename, *virus_list);
            *virus_list = (char *) malloc(BUF_SIZE);
            if (stat(filename, &buffer) == -1) {
                printf("Error: Unable to stat file %s\n", filename);
            } else if (S_ISREG(buffer.st_mode)) {
                fd = open(filename, O_RDONLY);
                if (fd < 0) {
                    printf("Error: Unable to open file %s\n", filename);
                } else {
                    char buf[BUF_SIZE];
                    while (read(fd, buf, BUF_SIZE) > 0) {
                        for (int i = 0; i < strlen(virus_list); i++) {
                            if (strstr(buf, virus_list[i])!= NULL) {
                                printf("Found virus in file %s\n", filename);
                                close(fd);
                                unlink(filename);
                                break;
                            }
                        }
                    }
                    close(fd);
                    free(filename);
                }
            }
        }

        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char **argv) {
    int i;
    char *virus_list = (char *) malloc(MAX_FILES * BUF_SIZE);
    DIR *dir;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error: Unable to open directory");
        return 1;
    }

    for (i = 0; i < MAX_FILES; i++) {
        strcpy(virus_list[i], "virus");
    }

    pthread_t threads[argc];
    for (i = 0; i < argc; i++) {
        pthread_create(&threads[i], NULL, scan_file, (void *) virus_list);
    }

    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    for (i = 0; i < argc; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dir);
    free(virus_list);

    return 0;
}