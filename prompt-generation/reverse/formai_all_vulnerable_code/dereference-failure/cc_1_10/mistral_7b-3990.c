//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 12
#define MAX_LEN 20
#define CHAR_COUNT 47
#define SEED_SIZE 128

char *password;
char charset[CHAR_COUNT] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '!', '@', '#', '$', '%', '&', '*', '(', ')', '_', '+', '=', '-', ';',
        ':', ',', '.', '>', '<', '/', '?', '`', '{', '|', '}', '[', ']', '\\'};

void generate_password(int length) {
    int i, j, rand_index1, rand_index2;
    password = (char*)malloc(length + 1);

    if (password == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL) + getpid());

    for (i = 0; i < length; i++) {
        rand_index1 = rand() % CHAR_COUNT;
        rand_index2 = rand() % CHAR_COUNT;

        if (i > 0 && rand() % 2) {
            int temp = charset[rand_index1];
            charset[rand_index1] = charset[rand_index2];
            charset[rand_index2] = temp;
        }

        password[i] = charset[rand() % CHAR_COUNT];
    }

    password[length] = '\0';
    printf("Generated password: %s\n", password);
}

int main(int argc, char *argv[]) {
    int length;

    if (argc != 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    length = atoi(argv[1]);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Error: length should be between %d and %d.\n", MIN_LEN, MAX_LEN);
        return 1;
    }

    generate_password(length);
    free(password);
    return 0;
}