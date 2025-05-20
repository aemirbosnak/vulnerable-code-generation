//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define TICKLE_DELAY 100000    // Delay between checks (in microseconds)

void tickle_file(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file) {
        fprintf(file, "\n# I love to be synchronized!\n");
        fclose(file);
        printf("Tickled %s! 🐥\n", filename);
    } else {
        printf("Failed to tickle %s. 😢\n", filename);
    }
}

void synchronize_files(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (!dir) {
        printf("Oops! I can't find the source directory! 🔍\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char src_path[BUFFER_SIZE];
            char dest_path[BUFFER_SIZE];
            snprintf(src_path, BUFFER_SIZE, "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, BUFFER_SIZE, "%s/%s", dest_dir, entry->d_name);

            FILE *src_file = fopen(src_path, "r");
            FILE *dest_file = fopen(dest_path, "r");

            if (src_file) {
                if (!dest_file) {
                    printf("File %s doesn't exist in destination. Copying it over! ✈️\n", entry->d_name);
                    FILE *new_dest_file = fopen(dest_path, "w");
                    fseek(src_file, 0, SEEK_END);
                    long fsize = ftell(src_file);
                    rewind(src_file);
                    char *buffer = malloc(fsize + 1);
                    fread(buffer, 1, fsize, src_file);
                    buffer[fsize] = 0; // Null-terminate the string
                    fwrite(buffer, 1, fsize, new_dest_file);
                    fclose(new_dest_file);
                    free(buffer);
                } else {
                    fclose(dest_file);
                    printf("File %s exists, checking for changes... 🧐\n", entry->d_name);
                    // Just tickling for now!
                    tickle_file(dest_path);
                }
                fclose(src_file);
            } else {
                printf("Can't open source file %s. Is it hiding? 👻\n", src_path);
            }
        }
    }
    closedir(dir);
}

void welcome_message() {
    printf("Welcome to the Silly Synchronizer! 🤪\n");
    printf("This tool will tickle your files in sync. Ready? Let's go!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    welcome_message();

    while (1) {
        printf("Looking for file updates... 🤔\n");
        synchronize_files(argv[1], argv[2]);
        usleep(TICKLE_DELAY); // Take a nap (wait) before checking again
    }

    return EXIT_SUCCESS;
}