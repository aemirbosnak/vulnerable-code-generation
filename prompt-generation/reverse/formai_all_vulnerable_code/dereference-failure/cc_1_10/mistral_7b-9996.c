//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

typedef struct {
    int length;
    char data[1];
} string_t;

void reverse(char* str, int length) {
    int i = 0, j = length - 1;
    while (i < length / 2) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void encrypt(char* str, int length) {
    int i = 0;
    while (i < length) {
        str[i] = str[i] ^ 0x13;
        i++;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    struct stat st;
    fstat(fd, &st);
    void* map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("Error mapping file to memory");
        exit(1);
    }

    string_t* str = (string_t*)map;
    int len = str->length;
    reverse(str->data, len);
    encrypt(str->data, len);

    close(fd);
    munmap(map, st.st_size);

    printf("Encrypted string:\n%s\n", str->data);

    return 0;
}