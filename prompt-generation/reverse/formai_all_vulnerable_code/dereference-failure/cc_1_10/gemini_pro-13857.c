//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    off_t size;
} FileInfo;

int compare_files(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

int main() {
    // Initiate the spacecraft's systems
    DIR *dir = opendir("/");
    if (dir == NULL) {
        perror("Unable to open the root directory");
        return EXIT_FAILURE;
    }

    // Gather data from the celestial bodies (files)
    int num_files = 0;
    FileInfo *files = NULL;
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            char *path = malloc(strlen(ent->d_name) + 2);
            strcpy(path, "/");
            strcat(path, ent->d_name);

            struct stat st;
            if (stat(path, &st) == 0) {
                files = realloc(files, (num_files + 1) * sizeof(FileInfo));
                files[num_files].name = malloc(strlen(path) + 1);
                strcpy(files[num_files].name, path);
                files[num_files].size = st.st_size;
                num_files++;
            }
        }
    }
    closedir(dir);

    // Sort the celestial bodies by their mass (size)
    qsort(files, num_files, sizeof(FileInfo), compare_files);

    // Print the results of the cosmic expedition
    printf("**Cosmic Disk Space Analyzer Report**\n\n");
    printf("Number of files detected: %d\n", num_files);
    printf("\n**Top 10 Colossal Celestial Bodies (Files) by Mass (Size):**\n");
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%-60s %12.2f GB\n", files[i].name, files[i].size / (1024.0 * 1024.0 * 1024.0));
    }

    // Terminate the program's execution
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);
    return EXIT_SUCCESS;
}