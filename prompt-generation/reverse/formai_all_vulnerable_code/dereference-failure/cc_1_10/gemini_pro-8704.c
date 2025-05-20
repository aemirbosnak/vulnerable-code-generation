//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ram_usage_monitor {
    uint64_t total_ram;
    uint64_t free_ram;
    uint64_t used_ram;
    uint64_t buffer_ram;
    uint64_t cached_ram;
    uint64_t slab_ram;

    struct ram_usage_monitor *next;
} ram_usage_monitor_t;

ram_usage_monitor_t *head = NULL;

void add_ram_usage(uint64_t total_ram, uint64_t free_ram, uint64_t used_ram, uint64_t buffer_ram, uint64_t cached_ram, uint64_t slab_ram) {
    ram_usage_monitor_t *new_node = (ram_usage_monitor_t *)malloc(sizeof(ram_usage_monitor_t));
    new_node->total_ram = total_ram;
    new_node->free_ram = free_ram;
    new_node->used_ram = used_ram;
    new_node->buffer_ram = buffer_ram;
    new_node->cached_ram = cached_ram;
    new_node->slab_ram = slab_ram;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        ram_usage_monitor_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void print_ram_usage() {
    ram_usage_monitor_t *current_node = head;

    printf("Total RAM: %lu MB\n", current_node->total_ram / 1024 / 1024);
    printf("Free RAM: %lu MB\n", current_node->free_ram / 1024 / 1024);
    printf("Used RAM: %lu MB\n", current_node->used_ram / 1024 / 1024);
    printf("Buffer RAM: %lu MB\n", current_node->buffer_ram / 1024 / 1024);
    printf("Cached RAM: %lu MB\n", current_node->cached_ram / 1024 / 1024);
    printf("Slab RAM: %lu MB\n", current_node->slab_ram / 1024 / 1024);
}

int main() {
    add_ram_usage(16384, 12288, 4096, 512, 1024, 256);
    add_ram_usage(32768, 28672, 4096, 1024, 2048, 512);
    add_ram_usage(65536, 57344, 8192, 2048, 4096, 1024);

    print_ram_usage();

    return 0;
}