//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Romeo and Juliet's file locations
#define ROMEO_FILE "romeo.txt"
#define JULIET_FILE "juliet.txt"

int main() {
    // Open Romeo's file for reading
    FILE *romeo_file = fopen(ROMEO_FILE, "r");
    if (romeo_file == NULL) {
        printf("Oh happy dagger! Cannot open Romeo's file!\n");
        exit(1);
    }

    // Open Juliet's file for reading
    FILE *juliet_file = fopen(JULIET_FILE, "r");
    if (juliet_file == NULL) {
        printf("O Romeo, Romeo! Cannot open Juliet's file!\n");
        exit(1);
    }

    // Find the size of Romeo's file
    fseek(romeo_file, 0L, SEEK_END);
    long romeo_file_size = ftell(romeo_file);
    rewind(romeo_file);

    // Find the size of Juliet's file
    fseek(juliet_file, 0L, SEEK_END);
    long juliet_file_size = ftell(juliet_file);
    rewind(juliet_file);

    // Compare the sizes of the files
    if (romeo_file_size != juliet_file_size) {
        printf("It seems she hangs upon the cheek of night like a rich jewel in an Ethiope's ear, but their files are not of equal size!\n");
        exit(1);
    }

    // Read the contents of Romeo's file
    char romeo_file_contents[romeo_file_size];
    fread(romeo_file_contents, sizeof(char), romeo_file_size, romeo_file);

    // Read the contents of Juliet's file
    char juliet_file_contents[juliet_file_size];
    fread(juliet_file_contents, sizeof(char), juliet_file_size, juliet_file);

    // Compare the contents of the files
    if (strcmp(romeo_file_contents, juliet_file_contents) != 0) {
        printf("Ay me, what fray was here? Their files are different!\n");
        exit(1);
    }

    // If everything matches, rejoice!
    printf("O happy dagger, this is thy sheath; there rust, and let me die. The files match!\n");

    // Close the files
    fclose(romeo_file);
    fclose(juliet_file);

    return 0;
}