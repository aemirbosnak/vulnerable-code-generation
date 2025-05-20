//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short int ushort;
typedef unsigned long long int u64long;
typedef unsigned char ubyte;
typedef unsigned int uint;

u64long checksum(ubyte *buf, uint len)
{
    if (len == 0)
        return 0;

    u64long sum = buf[0] + checksum(buf + 1, len - 1);

    if (sum > 0xFFFF)
        sum = (sum >> 16) + (sum & 0xFFFF);

    return sum;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    uint len = ftell(file);
    fseek(file, 0, SEEK_SET);

    ubyte *buf = malloc(len);
    if (!buf)
    {
        perror("malloc");
        return 1;
    }

    if (fread(buf, 1, len, file) < (size_t)len)
    {
        perror("fread");
        return 1;
    }

    fclose(file);

    printf("Checksum: %08llX\n", checksum(buf, len));

    free(buf);

    return 0;
}