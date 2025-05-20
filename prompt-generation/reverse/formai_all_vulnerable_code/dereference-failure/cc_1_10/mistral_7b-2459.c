//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// A poem about corruption and decay

#define FILE_NAME "data.bin"
#define CHAOS_PERCENT 25

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void corrupt_data(int fd) {
    off_t file_size = lseek(fd, 0, SEEK_END);
    char *buffer = malloc(file_size);

    read(fd, buffer, file_size);

    for (int i = 0; i < file_size; i += sizeof(Person)) {
        Person *person = (Person*) (buffer + i);

        if (rand() % 100 < CHAOS_PERCENT) {
            // Corrupt name
            for (int j = 0; j < strlen(person->name); j++) {
                person->name[j] = (char) rand() % 128;
            }

            // Corrupt age
            person->age = rand() % 120;

            // Corrupt weight
            person->weight = (float) rand() / (float) RAND_MAX;
        }
    }

    lseek(fd, 0, SEEK_SET);
    write(fd, buffer, file_size);

    free(buffer);
}

int main() {
    int fd = open(FILE_NAME, O_RDWR);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    corrupt_data(fd);

    close(fd);

    printf("The data has been corrupted.\n");

    return 0;
}