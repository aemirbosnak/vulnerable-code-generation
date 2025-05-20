//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define GB (1024 * 1024 * 1024)
#define MB (1024 * 1024)
#define KB 1024

#define PATH_SIZE 1024

const char* unit[] = {"B", "KB", "MB", "GB", "TB"};

char prog_name[PATH_SIZE];
char cwd[PATH_SIZE];

/* get the file size and human readable size string */
long long get_file_size(const char* path, char* size_str) {

    struct stat sb;
    if (stat(path, &sb) == -1) {
        fprintf(stderr, "stat error on %s: ", path);
        perror("");
        exit(EXIT_FAILURE);
    }
    long long size = sb.st_size;

    int i = 0;
    while(size >= 1024 && i < 4) {
        size /= 1024;
        i++;
    }

    snprintf(size_str, 16, "%lld %s", size, unit[i]);
    return sb.st_size;
}

/* traverse the file system recursively and print directories and files sizes */
long long traverse_system(const char* path, int level) {

    /* construct the current path */
    char curr_path[PATH_SIZE];
    if (level == 1) {
        snprintf(curr_path, PATH_SIZE, "%s", path);
    }
    else {
        snprintf(curr_path, PATH_SIZE, "%s/%s", path, ".");
        for (int i = 1; i < level - 1; i++) {
            strncat(curr_path, "/.", PATH_SIZE - strlen(curr_path) - 1);
        }
    }

    struct dirent* entry;
    long long total_size = 0;

    /* open the directory and list contents */
    DIR* dir = opendir(curr_path);
    if (dir == NULL) {
        fprintf(stderr, "opendir error on %s: ", curr_path);
        perror("");
        exit(EXIT_FAILURE);
    }

    /* print directory size */
    char size_str[16];
    long long size;
    size = get_file_size(curr_path, size_str);

    total_size += size;
    printf("%lld %s %s\n", size, size_str, curr_path);

    /* iterate through each entry in the directory */
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char next_path[PATH_SIZE];
        snprintf(next_path, PATH_SIZE, "%s/%s", curr_path, entry->d_name);

        /* if entry is a directory, traverse it recursively */
        if (entry->d_type == DT_DIR) {
            total_size += traverse_system(next_path, level + 1);
        }
        /* if entry is a file, print its size */
        else if (entry->d_type == DT_REG) {
            size = get_file_size(next_path, size_str);
            total_size += size;
            for (int i = 0; i < level - 1; i++) {
                putchar('\t');
            }
            printf("%lld %s %s\n", size, size_str, entry->d_name);
        }
        else {
            fprintf(stderr, "unknown entry type %d for %s/%s\n", entry->d_type, curr_path, entry->d_name);
        }
    }

    /* close the directory and return the total size for the current directory */
    closedir(dir);
    return total_size;
}

/* get program name from full path */
void get_prog_name() {
    char* name_end = strrchr(prog_name, '/');
    if (name_end == NULL) {
        name_end = prog_name;
    }
    else {
        name_end++;
    }
    snprintf(prog_name, PATH_SIZE, "%s", name_end);
}

/* get current working directory */
void get_cwd() {
    if (getcwd(cwd, PATH_SIZE) == NULL) {
        perror("getcwd error");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {

    /* get program name and current working directory */
    snprintf(prog_name, PATH_SIZE, "%s", argv[0]);
    get_prog_name();
    get_cwd();

    /* parse command line arguments */
    if (argc == 1) {
        traverse_system(".", 1);
    }
    else if (argc == 2) {
        traverse_system(argv[1], 1);
    }
    else {
        fprintf(stderr, "usage: %s [path]\n", prog_name);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}