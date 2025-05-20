//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void recoverData(char *filename)
{
    printf("Scanning file for recoverable data...\n");

    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("File doesn't exist.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = (char *)malloc(sizeof(char) * file_size);
    fread(data, sizeof(char), file_size, file);

    printf("Analyzing data blocks for recoverable data...\n");

    char *recovered_data = (char *)malloc(sizeof(char) * file_size);
    int recovered_size = 0;

    for (int i = 0; i < file_size; i++) {
        if (data[i] == 0) {
            recovered_data[recovered_size++] = data[i];
        } else if (i > 0 && data[i] != data[i - 1]) {
            recovered_data[recovered_size++] = data[i];
        }
    }

    printf("Recovered data:\n%s\n", recovered_data);

    free(data);
    free(recovered_data);
    fclose(file);
}

int main()
{
    printf("Welcome to the Data Recovery Tool!\n");
    printf("Please enter the name of the file to recover:\n");

    char filename[100];
    scanf("%s", filename);

    recoverData(filename);

    printf("Data recovery complete. Thank you for using our tool!\n");

    return 0;
}