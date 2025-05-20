//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {

    DIR *d;
    struct dirent *dir;
    int virusFound = 0;
    char folder[100];
    char virus[10][100] = {"virus1.txt", "virus2.txt", "virus3.txt", "virus4.txt", "virus5.txt", "virus6.txt", "virus7.txt", "virus8.txt", "virus9.txt", "virus10.txt"};

    printf("Please enter the folder path to scan:\n");
    scanf("%s", folder);

    d = opendir(folder);

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                char file_path[1000];
                snprintf(file_path, sizeof(file_path), "%s/%s", folder, dir->d_name);

                FILE *file;
                file = fopen(file_path, "r");

                if (file) {
                    char buffer[1000];
                    while(fgets(buffer, sizeof(buffer), file) != NULL) {
                        for(int i = 0; i < 10; i++) {
                            if(strstr(buffer, virus[i])) {
                                virusFound = 1;
                                printf("File %s contains virus: %s\n", file_path, virus[i]);
                            }
                        }
                    }
                    fclose(file);
                }
            }
        }
        closedir(d);
    } else {
        printf("Could not open directory.");
        return 0;
    }

    if(virusFound == 0) {
        printf("No viruses found in folder %s", folder);
    }

    return 0;
}