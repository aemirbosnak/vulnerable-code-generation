//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void extract_metadata(FILE *file, char *filename) {
    char buffer[1024];
    char *line;
    int line_num = 0;
    int i;
    char *token;
    int num_tokens = 0;
    int token_len;

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        line_num++;
        line = strtok(buffer, "\n");
        while (line!= NULL) {
            num_tokens = 0;
            token_len = strlen(line);
            for (i = 0; i < token_len; i++) {
                if (isalnum(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '-') {
                    token = (char *) malloc(sizeof(char) * (i + 1));
                    strncpy(token, line + i, i);
                    token[i] = '\0';
                    printf("%s\n", token);
                    num_tokens++;
                }
            }
            line = strtok(NULL, "\n");
        }
    }

    printf("Total tokens: %d\n", num_tokens);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    extract_metadata(file, filename);

    fclose(file);
    return 0;
}