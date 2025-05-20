//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFSIZE 4096

struct virus {
    char *name;
    char *signature;
    int size;
};

struct virus_database {
    struct virus *viruses;
    int num_viruses;
};

int load_virus_database(const char *filename, struct virus_database *db) {
    int fd, i;
    struct stat st;
    char *buf;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    if (fstat(fd, &st) < 0) {
        close(fd);
        return -1;
    }

    buf = malloc(st.st_size);
    if (!buf) {
        close(fd);
        return -1;
    }

    if (read(fd, buf, st.st_size) != st.st_size) {
        free(buf);
        close(fd);
        return -1;
    }

    close(fd);

    db->num_viruses = 0;
    for (i = 0; i < st.st_size; i++) {
        if (buf[i] == '\n') {
            db->num_viruses++;
        }
    }

    db->viruses = malloc(sizeof(struct virus) * db->num_viruses);
    if (!db->viruses) {
        free(buf);
        return -1;
    }

    i = 0;
    while (i < st.st_size) {
        char *name = strtok(&buf[i], "\n");
        if (!name) {
            break;
        }

        char *signature = strtok(NULL, "\n");
        if (!signature) {
            free(buf);
            free(db->viruses);
            return -1;
        }

        db->viruses[db->num_viruses - 1].name = strdup(name);
        db->viruses[db->num_viruses - 1].signature = strdup(signature);
        db->viruses[db->num_viruses - 1].size = strlen(signature);

        i += strlen(name) + strlen(signature) + 2;
    }

    free(buf);

    return 0;
}

void free_virus_database(struct virus_database *db) {
    int i;

    for (i = 0; i < db->num_viruses; i++) {
        free(db->viruses[i].name);
        free(db->viruses[i].signature);
    }

    free(db->viruses);
}

int scan_file(const char *filename, struct virus_database *db) {
    int fd, i, j;
    struct stat st;
    char *buf;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    if (fstat(fd, &st) < 0) {
        close(fd);
        return -1;
    }

    buf = malloc(st.st_size);
    if (!buf) {
        close(fd);
        return -1;
    }

    if (read(fd, buf, st.st_size) != st.st_size) {
        free(buf);
        close(fd);
        return -1;
    }

    close(fd);

    for (i = 0; i < st.st_size; i++) {
        for (j = 0; j < db->num_viruses; j++) {
            if (db->viruses[j].size <= st.st_size - i) {
                if (memcmp(&buf[i], db->viruses[j].signature, db->viruses[j].size) == 0) {
                    free(buf);
                    return 1;
                }
            }
        }
    }

    free(buf);

    return 0;
}

int main(int argc, char **argv) {
    struct virus_database db;
    int i;

    if (argc < 2) {
        printf("Usage: %s <virus_database> <files>\n", argv[0]);
        return 1;
    }

    if (load_virus_database(argv[1], &db) < 0) {
        printf("Error loading virus database\n");
        return 1;
    }

    for (i = 2; i < argc; i++) {
        if (scan_file(argv[i], &db)) {
            printf("File %s is infected\n", argv[i]);
        } else {
            printf("File %s is clean\n", argv[i]);
        }
    }

    free_virus_database(&db);

    return 0;
}