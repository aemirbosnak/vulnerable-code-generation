//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define CHAR_SET_SIZE 26

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char char_set[CHAR_SET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    int char_set_size = CHAR_SET_SIZE;
    int *random_numbers;
    int random_numbers_size = 10;
    int i, j, k;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    srand(time(NULL));

    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    random_numbers = (int *)malloc(random_numbers_size * sizeof(int));

    for (i = 0; i < random_numbers_size; i++) {
        random_numbers[i] = rand() % (BUFFER_SIZE / 2);
    }

    for (i = 0; i < strlen(buffer); i++) {
        for (j = 0; j < random_numbers_size; j++) {
            if (i == random_numbers[j]) {
                putchar(char_set[rand() % char_set_size]);
                break;
            }
        }
        putchar(buffer[i]);
    }

    free(random_numbers);

    return 0;
}