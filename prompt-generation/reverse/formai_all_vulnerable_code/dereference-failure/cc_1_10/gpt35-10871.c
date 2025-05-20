//FormAI DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* url;
    char* html;
    bool loaded;
} Page;

Page* new_page(char* url) {
    Page* page = malloc(sizeof(Page));
    page->url = url;
    page->html = NULL;
    page->loaded = false;
    return page;
}

void load_page(Page* page) {
    FILE* file = fopen(page->url, "r");
    if (file) {
        char buffer[BUFFER_SIZE];
        size_t length;
        while ((length = fread(buffer, 1, BUFFER_SIZE, file))) {
            if (!page->html) {
                page->html = malloc(length + 1);
                memcpy(page->html, buffer, length);
                page->html[length] = '\0';
            } else {
                page->html = realloc(page->html, strlen(page->html) + length + 1);
                strcat(page->html, buffer);
            }
        }
        fclose(file);
        page->loaded = true;
        printf("Loaded page: %s\n", page->url);
    } else {
        printf("Error: could not load page: %s\n", page->url);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: no URL specified.\n");
        exit(1);
    }

    Page* page = new_page(argv[1]);
    load_page(page);

    if (page->loaded) {
        printf("%s\n", page->html); // print the HTML contents
        // do something with the HTML contents
    }

    free(page->url);
    free(page->html);
    free(page);

    return 0;
}