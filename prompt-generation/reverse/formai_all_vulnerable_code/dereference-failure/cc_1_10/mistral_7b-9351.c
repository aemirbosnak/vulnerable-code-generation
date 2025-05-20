//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINES 50
#define MAX_LINE_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct {
    char filename[MAX_LINE_LENGTH];
    char** lines;
    int num_lines;
} Book;

void load_file(Book* book, char* filename) {
    int fd = open(filename, O_RDONLY);
    struct stat st;
    fstat(fd, &st);
    char* buffer = malloc(st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';

    char* line = strtok(buffer, "\n");
    book->num_lines = 0;
    book->lines = malloc(MAX_LINES * sizeof(char*));

    while (line != NULL) {
        book->lines[book->num_lines] = strdup(line);
        book->num_lines++;
        line = strtok(NULL, "\n");
    }
    close(fd);
    free(buffer);
}

void print_menu() {
    printf("\n***** eBook Reader Menu *****\n");
    printf("1. Load Book\n");
    printf("2. Display Book\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

void display_book(Book book) {
    for (int i = 0; i < book.num_lines; i++) {
        printf("\033[%d;%dH%s\n", 2 + i, 0, book.lines[i]);
    }
}

int main() {
    Book my_book;
    char filename[MAX_LINE_LENGTH];

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                load_file(&my_book, filename);
                break;
            case 2:
                system("clear"); // or use \033[2J for non-linux terminals
                display_book(my_book);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    for (int i = 0; i < my_book.num_lines; i++) {
        free(my_book.lines[i]);
    }
    free(my_book.lines);

    return 0;
}