//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

int main()
{
    char **csv_data = NULL;
    int num_lines = 0, num_cols = 0;
    char line[MAX_LINES];
    FILE *fp = fopen("data.csv", "r");

    if (fp)
    {
        while (fgets(line, MAX_LINES, fp) != NULL)
        {
            num_lines++;

            char **columns = malloc(num_cols * sizeof(char *));
            for (int i = 0; i < num_cols; i++)
            {
                columns[i] = strdup(strtok(line, ","));
            }

            if (csv_data == NULL)
            {
                csv_data = malloc(num_lines * sizeof(char **));
            }

            csv_data[num_lines - 1] = columns;
            num_cols = atoi(columns[0]);
        }

        fclose(fp);
    }

    for (int i = 0; i < num_lines; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            printf("%s,", csv_data[i][j]);
        }

        printf("\n");
    }

    free(csv_data);

    return 0;
}