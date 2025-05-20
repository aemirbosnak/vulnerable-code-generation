//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_csv_line(char *line, char *delimiter, char **tokens, int *num_tokens)
{
    char *token;
    *num_tokens = 0;
    token = strtok(line, delimiter);
    while(token != NULL)
    {
        tokens[*num_tokens] = token;
        (*num_tokens)++;
        token = strtok(NULL, delimiter);
    }
}

void read_csv_file(char *filename, char *delimiter)
{
    FILE *fptr;
    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_LINE_LENGTH];
    int num_tokens, i;
    fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fgets(line, MAX_LINE_LENGTH, fptr); // skip header line
    while(fgets(line, MAX_LINE_LENGTH, fptr))
    {
        parse_csv_line(line, delimiter, tokens, &num_tokens);
        for(i = 0; i < num_tokens; i++)
        {
            printf("%s\t", tokens[i]); // print each token
        }
        printf("\n");
    }
    fclose(fptr);
}

int main(int argc, char *argv[])
{
    char *filename, *delimiter;
    if(argc < 3)
    {
        printf("Usage: %s filename delimiter\n", argv[0]);
        return 1;
    }
    filename = argv[1];
    delimiter = argv[2];
    printf("Reading CSV file %s with delimiter %s...\n", filename, delimiter);
    read_csv_file(filename, delimiter);
    return 0;
}