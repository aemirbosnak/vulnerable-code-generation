//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct {
    char magic[4];
    int num_pages;
    int page_size;
    char **pages;
} ebook;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

ebook *open_ebook(const char *filename) {
    int fd, i;
    ebook *eb;

    fd = open(filename, O_RDONLY);
    if (fd < 0) die("open");

    eb = mmap(NULL, sizeof(ebook), PROT_READ, MAP_PRIVATE, fd, 0);
    if (eb == MAP_FAILED) die("mmap");

    if (strncmp(eb->magic, "CEBK", 4) != 0) {
        close(fd);
        munmap(eb, sizeof(ebook));
        die("Invalid file format");
    }

    eb->pages = malloc(eb->num_pages * sizeof(char *));
    for (i = 0; i < eb->num_pages; i++) {
        eb->pages[i] = mmap(NULL, eb->page_size, PROT_READ, MAP_PRIVATE, fd, eb->page_size * i);
        if (eb->pages[i] == MAP_FAILED) {
            close(fd);
            munmap(eb, sizeof(ebook));
            for (i--; i >= 0; i--) munmap(eb->pages[i], eb->page_size);
            die("mmap");
        }
    }

    close(fd);

    return eb;
}

void display_page(ebook *eb, int page_num) {
    if (page_num < 0 || page_num >= eb->num_pages) {
        printf("Invalid page number\n");
        return;
    }

    write(STDOUT_FILENO, eb->pages[page_num], eb->page_size);
}

void close_ebook(ebook *eb) {
    int i;

    for (i = 0; i < eb->num_pages; i++) munmap(eb->pages[i], eb->page_size);
    free(eb->pages);
    munmap(eb, sizeof(ebook));
}

int main(int argc, char **argv) {
    ebook *eb;
    int page_num;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    eb = open_ebook(argv[1]);

    printf("Enter page number to display (0 to quit): ");
    scanf("%d", &page_num);

    while (page_num >= 0) {
        display_page(eb, page_num);
        printf("Enter page number to display (0 to quit): ");
        scanf("%d", &page_num);
    }

    close_ebook(eb);

    return 0;
}