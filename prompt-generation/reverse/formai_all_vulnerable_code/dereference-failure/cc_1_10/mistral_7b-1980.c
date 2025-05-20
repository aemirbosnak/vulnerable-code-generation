//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#define MAX_BOOK_SIZE 1024 * 1024 // 1 MB
#define LINE_SIZE 80
#define PAGE_SIZE 25 // number of lines per page
#define FONT_SIZE 16

typedef struct {
    char *filename;
    char *content;
    size_t size;
} Book;

void load_file(const char *path, Book *book) {
    int fd = open(path, O_RDONLY);
    struct stat st;
    fstat(fd, &st);

    if (st.st_size > MAX_BOOK_SIZE) {
        fprintf(stderr, "File too large: %s\n", path);
        exit(EXIT_FAILURE);
    }

    book->size = st.st_size;
    book->content = mmap(NULL, book->size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    book->filename = strdup(path);
}

void print_page(const Book *book, int page) {
    int line = 0;
    size_t pos = page * PAGE_SIZE * FONT_SIZE;

    printf("\e[1;1H"); // go to the home position

    while (line < PAGE_SIZE && pos < book->size) {
        size_t line_len = 0;

        while (line_len < LINE_SIZE && pos + line_len < book->size) {
            if (book->content[pos + line_len] == '\n') {
                printf("\e[%d;%dH", (page * PAGE_SIZE) + line + 1, (line_len / FONT_SIZE) + 1);
                printf("%.*s\n", (int) (LINE_SIZE / FONT_SIZE) - (line_len / FONT_SIZE), &book->content[pos]);
                line++;
                pos += line_len + 1;
                line_len = 0;
                continue;
            }

            putchar(book->content[pos + line_len]);
            line_len++;
        }

        if (line_len < LINE_SIZE) {
            printf("\e[%d;%dH", (page * PAGE_SIZE) + line + 1, (LINE_SIZE / FONT_SIZE) + 1);
            printf("%*.*s\n", (int) (LINE_SIZE / FONT_SIZE) - (line_len / FONT_SIZE), LINE_SIZE, "");
        }

        pos += line_len;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <book.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Book book;
    load_file(argv[1], &book);

    int page = 0;
    while (1) {
        print_page(&book, page);
        page++;

        int ch = getchar();
        if (ch == 'q' || ch == EOF) {
            break;
        }

        if (ch == 'j') {
            page++;
        } else if (ch == 'k') {
            page--;
        }
    }

    munmap(book.content, book.size);
    free(book.filename);

    return EXIT_SUCCESS;
}