//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int main()
{
    FILE *fp;
    char line[1000];
    char *delimiters = ",";
    char *value;
    int i = 0;
    int num_rows = 0;
    int num_cols = 0;
    char *cols[100];
    time_t t;
    char *datestr;
    struct tm *tm_ptr;
    int j;
    srand(time(NULL));
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token;
        token = strtok(line, delimiters);
        num_rows++;
        while (token!= NULL) {
            char *token2;
            token2 = strtok(NULL, delimiters);
            cols[i] = token2;
            i++;
            token = strtok(NULL, delimiters);
        }
        num_cols++;
        tm_ptr = localtime(&t);
        datestr = asctime(tm_ptr);
        printf("CSV Reader\n");
        printf("---------------------\n");
        printf("Num Rows: %d\n", num_rows);
        printf("Num Cols: %d\n", num_cols);
        printf("---------------------\n");
        printf("Data: %s\n", datestr);
        printf("---------------------\n");
        for (j = 0; j < num_cols; j++) {
            value = strchr(cols[j], ',');
            if (value == NULL) {
                printf("Column %d: %s\n", j+1, cols[j]);
            } else {
                printf("Column %d: %s\n", j+1, cols[j] + strlen(cols[j]) + 1);
            }
        }
        printf("---------------------\n");
    }
    fclose(fp);
    return 0;
}