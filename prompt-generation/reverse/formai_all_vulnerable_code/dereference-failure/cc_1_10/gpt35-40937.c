//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define READ_BUFFER_SIZE 512

typedef struct {
    unsigned long long allocatedSize;
    unsigned long long usedSize;
    char *path;
} DirUsageData;

int parseFile(const char *buffer, unsigned long long *allocatedSize, unsigned long long *actualSize) {
    int i = 0, percentIdx = -1;
    int len=strlen(buffer);
    int foundStart=0;
    char numberBuffer[20];

    for (i = 0; i < len; ++i) {
        if(buffer[i] == '/') {
            foundStart = 1;
        }

        if(foundStart) {
            if(buffer[i] == '%') {
                percentIdx = i;
                break;
            }
        }
    }

    if(percentIdx == -1) {
        return 0;
    }

    foundStart = 0;
    int readIndex = 0;

    for (i = percentIdx; i > 0; --i) {
        if(buffer[i] == ' ') {
            if(!foundStart) {
                foundStart = 1;
            } else {
                break;
            }
        }

        if(foundStart) {
            numberBuffer[readIndex++] = buffer[i];
        }
    }

    numberBuffer[readIndex++] = '\0';

    *allocatedSize = strtoull(numberBuffer, NULL, 10) * 512;

    foundStart = 0;
    readIndex = 0;

    for (i = percentIdx; i < len; ++i) {
        if(buffer[i] == ' ') {
            if(!foundStart) {
                foundStart = 1;
            } else {
                break;
            }
        }

        if(foundStart) {
            numberBuffer[readIndex++] = buffer[i];
        }
    }

    numberBuffer[readIndex++] = '\0';

    *actualSize = strtoull(numberBuffer, NULL, 10) * 512;

    return 1;
}

void analyseDirAsync(char *path, void (*callback)(DirUsageData)) {
    pid_t pid = fork();

    if(pid == 0) {
        chdir(path);
        int fd = open("/dev/null", O_WRONLY);

        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);

        execl("/usr/bin/du", "du", "-sk", ".", NULL);

        _exit(127);
    } else if(pid > 0) {
        int wstatus;

        if(wait(&wstatus) == -1) {
            return;
        }

        if(WIFEXITED(wstatus) && !WEXITSTATUS(wstatus)) {
            char buffer[READ_BUFFER_SIZE];

            FILE *fp = fopen("result.txt", "r");

            if(fp != NULL) {
                if(fread(buffer, READ_BUFFER_SIZE, 1, fp)) {
                    fclose(fp);
                    unlink("result.txt");

                    unsigned long long allocatedSize, actualSize;

                    if(parseFile(buffer, &allocatedSize, &actualSize)) {
                        DirUsageData data = {allocatedSize, actualSize, path};
                        callback(data);
                    }
                } else {
                    fclose(fp);
                    unlink("result.txt");

                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
    } else {
        return;
    }
}

void printDirUsage(DirUsageData data) {
    printf("%s => Allocated : %llu, Used : %llu\n", data.path, data.allocatedSize, data.usedSize);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 0;
    }

    DIR *dir = opendir(argv[1]);

    if (dir) {
        struct dirent *entry;
        char path[PATH_MAX];

        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type & DT_DIR) {
                if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    strcpy(path, argv[1]);
                    strcat(path, "/");
                    strcat(path, entry->d_name);

                    analyseDirAsync(path, printDirUsage);
                }
            }
        }

        closedir(dir);
    } else {
        printf("Could not open directory %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}