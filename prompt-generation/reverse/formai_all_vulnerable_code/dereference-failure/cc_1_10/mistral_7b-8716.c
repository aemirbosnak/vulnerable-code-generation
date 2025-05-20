//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#pragma pack(push, 1)
typedef struct {
    char name[32];
    int age;
    char gender;
} Person;

typedef struct {
    int magic_number;
    Person person;
} MyStruct;
#pragma pack(pop)

void extract_person_metadata(const char *buffer, size_t size) {
    MyStruct *my_struct = (MyStruct *)buffer;
    printf("Extracted Person Metadata:\n");
    printf("Name: %s\n", my_struct->person.name);
    printf("Age: %d\n", my_struct->person.age);
    printf("Gender: %c\n", my_struct->person.gender);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    extract_person_metadata(buffer, file_size);

    free(buffer);
    fclose(file);

    return 0;
}