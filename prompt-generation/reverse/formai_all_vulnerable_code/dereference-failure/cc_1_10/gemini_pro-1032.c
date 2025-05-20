//GEMINI-pro DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new file
void create_file() {
    FILE *fp;
    char filename[100];

    printf("Enter the filename to create: ");
    scanf("%s", filename);

    // Open the file in write mode
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }

    // Write some data to the file
    fprintf(fp, "This is a new file created by C program.\n");

    // Close the file
    fclose(fp);

    printf("File created successfully.\n");
}

// Function to open an existing file
void open_file() {
    FILE *fp;
    char filename[100];
    char ch;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the contents of the file
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    fclose(fp);

    printf("File opened successfully.\n");
}

// Function to append data to an existing file
void append_file() {
    FILE *fp;
    char filename[100];
    char data[100];

    printf("Enter the filename to append: ");
    scanf("%s", filename);

    // Open the file in append mode
    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Get the data to append
    printf("Enter the data to append: ");
    scanf(" %[^\n]", data);

    // Append the data to the file
    fprintf(fp, "%s\n", data);

    // Close the file
    fclose(fp);

    printf("Data appended successfully.\n");
}

// Function to read data from a file and store it in a buffer
void read_file_to_buffer() {
    FILE *fp;
    char filename[100];
    char buffer[1000];

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the contents of the file into the buffer
    fread(buffer, sizeof(char), 1000, fp);

    // Close the file
    fclose(fp);

    // Print the contents of the buffer
    printf("Contents of the file:\n%s\n", buffer);
}

// Function to copy the contents of one file to another
void copy_file() {
    FILE *fp1, *fp2;
    char filename1[100], filename2[100];
    char ch;

    printf("Enter the name of the source file: ");
    scanf("%s", filename1);

    printf("Enter the name of the destination file: ");
    scanf("%s", filename2);

    // Open the source file in read mode
    fp1 = fopen(filename1, "r");

    if (fp1 == NULL) {
        printf("Error opening source file.\n");
        return;
    }

    // Open the destination file in write mode
    fp2 = fopen(filename2, "w");

    if (fp2 == NULL) {
        printf("Error opening destination file.\n");
        return;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    printf("File copied successfully.\n");
}

// Function to rename a file
void rename_file() {
    char oldname[100], newname[100];

    printf("Enter the old name of the file: ");
    scanf("%s", oldname);

    printf("Enter the new name of the file: ");
    scanf("%s", newname);

    // Rename the file
    if (rename(oldname, newname) == 0) {
        printf("File renamed successfully.\n");
    } else {
        printf("Error renaming file.\n");
    }
}

// Function to delete a file
void delete_file() {
    char filename[100];

    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);

    // Delete the file
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}

// Main function
int main() {
    int choice;

    // Display the menu
    printf("Choose an operation:\n");
    printf("1. Create a new file\n");
    printf("2. Open an existing file\n");
    printf("3. Append data to an existing file\n");
    printf("4. Read data from a file and store it in a buffer\n");
    printf("5. Copy the contents of one file to another\n");
    printf("6. Rename a file\n");
    printf("7. Delete a file\n");
    printf("8. Quit\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Perform the selected operation
    switch (choice) {
        case 1:
            create_file();
            break;
        case 2:
            open_file();
            break;
        case 3:
            append_file();
            break;
        case 4:
            read_file_to_buffer();
            break;
        case 5:
            copy_file();
            break;
        case 6:
            rename_file();
            break;
        case 7:
            delete_file();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}