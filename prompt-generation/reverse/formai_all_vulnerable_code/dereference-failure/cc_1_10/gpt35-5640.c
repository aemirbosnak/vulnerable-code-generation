//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void sync_files(const char* path1, const char* path2) {
    DIR* dir1 = opendir(path1); //open directory 1
    DIR* dir2 = opendir(path2); //open directory 2
    
    if (dir1 == NULL || dir2 == NULL) { //check if either directory does not exist
        printf("Error: Could not open directory.\n");
        return;
    }
    
    struct dirent* entry1;
    struct dirent* entry2;
    char filepath1[1000];
    char filepath2[1000];
    
    while ((entry1 = readdir(dir1)) != NULL) { //iterate through directory 1
        if (entry1->d_name[0] == '.') { //ignore hidden files
            continue;
        }
        sprintf(filepath1, "%s/%s", path1, entry1->d_name); //create full filepath for file in dir1
        sprintf(filepath2, "%s/%s", path2, entry1->d_name); //create full filepath for file in dir2
        FILE* file1 = fopen(filepath1, "rb"); //open file in dir1
        FILE* file2 = fopen(filepath2, "rb"); //open file in dir2
        
        if (file1 == NULL) { //file does not exist in dir1
            printf("File %s does not exist in %s. Copying...\n", entry1->d_name, path1);
            FILE* new_file = fopen(filepath1, "wb"); //create new file in dir1
            fclose(new_file);
        }
        else if (file2 == NULL) { //file does not exist in dir2
            printf("File %s does not exist in %s. Copying...\n", entry1->d_name, path2);
            FILE* new_file = fopen(filepath2, "wb"); //create new file in dir2
            fclose(new_file);
        }
        else { //file exists in both directories
            fseek(file1, 0, SEEK_END);
            int size1 = ftell(file1);
            fseek(file1, 0, SEEK_SET);
        
            fseek(file2, 0, SEEK_END);
            int size2 = ftell(file2);
            fseek(file2, 0, SEEK_SET);
        
            if (size1 != size2) { //files are different sizes
                printf("Files %s are different sizes. Updating...\n", entry1->d_name);
                fclose(file1);
                fclose(file2);
                file1 = fopen(filepath1, "rb");
                file2 = fopen(filepath2, "wb");
                char buffer[1024];
                int nbytes;
                while ((nbytes = fread(buffer, 1, sizeof(buffer), file1)) > 0) {
                    fwrite(buffer, 1, nbytes, file2);
                }
            }
            else { //files are the same size
                char buffer1[1024];
                char buffer2[1024];
                int nbytes1;
                int nbytes2;
                int same = 1;
                while ((nbytes1 = fread(buffer1, 1, sizeof(buffer1), file1)) > 0) {
                    nbytes2 = fread(buffer2, 1, sizeof(buffer2), file2);
                    if (nbytes1 != nbytes2 || memcmp(buffer1, buffer2, nbytes1) != 0) { //if file contents are different
                        same = 0;
                        break;
                    }
                }
                if (same) { //files are the same
                    printf("Files %s are up to date.\n", entry1->d_name);
                }
                else { //files are different
                    printf("Files %s are different. Updating...\n", entry1->d_name);
                    fclose(file1);
                    fclose(file2);
                    file1 = fopen(filepath1, "rb");
                    file2 = fopen(filepath2, "wb");
                    char buffer[1024];
                    while ((nbytes1 = fread(buffer, 1, sizeof(buffer), file1)) > 0) {
                        fwrite(buffer, 1, nbytes1, file2);
                    }
                }
            }
        }
        fclose(file1);
        fclose(file2);
    }
    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char** argv) {
    if (argc != 3) { //check number of arguments
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        return 0;
    }
    
    sync_files(argv[1], argv[2]); //synchronize files
    
    return 0;
}