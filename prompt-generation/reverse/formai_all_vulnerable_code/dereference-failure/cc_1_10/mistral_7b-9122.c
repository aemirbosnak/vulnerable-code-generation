//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIT_STRING_LENGTH 100

typedef struct {
    int length;
    char bit_string[MAX_BIT_STRING_LENGTH];
} BitString;

void swap_bits(BitString* a, BitString* b, int index) {
    char temp;
    temp = a->bit_string[index];
    a->bit_string[index] = b->bit_string[index];
    b->bit_string[index] = temp;
}

void print_bit_string(BitString bit_string) {
    int i;
    for (i = 0; i < bit_string.length; i++) {
        printf("%c", bit_string.bit_string[i] == '0' ? '0' : '1');
    }
    printf("\n");
}

void recursive_bit_swap(BitString a, BitString b, int index) {
    if (index >= a.length || index >= b.length) {
        return;
    }

    if (a.bit_string[index] != b.bit_string[index]) {
        swap_bits(&a, &b, index);
        recursive_bit_swap(a, b, index + 1);
    }
}

int main(int argc, char* argv[]) {
    BitString x, y;
    int i, index;

    if (argc != 3) {
        printf("Usage: %s <bit string x> <bit string y>\n", argv[0]);
        return 1;
    }

    x.length = strlen(argv[1]);
    y.length = strlen(argv[2]);

    x.bit_string[x.length] = '\0';
    y.bit_string[y.length] = '\0';

    strcpy(x.bit_string, argv[1]);
    strcpy(y.bit_string, argv[2]);

    for (i = 0; i < x.length && i < y.length; i++) {
        if (x.bit_string[i] != y.bit_string[i]) {
            index = i;
            break;
        }
    }

    if (i == x.length || i == y.length) {
        printf("Error: bit strings are identical.\n");
        return 1;
    }

    recursive_bit_swap(x, y, index);

    printf("Swapped bit strings x and y:\n");
    print_bit_string(x);
    print_bit_string(y);

    return 0;
}