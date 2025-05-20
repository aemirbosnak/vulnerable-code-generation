//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// A noble structure to represent the files of the kingdom
typedef struct File {
    char name[BUFFER_SIZE];
    long size;
} File;

// A function to gather files from a given directory
void gather_files(const char *dir_path, File **files, int *file_count) {
    struct dirent *entry;
    struct stat filestats;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        fprintf(stderr, "Hark! The directory %s could not be found!\n", dir_path);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            (*file_count)++;
            *files = (File *) realloc(*files, sizeof(File) * (*file_count));
            snprintf((*files)[*file_count - 1].name, BUFFER_SIZE, "%s/%s", dir_path, entry->d_name);
            stat((*files)[*file_count - 1].name, &filestats);
            (*files)[*file_count - 1].size = filestats.st_size;
        }
    }
    closedir(dp);
}

// A function to purge files before the grand synchronization
void purge_files(const char *dest_path, File *files, int file_count) {
    for (int i = 0; i < file_count; i++) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, BUFFER_SIZE, "%s/%s", dest_path, files[i].name);
        if (remove(filepath) == 0) {
            printf("The file %s has been gallantly removed!\n", files[i].name);
        } else {
            perror("Alas! The purge could not be fulfilled!");
        }
    }
}

// A function to copy files into the destination
void copy_files(File *files, int file_count, const char *dest_path) {
    for (int i = 0; i < file_count; i++) {
        char dest_path_full[BUFFER_SIZE];
        snprintf(dest_path_full, BUFFER_SIZE, "%s/%s", dest_path, files[i].name);

        FILE *src = fopen(files[i].name, "rb");
        FILE *dest = fopen(dest_path_full, "wb");

        if (src == NULL || dest == NULL) {
            fprintf(stderr, "By my troth! The file %s could not be found!\n", files[i].name);
            if (src) fclose(src);
            if (dest) fclose(dest);
            continue;
        }

        char buffer[BUFFER_SIZE];
        size_t bytes;

        while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
            fwrite(buffer, sizeof(char), bytes, dest);
        }

        printf("Aye! The file %s hath been sworn into %s!\n", files[i].name, dest_path);
        fclose(src);
        fclose(dest);
    }
}

// The heart of the synchronization
void synchronize_files(const char *src_path, const char *dest_path) {
    File *files = NULL;
    int file_count = 0;

    gather_files(src_path, &files, &file_count);
    purge_files(dest_path, files, file_count);
    copy_files(files, file_count, dest_path);

    free(files);
}

// The main function that doth run the synchronizer
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "O noble user! Thou must provide the source and destination paths!\n");
        return EXIT_FAILURE;
    }

    const char *src_path = argv[1];
    const char *dest_path = argv[2];

    printf("Commencing the Great File Synchronization of %s to %s...\n", src_path, dest_path);
    synchronize_files(src_path, dest_path);
    printf("The grand synchronization hath concluded! Rejoice!\n");

    return EXIT_SUCCESS;
}