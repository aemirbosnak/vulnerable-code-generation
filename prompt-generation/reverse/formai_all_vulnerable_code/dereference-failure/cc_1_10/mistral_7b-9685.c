//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DISK_COUNT 6
#define TOWER_NAME_LENGTH 10
#define TOWER_MIN_NAME "tower_min"
#define TOWER_MAX_NAME "tower_max"
#define LOG_FILE "hanoi.log"

typedef struct {
    char name[TOWER_NAME_LENGTH];
    int top_disk;
} Tower;

void print_towers(Tower towers[3]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%s: ", towers[i].name);
        for (int j = 0; j <= towers[i].top_disk; j++) {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
}

void hanoi(int n, Tower source, Tower target, Tower auxiliary) {
    if (n > 0) {
        hanoi(n - 1, source, auxiliary, target);
        target.top_disk++;
        source.top_disk--;
        target.name[source.top_disk + 1] = '\0';
        strcpy(target.name, "new_");
        strcat(target.name, target.name);
        int fd = open(target.name, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        time_t now = time(NULL);
        char time_string[20];
        strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&now));
        fprintf(fd, "%s: moved disk %d from %s to %s\n", time_string, n, source.name, target.name);
        close(fd);
        unlink(target.name);
        target.name[strlen(target.name) - 10] = '\0';
        hanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    Tower towers[3] = {{"tower_init", DISK_COUNT}, {"tower_min", 0}, {"tower_max", 0}};
    hanoi(DISK_COUNT / 2, towers[0], towers[2], towers[1]);
    print_towers(towers);
    return 0;
}