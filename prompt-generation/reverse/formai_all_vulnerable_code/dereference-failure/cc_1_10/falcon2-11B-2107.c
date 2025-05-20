//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void recoverFile(char *filename, char *newpath) {
    char buf[256];
    FILE *fp = NULL;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (fsize == 0) {
        printf("File is empty\n");
        fclose(fp);
        return;
    }

    if (fsize > 0x1000000) {
        printf("File is too large\n");
        fclose(fp);
        return;
    }

    char *tmpname = malloc((strlen(filename) + 1) * sizeof(char));
    strcpy(tmpname, filename);

    int count = 0;
    while (tmpname[count]!= '\0') {
        if (tmpname[count] == '/') {
            break;
        }
        count++;
    }

    char *newname = malloc((strlen(filename) + strlen(newpath) + strlen(".tmp") + 1) * sizeof(char));
    sprintf(newname, "%s/%s.tmp", newpath, tmpname);

    fp = fopen(newname, "wb");
    if (fp == NULL) {
        printf("Error opening new file: %s\n", newname);
        free(newname);
        return;
    }

    while (fsize > 0) {
        int bytes = fread(buf, 1, 256, fp);
        if (bytes == 0) {
            printf("Error reading file: %s\n", filename);
            break;
        }
        fwrite(buf, 1, bytes, fp);
        fsize -= bytes;
    }

    fclose(fp);
    free(newname);

    char *cmd = malloc((strlen(filename) + strlen("rm") + strlen(".tmp") + 1) * sizeof(char));
    sprintf(cmd, "rm %s.tmp", filename);
    system(cmd);

    free(tmpname);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <directory> <newpath>\n", argv[0]);
        return 1;
    }

    char *directory = argv[1];
    char *newpath = argv[2];

    DIR *dir = NULL;
    struct dirent *ent = NULL;

    dir = opendir(directory);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", directory);
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        char *filename = malloc((strlen(ent->d_name) + 1) * sizeof(char));
        strcpy(filename, ent->d_name);

        char *fullpath = malloc((strlen(directory) + strlen(filename) + 1) * sizeof(char));
        sprintf(fullpath, "%s/%s", directory, filename);

        if (strcmp(fullpath, ".")!= 0 && strcmp(fullpath, "..")!= 0) {
            recoverFile(fullpath, newpath);
        }

        free(fullpath);
        free(filename);
    }

    closedir(dir);

    return 0;
}