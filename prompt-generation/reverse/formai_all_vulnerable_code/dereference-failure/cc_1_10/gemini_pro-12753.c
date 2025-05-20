//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants
#define PAGE_SIZE           4096
#define FRAME_SIZE          256
#define NUM_FRAMES          1024
#define NUM_PAGES           (256 * 1024)

// Data structures
typedef struct {
    uint8_t *data;
    int32_t page_num;
    int32_t frame_num;
    int32_t ref_count;
} Page;

typedef struct {
    Page *pages;
    int32_t num_pages;
    int32_t num_free_frames;
    int32_t free_frames[NUM_FRAMES];
} RAM;

// Function prototypes
RAM *ram_init();
void ram_free(RAM *ram);
Page *ram_get_page(RAM *ram, int32_t page_num);
int32_t ram_add_page(RAM *ram, Page *page);
int32_t ram_remove_page(RAM *ram, int32_t page_num);
int32_t ram_get_usage(RAM *ram);

// Main function
int main() {
    // Initialize the RAM
    RAM *ram = ram_init();

    // Add some pages to the RAM
    Page *page1 = malloc(sizeof(Page));
    page1->data = malloc(PAGE_SIZE);
    page1->page_num = 1;
    ram_add_page(ram, page1);

    Page *page2 = malloc(sizeof(Page));
    page2->data = malloc(PAGE_SIZE);
    page2->page_num = 2;
    ram_add_page(ram, page2);

    Page *page3 = malloc(sizeof(Page));
    page3->data = malloc(PAGE_SIZE);
    page3->page_num = 3;
    ram_add_page(ram, page3);

    // Get the RAM usage
    int32_t usage = ram_get_usage(ram);

    // Print the RAM usage
    printf("RAM usage: %d%%\n", usage);

    // Free the RAM
    ram_free(ram);

    return 0;
}

// Function implementations

RAM *ram_init() {
    RAM *ram = malloc(sizeof(RAM));
    ram->pages = malloc(sizeof(Page) * NUM_PAGES);
    ram->num_pages = 0;
    ram->num_free_frames = NUM_FRAMES;
    for (int i = 0; i < NUM_FRAMES; i++) {
        ram->free_frames[i] = i;
    }
    return ram;
}

void ram_free(RAM *ram) {
    for (int i = 0; i < ram->num_pages; i++) {
        free(ram->pages[i].data);
    }
    free(ram->pages);
    free(ram);
}

Page *ram_get_page(RAM *ram, int32_t page_num) {
    for (int i = 0; i < ram->num_pages; i++) {
        if (ram->pages[i].page_num == page_num) {
            return &ram->pages[i];
        }
    }
    return NULL;
}

int32_t ram_add_page(RAM *ram, Page *page) {
    if (ram->num_free_frames == 0) {
        return -1;
    }

    // Allocate a frame for the page
    page->frame_num = ram->free_frames[ram->num_free_frames - 1];
    ram->free_frames[ram->num_free_frames - 1] = -1;
    ram->num_free_frames--;

    // Add the page to the RAM
    ram->pages[ram->num_pages] = *page;
    ram->num_pages++;

    return 0;
}

int32_t ram_remove_page(RAM *ram, int32_t page_num) {
    for (int i = 0; i < ram->num_pages; i++) {
        if (ram->pages[i].page_num == page_num) {
            // Free the frame used by the page
            ram->free_frames[ram->num_free_frames] = ram->pages[i].frame_num;
            ram->num_free_frames++;

            // Remove the page from the RAM
            for (int j = i + 1; j < ram->num_pages; j++) {
                ram->pages[j - 1] = ram->pages[j];
            }
            ram->num_pages--;

            return 0;
        }
    }
    return -1;
}

int32_t ram_get_usage(RAM *ram) {
    int32_t used_frames = ram->num_pages - ram->num_free_frames;
    int32_t usage = (used_frames * 100) / NUM_FRAMES;
    return usage;
}