//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PID_LENGTH 64
#define MAX_PROC_NAME_LENGTH 256
#define MAX_STAT_LENGTH 4096

typedef struct {
    char pid[MAX_PID_LENGTH];
    char name[MAX_PROC_NAME_LENGTH];
    char state;
    unsigned long long int utime;
    unsigned long long int stime;
    unsigned long long int vsize;
} ProcInfo;

int isNumber(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int readProcInfoFromStatFile(const char* filepath, ProcInfo* info) {
    char stat_buf[MAX_STAT_LENGTH];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    int nread = read(fd, stat_buf, MAX_STAT_LENGTH);
    close(fd);
    if (nread <= 0) {
        return -1;
    }
    char *pch = strtok(stat_buf, " ");
    for (int i = 0; i < 22; i++) {
        pch = strtok(NULL, " ");
        if (pch == NULL) {
            return -1;
        }
        if (i == 0) {
            strncpy(info->pid, pch, MAX_PID_LENGTH - 1);
        }
        if (i == 1) {
            strncpy(info->name, pch, MAX_PROC_NAME_LENGTH - 1);
        }
        if (i == 2) {
            info->state = pch[0];
        }
        if (i == 13) {
            info->utime = strtoull(pch, NULL, 10);
        }
        if (i == 14) {
            info->stime = strtoull(pch, NULL, 10);
        }
        if (i == 22) {
            info->vsize = strtoull(pch, NULL, 10);
        }
    }
    return 0;
}

int getProcessList(ProcInfo*** procListPtr) {
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");
    if (!d) {
        return -1;
    }
    int procCount = 0;
    ProcInfo** procList = NULL;
    while ((dir = readdir(d)) != NULL) {
        if (isNumber(dir->d_name)) {
            char stat_file_path[MAX_PID_LENGTH + 12];
            snprintf(stat_file_path, sizeof(stat_file_path), "/proc/%s/stat", dir->d_name);
            ProcInfo* info = (ProcInfo*)malloc(sizeof(ProcInfo));
            if (readProcInfoFromStatFile(stat_file_path, info) == 0) {
                procCount++;
                procList = (ProcInfo**)realloc(procList, sizeof(ProcInfo*) * procCount);
                procList[procCount - 1] = info;
            } else {
                free(info);
            }
        }
    }
    closedir(d);
    *procListPtr = procList;
    return procCount;
}

int compareByVSizeAsc(const void* a, const void* b) {
    const ProcInfo* pa = *(const ProcInfo**)a;
    const ProcInfo* pb = *(const ProcInfo**)b;
    if (pa->vsize < pb->vsize) {
        return -1;
    } else if (pa->vsize > pb->vsize) {
        return 1;
    }
    return 0;
}

int compareByVSizeDesc(const void* a, const void* b) {
    return compareByVSizeAsc(b, a);
}

int compareByTimeSpentAsc(const void* a, const void* b) {
    const ProcInfo* pa = *(const ProcInfo**)a;
    const ProcInfo* pb = *(const ProcInfo**)b;
    if (pa->utime + pa->stime < pb->utime + pb->stime) {
        return -1;
    } else if (pa->utime + pa->stime > pb->utime + pb->stime) {
        return 1;
    }
    return 0;
}

int compareByTimeSpentDesc(const void* a, const void* b) {
    return compareByTimeSpentAsc(b, a);
}

void printProcessList(ProcInfo** procList, int procCount, int sortedBy, int sortAsc) {
    printf("PID\tNAME\tSTATE\tVSZ\tTIME\n");
    printf("----------------------------------\n");
    ProcInfo** sortedProcList = (ProcInfo**)malloc(sizeof(ProcInfo*) * procCount);
    memcpy(sortedProcList, procList, sizeof(ProcInfo*) * procCount);
    switch (sortedBy) {
        case 0:
            qsort(sortedProcList, procCount, sizeof(ProcInfo*), sortAsc ? compareByVSizeAsc : compareByVSizeDesc);
            break;
        case 1:
            qsort(sortedProcList, procCount, sizeof(ProcInfo*), sortAsc ? compareByTimeSpentAsc : compareByTimeSpentDesc);
            break;
    }
    for (int i = 0; i < procCount; i++) {
        ProcInfo* info = sortedProcList[i];
        printf("%s\t%s\t%c\t%llu\t%.2f\n",
               info->pid, info->name, info->state, info->vsize,
               (float)(info->utime + info->stime) / sysconf(_SC_CLK_TCK));
    }
    free(sortedProcList);
}

int main(int argc, char* argv[]) {
    ProcInfo** procList = NULL;
    int procCount = getProcessList(&procList);
    if (procCount == -1) {
        printf("Failed to get process list\n");
        return -1;
    }
    int sortedBy = 0;
    int sortAsc = 1;
    if (argc > 1) {
        if (strcmp(argv[1], "-t") == 0) {
            sortedBy = 1;
        }
        if (argc > 2 && strcmp(argv[2], "-r") == 0) {
            sortAsc = 0;
        }
    }
    printProcessList(procList, procCount, sortedBy, sortAsc);
    for (int i = 0; i < procCount; i++) {
        free(procList[i]);
    }
    free(procList);
    return 0;
}