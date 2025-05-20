//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 1024

/* Function to compare two strings */
int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

/* Function to print a list of strings */
void print_string_list(char **list, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", list[i]);
    }
}

/* Function to get a list of running processes */
char **get_process_list(void) {
    DIR *dir;
    struct dirent *ent;
    char **list = NULL;
    int count = 0;

    dir = opendir("/proc");

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[MAX_LINE_LENGTH];
                snprintf(path, MAX_LINE_LENGTH, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");

                if (file!= NULL) {
                    char *line = NULL;
                    size_t len = 0;
                    ssize_t read;

                    while ((read = getline(&line, &len, file))!= -1) {
                        list = realloc(list, sizeof(char *) * ++count);
                        list[count - 1] = strdup(line);
                    }

                    fclose(file);
                }
            }
        }

        closedir(dir);
    }

    list = realloc(list, sizeof(char *) * count);
    list[count] = NULL;

    qsort(list, count, sizeof(char *), compare_strings);

    return list;
}

int main(int argc, char **argv) {
    char **list = get_process_list();
    print_string_list(list, argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        free(list[i]);
    }
    free(list);

    return 0;
}