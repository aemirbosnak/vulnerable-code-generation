//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int readCSV(const char* filename, char** lines, int* num_lines)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char* line = NULL;
    int num_chars = 0;
    int num_lines_read = 0;
    char delimiter = ',';

    while ((line = fgets(line, sizeof(line), file))!= NULL) {
        num_chars = strlen(line);
        if (line[num_chars - 1] == '\n' || line[num_chars - 1] == '\r') {
            line[num_chars - 1] = '\0';
        }

        int index = 0;
        char* token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (index < *num_lines) {
                (*lines)[index] = strdup(token);
            }
            index++;
            token = strtok(NULL, &delimiter);
        }
        *num_lines = index;
        num_lines_read++;
    }

    fclose(file);
    return num_lines_read;
}

int main(int argc, char** argv)
{
    char* filename = argv[1];
    char** lines = malloc(sizeof(char*) * 100);
    int num_lines = 0;
    int num_lines_read = readCSV(filename, lines, &num_lines);

    if (num_lines_read == 0) {
        printf("No lines were read from the CSV file.\n");
    } else {
        printf("Read %d lines from the CSV file:\n", num_lines_read);
        for (int i = 0; i < num_lines; i++) {
            printf("%s\n", lines[i]);
        }
    }

    free(lines);
    return 0;
}