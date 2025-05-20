//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define HEX_TO_DEC(x) ((x >= '0' && x <= '9') ? (x - '0') : (x >= 'A' && x <= 'F') ? (x - 'A' + 10) : -1)

void die(const char *msg) {
        fprintf(stderr, "%s\n", msg);
        exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
        unsigned char hex[MAX];
        unsigned int num, i;
        char str[MAX], *end;

        if (argc != 3)
                die("Usage: ./hex2dec <hex_string> <decimal_number>\n");

        strcpy(str, argv[1]);
        num = strtoul(argv[2], &end, 10);

        if (argc != 3 || *end != '\0')
                die("Invalid arguments.\n");

        for (i = 0; i < strlen(str) && i < MAX; i++) {
                if (isxdigit(str[i]))
                        hex[i] = HEX_TO_DEC(tolower(str[i]));
                else
                        die("Invalid hexadecimal digits.\n");
        }

        for (i = 0; i < strlen(str) / 2; i++) {
                unsigned char tmp = hex[i];
                hex[i] = hex[strlen(str) - i - 1];
                hex[strlen(str) - i - 1] = tmp;
        }

        for (i = 0; i < strlen(str) / 2; i++) {
                num = num * 16 + hex[i];
        }

        if (num != atoi(argv[2]))
                die("Conversion failed.\n");

        printf("Successfully converted '%s' to %u.\n", argv[1], num);

        return EXIT_SUCCESS;
}