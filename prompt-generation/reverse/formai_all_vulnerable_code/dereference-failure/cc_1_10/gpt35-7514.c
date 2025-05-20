//FormAI DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if(argc < 3) {
        printf("USAGE: %s [OPTION] [DIRECTORY NAME]\n", argv[0]);
        return -1;
    }

    char *option = argv[1];
    char *dirname = argv[2];

    if(strcmp(option, "-list") == 0) {

        // List all files in the directory
        char *cmd = (char*) malloc(strlen("ls -la ") + strlen(dirname));
        strcpy(cmd, "ls -la ");
        strcat(cmd, dirname);
        system(cmd);
        free(cmd);

    } else if(strcmp(option, "-create") == 0) {

        // Create a new directory
        char *cmd = (char*) malloc(strlen("mkdir ") + strlen(dirname));
        strcpy(cmd, "mkdir ");
        strcat(cmd, dirname);
        system(cmd);
        free(cmd);

    } else if(strcmp(option, "-delete") == 0) {

        // Delete the directory
        char *cmd = (char*) malloc(strlen("rm -rf ") + strlen(dirname));
        strcpy(cmd, "rm -rf ");
        strcat(cmd, dirname);
        system(cmd);
        free(cmd);

    } else if(strcmp(option, "-rename") == 0) {

        if(argc < 4) {
            printf("USAGE: %s -rename [OLD DIRECTORY NAME] [NEW DIRECTORY NAME]\n", argv[0]);
            return -1;
        }

        // Rename the directory
        char *oldname = dirname;
        char *newname = argv[3];

        char *cmd = (char*) malloc(strlen("mv ") + strlen(oldname) + strlen(newname) + 1);
        strcpy(cmd, "mv ");
        strcat(cmd, oldname);
        strcat(cmd, " ");
        strcat(cmd, newname);
        system(cmd);
        free(cmd);

    } else {
        printf("Unknown option: %s\n", option);
        return -1;
    }

    printf("Operation successful!\n");
    return 0;
}