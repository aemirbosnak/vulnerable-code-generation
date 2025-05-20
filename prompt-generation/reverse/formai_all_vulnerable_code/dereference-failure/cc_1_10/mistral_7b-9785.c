//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bit {
    bool value;
    struct Bit* next;
} Bit;

void display_bit(const Bit* bit) {
    if (bit == NULL) {
        printf("Empty bitstream\n");
        return;
    }

    printf("%s", bit->value ? "1" : "0");
    display_bit(bit->next);
}

Bit* append_bit(Bit* stream, bool value) {
    Bit* new_bit = (Bit*)malloc(sizeof(Bit));
    new_bit->value = value;
    new_bit->next = NULL;

    if (stream == NULL) {
        return new_bit;
    }

    return stream->next = new_bit;
}

bool calculate_parity(const Bit* stream) {
    if (stream == NULL) {
        return false;
    }

    return stream->value ^ calculate_parity(stream->next);
}

bool is_valid_binary(const Bit* stream, int length) {
    if (stream == NULL) {
        return false;
    }

    if (length <= 0) {
        return stream->value == false;
    }

    bool current_bit = stream->value;
    Bit* current_node = stream;

    length--;

    while (length > 0) {
        if (current_bit != (length % 2)) {
            return false;
        }

        current_bit = current_node->next->value;
        current_node = current_node->next;
        length--;
    }

    return calculate_parity(stream) == current_bit;
}

int main() {
    int binary_number;

    printf("Enter the binary number (in reverse order): ");
    scanf("%d", &binary_number);

    Bit* bitstream = NULL;

    while (binary_number > 0) {
        bitstream = append_bit(bitstream, binary_number % 2);
        binary_number /= 2;
    }

    printf("Binary number: ");
    display_bit(bitstream);
    printf("\n");

    if (is_valid_binary(bitstream, sizeof(int) * 8)) {
        printf("Valid binary number\n");
    } else {
        printf("Invalid binary number\n");
    }

    free(bitstream);

    return 0;
}