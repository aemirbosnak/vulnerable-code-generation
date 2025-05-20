//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

struct checksum_data {
    char *filename;
    unsigned int checksum;
};

unsigned int calculate_checksum(char *filename) {
    FILE *fp;
    unsigned int checksum = 0;
    int c;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", filename);
        exit(1);
    }

    while ((c = fgetc(fp))!= EOF) {
        checksum += c;
    }

    fclose(fp);

    return checksum;
}

void print_checksum_data(struct checksum_data *data, int num_files) {
    printf("Filename\tChecksum\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%u\n", data[i].filename, data[i].checksum);
    }
}

int main() {
    int num_files;
    char filename[MAX_LENGTH];
    struct checksum_data data[MAX_LENGTH];

    printf("Enter number of files to calculate checksum: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter filename for file %d: ", i+1);
        scanf("%s", filename);

        data[i].filename = strdup(filename);
        data[i].checksum = calculate_checksum(filename);
    }

    printf("\nChecksum for %d files:\n", num_files);
    print_checksum_data(data, num_files);

    for (int i = 0; i < num_files; i++) {
        free(data[i].filename);
    }

    return 0;
}