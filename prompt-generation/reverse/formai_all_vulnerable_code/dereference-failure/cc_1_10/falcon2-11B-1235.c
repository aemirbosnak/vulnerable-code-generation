//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[100];
    char *fields[100];
    int field_count = 0;
    int row_count = 0;
    int i;

    fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf("Unable to open file\n");
        exit(0);
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (row_count == 0)
        {
            char *temp = strtok(line, ",");
            while (temp!= NULL)
            {
                fields[field_count] = (char *) malloc(strlen(temp) + 1);
                strcpy(fields[field_count], temp);
                field_count++;
                temp = strtok(NULL, ",");
            }
        }
        else
        {
            for (i = 0; i < field_count; i++)
            {
                if (fields[i]!= NULL)
                {
                    printf("%s\n", fields[i]);
                }
            }
            field_count = 0;
            row_count++;
        }
    }
    fclose(fp);
    printf("Total number of rows: %d\n", row_count);
    printf("Total number of fields: %d\n", field_count);
    printf("That's all, folks!\n");
    return 0;
}