//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t mask;
    size_t length;
} bit_vector;

void bit_vector_init(bit_vector* bv, size_t length) {
    bv->length = length;
    bv->mask = ((1ULL << length) - 1) << (64 - length);
}

void bit_vector_set(bit_vector* bv, size_t index, bool value) {
    if (value)
        bv->mask |= (1ULL << index);
    else
        bv->mask &= ~(1ULL << index);
}

bool bit_vector_get(const bit_vector* bv, size_t index) {
    return (bv->mask >> index) & 1;
}

bool recursive_palindrome_checker(const char* str, size_t left, size_t right) {
    if (left >= right)
        return true;

    if (*(str + left) != *(str + right))
        return false;

    bit_vector left_half;
    bit_vector_init(&left_half, (size_t)((right - left) / 2 + 1));

    for (size_t i = left + 1; i <= right; ++i) {
        bit_vector_set(&left_half, i - left - 1, true);
        if (!recursive_palindrome_checker(str, i + 1, i - 1))
            return false;
    }

    return true;
}

bool palindrome_checker(const char* str) {
    return recursive_palindrome_checker(str, 0, strlen(str) - 1);
}

int main() {
    char str[101];
    printf("Enter a string: ");
    scanf("%s", str);

    if (palindrome_checker(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}