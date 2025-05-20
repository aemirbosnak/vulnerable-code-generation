//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    else
        return -1;
}

int get_directory_size(const char* dirname, size_t total) {
    DIR* dir = opendir(dirname);
    if (dir!= NULL) {
        struct dirent* entry;
        while ((entry = readdir(dir))!= NULL) {
            const char* name = entry->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
                continue;

            size_t sub_total = 0;
            const char* sub_dirname = dirname;
            if (strcmp(name, ".")!= 0 && strcmp(name, "..")!= 0) {
                sub_dirname = dirname;
                while (*sub_dirname!= '\0') {
                    if (*sub_dirname == '/')
                        sub_dirname++;
                    else
                        break;
                }
                sub_dirname++;
            }

            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
                continue;

            if (strcmp(name, ".")!= 0 && strcmp(name, "..")!= 0) {
                sub_total += get_directory_size(sub_dirname, sub_total);
            } else {
                const char* sub_file = name;
                if (strcmp(name, ".")!= 0 && strcmp(name, "..")!= 0) {
                    sub_file = sub_dirname;
                    while (*sub_file!= '\0') {
                        if (*sub_file == '/')
                            sub_file++;
                        else
                            break;
                    }
                    sub_file++;
                }

                size_t sub_size = get_file_size(sub_file);
                if (sub_size!= -1)
                    sub_total += sub_size;
            }
            total += sub_total;
        }
        closedir(dir);
    }
    return total;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    size_t total = 0;
    total += get_directory_size(argv[1], total);
    printf("%zu bytes used\n", total);

    return 0;
}