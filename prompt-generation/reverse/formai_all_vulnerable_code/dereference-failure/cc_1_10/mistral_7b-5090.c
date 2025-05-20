//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int binary[32];
} Person;

void print_binary(int num, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", num % 2);
        num /= 2;
    }
}

void convert_to_binary(Person *person) {
    int decimal = atoi(person->name);
    for (int i = 0; i < 32; i++) {
        person->binary[i] = decimal % 2;
        decimal /= 2;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s name decimal\n", argv[0]);
        return 1;
    }

    Person juliet = {"Juliet", 0};
    strcpy(juliet.name, argv[1]);
    convert_to_binary(&juliet);

    printf("Name: %s, Binary:\n", argv[1]);
    print_binary(1, 32);
    printf("\n");

    printf("Name: %s, Binary:\n", argv[1]);
    for (int i = 0; i < 32; i++) {
        printf("%d", juliet.binary[i]);
    }
    printf("\n");

    int shakespeare = atoi(argv[2]);
    Person romeo = {"Romeo", 0};
    convert_to_binary(&romeo);

    int sum = shakespeare + juliet.binary[0] * 256 + juliet.binary[1] * 128 +
              juliet.binary[2] * 64 + juliet.binary[3] * 32 + juliet.binary[4] * 16 +
              juliet.binary[5] * 8 + juliet.binary[6] * 4 + juliet.binary[7] * 2 +
              juliet.binary[8] * 1;

    printf("Name: Romeo, Binary:\n");
    print_binary(romeo.binary[0], 32);
    printf("\n");

    printf("Name: Romeo, Decimal: %d\n", sum);

    return 0;
}