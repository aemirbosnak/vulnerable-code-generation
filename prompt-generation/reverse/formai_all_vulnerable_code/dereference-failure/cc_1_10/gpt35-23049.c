//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void recover_data(char *filename_org, char *filename_rec)
{
    FILE *file_org = fopen(filename_org, "rb");
    FILE *file_rec = fopen(filename_rec, "wb");

    if (file_org == NULL || file_rec == NULL)
    {
        printf("Error opening files!\n");
        return;
    }

    fseek(file_org, 0, SEEK_END);
    int file_size = ftell(file_org);
    fseek(file_org, 0, SEEK_SET);

    char *data = (char *)malloc(file_size);

    if (data == NULL)
    {
        printf("Error allocating memory!\n");
        return;
    }

    fread(data, file_size, 1, file_org);

    for (int i = 0; i < file_size; i++)
    {
        if (data[i] == '0')
        {
            data[i] = '1';
        }
        else if (data[i] == '1')
        {
            data[i] = '0';
        }
    }

    fwrite(data, file_size, 1, file_rec);

    printf("Data recovered!\n");

    free(data);
    fclose(file_org);
    fclose(file_rec);
}

int main()
{
    recover_data("original_data.txt", "recovered_data.txt");

    return 0;
}