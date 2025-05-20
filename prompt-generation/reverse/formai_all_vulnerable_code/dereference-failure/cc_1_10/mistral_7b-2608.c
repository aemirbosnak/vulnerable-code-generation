//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    int value;
    char name[20];
} PintsizedInt;

void print_int(PintsizedInt pint) {
    printf("%s = %d\n", pint.name, pint.value);
}

int main() {
    PintsizedInt Bob = {.value = 5, .name = "Bob"};
    PintsizedInt Al = {.value = 7, .name = "Al"};
    PintsizedInt sum, diff, prod, quot, rem;

    // Bob meets some friends and they start performing arithmetic operations!

    // Addition (Bob + Al)
    sum = (PintsizedInt){.value = Bob.value + Al.value, .name = "Sum"};
    printf("\n--- ADDITION ---\n");
    print_int(Bob);
    print_int(Al);
    print_int(sum);
    printf("%s absorbs the sum's energy!\n\n", sum.name);
    sum.value -= 2 * (Bob.value + Al.value); // Sum disappears due to excessive energy!

    // Subtraction (Bob - Al)
    diff = (PintsizedInt){.value = Bob.value - Al.value, .name = "Difference"};
    printf("\n--- SUBTRACTION ---\n");
    print_int(Bob);
    print_int(Al);
    print_int(diff);
    printf("%s runs away, leaving %s behind!\n\n", diff.name, Al.name);

    // Multiplication (Bob * Al)
    prod = (PintsizedInt){.value = Bob.value * Al.value, .name = "Product"};
    printf("\n--- MULTIPLICATION ---\n");
    print_int(Bob);
    print_int(Al);
    print_int(prod);
    printf("%s grows fatter with each passing second!\n\n", prod.name);

    // Division (Bob / Al) with remainder
    quot = (PintsizedInt){.value = Bob.value / Al.value, .name = "Quotient"};
    rem = (PintsizedInt){.value = Bob.value % Al.value, .name = "Remainder"};
    printf("\n--- DIVISION ---\n");
    print_int(Bob);
    print_int(Al);
    print_int(quot);
    print_int(rem);
    printf("%s proudly announces: \"I have %s left over!\"\n", quot.name, rem.name);

    free(Bob.name);
    free(Al.name);
    free(sum.name);
    free(diff.name);
    free(prod.name);
    free(quot.name);
    free(rem.name);

    return 0;
}