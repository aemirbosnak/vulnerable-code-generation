//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STR_LEN 50
#define FILE_NAME_LEN 100

char target_string[STR_LEN] = {"SURPRISE! YOU'VE BEEN CAUGHT!"};
char file_name[FILE_NAME_LEN];
int file_size;
char *file_content;
int i, j;
int flag = 0;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(file_name, argv[1]);

    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        die("Error opening file.");
    }

    struct stat st;
    fstat(fd, &st);
    file_size = st.st_size;

    file_content = (char *) malloc(file_size);
    if (file_content == NULL) {
        die("Error allocating memory.");
    }

    ssize_t bytes_read = read(fd, file_content, file_size);
    if (bytes_read != file_size) {
        die("Error reading file.");
    }

    close(fd);

    for (i = 0; i < file_size - (STR_LEN - 1); i++) {
        for (j = 0; j < STR_LEN; j++) {
            if (file_content[i + j] != target_string[j]) {
                break;
            }
            if (j == STR_LEN - 1) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("Found target string at position %d in file %s.\n", i, file_name);
            free(file_content);
            return 0;
        }
        flag = 0;
    }

    printf("String not found in file %s.\n", file_name);
    free(file_content);

    return 1;
}