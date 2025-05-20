//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define PATH "/proc"

int is_num(const char* str){
    for (int i = 0; isdigit(str[i]); i++) {
        if (str[i + 1] == '\0') {
            return 1;
        }
    }
    return 0;
}

void get_proc_info(const char* pid){
    char path[256], line[256], *str_val, buf[1024];
    int int_val;
    FILE *fp;
    sprintf(path, "%s/%s/stat", PATH, pid);
    fp = fopen(path, "r");
    if (fp) {
        fgets(line, sizeof(line), fp);
        fclose(fp);
        if (line) {
            str_val = strtok(line, " ");
            int_val = 1;
            while (str_val != NULL) {
                switch (int_val){
                    case 1:
                        printf("PID: %s\n", str_val);
                        break;
                    case 2:
                        printf("NAME: %s\n", str_val+1);
                        break;
                    case 3:
                        printf("STATE: %s\n", str_val);
                        break;
                    case 14:
                        printf("CPU TIME: %s\n", str_val);
                        break;
                }
                str_val = strtok(NULL, " ");
                int_val++;
            }

            sprintf(path, "%s/%s/status", PATH, pid);
            fp = fopen(path, "r");
            if (fp) {
                while (fgets(line, sizeof(line), fp)){
                    if (strncmp(line, "VmSize:", 7) == 0){
                        printf("%s", line);
                        break;
                    }
                }
                fclose(fp);
            }
        }
    }
}

void list_procs(){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (PATH)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (is_num(ent->d_name)) {
                get_proc_info(ent->d_name);
                printf("\n");
            }
        }
        closedir (dir);
    } else {
        perror ("Couldn't open the directory."); 
        exit(EXIT_FAILURE);
    }
}
int main() {
    list_procs();
    return 0;
}