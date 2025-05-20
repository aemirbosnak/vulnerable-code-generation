//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

char *trim_whitespace(char *str)
{
    char *end;
    int i;

    if (str == NULL) {
        return NULL;
    }

    end = str + strlen(str) - 1;

    while (isspace(*end)) {
        end--;
    }

    end[1] = '\0';

    i = 0;
    while (isspace(*str)) {
        str++;
    }

    return str;
}

int main(int argc, char **argv)
{
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *word;
    int count = 0;
    int max_count = 0;
    int max_index = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        word = trim_whitespace(line);
        count = 0;

        if (word == NULL) {
            continue;
        }

        while (word[count]!= '\0') {
            if (isalpha(word[count])) {
                count++;
            } else {
                break;
            }
        }

        if (count > max_count) {
            max_count = count;
            max_index = 0;
        } else if (count == max_count) {
            max_index++;
        }
    }

    fclose(fp);

    if (max_count == 0) {
        printf("No words found.\n");
    } else {
        printf("Longest word: %s (%d characters)\n", argv[1], max_count);
    }

    return 0;
}