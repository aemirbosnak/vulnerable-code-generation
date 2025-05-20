//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

void printTopBar(){
    printf("\n");
    printf("\t\t\t\t****************************************************\n");
    printf("\t\t\t\t*                                                  *\n");
    printf("\t\t\t\t*         Welcome to the Process Viewer             *\n");
    printf("\t\t\t\t*                                                  *\n");
    printf("\t\t\t\t****************************************************\n");
}

int main(){
    DIR* dir;
    struct dirent* ent;
    char path[1024];
    char pid[12];
    FILE *fp;
    char cmdline[1024];
    
    printTopBar();
    printf("\n");
    printf("PID\tCOMMAND\n");
    printf("===\t=======\n");

    dir = opendir("/proc/");
    if (dir != NULL){

        while ((ent = readdir(dir)) != NULL){

            if (ent->d_type == DT_DIR){

                sprintf(pid, "%s", ent->d_name);
                if (atoi(pid) != 0){
                    
                    sprintf(path, "/proc/%s/cmdline", pid);
                    fp = fopen(path, "r");

                    if (fp){
                        fgets(cmdline, 1024, fp);
                        fclose(fp);
                        
                        printf("%d\t%s\n", atoi(pid), cmdline);

                    }
                }
            }
        }
        closedir(dir);
        printf("\nTotal Processes: %d", atoi(ent->d_name) - 1);
        printf("\n\n");
        return 0;
    } else {
        perror("Error!!! Unable to open the /proc directory.");
    }
    return 1;
}