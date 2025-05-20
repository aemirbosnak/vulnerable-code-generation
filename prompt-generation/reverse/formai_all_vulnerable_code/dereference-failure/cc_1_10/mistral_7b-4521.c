//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char name[64];
    int age;
    char gender;
} Person;

typedef struct {
    char magic_word[4];
    int metadata_size;
    Person person;
} MyMetadata;

void extract_metadata(const char *buffer, size_t size) {
    MyMetadata *metadata;

    if (size < sizeof(MyMetadata)) {
        fprintf(stderr, "Invalid buffer size\n");
        return;
    }

    metadata = (MyMetadata *)buffer;

    if (strcmp(metadata->magic_word, "METADATA") != 0) {
        fprintf(stderr, "Invalid metadata\n");
        return;
    }

    printf("Name: %s\n", metadata->person.name);
    printf("Age: %d\n", metadata->person.age);
    printf("Gender: %c\n", metadata->person.gender);
}

int main(int argc, char *argv[]) {
    const char *buffer;
    size_t size;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <buffer>\n", argv[0]);
        return 1;
    }

    buffer = argv[1];
    size = strlen(buffer);

    extract_metadata(buffer, size);

    return 0;
}