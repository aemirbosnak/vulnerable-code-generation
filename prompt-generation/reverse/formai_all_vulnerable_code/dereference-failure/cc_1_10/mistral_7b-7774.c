//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 100
#define MAX_LEN 500
#define MIN_CHAR 'a'
#define MAX_CHAR 'z'
#define BUF_SIZE 4096

char *generate_random_string(size_t length) {
    char *str;
    char ch;
    int rand_num;

    str = (char *)calloc(length + 1, sizeof(char));

    if (str == NULL) {
        perror("Calloc failed\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (size_t i = 0; i < length; i++) {
        rand_num = rand() % (MAX_CHAR - MIN_CHAR + 1) + MIN_CHAR;
        ch = (char)rand_num;
        str[i] = ch;
    }

    str[length] = '\0';

    return str;
}

void print_string(char *str) {
    int len = strlen(str);

    printf("String length: %d\n", len);
    printf("Random String: %s\n", str);
}

int main(int argc, char **argv) {
    clock_t start, end;
    double time_diff;
    size_t length;
    char *random_str;

    if (argc < 2) {
        printf("Usage: %s <length of random string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    length = atoi(argv[1]);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Invalid length: %d\n", length);
        exit(EXIT_FAILURE);
    }

    start = clock();
    random_str = generate_random_string(length);
    end = clock();

    time_diff = (double)(end - start) / CLOCKS_PER_SEC;

    print_string(random_str);
    printf("Time taken: %f seconds\n", time_diff);

    free(random_str);

    return EXIT_SUCCESS;
}