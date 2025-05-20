//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if(!dir) {
        perror("opendir");
        exit(1);
    }

    while((entry = readdir(dir))) {
        if(entry->d_type == DT_DIR && isdigit(*entry->d_name)) {
            char path[1024];
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            FILE *fp = fopen(path, "r");
            if(!fp){
                perror("fopen");
                exit(1);
            }
            char line[128];

            while(fgets(line, sizeof(line), fp)) {
                if(strncmp(line, "Name:", 5) == 0) {
                    printf("%s -> ", line + 5);
                    break;
                }
            }

            fclose(fp);

            snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);
            fp = fopen(path, "r");
            if(!fp){
                perror("fopen");
                exit(1);
            }
            fgets(line, sizeof(line), fp);
            printf("%s\n", line);

            fclose(fp);
        }
    }

    closedir(dir);

    return 0;
}