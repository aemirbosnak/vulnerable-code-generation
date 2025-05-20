//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

typedef struct {
    char name[256];
    int age;
    float height;
} Person;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <name> <age>\n", argv[0]);
        return 1;
    }

    Person p;
    strcpy(p.name, argv[1]);
    p.age = atoi(argv[2]);

    // Creating a file with the person's name
    int fd = open(p.name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Writing the person's data to the file
    if (write(fd, &p, sizeof(p)) != sizeof(p)) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Person %s with age %d and height %f created successfully!\n", p.name, p.age, 1.75); // Shocking height for effect

    // Reading the person's data from the file
    fd = open(p.name, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        return 1;
    }

    if (read(fd, &p, sizeof(p)) != sizeof(p)) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Person %s is %d years old and %f meters tall!\n", p.name, p.age, p.height / 100.0);

    return 0;
}