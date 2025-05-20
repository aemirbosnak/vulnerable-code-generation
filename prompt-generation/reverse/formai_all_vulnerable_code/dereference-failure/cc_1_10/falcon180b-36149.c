//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 1000000

int main() {
    char *mem = malloc(MEM_SIZE);
    int used_mem = 0;
    int max_mem = 0;
    int i = 0;

    printf("RAM Usage Monitor\n");
    printf("=================\n");
    printf("Initializing...\n");

    for (i = 0; i < MEM_SIZE; i++) {
        mem[i] = 0;
    }

    printf("Ready.\n");

    while (1) {
        printf("\r%d KB used out of %d KB total", used_mem, MEM_SIZE);
        fflush(stdout);

        if (max_mem < used_mem) {
            max_mem = used_mem;
        } else if (max_mem > used_mem) {
            max_mem--;
        }

        if (max_mem == 0) {
            printf("\n");
        }

        used_mem = 0;

        for (i = 0; i < MEM_SIZE; i++) {
            if (mem[i]) {
                used_mem++;
            }
        }

        sleep(1);
    }

    free(mem);
    return 0;
}