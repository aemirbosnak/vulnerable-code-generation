//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MEGABYTE (1024 * 1024)

int main() {
    char *buffer = malloc(MEGABYTE);
    int buffer_size = MEGABYTE;
    int total_memory = 0;
    int used_memory = 0;
    int free_memory = 0;
    int largest_free_block = 0;
    int largest_free_index = 0;

    printf("RAM Usage Monitor\n");
    printf("------------------\n");

    while(1) {
        system("clear");
        printf("Total Memory: %d MB\n", total_memory);
        printf("Used Memory: %d MB\n", used_memory);
        printf("Free Memory: %d MB\n", free_memory);
        printf("Largest Free Block: %d MB\n", largest_free_block);
        printf("\n");

        total_memory = 0;
        used_memory = 0;
        free_memory = 0;
        largest_free_block = 0;
        largest_free_index = 0;

        int i;
        for(i = 0; i < buffer_size; i += MEGABYTE) {
            if(buffer[i] == 0) {
                total_memory += MEGABYTE;
                if(free_memory == 0) {
                    largest_free_block = MEGABYTE;
                    largest_free_index = i;
                } else if(free_memory < MEGABYTE) {
                    largest_free_block = free_memory;
                    largest_free_index = i - MEGABYTE;
                }
                free_memory += MEGABYTE;
            } else {
                used_memory += MEGABYTE;
            }
        }

        if(free_memory > 0) {
            printf("Largest Free Block: %d MB (starting at %d)\n", largest_free_block, largest_free_index);
        }

        if(total_memory > 0) {
            used_memory = total_memory - free_memory;
        }

        if(used_memory > 0) {
            printf("Used Memory: %d MB\n", used_memory);
        } else {
            printf("Used Memory: 0 MB\n");
        }

        if(free_memory > 0) {
            printf("Free Memory: %d MB\n", free_memory);
        } else {
            printf("Free Memory: 0 MB\n");
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}