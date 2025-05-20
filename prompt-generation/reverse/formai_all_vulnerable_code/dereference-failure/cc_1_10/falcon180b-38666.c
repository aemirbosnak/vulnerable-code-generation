//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char *keywords[MAX_KEYWORDS];
    int num_keywords;
} MetadataExtractor;

MetadataExtractor *create_metadata_extractor(char **keywords, int num_keywords) {
    MetadataExtractor *extractor = malloc(sizeof(MetadataExtractor));
    extractor->num_keywords = num_keywords;
    for (int i = 0; i < num_keywords; i++) {
        extractor->keywords[i] = strdup(keywords[i]);
    }
    return extractor;
}

void destroy_metadata_extractor(MetadataExtractor *extractor) {
    for (int i = 0; i < extractor->num_keywords; i++) {
        free(extractor->keywords[i]);
    }
    free(extractor);
}

int extract_metadata(MetadataExtractor *extractor, char *line) {
    int num_keywords_found = 0;
    for (int i = 0; i < extractor->num_keywords; i++) {
        char *keyword = extractor->keywords[i];
        int keyword_length = strlen(keyword);
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int token_length = strlen(token);
            if (token_length == keyword_length && strcasecmp(token, keyword) == 0) {
                num_keywords_found++;
            }
            token = strtok(NULL, " ");
        }
    }
    return num_keywords_found;
}

int main() {
    char *keywords[] = {"Author", "Title", "Date"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    MetadataExtractor *extractor = create_metadata_extractor(keywords, num_keywords);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int num_keywords_found = extract_metadata(extractor, line);
        if (num_keywords_found > 0) {
            printf("Found metadata: ");
            for (int i = 0; i < num_keywords; i++) {
                if (extractor->keywords[i]!= NULL) {
                    printf("%s ", extractor->keywords[i]);
                }
            }
            printf("\n");
        }
    }

    destroy_metadata_extractor(extractor);
    return 0;
}