//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;

// Adler-32 checksum algorithm implementation
word adler32(const void* data, size_t size) {
    const word ONE = 0x01U;
    const word A = 0x01U;
    const word B = 0x009dU;

    word s1 = A;
    word s2 = B;

    const byte* p = (const byte*) data;

    while (size--) {
        s1 = (s1 + *p++) % 65521;
        s2 = (s2 + s1) % 65521;
    }

    return (s1 << 16 | s2);
}

int main() {
    const char* message = "This is a unique C Checksum Calculator example program.";
    const size_t message_length = strlen(message);

    dword checksum = adler32(message, message_length);

    printf("Original message checksum: %08x%08x\n", (checksum >> 16), (checksum & 0xFFFF));

    // Manipulate the message
    strcpy(message, "This is a modified C Checksum Calculator example program.");
    const size_t modified_message_length = strlen(message);

    dword modified_checksum = adler32(message, modified_message_length);

    printf("Modified message checksum: %08x%08x\n", (modified_checksum >> 16), (modified_checksum & 0xFFFF));

    // Compare checksums
    if (checksum == modified_checksum) {
        printf("Both messages have the same checksum.\n");
    } else {
        printf("Messages have different checksums.\n");
    }

    return 0;
}