//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: high level of detail
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_PHYS_MEM 16 * 1024 * 1024 // 16 MiB of physical memory

typedef struct {
    uint64_t base_addr;
    uint64_t length;
} mem_region_t;

// Initializes the memory map with a single region covering all of physical memory.
void init_mem_map(mem_region_t* mem_map) {
    mem_map->base_addr = 0;
    mem_map->length = MAX_PHYS_MEM;
}

// Allocates a contiguous region of memory of the specified size from the memory map.
void* alloc_mem(mem_region_t* mem_map, size_t size) {
    // Find a free region that is large enough.
    for (mem_region_t* region = mem_map; region < mem_map + MAX_PHYS_MEM; region++) {
        if (region->length >= size) {
            // Allocate the memory from the free region.
            void* addr = (void*)region->base_addr;
            region->base_addr += size;
            region->length -= size;
            return addr;
        }
    }

    // No free region found.
    return NULL;
}

// Frees a previously allocated region of memory.
void free_mem(mem_region_t* mem_map, void* addr, size_t size) {
    // Find the region that contains the freed memory.
    for (mem_region_t* region = mem_map; region < mem_map + MAX_PHYS_MEM; region++) {
        if (region->base_addr <= addr && addr + size <= region->base_addr + region->length) {
            // Merge the freed region with the adjacent free regions.
            if (addr == region->base_addr) {
                region->base_addr += size;
                region->length -= size;
            } else if (addr + size == region->base_addr + region->length) {
                region->length += size;
            } else {
                // Split the region into two free regions.
                mem_region_t* new_region = region + 1;
                new_region->base_addr = addr + size;
                new_region->length = region->base_addr + region->length - new_region->base_addr;
                region->length = addr - region->base_addr;
            }

            return;
        }
    }
}

// Main function.
int main() {
    // Initialize the memory map.
    mem_region_t mem_map;
    init_mem_map(&mem_map);

    // Allocate some memory from the memory map.
    void* addr1 = alloc_mem(&mem_map, 1024);
    void* addr2 = alloc_mem(&mem_map, 2048);

    // Use the allocated memory.

    // Free the allocated memory.
    free_mem(&mem_map, addr1, 1024);
    free_mem(&mem_map, addr2, 2048);

    return 0;
}