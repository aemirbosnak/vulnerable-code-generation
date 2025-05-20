//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 100

typedef struct {
    char *name;
    char *sig;
    int len;
} signature;

signature sigs[MAX_SIGS];
int num_sigs = 0;

void load_signatures() {
    FILE *fp;
    char line[1024];
    char *name, *sig;
    int len;

    fp = fopen("signatures.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        name = strtok(line, ":");
        sig = strtok(NULL, ":");
        len = strlen(sig);

        sigs[num_sigs].name = strdup(name);
        sigs[num_sigs].sig = strdup(sig);
        sigs[num_sigs].len = len;

        num_sigs++;
    }

    fclose(fp);
}

void scan_file(char *filename) {
    int fd;
    char *buf;
    int len;
    int i;
    int found = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    buf = malloc(len);
    if (buf == NULL) {
        perror("malloc");
        close(fd);
        return;
    }

    read(fd, buf, len);
    close(fd);

    for (i = 0; i < num_sigs; i++) {
        if (strstr(buf, sigs[i].sig)) {
            printf("%s: %s\n", filename, sigs[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%s: Clean\n", filename);
    }

    free(buf);
}

void scan_directory(char *dirname) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        if (ent->d_type == DT_DIR) {
            scan_directory(ent->d_name);
        } else if (ent->d_type == DT_REG) {
            scan_file(ent->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char *dirname;

    if (argc < 2) {
        dirname = ".";
    } else {
        dirname = argv[1];
    }

    load_signatures();
    scan_directory(dirname);

    return 0;
}