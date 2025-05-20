//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

// Function to print DNA sequence in a peaceful way
void print_sequence(char *sequence) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        switch (sequence[i]) {
            case 'A':
                printf("%c %s\n", sequence[i], "peaceful sunrise");
                break;
            case 'C':
                printf("%c %s\n", sequence[i], "calm ocean waves");
                break;
            case 'G':
                printf("%c %s\n", sequence[i], "gentle breeze rustling leaves");
                break;
            case 'T':
                printf("%c %s\n", sequence[i], "tranquil forest");
                break;
            default:
                printf("Invalid nucleotide: %c\n", sequence[i]);
                break;
        }
        usleep(100000); // Pause for a peaceful moment between nucleotides
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <DNA_sequence_file>\n", argv[0]);
        return 1;
    }

    int file_fd = open(argv[1], O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stats;
    fstat(file_fd, &file_stats);
    char *sequence = malloc(file_stats.st_size + 1);
    if (!sequence) {
        perror("Error allocating memory");
        close(file_fd);
        return 1;
    }

    ssize_t bytes_read = read(file_fd, sequence, file_stats.st_size);
    if (bytes_read != file_stats.st_size) {
        perror("Error reading file");
        free(sequence);
        close(file_fd);
        return 1;
    }

    sequence[bytes_read] = '\0';

    print_sequence(sequence);

    free(sequence);
    close(file_fd);

    return 0;
}