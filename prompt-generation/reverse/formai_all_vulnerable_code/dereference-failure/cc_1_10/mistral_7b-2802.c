//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_STR_LEN 256

void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void encrypt_file(char *filename) {
    int fd, i, c;
    char *buffer, *key = "qwertyuiopasdfghjklzxcvbnm";

    fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    buffer = (char *) malloc(MAX_STR_LEN);
    if (buffer == NULL) {
        perror("Error allocating memory");
        close(fd);
        exit(1);
    }

    while ((i = read(fd, buffer, MAX_STR_LEN)) > 0) {
        for (int j = 0; j < strlen(buffer); j++) {
            for (int k = 0; k < strlen(key); k++) {
                if (buffer[j] == key[k]) {
                    c = key[(strlen(key) + k) % strlen(key)];
                    break;
                }
            }
            buffer[j] = c;
        }
        write(STDOUT_FILENO, buffer, i);
    }

    free(buffer);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    reverse_string(argv[1]);
    encrypt_file(argv[1]);

    return 0;
}