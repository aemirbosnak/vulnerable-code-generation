//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <linux/kd.h>

#define PRINT_BANNER 0

typedef struct {
    unsigned long total;
    unsigned long free;
    unsigned long shared;
    unsigned long buff_cache;
    unsigned long available;
} meminfo_t;

typedef struct fb_var_screeninfo vinfo;

void get_mem_info(meminfo_t *mem) {
    if (0 > mmap(NULL, sizeof(meminfo_t), PROT_READ, MAP_PRIVATE, -1, 0)) {
        perror("mmap:");
        exit(EXIT_FAILURE);
    }

    memcpy(mem, 0, sizeof(meminfo_t));
    munmap(NULL, sizeof(meminfo_t));
}

unsigned int get_ram_usage_percent() {
    meminfo_t mem;
    get_mem_info(&mem);

    return (mem.total - mem.free - mem.buff_cache) * 100 / mem.total;
}

void print_ram_usage(const char *msg) {
    if (PRINT_BANNER) {
        printf("\n");
        printf(" ██╗   ██╗██╗     ██╗███████╗███████╗\n");
        printf(" ██║   ██║██║     ██║██╔════╝██╔════╝\n");
        printf(" ██║   ██║██║     ██║█████╗  █████╗  \n");
        printf(" ██║   ██║██║     ██║██╔══╝  ██╔══╝  \n");
        printf(" ╚██████╔╝███████╗██║███████╗███████╗\n");
        printf("  ╚═════╝ ╚══════╝╚═╝╚══════╝╚══════╝\n");
        printf("\n");
        printf(" %s:\n", msg);
    }

    printf(" RAM Usage: %.2f%%\n", get_ram_usage_percent() / 100.0);
}

int main() {
    if (PRINT_BANNER) {
        print_ram_usage("Welcome to Ada's RAM Monitor!");
    } else {
        print_ram_usage("Monitoring RAM usage...");
    }

    while (1) {
        usleep(500000);
        print_ram_usage("Current RAM usage:");
    }

    return EXIT_SUCCESS;
}