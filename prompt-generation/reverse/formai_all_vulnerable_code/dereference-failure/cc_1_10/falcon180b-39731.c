//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

typedef struct {
    char file_name[256];
    char file_type[4];
    int file_size;
    char file_content[BUFFER_SIZE];
} File;

void print_files(File file[], int num_files) {
    for(int i = 0; i < num_files; i++) {
        printf("%s\t%s\t%d\t", file[i].file_name, file[i].file_type, file[i].file_size);
        for(int j = 0; j < file[i].file_size; j++) {
            printf("%c", file[i].file_content[j]);
        }
        printf("\n");
    }
}

int main() {
    char directory_name[256];
    printf("Enter the directory name: ");
    scanf("%s", directory_name);

    DIR *dir;
    struct dirent *ent;
    int num_files = 0;
    File file[1000];

    dir = opendir(directory_name);
    if(dir == NULL) {
        printf("Error: Directory not found.\n");
        return 1;
    }

    while((ent = readdir(dir))!= NULL) {
        if(ent->d_type == DT_REG) {
            sprintf(file[num_files].file_name, "%s%s", directory_name, ent->d_name);
            sprintf(file[num_files].file_type, "REG");
            int file_size = ent->d_reclen;
            file[num_files].file_size = file_size;
            char *content = (char *)malloc(file_size * sizeof(char));
            int fd = open(file[num_files].file_name, O_RDONLY);
            if(fd!= -1) {
                read(fd, content, file_size);
                close(fd);
            } else {
                printf("Error: %s\n", strerror(errno));
            }
            strncpy(file[num_files].file_content, content, file_size);
            free(content);
            num_files++;
        }
    }

    closedir(dir);

    print_files(file, num_files);

    return 0;
}