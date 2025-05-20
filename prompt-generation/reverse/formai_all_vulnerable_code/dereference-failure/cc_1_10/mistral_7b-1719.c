//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 200

void binary_to_text(unsigned char *binary, char *format, char *output) {
    int i, j, len_format, len_output;
    unsigned int binary_num;

    len_format = strlen(format);

    for (i = 0; i < len_format; i++) {
        if (format[i] == '%') {
            i++;

            if (format[i] == 'b') {
                binary_num = 0;
                len_output = 0;

                while (i < len_format + MAX_INPUT_LENGTH && binary[binary_num] != '\0') {
                    binary_num <<= 1;
                    if (binary[binary_num + binary_num] != '\0')
                        binary_num |= binary[binary_num + binary_num] & 0x01;

                    output[len_output++] = (binary_num % 2) + '0';
                    binary_num >>= 1;
                }

                output[len_output] = '\0';
                i++;
            } else {
                if (format[i] != '%') {
                    output[i - (len_format - i)] = format[i];
                }
            }
        } else {
            output[i - (len_format - i)] = binary[i];
        }
    }

    output[len_output = strlen(output)] = '\0';
}

int main() {
    unsigned char binary[] = {0x01, 0x00, 0x11, 0x11};
    char format[MAX_OUTPUT_LENGTH] = "%s%b%s%b%s";
    char output1[MAX_OUTPUT_LENGTH] = {0};
    char output2[MAX_OUTPUT_LENGTH] = {0};

    binary_to_text(binary, format, output1);
    printf("Output 1: %s\n", output1);

    memset(output1, 0, sizeof(output1));
    memset(output2, 0, sizeof(output2));

    binary[0] = 0x41;
    binary[1] = 0x42;
    binary[2] = 0x43;
    binary[3] = 0x44;

    binary_to_text(binary, "%c%c%c%c%sb%s", output2);
    printf("Output 2: %s\n", output2);

    return 0;
}