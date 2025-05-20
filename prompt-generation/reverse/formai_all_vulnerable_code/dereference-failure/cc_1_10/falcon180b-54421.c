//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BACKUP_DIR "/backup"
#define BACKUP_FILE_FORMAT "backup-%Y-%m-%d-%H-%M-%S.tar.gz"

void create_backup_dir(void) {
    char cmd[100];

    sprintf(cmd, "mkdir -p %s", BACKUP_DIR);
    system(cmd);
}

int backup_file(const char *filename) {
    char backup_filename[100];
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    FILE *fp;
    int ret = 0;

    sprintf(backup_filename, BACKUP_FILE_FORMAT,
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    char backup_path[200];
    sprintf(backup_path, "%s/%s", BACKUP_DIR, backup_filename);

    fp = fopen(backup_path, "w");
    if (fp == NULL) {
        printf("Error: failed to create backup file '%s'\n", backup_path);
        ret = -1;
        goto cleanup;
    }

    FILE *src_fp = fopen(filename, "r");
    if (src_fp == NULL) {
        printf("Error: failed to open source file '%s'\n", filename);
        ret = -1;
        goto cleanup;
    }

    char buf[4096];
    while (fgets(buf, sizeof(buf), src_fp)!= NULL) {
        fputs(buf, fp);
    }

    fclose(src_fp);
    fclose(fp);

    printf("Backup file created: %s\n", backup_path);

cleanup:
    return ret;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    if (access(filename, F_OK)!= 0) {
        printf("Error: file '%s' not found\n", filename);
        return 1;
    }

    create_backup_dir();

    backup_file(filename);

    return 0;
}