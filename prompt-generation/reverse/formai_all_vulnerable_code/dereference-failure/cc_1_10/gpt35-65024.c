//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILENAME_LEN 1024
#define MAX_METADATA_LEN 1024
#define MAX_KEY_LEN 128
#define MAX_VALUE_LEN 896

struct metadata_entry {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
};

struct metadata {
    int count;
    struct metadata_entry entries[MAX_METADATA_LEN];
};

void extract_metadata(const char *filename, struct metadata *metadata)
{
    // Open file and check if it exists
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: File '%s' not found.\n", filename);
        return;
    }

    // Get file size
    struct stat st;
    if (stat(filename, &st) == -1) {
        perror("ERROR");
        return;
    }
    int filesize = st.st_size;

    // Allocate memory for file buffer
    char *filebuf = malloc(filesize + 1);
    if (!filebuf) {
        perror("ERROR");
        return;
    }
    filebuf[filesize] = '\0';

    // Read file contents into buffer
    fread(filebuf, 1, filesize, fp);

    // Close file
    fclose(fp);

    // Extract metadata entries from buffer
    char *ptr = filebuf;
    while (*ptr == '\n') {
        ptr++;
    }
    while (ptr < filebuf + filesize && strncmp(ptr, "META:", 5) == 0) {
        ptr += 5; // skip "META:"
        char key[MAX_KEY_LEN] = {0};
        char value[MAX_VALUE_LEN] = {0};
        sscanf(ptr, "%127[^=]=%895[^;\n]", key, value);
        if (strlen(key) == 0 || strlen(value) == 0) {
            break;
        }
        struct metadata_entry *entry = &metadata->entries[metadata->count++];
        strncpy(entry->key, key, MAX_KEY_LEN);
        strncpy(entry->value, value, MAX_VALUE_LEN);

        // Advance pointer to next line
        while (*ptr && *ptr != '\n') {
            ptr++;
        }
        if (*ptr == '\n') {
            ptr++;
        }
    }

    // Free file buffer
    free(filebuf);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "ERROR: No filename provided.\n");
        return 1;
    }

    struct metadata metadata = {0};
    extract_metadata(argv[1], &metadata);

    // Print metadata entries
    for (int i = 0; i < metadata.count; i++) {
        printf("%s=%s\n", metadata.entries[i].key, metadata.entries[i].value);
    }

    return 0;
}