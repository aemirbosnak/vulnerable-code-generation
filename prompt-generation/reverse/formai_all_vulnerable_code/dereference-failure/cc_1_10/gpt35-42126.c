//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of metadata string */
#define MAX_METADATA_LENGTH 100

/* Define the maximum number of metadata keys */
#define MAX_METADATA_KEYS 10

/* Define a structure to hold metadata keys and values */
struct Metadata {
    char keys[MAX_METADATA_KEYS][MAX_METADATA_LENGTH];
    char values[MAX_METADATA_KEYS][MAX_METADATA_LENGTH];
};

/**
 * Function to extract metadata from a given string
 * Takes in a metadata string and a pointer to a Metadata structure
 */
void extract_metadata(char* metadata_string, struct Metadata* metadata) {
    /* Define a token to be used while parsing the metadata */
    char* token;

    /* Loop through the metadata keys and values */
    for(int i=0; i<MAX_METADATA_KEYS; i++) {
        /* Extract the key and value */
        token = strtok(metadata_string, "=");
        if(token == NULL) break;
        strcpy(metadata->keys[i], token);

        token = strtok(NULL, ";");
        if(token == NULL) break;
        strcpy(metadata->values[i], token);

        /* Move to next metadata key-value pair */
        metadata_string = NULL;
    }
}

int main() {
    /* Define a sample metadata string */
    char* metadata_string = "title=Metallica - Enter Sandman; artist=Metallica; year=1991; album=The Black Album; genre=Heavy Metal;";

    /* Define a Metadata structure */
    struct Metadata metadata;

    /* Extract metadata from the sample metadata string */
    extract_metadata(metadata_string, &metadata);

    /* Print the extracted metadata keys and values */
    for(int i=0; i<MAX_METADATA_KEYS; i++) {
        if(strlen(metadata.keys[i]) > 0) {
            printf("%s : %s\n", metadata.keys[i], metadata.values[i]);
        } else {
            break;
        }
    }

    return 0;
}