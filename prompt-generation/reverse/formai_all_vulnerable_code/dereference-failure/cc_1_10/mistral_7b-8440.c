//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_SIZE 1024
#define TABLE_SIZE 10
#define ELEMENT_SIZE 32
#define HASH_FUNCTION(x) ((x % TABLE_SIZE) & (TABLE_SIZE - 1))

typedef struct {
    int key;
    char data[ELEMENT_SIZE];
} Element;

Element table[TABLE_SIZE];

void init_table() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
    }
}

int search(int key) {
    int index;

    if ((index = HASH_FUNCTION(key)) >= 0) {
        while (table[index].key != -1 && table[index].key != key) {
            index = (index + 1) & (TABLE_SIZE - 1);
        }
    }

    if (table[index].key == key) {
        return index;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    int i, key;
    char filename[MAX_SIZE];
    char buffer[MAX_SIZE];
    int fd;
    int num_elements = 0;

    init_table();

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while (read(fd, buffer, MAX_SIZE) > 0) {
        sscanf(buffer, "%d%s", &key, table[num_elements].data);
        table[num_elements].key = key;
        num_elements++;
    }

    close(fd);

    if (num_elements == 0) {
        printf("No elements found in file.\n");
        return 1;
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    if (search(key) != -1) {
        printf("Key %d found at index %d.\n", key, search(key));
    } else {
        printf("Key %d not found.\n", key);
    }

    return 0;
}