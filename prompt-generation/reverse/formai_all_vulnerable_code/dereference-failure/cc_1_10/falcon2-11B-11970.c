//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void monitorRAM(void){
    FILE *fp;
    int total_ram_bytes = 0;
    char *ram_content = NULL;

    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        perror("fopen failed");
        exit(1);
    }

    fscanf(fp, "%*s %d", &total_ram_bytes);

    if (total_ram_bytes == 0) {
        printf("Failed to read RAM size");
        return;
    }

    fclose(fp);

    char *mem_name = (char *)malloc(20);
    snprintf(mem_name, 20, "mem");
    int fd = open(mem_name, O_RDONLY);
    if(fd == -1) {
        perror("open failed");
        exit(1);
    }

    ssize_t read_size;
    read_size = read(fd, &ram_content, sizeof(ram_content));
    if(read_size < 0) {
        perror("read failed");
        exit(1);
    }
    close(fd);

    printf("Current RAM usage: %d bytes (%d%%)\n", total_ram_bytes, (total_ram_bytes * 100) / (1024 * 1024));
}

int main() {
    monitorRAM();
    return 0;
}