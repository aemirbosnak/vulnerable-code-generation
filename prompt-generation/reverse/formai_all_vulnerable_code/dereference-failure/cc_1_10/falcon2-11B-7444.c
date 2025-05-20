//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1000

void print_csv_line(char line[]) {
    if (strlen(line) > 0) {
        printf("%s,%s,%s\n", line, line + 1, line + 2);
    }
}

int csv_read(FILE* fp) {
    char line[MAX_LINE_LENGTH];
    char* delim = ",";
    int count = 0;

    while (fgetc(fp)!= EOF) {
        if (isdigit(fgetc(fp))) {
            count++;
        } else {
            count = 0;
        }

        if (count == 3) {
            strncpy(line, (char*) malloc(sizeof(char) * (count + 1)), count);
            line[count] = '\0';
            print_csv_line(line);
            count = 0;
        }
    }

    return count;
}

int main() {
    FILE* fp;
    char filename[] = "data.csv";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int count = csv_read(fp);
    fclose(fp);

    return 0;
}