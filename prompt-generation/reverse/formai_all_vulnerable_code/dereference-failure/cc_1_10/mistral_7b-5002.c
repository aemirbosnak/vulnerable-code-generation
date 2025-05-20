//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a funny name for the backup file
char* generateFunnyName(char* origFileName) {
    char* funnyName = (char*) malloc(strlen(origFileName) + 20); // allocate memory for the new name

    // Add funny suffixes to the original file name
    strcat(funnyName, origFileName);
    strcat(funnyName, "_Oh_Blast!");
    strcat(funnyName, "_Backup_of_the_Day!");
    strcat(funnyName, "_Save_me_Bacon!");

    return funnyName;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // check if the correct number of arguments is provided
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char* origFileName = argv[1]; // save the original file name
    char* funnyName = generateFunnyName(origFileName); // generate a funny name for the backup file

    FILE* origFile = fopen(origFileName, "r"); // open the original file for reading

    if (origFile == NULL) { // check if the file exists and can be opened
        printf("Error: Unable to open %s\n", origFileName);
        free(funnyName); // free the memory allocated for the funny name
        return 1;
    }

    FILE* backupFile = fopen(funnyName, "w"); // open or create the backup file for writing

    if (backupFile == NULL) { // check if the backup file can be opened or created
        printf("Error: Unable to create %s\n", funnyName);
        fclose(origFile); // close the original file
        free(funnyName); // free the memory allocated for the funny name
        return 1;
    }

    clock_t startTime = clock(); // record the start time for the backup process

    size_t bytesRead; // variable to store the number of bytes read from the original file
    char buffer[1024]; // buffer to read data from the original file

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), origFile)) > 0) { // read data from the original file and write it to the backup file
        fwrite(buffer, bytesRead, 1, backupFile);
    }

    clock_t endTime = clock(); // record the end time for the backup process
    double backupTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // calculate the backup time in seconds

    printf("Backup of %s completed in %.2f seconds!\n", origFileName, backupTime); // print a message indicating the backup is complete

    fclose(origFile); // close the original file
    fclose(backupFile); // close the backup file
    free(funnyName); // free the memory allocated for the funny name

    return 0;
}