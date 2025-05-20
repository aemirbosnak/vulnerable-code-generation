//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extract_metadata(char* str, int len) {
    char* metadata = malloc(sizeof(char) * len);
    int j = 0;
    for (int i = 0; i < len; i++) {
        char c = *(str+i);
        if (c == '/') {
            j = 0;
            continue;
        }
        if (c == '.') {
            metadata[j] = '\0';
            break;
        }
        metadata[j] = c;
        j++;
    }
    return metadata;
}

void paranoid_mode() {
    printf("WARNING: You are now in paranoid mode.\n");
    printf("This mode will scan all files in the directory and extract their metadata.\n");
    printf("Press 'Y' to continue, or any other key to exit.\n");

    char c = getchar();
    if (c != 'Y' && c != 'y') {
        printf("Exiting.\n");
        return;
    }

    system("ls -p | grep -v / > filenames.txt");

    FILE* file = fopen("filenames.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        char* metadata = extract_metadata(line, len);
        printf("Metadata for file '%s': %s\n", line, metadata);
        free(metadata);
    }

    fclose(file);
    system("rm -f filenames.txt");
}

int main() {
    paranoid_mode();
    return 0;
}