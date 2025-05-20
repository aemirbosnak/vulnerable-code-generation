//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to be searched
#define MAX_LINE_SIZE 256 // Maximum line size to be searched
#define MAX_FILE_NAME_SIZE 100 // Maximum file name size
#define MAX_SEARCH_STRING_SIZE 100 // Maximum search string size
#define MAX_NUM_SEARCH_STRINGS 100 // Maximum number of search strings

typedef struct {
    char *file_name; // File name to be searched
    char *search_strings[MAX_NUM_SEARCH_STRINGS]; // Search strings to be searched
    int num_search_strings; // Number of search strings
} FileSearchData;

void load_file_search_data(FileSearchData *data) {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name to be searched: ");
    scanf("%s", file_name);
    data->file_name = strdup(file_name);

    printf("Enter number of search strings: ");
    scanf("%d", &data->num_search_strings);

    for (int i = 0; i < data->num_search_strings; i++) {
        char search_string[MAX_SEARCH_STRING_SIZE];
        printf("Enter search string %d: ", i + 1);
        scanf("%s", search_string);
        data->search_strings[i] = strdup(search_string);
    }
}

int search_file(FileSearchData *data) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int line_num = 0;

    file = fopen(data->file_name, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", data->file_name);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_num++;
        char *token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            for (int i = 0; i < data->num_search_strings; i++) {
                if (strstr(token, data->search_strings[i])!= NULL) {
                    printf("Search string '%s' found in line %d.\n", data->search_strings[i], line_num);
                }
            }
            token = strtok(NULL, " \t\r\n");
        }
    }

    fclose(file);
    return 0;
}

int main() {
    FileSearchData data;
    load_file_search_data(&data);
    search_file(&data);

    for (int i = 0; i < data.num_search_strings; i++) {
        free(data.search_strings[i]);
    }
    free(data.file_name);
    return 0;
}