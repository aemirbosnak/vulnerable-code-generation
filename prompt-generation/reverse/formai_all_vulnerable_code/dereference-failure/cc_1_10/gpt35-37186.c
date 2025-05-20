//FormAI DATASET v1.0 Category: Data recovery tool ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512

typedef struct {
    char name[50];
    char extension[5];
    char modified_date[20];
    int block_start;
    int num_blocks;
} File;

void recover_data(char* disk_image_path, char* output_dir_path){
    FILE* disk_image = fopen(disk_image_path, "rb");
    if(disk_image == NULL){
        printf("ERROR: Could not open disk image.\n");
        return;
    }

    unsigned char* buffer = malloc(sizeof(unsigned char) * BLOCK_SIZE);
    int current_block = 0;
    int num_files = 0;
    int files_allocated = 10;
    File* files = malloc(sizeof(File) * files_allocated);

    while(fread(buffer, BLOCK_SIZE, 1, disk_image) == 1){
        // Check for file signature
        if(buffer[0] == 0x45 && buffer[1] == 0x4e && buffer[2] == 0x44){
            // Found start of file
            if(num_files == files_allocated){
                files_allocated = files_allocated * 2;
                files = realloc(files, sizeof(File) * files_allocated);
            }
            File f;
            // Parse file name
            memcpy(f.name, buffer + 3, 50);
            f.name[strcspn(f.name, "\n")] = 0;
            // Parse file extension
            memcpy(f.extension, buffer + 53, 5);
            f.extension[strcspn(f.extension, "\n")] = 0;
            // Parse modified date
            memcpy(f.modified_date, buffer + 58, 20);
            f.modified_date[strcspn(f.modified_date, "\n")] = 0;
            // Set file start and number of blocks
            f.block_start = current_block + 1;
            f.num_blocks = 0;
            num_files++;
            // Write file to output directory
            char file_path[200];
            sprintf(file_path, "%s/%s.%s", output_dir_path, f.name, f.extension);
            FILE* file = fopen(file_path, "wb");
            if(file == NULL){
                printf("WARNING: Could not create file %s.%s in %s directory.\n", f.name, f.extension, output_dir_path);
            } else {
                fwrite(buffer + 78, BLOCK_SIZE - 78, 1, file); // Write first block of file
                f.num_blocks++;
                while(fread(buffer, BLOCK_SIZE, 1, disk_image) == 1){
                    if(buffer[0] == 0x45 && buffer[1] == 0x4e && buffer[2] == 0x44){
                        // Found start of next file, exit loop
                        break;
                    } else {
                        fwrite(buffer, BLOCK_SIZE, 1, file);
                        f.num_blocks++;
                    }
                }
                fclose(file);
                files[num_files - 1] = f;
            }
        }
        current_block++;
    }
    free(buffer);
    fclose(disk_image);

    // Print recovered files information
    for(int i = 0; i < num_files; i++){
        File f = files[i];
        printf("Recovered file #%d:\n", i+1);
        printf("Name: %s.%s\n", f.name, f.extension);
        printf("Modified date: %s\n", f.modified_date);
        printf("Start block: %d\n", f.block_start);
        printf("Number of blocks: %d\n", f.num_blocks);
        printf("\n");
    }
    free(files);
}

int main(int argc, char** argv){
    if(argc != 3){
        printf("USAGE: data_recovery_tool <disk_image_path> <output_dir_path>\n");
    } else {
        recover_data(argv[1], argv[2]);
    }
    return 0;
}