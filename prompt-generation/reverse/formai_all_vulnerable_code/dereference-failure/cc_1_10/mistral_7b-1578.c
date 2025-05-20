//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_STOCKS 100
#define BUFFER_SIZE 1024
#define FILE_NAME "stock_data.bin"

typedef struct {
    char symbol[5];
    double price;
} Stock;

void load_stocks(Stock stocks[]) {
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    fstat(fd, &st);
    void *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    Stock *stock_ptr = (Stock *)data;
    int i = 0;
    while (i < st.st_size / sizeof(Stock) && i < MAX_STOCKS) {
        stocks[i] = *stock_ptr++;
        i++;
    }

    munmap(data, st.st_size);
}

void save_stocks(Stock stocks[]) {
    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size_t size = sizeof(Stock) * MAX_STOCKS;
    void *data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    Stock *stock_ptr = (Stock *)data;
    for (int i = 0; i < MAX_STOCKS; i++) {
        *stock_ptr++ = stocks[i];
    }

    msync(data, size, MS_SYNC);
    munmap(data, size);
}

void print_stocks(Stock stocks[]) {
    printf("Current Stock Prices:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    load_stocks(stocks);
    print_stocks(stocks);

    // Update stock prices here

    save_stocks(stocks);

    return 0;
}