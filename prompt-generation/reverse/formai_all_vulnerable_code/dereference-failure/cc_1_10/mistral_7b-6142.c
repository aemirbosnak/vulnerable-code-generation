//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

// Alien Symbols and their Human Equivalents
const char* ALIEN_TO_HUMAN[] = {
    "|\\/|", "O_O", "X_X", "&%@", "^_^", "V(^_^)", "U<(|||)", "(~)_", "|:|", "B_b"
};

const int NUM_ALIEN_SYMBOLS = sizeof(ALIEN_TO_HUMAN) / sizeof(ALIEN_TO_HUMAN[0]);

void* load_file(const char* filename, size_t* size) {
    int fd = open(filename, O_RDONLY);
    struct stat file_stat;
    fstat(fd, &file_stat);
    *size = file_stat.st_size;
    void* map = mmap(NULL, *size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    return map;
}

void decode_alien_message(const char* alien_message) {
    int message_length = strlen(alien_message);
    char alien_symbol;
    int human_index;

    for (int i = 0; i < message_length; ++i) {
        alien_symbol = alien_message[i];

        for (int j = 0; j < NUM_ALIEN_SYMBOLS; ++j) {
            if (strncmp(ALIEN_TO_HUMAN[j], &alien_symbol, strlen(ALIEN_TO_HUMAN[j])) == 0) {
                human_index = j;
                break;
            }
        }

        putchar(ALIEN_TO_HUMAN[human_index][0]);
    }
}

int main() {
    char* alien_message;
    size_t file_size;

    alien_message = (char*) load_file("alien_message.txt", &file_size);

    if (file_size > 0) {
        decode_alien_message(alien_message);
        free(alien_message);
    } else {
        puts("Error: Could not read the alien message file.");
    }

    return 0;
}