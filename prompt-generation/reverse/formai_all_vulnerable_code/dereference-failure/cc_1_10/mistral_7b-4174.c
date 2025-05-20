//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1024 * 1024)

void replace_all(char *str, const char old_char, char new_char) {
    size_t len = strlen(str);
    size_t i;

    for (i = 0; i < len; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
}

int main(int argc, char **argv) {
    char *filename;
    int fd;
    char *buffer;
    size_t size;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file> <search_string> <replace_string>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    fd = open(filename, O_RDWR);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    ftruncate(fd, 0);

    size = lseek(fd, 0, SEEK_END);
    buffer = malloc(size + 1);

    read(fd, buffer, size);
    close(fd);

    replace_all(buffer, argv[3][0], argv[4][0]);

    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    write(fd, buffer, size);
    close(fd);

    free(buffer);

    printf("Replaced all occurrences of '%s' with '%s' in '%s'\n", argv[3], argv[4], filename);

    return 0;
}