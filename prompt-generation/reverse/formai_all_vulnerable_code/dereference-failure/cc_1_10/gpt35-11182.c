//FormAI DATASET v1.0 Category: QR code generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 25

unsigned char qr_code[BLOCK_SIZE][BLOCK_SIZE];

void initialize_code(void)
{
    memset(qr_code, 0xFF, sizeof(qr_code));
}

void set_code(int x, int y, int value)
{
    qr_code[x][y] = (unsigned char)value;
}

int generate_block(int index, char *data)
{
    int count = strlen(data);
    int i, x, y;

    initialize_code();

    switch(index) {
        case 1:
            for(i = 0; i < count; i++) {
                x = (i % 5) + 2;
                y = (i / 5) + 2;
                set_code(x, y, data[i]);
            }
            break;
        case 2:
            for(i = 0; i < count; i++) {
                x = (i / 5) + 2;
                y = (i % 5) + 2;
                set_code(x, y, data[i]);
            }
            break;
        case 3:
            for(i = 0; i < count; i++) {
                x = (i % 3) + 2;
                y = (i / 3) + 2;
                set_code(x, y, data[i]);
            }
            break;
        case 4:
            for(i = 0; i < count; i++) {
                x = (i / 3) + 2;
                y = (i % 3) + 2;
                set_code(x, y, data[i]);
            }
            break;
    }

    printf("QR Code Block %d:\n", index);
    for(y = 0; y < BLOCK_SIZE; y++) {
        for(x = 0; x < BLOCK_SIZE; x++) {
            printf("%c ", qr_code[x][y]);
        }
        printf("\n");
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 5) {
        printf("Usage: qr_code_generator <block1_data> <block2_data> <block3_data> <block4_data>\n");
        return -1;
    }

    generate_block(1, argv[1]);
    generate_block(2, argv[2]);
    generate_block(3, argv[3]);
    generate_block(4, argv[4]);

    return 0;
}