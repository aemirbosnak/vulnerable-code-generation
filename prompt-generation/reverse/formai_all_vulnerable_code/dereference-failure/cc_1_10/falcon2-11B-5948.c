//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare two files and return the number of differences.
int compareFiles(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    int diff = 0;

    // Open the files for reading.
    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Error opening file %s\n", file1);
        return diff;
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Error opening file %s\n", file2);
        return diff;
    }

    // Read the lines from the two files.
    char line1[256], line2[256];
    while (fgets(line1, sizeof(line1), fp1)!= NULL && fgets(line2, sizeof(line2), fp2)!= NULL) {
        // Compare the lines.
        if (strcmp(line1, line2)!= 0)
            diff++;
    }

    // Close the files.
    fclose(fp1);
    fclose(fp2);

    return diff;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <source> <destination> <output>\n", argv[0]);
        return 1;
    }

    const char *source = argv[1];
    const char *destination = argv[2];
    const char *output = argv[3];

    int diff = compareFiles(source, destination);
    if (diff == 0)
        printf("Files are identical.\n");
    else
        printf("%d differences found.\n", diff);

    return 0;
}