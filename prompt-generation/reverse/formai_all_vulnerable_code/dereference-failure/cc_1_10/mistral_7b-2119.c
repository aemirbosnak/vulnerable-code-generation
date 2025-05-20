//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

typedef struct {
    size_t magic;
    size_t word_count;
} invasive_word_count;

size_t invasive_count_words(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(fd);
        exit(1);
    }

    char *mmaped_memory = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mmaped_memory == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        exit(1);
    }

    invasive_word_count *word_count = (invasive_word_count *)mmaped_memory;
    if (word_count->magic != 0xDEADBEEF) {
        word_count->magic = 0xDEADBEEF;
        word_count->word_count = 1;
        msync(mmaped_memory, file_stat.st_size, MS_SYNC);
        munmap(mmaped_memory, file_stat.st_size);
        close(fd);
        return 1;
    }

    size_t word_count_value = word_count->word_count;
    munmap(mmaped_memory, file_stat.st_size);
    close(fd);

    return word_count_value;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    size_t word_count = invasive_count_words(argv[1]);
    printf("Word count: %zu\n", word_count);

    return 0;
}