//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

typedef struct {
    char source[100];
    char destination[100];
} Directory;

void read_directories(char* source, char* destination) {
    DIR *dir;
    struct dirent *ent;
    Directory directory;

    if ((dir = opendir(source))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                strcpy(directory.source, source);
                strcat(directory.source, "/");
                strcat(directory.source, ent->d_name);

                strcpy(directory.destination, destination);
                strcat(directory.destination, "/");
                strcat(directory.destination, ent->d_name);

                read_directories(directory.source, directory.destination);
            } else {
                FILE *fp;
                char ch;
                int count = 0;

                strcpy(directory.source, source);
                strcat(directory.source, "/");
                strcat(directory.source, ent->d_name);

                strcpy(directory.destination, destination);
                strcat(directory.destination, "/");
                strcat(directory.destination, ent->d_name);

                if ((fp = fopen(directory.source, "r"))!= NULL) {
                    if ((fp = fopen(directory.destination, "w"))!= NULL) {
                        while ((ch = fgetc(fp))!= EOF) {
                            fputc(ch, fp);
                            count++;
                        }
                        fclose(fp);
                    } else {
                        printf("Unable to open file: %s\n", directory.destination);
                    }
                } else {
                    printf("Unable to open file: %s\n", directory.source);
                }

                printf("Synchronized %d files.\n", count);
            }
        }
        closedir(dir);
    } else {
        printf("Unable to open directory: %s\n", source);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }

    read_directories(argv[1], argv[2]);

    return 0;
}