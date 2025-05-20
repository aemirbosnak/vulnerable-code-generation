//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// surreal file system simulation
// where files are made of soup and folders are made of clouds

struct SoupyFile { // struct to represent a soup file
    char *filename; // file name
    int size; // size of the soup file
    char *content; // content of the soup file
};

struct CloudyFolder { // struct to represent a folder
    char *foldername; // folder name
    int num_files; // number of soup files in folder
    struct SoupyFile *soup_files; // array of soup files
};

struct SkyDrive { // struct to represent the entire sky drive
    int num_folders; // number of folders in sky drive
    struct CloudyFolder *cloud_folders; // array of clouds (folders) on sky drive
};

void print_folder(struct CloudyFolder folder) { // function to print folder details
    printf("Folder - %s\n", folder.foldername);
    printf("Number of soup files - %d\n", folder.num_files);
    for (int i=0; i<folder.num_files; i++) {
        printf("Soupy file name - %s\n", folder.soup_files[i].filename);
        printf("Soupy file size - %d\n", folder.soup_files[i].size);
        printf("Soupy file content - %s\n", folder.soup_files[i].content);
    }
}

int main() {
    // creating a sky drive
    struct SkyDrive sky_drive;
    sky_drive.num_folders = 2; // total number of folders in sky drive
    
    // creating first folder
    struct CloudyFolder first_folder;
    first_folder.foldername = "FluffyClouds";
    first_folder.num_files = 2;
    first_folder.soup_files = malloc(first_folder.num_files * sizeof(struct SoupyFile));
    
    // creating first soup file
    struct SoupyFile first_file;
    first_file.filename = "Soup1";
    first_file.size = 10;
    first_file.content = "chicken soup";
    first_folder.soup_files[0] = first_file;
    
    // creating second soup file
    struct SoupyFile second_file;
    second_file.filename = "Soup2";
    second_file.size = 8;
    second_file.content = "vegetable soup";
    first_folder.soup_files[1] = second_file;

    // creating second folder
    struct CloudyFolder second_folder;
    second_folder.foldername = "DarkClouds";
    second_folder.num_files = 1;
    second_folder.soup_files = malloc(second_folder.num_files * sizeof(struct SoupyFile));

    // creating third soup file
    struct SoupyFile third_file;
    third_file.filename = "Soup3";
    third_file.size = 12;
    third_file.content = "mushroom soup";
    second_folder.soup_files[0] = third_file;

    // adding folders to sky drive
    sky_drive.cloud_folders = malloc(sky_drive.num_folders * sizeof(struct CloudyFolder));
    sky_drive.cloud_folders[0] = first_folder;
    sky_drive.cloud_folders[1] = second_folder;

    // printing details of sky drive
    printf("Sky Drive details - \n");
    for (int i=0; i<sky_drive.num_folders; i++) {
        print_folder(sky_drive.cloud_folders[i]);
    }
    return 0;
}