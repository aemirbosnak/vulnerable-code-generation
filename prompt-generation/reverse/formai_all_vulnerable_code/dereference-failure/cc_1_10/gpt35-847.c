//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FIELD_LEN 1024 // define max field length

void parse_csv(char *row, char **fields, int num_fields) {
    char *ptr = strtok(row, ",");
    int i = 0;
    while (ptr != NULL && i < num_fields) {
        int len = strlen(ptr);
        if (len > MAX_FIELD_LEN) { // check if field length is greater than MAX_FIELD_LEN
            printf("Error: Field %d is too long!\n", i+1);
            exit(1);
        }
        fields[i] = malloc(len+1); // allocate memory for field
        strncpy(fields[i], ptr, len+1); // copy field into allocated memory
        ptr = strtok(NULL, ",");
        i++;
    }
    if (i != num_fields) { // check if correct number of fields were parsed
        printf("Error: Expected %d fields, but found %d fields!\n", num_fields, i);
        exit(1);
    }
    return;
}

int main() {
    char *filename = "data.csv";
    char *mode = "r";
    int num_fields = 3;
    FILE *fp = fopen(filename, mode); // open file for reading
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char *row = malloc(MAX_FIELD_LEN*num_fields); // allocate memory for row
    char **fields = malloc(num_fields*sizeof(char*)); // allocate memory for array of fields
    printf("Parsing CSV...\n");
    while (fgets(row, MAX_FIELD_LEN*num_fields, fp)) { // read in row
        parse_csv(row, fields, num_fields); // parse row
        printf("%s %s %s\n", fields[0], fields[1], fields[2]); // print fields
        for (int i = 0; i < num_fields; i++) {
            free(fields[i]); // free allocated memory for fields
        }
    }
    free(row); // free allocated memory for row
    free(fields); // free allocated memory for array of fields
    printf("Done!\n");
    fclose(fp); // close file
    return 0;
}