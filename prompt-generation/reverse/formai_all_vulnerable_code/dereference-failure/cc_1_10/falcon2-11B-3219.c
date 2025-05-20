//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_USERNAME_LEN 256

typedef struct {
    char username[MAX_USERNAME_LEN];
    int count;
} User;

typedef struct {
    User* data;
    int size;
    int capacity;
} HashTable;

HashTable* create_hash_table(int capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL) {
        fprintf(stderr, "Failed to allocate memory for hash table\n");
        exit(1);
    }
    table->data = (User*)malloc(capacity * sizeof(User));
    if (table->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for hash table data\n");
        exit(1);
    }
    table->size = 0;
    table->capacity = capacity;
    return table;
}

void destroy_hash_table(HashTable* table) {
    free(table->data);
    free(table);
}

int hash_function(const char* username, int size) {
    int hash = 0;
    while (*username) {
        hash = (hash << 2) ^ *username++;
    }
    return hash % size;
}

void insert_user(HashTable* table, const char* username) {
    int index = hash_function(username, table->capacity);
    User* user = &table->data[index];
    if (user->count == table->size) {
        table->capacity *= 2;
        User* new_data = (User*)realloc(table->data, table->capacity * sizeof(User));
        if (new_data == NULL) {
            fprintf(stderr, "Failed to reallocate memory for hash table data\n");
            exit(1);
        }
        table->data = new_data;
    }
    strcpy(user->username, username);
    user->count++;
}

int count_users(HashTable* table) {
    int count = 0;
    for (int i = 0; i < table->size; i++) {
        count += table->data[i].count;
    }
    return count;
}

int main(int argc, char* argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open log file: %s\n", strerror(errno));
        exit(1);
    }
    HashTable* table = create_hash_table(256);
    char buffer[BUF_SIZE];
    while (read(fd, buffer, BUF_SIZE) > 0) {
        char* user = strtok(buffer, " ");
        while (user!= NULL) {
            insert_user(table, user);
            user = strtok(NULL, " ");
        }
    }
    close(fd);
    int count = count_users(table);
    printf("Total number of unique users: %d\n", count);
    for (int i = 0; i < table->size; i++) {
        printf("%s: %d\n", table->data[i].username, table->data[i].count);
    }
    destroy_hash_table(table);
    return 0;
}