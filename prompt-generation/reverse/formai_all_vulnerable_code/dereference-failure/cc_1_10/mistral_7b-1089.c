//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define WORD_SIZE 4
#define OPCODE_BYTE 0
#define OPERAND_BYTES 3

typedef uint16_t word_t;
typedef uint8_t byte_t;

const char *aliens[] = {
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "MOD",
    "AND",
    "OR",
    "XOR",
    "NOT",
    "LOAD"
};

void translate(byte_t *code, size_t length) {
    size_t i = 0;
    while (i < length) {
        word_t word = *(word_t *)code;
        byte_t opcode = (byte_t)(word >> (8 * OPCODE_BYTE));
        byte_t operand1 = (byte_t)(word >> (8 * (OPCODE_BYTE + OPERAND_BYTES)));
        byte_t operand2 = (byte_t)((word >> (8 * (OPCODE_BYTE + OPERAND_BYTES + 1))) & 0xFF);
        byte_t operand3 = (byte_t)((word >> (8 * (OPCODE_BYTE + OPERAND_BYTES + 2))) & 0xFF);

        printf("%s %s %s, %d, %d\n", aliens[opcode],
            (operand1 > 0x10) ? "R" : "R" + operand1,
            (operand2 > 0x10) ? "R" : "R" + operand2,
            (int)operand3, (int)operand3);

        i += WORD_SIZE;
        code += WORD_SIZE;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <Alien code>\n", argv[0]);
        return 1;
    }

    size_t length = strlen(argv[1]) / WORD_SIZE;
    byte_t *code = (byte_t *)argv[1];

    translate(code, length);
    return 0;
}