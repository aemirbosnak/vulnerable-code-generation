//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define PROC_DIR "/proc"
#define LINE_MAX 1024

/* Function to read process information from procfs */
void read_proc(char* pid) {
    char path[LINE_MAX], line[LINE_MAX];

    snprintf(path, LINE_MAX, "%s/%s/stat", PROC_DIR, pid);
    FILE* fp = fopen(path, "r");
    if (!fp) {
        printf("Error: could not open %s\n", path);
        return;
    }

    fgets(line, LINE_MAX, fp);
    fclose(fp);

    char* token;
    token = strtok(line, " "); // read PID
    printf("PID: %s\n", token);

    for (int i = 0; i < 14; i++) { // skip various fields
        token = strtok(NULL, " ");
    }

    token = strtok(NULL, " "); // read RSS
    int rss = atoi(token);
    printf("RSS: %d\n", rss);
}

int main() {
    DIR* proc_dir = opendir(PROC_DIR);
    if (!proc_dir) {
        printf("Error: could not open %s\n", PROC_DIR);
        return 1;
    }

    struct dirent* ent;
    while ((ent = readdir(proc_dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            char* name = ent->d_name;
            if (name[0] >= '0' && name[0] <= '9') { // process directories start with digits
                read_proc(name);
            }
        }
    }

    closedir(proc_dir);
    return 0;
}