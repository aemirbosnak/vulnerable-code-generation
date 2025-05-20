//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

int num_fields = 0;
char field_names[MAX_FIELDS][MAX_LINE_LEN];
int field_indexes[MAX_FIELDS];

// Function to tokenize a given string and store the tokens as an array
int tokenize(char* line, char* delimiter, char*** tokens) {
    int num_tokens = 0;
    char* token = strtok(line, delimiter);
    while (token != NULL) {
        (*tokens)[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, delimiter);
    }
    return num_tokens;
}

// Function to read the CSV file and obtain the field names and their positions
void read_csv_file(char* file_name) {
    FILE* fp = fopen(file_name, "r");
    if (fp != NULL) {
        char line[MAX_LINE_LEN];
        fgets(line, MAX_LINE_LEN, fp);
        char** tokens = (char**) malloc(sizeof(char*)*MAX_FIELDS);
        int num_tokens = tokenize(line, ",", &tokens);
        for (int i = 0; i < num_tokens; i++) {
            strcpy(field_names[i], tokens[i]);
            field_indexes[i] = i;
        }
        num_fields = num_tokens;
        free(tokens);
    }
    fclose(fp);
}

// Function to generate the counts for the different field values in the CSV file
void generate_field_counts(char* file_name, int field_index) {
    int counts[MAX_FIELDS] = {0};
    FILE* fp = fopen(file_name, "r");
    if (fp != NULL) {
        char line[MAX_LINE_LEN];
        fgets(line, MAX_LINE_LEN, fp); // Ignore header line
        while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
            char** tokens = (char**) malloc(sizeof(char*)*MAX_FIELDS);
            int num_tokens = tokenize(line, ",", &tokens);
            for (int i = 0; i < num_tokens; i++) {
                if (i == field_index) {
                    for (int j = 0; j < num_fields; j++) {
                        if (strcmp(tokens[i], field_names[j]) == 0) {
                            counts[j]++;
                            break;
                        }
                    }
                }
            }
            free(tokens);
        }
    }
    fclose(fp);
    printf("Counts for field %s:\n", field_names[field_index]);
    for (int i = 0; i < num_fields; i++) {
        printf("%s: %d\n", field_names[i], counts[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return -1;
    }
    read_csv_file(argv[1]);
    for (int i = 0; i < num_fields; i++) {
        generate_field_counts(argv[1], i);
        printf("\n");
    }
    return 0;
}