//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <limits.h>

#define BUF_SIZE 1024
#define PROC_FILE "/proc/stat"

int main() {
    FILE *fp;
    char buf[BUF_SIZE];
    int i, j, n;
    float idle, total;
    struct stat stat_buf;

    // Open the file
    fp = fopen(PROC_FILE, "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", PROC_FILE);
        exit(1);
    }

    // Read the file
    if (fstat(fileno(fp), &stat_buf) == -1) {
        printf("Cannot get file status\n");
        exit(1);
    }
    n = stat_buf.st_size / sizeof(long);

    // Get the CPU usage
    for (i = 0; i < n; i++) {
        if (fgets(buf, BUF_SIZE, fp) == NULL) {
            printf("Cannot read line %d\n", i + 1);
            exit(1);
        }
        for (j = 0; j < 4; j++) {
            if (sscanf(buf, "cpu%d %ld", &j + 1, &total) == 2) {
                break;
            }
        }
        if (j == 4) {
            printf("Cannot find CPU usage\n");
            exit(1);
        }
        if (i == 0) {
            idle = total;
        } else {
            total -= idle;
            printf("CPU%d: %.2f%%\n", j + 1, total * 100.0 / (total + idle));
        }
    }

    fclose(fp);
    return 0;
}