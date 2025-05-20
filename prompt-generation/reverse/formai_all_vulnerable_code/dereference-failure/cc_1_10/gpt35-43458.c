//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: medieval
/* Medieval Antivirus Scanner */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char virus_one[] = "plague"; // first virus name
    char virus_two[] = "black death"; // second virus name
    char virus_three[] = "smallpox"; // third virus name
    char *filename = "suspicious_file.exe"; // the name of the suspicious file
    char *file_content; // the content of the suspicious file
    int file_size; // the size of the suspicious file

    // Read the suspicious file
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("File cannot be opened.");
        exit(0);
    }

    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file content
    file_content = (char *) malloc (file_size);

    // Read the file content
    fread(file_content, sizeof(char), file_size, fp);

    // Close the file
    fclose(fp);

    // Scan for viruses
    int virus_found = 0;
    if(strstr(file_content, virus_one)) {
        virus_found = 1;
    }
    if(strstr(file_content, virus_two)) {
        virus_found = 1;
    }
    if(strstr(file_content, virus_three)) {
        virus_found = 1;
    }

    // Remove the file content from memory
    free(file_content);

    // Display the result
    if(virus_found) {
        printf("Warning: Virus detected in the file!");
    } else {
        printf("The file is clean.");
    }

    return 0;
}