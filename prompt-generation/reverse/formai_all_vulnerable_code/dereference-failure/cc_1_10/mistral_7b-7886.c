//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100
#define MAX_LINE_LEN 256
#define MAX_ELEMENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int value;
} Element;

typedef struct {
    int num_elements;
    Element elements[MAX_ELEMENTS];
} DataStruct;

bool is_valid_name(const char* name) {
    int len = strlen(name);
    bool valid = true;

    if (len < 1 || len > MAX_NAME_LEN) {
        valid = false;
    } else {
        int i;
        for (i = 0; i < len; ++i) {
            if (!isalnum(name[i]) && name[i] != '_') {
                valid = false;
                break;
            }
        }
    }

    return valid;
}

void extract_data_struct(const char* metadata) {
    int pos = 0;
    int num_elements = 0;
    char name[MAX_NAME_LEN];
    int value;
    DataStruct ds;

    while (pos < strlen(metadata)) {
        int name_start = pos;
        while (pos < strlen(metadata) && isalnum(metadata[pos]) || metadata[pos] == '_') {
            pos++;
        }
        if (pos > name_start) {
            int name_len = pos - name_start;
            if (is_valid_name(&metadata[name_start])) {
                strncpy(name, &metadata[name_start], name_len);
                name[name_len] = '\0';

                if (sscanf(&metadata[pos], "%d", &value) == 1) {
                    if (num_elements < MAX_ELEMENTS) {
                        ds.elements[num_elements].value = value;
                        strcpy(ds.elements[num_elements].name, name);
                        num_elements++;
                    } else {
                        printf("Error: too many elements in data struct\n");
                        break;
                    }
                } else {
                    printf("Error: invalid value for %s\n", name);
                    break;
                }

                pos += strlen(&metadata[pos]);
            } else {
                printf("Error: invalid name %.*s\n", (int)(pos - name_start), &metadata[name_start]);
                break;
            }
        }
    }

    if (num_elements > 0) {
        printf("Extracted data struct:\n");
        for (int i = 0; i < num_elements; ++i) {
            printf("%s: %d\n", ds.elements[i].name, ds.elements[i].value);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata>\n", argv[0]);
        return 1;
    }

    const char* metadata = argv[1];
    extract_data_struct(metadata);

    return 0;
}