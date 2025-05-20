//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void read_csv(char *filename, char data[MAX_ROWS][MAX_COLS][100], int *rows, int *cols)
{
    FILE *fp = fopen(filename, "r");
    char buffer[1000], *token;
    int i = 0, j = 0;

    fgets(buffer, 1000, fp);

    token = strtok(buffer, ",");

    while(token != NULL)
    {
        strcpy(data[i][j], token);
        j++;
        token = strtok(NULL, ",");
    }

    *cols = j;
    i++;

    while(fgets(buffer, 1000, fp) != NULL)
    {
        j = 0;
        token = strtok(buffer, ",");
        while(token != NULL)
        {
            strcpy(data[i][j], token);
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }

    *rows = i;

    fclose(fp);
}

int main()
{
    char data[MAX_ROWS][MAX_COLS][100];
    int rows, cols;

    read_csv("example.csv", data, &rows, &cols);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}