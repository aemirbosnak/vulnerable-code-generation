//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define KEY "mysecretkey123"
#define ENCRYPTION_SHIFT 5

void* mapFile(int fd, size_t length) {
    return mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0);
}

void unmapFile(void* addr, size_t length) {
    munmap(addr, length);
}

void encryptChar(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = (str[i] + KEY[i % strlen(KEY)]) >> ENCRYPTION_SHIFT;
    }
}

void decryptChar(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = (str[i] << ENCRYPTION_SHIFT) ^ KEY[i % strlen(KEY)];
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    int file_fd = open(argv[1], O_RDONLY);
    if (file_fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(file_fd);
        return 1;
    }

    void* file_map = mapFile(file_fd, file_stat.st_size);
    if (file_map == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(file_fd);
        return 1;
    }

    char* ebook_content = (char*) file_map;
    int content_len = file_stat.st_size;

    // Encrypt the ebook content
    encryptChar(ebook_content, content_len);

    // Display the encrypted ebook content
    for (int i = 0; i < content_len; i++) {
        printf("%c", ebook_content[i]);
    }

    // Decrypt and free the memory
    decryptChar(ebook_content, content_len);
    unmapFile(file_map, file_stat.st_size);
    close(file_fd);

    return 0;
}