//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: portable
#define KEY 0x1A
#define ROUNDS 3

typedef unsigned char byte;

void swap_bytes(byte *a, byte *b) {
    byte t = *a;
    *a = *b;
    *b = t;
}

void left_rotate(byte *data, int shift) {
    byte temp = data[0];
    for (int i = 0; i < 7; i++) {
        data[i] = data[i + 1];
    }
    data[6] = temp;

    for (int i = 0; i < shift; i++) {
        left_rotate(data, 1);
    }
}

void encrypt_byte(byte *data) {
    byte key_copy = KEY;
    for (int i = 0; i < 8; i++) {
        byte temp = (*data) >> i;
        *data ^= (key_copy & (1 << (7 - i)));
        key_copy = key_copy << 1 | temp & 1;
    }
}

void process_block(byte *block) {
    byte temp;

    // Swap bytes 1 and 2
    swap_bytes(&block[1], &block[2]);

    // Left rotate bytes 1, 2, and 3
    left_rotate(&block[1], 2);
    left_rotate(&block[2], 2);
    left_rotate(&block[1], 1);

    // Encrypt each byte using the key
    for (int i = 0; i < 3; i++) {
        encrypt_byte(&block[i]);
    }

    // Swap bytes 1 and 3
    swap_bytes(&block[1], &block[2]);

    // XOR bytes 1 and 2
    temp = block[0];
    block[0] = block[1];
    block[1] = temp;
    temp = block[1];
    block[1] = block[2];
    block[2] = temp;
}

int main() {
    byte input[3] = {0x65, 0x69, 0x6E};
    byte output[3];

    for (int round = 0; round < ROUNDS; round++) {
        for (int i = 0; i < 3; i++) {
            process_block(&input[i]);
        }

        for (int i = 0; i < 3; i++) {
            process_block(&output[i]);
            process_block(&input[i]);
        }
    }

    // Print the encrypted output
    for (int i = 0; i < 3; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");

    return 0;
}