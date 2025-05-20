//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define MAX_BUFF_SIZE 1024
#define SWAP(a, b) {(a) ^= (b), (b) ^= (a), (a) ^= (b);}

typedef struct {
    int flag;
    int counter;
    char data[MAX_BUFF_SIZE];
} MyStruct;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    MyStruct *myStruct = mmap(NULL, sizeof(MyStruct), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (myStruct == MAP_FAILED) {
        perror("mmap failed");
        return -1;
    }

    myStruct->flag = 1;
    myStruct->counter = 0;

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        munmap(myStruct, sizeof(MyStruct));
        return -1;
    }

    char *file_data = mmap(NULL, MAX_BUFF_SIZE, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (file_data == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        munmap(myStruct, sizeof(MyStruct));
        return -1;
    }

    int bytes_read = read(fd, file_data, MAX_BUFF_SIZE);

    if (bytes_read < 0) {
        perror("read failed");
        munmap(file_data, MAX_BUFF_SIZE);
        close(fd);
        munmap(myStruct, sizeof(MyStruct));
        return -1;
    }

    int i, j;
    for (i = 0; i < bytes_read; i += 4) {
        int num = 0;
        for (j = 0; j < 4; j++) {
            num |= file_data[i + j] << (8 * j);
        }

        myStruct->data[myStruct->counter++] = (num & 0xFF);
        num >>= 8;

        myStruct->data[myStruct->counter++] = (num & 0xFF);
        num >>= 8;

        myStruct->data[myStruct->counter++] = (num & 0xFF);
        num >>= 8;

        myStruct->data[myStruct->counter++] = (num & 0xFF);
    }

    close(fd);
    munmap(file_data, MAX_BUFF_SIZE);

    printf("Data from file: ");
    for (i = 0; i < myStruct->counter; i++) {
        printf("%.2X ", myStruct->data[i]);
    }
    printf("\n");

    int x = 0x12, y = 0x34;
    int a = x & y;
    int b = x | y;
    int c = x ^ y;
    int d = ~x;
    int e = x << 1;
    int f = x >> 1;
    int g = x << 3;
    int h = x >> 3;

    printf("Bitwise operations result:\n");
    printf("a = %x\n", a);
    printf("b = %x\n", b);
    printf("c = %x\n", c);
    printf("d = %x\n", d);
    printf("e = %x\n", e);
    printf("f = %x\n", f);
    printf("g = %x\n", g);
    printf("h = %x\n", h);

    munmap(myStruct, sizeof(MyStruct));

    return 0;
}