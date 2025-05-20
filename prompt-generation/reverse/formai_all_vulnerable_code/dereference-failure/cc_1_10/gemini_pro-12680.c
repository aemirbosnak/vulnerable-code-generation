//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct checksum_t
{
    unsigned int value;
    unsigned char *data;
    size_t size;
};

static unsigned int checksum_calc(struct checksum_t *cs)
{
    unsigned int sum = 0;
    int i;

    if (!cs)
        return 0;

    for (i = 0; i < cs->size; i++)
    {
        sum += cs->data[i];
    }

    return sum;
}

static void checksum_print(struct checksum_t *cs)
{
    if (!cs)
        return;

    printf("Checksum: 0x%08X\n", cs->value);
}

int main(int argc, char **argv)
{
    int i;
    struct checksum_t cs;

    if (argc < 2)
    {
        printf("Usage: %s <string1> <string2> ...\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        cs.data = argv[i];
        cs.size = strlen(argv[i]);
        cs.value = checksum_calc(&cs);
        checksum_print(&cs);
    }

    return 0;
}