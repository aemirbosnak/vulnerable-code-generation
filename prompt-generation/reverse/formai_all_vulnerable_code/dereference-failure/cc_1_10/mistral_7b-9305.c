//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_PURPLE "\033[35m"

typedef struct {
    char name[100];
    int size;
} FileInfo;

void print_file_info(const char* path) {
    struct stat st;
    FileInfo file;
    strcpy(file.name, path);

    if (stat(path, &st) < 0) {
        printf("%s: %s\n", COLOR_RED, "Error opening file");
        return;
    }

    file.size = st.st_size;

    printf("%s%s\n", COLOR_BLUE, "File Info:");
    printf("%s%s: %ld bytes\n", COLOR_GREEN, "Size:", file.size);
    printf("%s%s: %s\n", COLOR_YELLOW, "Name:", file.name);
}

int main(int argc, char** argv) {
    int fd;
    char line[1024];
    if (argc != 2) {
        printf("%s%s\n", COLOR_RED, "Usage: ./reverse_reader <filename>");
        return 1;
    }

    print_file_info(argv[1]);

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("%s%s\n", COLOR_RED, "Error opening file");
        return 1;
    }

    printf("%s%s\n", COLOR_PURPLE, "Reading file...");
    while (fgets(line, sizeof(line), fd) != NULL) {
        int len = strlen(line);
        for (int i = len - 1; i >= 0; i--) {
            putchar(line[i]);
        }
        printf("%s", COLOR_RESET);
    }

    close(fd);
    return 0;
}