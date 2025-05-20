//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encrypt_file(const char* filename, const char* password) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error: Unable to open file\n");
        return;
    }

    char key[KEY_SIZE];
    strcpy(key, password);

    void* mapped_memory = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        printf("Error: Unable to map file to memory\n");
        return;
    }

    char* p = (char*)mapped_memory;
    char* q = (char*)mapped_memory + BLOCK_SIZE;
    char* r = (char*)mapped_memory + 2 * BLOCK_SIZE;

    for (int i = 0; i < 2 * BLOCK_SIZE; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            int k = j % KEY_SIZE;
            int m = i % KEY_SIZE;
            char c = p[i + j];
            char d = p[i + j] ^ (char)key[k];
            char e = p[i + j + 1] ^ (char)key[m];
            p[i + j] = c;
            p[i + j + 1] = d;
            q[i + j] = e;
            q[i + j + 1] = c;
        }
        p += BLOCK_SIZE;
        q += BLOCK_SIZE;
    }

    for (int i = 0; i < 2 * BLOCK_SIZE; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            int k = j % KEY_SIZE;
            int m = i % KEY_SIZE;
            char c = q[i + j];
            char d = q[i + j] ^ (char)key[k];
            char e = r[i + j] ^ (char)key[m];
            r[i + j] = c;
            r[i + j + 1] = d;
            q[i + j] = e;
            q[i + j + 1] = c;
        }
        r += BLOCK_SIZE;
    }

    munmap(mapped_memory, BLOCK_SIZE * 3);
    close(fd);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <password>\n", argv[0]);
        return 1;
    }

    encrypt_file(argv[1], argv[2]);
    printf("File encrypted successfully\n");

    return 0;
}