//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(){
    DIR *dir;
    struct dirent *ent;
    char path[100];
    int pid;

    printf("Enter the PID of the process you want to view:\n");
    scanf("%d", &pid);

    sprintf(path, "/proc/%d", pid);

    dir = opendir(path);

    if(dir != NULL){
        printf("\n{\n");

        while((ent = readdir(dir)) != NULL){
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                printf("\t\"%s\": ", ent->d_name);

                char data[100];
                sprintf(data, "%s/%s", path, ent->d_name);

                FILE *fp = fopen(data, "r");
                if(fp){
                    fgets(data, 100, fp);
                    printf("\"%s\"", data);
                    fclose(fp);
                }else{
                    printf("\"Error reading file\"");
                }

                printf(",\n");
            }
        }

        printf("}\n");

        closedir(dir);
    }else{
        printf("Error opening directory.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}