//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef unsigned char byte;
typedef unsigned int word;

void checksum_update(word *sum, const byte *data, size_t length) {
    size_t i;

    for (i = 0; i < length; ++i) {
        sum[0] += data[i];
        if (++sum[1] >= 0xFFFF) {
            sum[0] += sum[1] & 0xFFFF;
            sum[1] = sum[1] >> 16;
        }
    }
}

word calculate_checksum(const byte *data, size_t length) {
    word sum[2] = {0, 0};

    checksum_update(sum, data, length);
    checksum_update(sum, (const byte *) &length, sizeof(length));

    byte temp[2 * sizeof(word)];
    memcpy(temp, sum, sizeof(sum));

    sum[0] = (sum[0] & 0xFFFF) << 16;
    sum[0] |= temp[0] & 0xFFFF;
    sum[1] = (sum[1] & 0xFFFF) << 16;
    sum[1] |= temp[1] & 0xFFFF;

    return sum[0];
}

void print_hex(const byte *data, size_t length) {
    size_t i;

    printf("[");

    for (i = 0; i < length; ++i) {
        printf("%02X", data[i]);

        if (i != length - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main() {
    const char *test_string = "Hello, World!";
    const size_t test_string_length = strlen(test_string);
    const byte *test_data = (const byte *) test_string;
    const byte *test_data_end = test_data + test_string_length;

    byte *data_buffer = malloc(MAX_BUFFER_SIZE);
    byte *data_write_ptr = data_buffer;

    printf("Test string: ");
    print_hex(test_data, test_string_length);

    size_t test_data_length = test_string_length;

    while (test_data < test_data_end) {
        *data_write_ptr++ = *test_data++;

        if ((data_write_ptr - data_buffer) >= MAX_BUFFER_SIZE - sizeof(size_t)) {
            word checksum = calculate_checksum(data_buffer, data_write_ptr - data_buffer);
            print_hex((const byte *) &checksum, sizeof(checksum));
            printf(" (length: %zu)\n", (data_write_ptr - data_buffer));

            data_write_ptr = data_buffer;
        }
    }

    word checksum = calculate_checksum(data_buffer, data_write_ptr - data_buffer);
    print_hex((const byte *) &checksum, sizeof(checksum));
    printf(" (length: %zu)\n", (data_write_ptr - data_buffer));

    free(data_buffer);

    return 0;
}