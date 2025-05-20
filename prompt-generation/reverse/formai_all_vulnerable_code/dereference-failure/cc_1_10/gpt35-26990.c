//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to extract metadata recursively */
void extract_metadata(const char *file_path)
{
    /* Open file for reading */
    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    /* Get file size */
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Allocate memory for contents of file */
    char *contents = (char *) malloc(size + 1);
    if (contents == NULL) {
        fclose(fp);
        printf("Error allocating memory\n");
        return;
    }

    /* Read file contents into memory */
    fread(contents, size, 1, fp);
    fclose(fp);

    /* Add null terminator to file contents */
    contents[size] = '\0';

    /* Extract metadata from file */
    char *pos = strstr(contents, "/* Metadata:");
    if (pos != NULL) {
        /* Get length of metadata section */
        char *end_pos = strstr(pos, "*/");
        int len = end_pos - pos + 2;

        /* Print metadata */
        printf("%.*s\n", len, pos);

        /* Extract metadata from included files */
        pos += len;
        while (pos != NULL) {
            /* Get path of included file */
            char *include_pos = strstr(pos, "#include");
            if (include_pos == NULL) {
                break;
            }
            include_pos += strlen("#include") + 1;
            char *end_quotes_pos = strchr(include_pos, '\"');
            if (end_quotes_pos == NULL) {
                break;
            }
            char *start_quotes_pos = end_quotes_pos - 1;
            while (*start_quotes_pos != '\"') {
                start_quotes_pos--;
            }
            char *include_file_path = (char *) malloc(end_quotes_pos - start_quotes_pos);

            /* Copy path of included file to new string */
            memcpy(include_file_path, start_quotes_pos, end_quotes_pos - start_quotes_pos);
            include_file_path[end_quotes_pos - start_quotes_pos] = '\0';

            /* Extract metadata recursively from included file */
            extract_metadata(include_file_path);
            pos = strstr(end_quotes_pos, "/* Metadata:");
        }
    }

    /* Free memory */
    free(contents);
}

int main()
{
    extract_metadata("test.c");
    return 0;
}