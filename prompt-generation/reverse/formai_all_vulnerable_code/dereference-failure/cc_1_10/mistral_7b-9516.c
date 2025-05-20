//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define MAGIC_NUM 0xDEADBEEF

typedef struct {
    int id;
    char name[32];
    float balance;
} Account;

typedef struct {
    int magic;
    int num_accounts;
    Account *accounts;
} DataStruct;

void extract_data(void *src, size_t size) {
    DataStruct *data = (DataStruct *)src;

    if (data->magic != MAGIC_NUM) {
        printf("Invalid data structure!\n");
        return;
    }

    for (int i = 0; i < data->num_accounts; ++i) {
        Account *account = &data->accounts[i];

        printf("Account %d:\n", account->id);
        printf("Name: %s\n", account->name);
        printf("Balance: %.2f\n", account->balance);
    }
}

int main(int argc, char *argv[]) {
    void *data;
    size_t size;

    if (argc != 2) {
        printf("Usage: %s <path to data>\n", argv[0]);
        return 1;
    }

    data = mmap(NULL, atoi(argv[1]), PROT_READ, MAP_PRIVATE, 0, 0);

    if (data == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    extract_data(data, atoi(argv[1]));

    munmap(data, atoi(argv[1]));

    return 0;
}