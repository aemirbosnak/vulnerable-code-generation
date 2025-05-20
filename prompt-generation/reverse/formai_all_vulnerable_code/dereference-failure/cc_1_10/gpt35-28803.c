//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata_tag {
    char *key;
    char *value;
} metadata;

int main(int argc, char *argv[]) {
    char filename[100], metadata_filename[100];
    char c;
    int i = 0, j = 0, k = 0;
    FILE *fp, *metadata_fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    printf("Enter metadata filename: ");
    scanf("%s", metadata_filename);

    metadata_fp = fopen(metadata_filename, "w");
    if (metadata_fp == NULL) {
        printf("Error: Metadata file creation failed.\n");
        return 1;
    }

    metadata *md = (metadata *)malloc(sizeof(metadata) * 100);
    int count = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '{') {
            i = 0;
            char key[100], value[100];
            while ((c = fgetc(fp)) != '}') {
                if (c == ':') {
                    j = 0;
                    continue;
                }
                if (c == ',') {
                    k = 0;
                    md[count].key = strdup(key);
                    md[count].value = strdup(value);
                    count++;
                    memset(key, 0, 100);
                    memset(value, 0, 100);
                    continue;
                }
                if (j == 0) key[i++] = c;
                else value[k++] = c;
            }
            md[count].key = strdup(key);
            md[count].value = strdup(value);
            count++;
            memset(key, 0, 100);
            memset(value, 0, 100);
        }
    }

    printf("Extracted metadata:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", md[i].key, md[i].value);
        fprintf(metadata_fp, "%s: %s\n", md[i].key, md[i].value);
    }

    fclose(fp);
    fclose(metadata_fp);

    return 0;
}