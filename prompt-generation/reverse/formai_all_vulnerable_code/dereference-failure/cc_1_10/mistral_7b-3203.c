//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

typedef struct {
    char name[256];
    int age;
    float height;
} Person;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int fd;
    Person person;
    char filename[256];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <name> <age>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, "people/");
    strcat(filename, argv[1]);
    strcat(filename, ".dat");

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        die("Failed to open file");
    }

    person.age = atoi(argv[2]);
    strcpy(person.name, argv[1]);
    person.height = rand() / (float)RAND_MAX * 2.0;

    write(fd, &person, sizeof(Person));
    close(fd);

    printf("Person %s saved successfully!\n", argv[1]);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        die("Failed to open file for reading");
    }

    read(fd, &person, sizeof(Person));
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);

    close(fd);

    unlink(filename);

    return EXIT_SUCCESS;
}