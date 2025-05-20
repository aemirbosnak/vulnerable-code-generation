//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAGIC_BITMASK_SIZE 32
#define LOG_BASE2_MAX INT32_MAX

typedef struct {
    int number;
    char name[50];
} Person;

typedef unsigned int MagicBitmask;

void createMagicBitmask(MagicBitmask* bitmask) {
    *bitmask = 0;
    int i;
    for (i = 0; i < MAGIC_BITMASK_SIZE; ++i) {
        *bitmask |= 1 << i;
    }
}

bool isPowerOfTwo(int number) {
    if (number <= 0) {
        fprintf(stderr, "Error: Number must be positive.\n");
        exit(EXIT_FAILURE);
    }

    MagicBitmask magicBitmask;
    createMagicBitmask(&magicBitmask);

    return (magicBitmask & (number - 1)) == 0;
}

void printPerson(Person person) {
    printf("%s is %s power of 2: %s\n", person.name,
           (isPowerOfTwo(person.number) ? "a" : "not a"),
           (isPowerOfTwo(person.number) ? "true" : "false"));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <name> <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Person person;
    strcpy(person.name, argv[1]);
    person.number = atoi(argv[2]);

    clock_t start = clock();
    printPerson(person);
    clock_t end = clock();

    double time_spent = (end - start) / (double)CLOCKS_PER_SEC;
    printf("Time spent: %.16f seconds\n", time_spent);

    return EXIT_SUCCESS;
}