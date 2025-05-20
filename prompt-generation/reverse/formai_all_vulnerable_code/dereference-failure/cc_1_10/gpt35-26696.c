//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 512

typedef unsigned char byte;

byte get_checksum(byte *data, size_t size)
{
    byte checksum = 0;
    for(int i = 0; i < size; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

int main(void)
{
    // allocate memory for data
    byte *data = malloc(DATA_SIZE);

    // generate random data
    for(int i = 0; i < DATA_SIZE; i++) {
        data[i] = (byte)rand();
    }

    // calculate and print checksum
    byte checksum = get_checksum(data, DATA_SIZE);
    printf("Checksum: 0x%02X\n", checksum);

    // check if data has been tampered with
    printf("Performing paranoid check...\n");
    for(int i = 0; i < 10000; i++) {
        // tamper with one random byte
        int idx = rand() % DATA_SIZE;
        byte old_value = data[idx];
        data[idx] = (byte)rand();

        // check if checksum has changed
        byte new_checksum = get_checksum(data, DATA_SIZE);
        if(new_checksum != checksum) {
            printf("Data has been tampered with at index %d!\n", idx);
            printf("Old value: 0x%02X, New value: 0x%02X\n", old_value, data[idx]);
            printf("Checksum: Old value: 0x%02X, New value: 0x%02X\n", checksum, new_checksum);
            return EXIT_FAILURE;
        }

        // restore old value
        data[idx] = old_value;
    }

    printf("Paranoid check successful!\n");

    free(data);
    return EXIT_SUCCESS;
}