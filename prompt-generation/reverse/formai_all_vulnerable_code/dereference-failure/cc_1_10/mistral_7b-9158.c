//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100

void print_rainbow(void) {
    const char *colors[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m"};
    int i;

    for (i = 0; i < 7; i++)
        printf("%s", colors[i]);
    puts("Rainbow print in the terminal!");

    for (i = 6; i >= 0; i--)
        printf("\033[0m%s", colors[i]);
}

int main(int argc, char *argv[]) {
    char str[MAX_LEN];
    int len;

    if (argc < 2) {
        puts("Usage: ./a.out <string to print>");
        return 1;
    }

    len = strlen(argv[1]);

    if (len > MAX_LEN - 1) {
        fprintf(stderr, "Error: string too long\n");
        return 1;
    }

    strcpy(str, argv[1]);

    printf("Original string: %s\n", str);

    print_rainbow();

    printf("\nPrinting the string in rainbow color:\n");

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        printf("\033[31m%c\033[32m", str[i]);
    }

    printf("\nString in rainbow color: %s\n", str);

    print_rainbow();

    return 0;
}