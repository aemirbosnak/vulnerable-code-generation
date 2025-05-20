//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONFIG_PARAMS 10
#define MAX_METADATA_FIELDS 20

// Configurable parameters struct
struct ConfigParams {
    char filename[50];
    char metadata_delim[5];
    char metadata_fields[MAX_METADATA_FIELDS][50];
    int num_metadata_fields;
};

// Function to read and parse config file
struct ConfigParams read_config(char* config_file) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *param_name, *param_value;

    struct ConfigParams config_params = { "", "", {0}, 0 };

    fp = fopen(config_file, "r");
    if (fp == NULL) {
        printf("Error reading config file\n");
        exit(EXIT_FAILURE);
    }

    // Read and parse each line of config file
    while ((read = getline(&line, &len, fp)) != -1) {
        // Split line at '=' to get parameter name and value
        param_name = strtok(line, "=");
        param_value = strtok(NULL, "=");

        // Strip newline character from end of parameter value
        param_value[strcspn(param_value, "\n")] = 0;

        // Fill in ConfigParams struct based on parameter name
        if (strcmp(param_name, "filename") == 0) {
            strcpy(config_params.filename, param_value);
        }
        else if (strcmp(param_name, "metadata_delim") == 0) {
            strcpy(config_params.metadata_delim, param_value);
        }
        else if (strcmp(param_name, "metadata_fields") == 0) {
            char *field = strtok(param_value, ",");
            int i = 0;
            while (field != NULL && i < MAX_METADATA_FIELDS) {
                strcpy(config_params.metadata_fields[i], field);
                i++;
                field = strtok(NULL, ",");
            }
            config_params.num_metadata_fields = i;
        }
    }

    fclose(fp);
    if (line) free(line);

    return config_params;
}

// Function to extract metadata from file based on config
void extract_metadata(struct ConfigParams config_params) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *id, *metadata_field;

    fp = fopen(config_params.filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // Print header row for metadata fields
    for (int i = 0; i < config_params.num_metadata_fields; i++) {
        printf("%s\t", config_params.metadata_fields[i]);
    }
    printf("\n");

    // Parse file and extract metadata for each line
    while ((read = getline(&line, &len, fp)) != -1) {
        // Split line at metadata delimiter
        id = strtok(line, config_params.metadata_delim);
        metadata_field = strtok(NULL, config_params.metadata_delim);

        // Print metadata for each field
        printf("%s\t", id);
        for (int i = 0; i < config_params.num_metadata_fields-1; i++) {
            printf("%s", metadata_field);
            metadata_field = strtok(NULL, config_params.metadata_delim);
            printf("\t");
        }
        printf("%s\n", metadata_field);
    }

    fclose(fp);
    if (line) free(line);
}

int main() {
    // Read config file
    struct ConfigParams config_params = read_config("config.txt");

    // Extract metadata from file
    extract_metadata(config_params);

    return 0;
}