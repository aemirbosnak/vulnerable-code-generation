//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

unsigned short checksum(unsigned short *ptr, int nbytes);

int main()
{
    FILE *fp;
    char filename[BUFSIZE];
    unsigned short sum;
    unsigned short *buf;
    int nbytes;

    printf("Enter the name of the file to calculate checksum: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    nbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    buf = (unsigned short *) malloc(nbytes);
    if (buf == NULL) {
        printf("Memory allocation error.\n");
        return 0;
    }

    if (fread(buf, 1, nbytes, fp) != nbytes) {
        printf("Error reading file.\n");
        return 0;
    }

    sum = checksum(buf, nbytes/2);

    printf("Checksum of %s: %04X\n", filename, sum);

    free(buf);
    fclose(fp);

    return 0;
}

unsigned short checksum(unsigned short *ptr, int nbytes)
{
    unsigned long sum;
    for (sum = 0; nbytes > 0; nbytes--)
        sum += (unsigned long) *(ptr++);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}