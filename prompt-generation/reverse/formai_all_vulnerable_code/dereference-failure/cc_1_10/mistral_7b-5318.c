//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 128
#define DATA_FILE "passwords.dat"
#define SEP "------------------------------------------------------------------------------"

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void print_separator() {
    printf("%s\n", SEP);
}

int read_password(char *username, char *password) {
    int fd = open(DATA_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening data file");
        return -1;
    }

    ssize_t bytes_read;
    size_t username_len = strlen(username);
    char line[2 * MAX_PASSWORD_LENGTH];

    while ((bytes_read = read(fd, line, sizeof(line) - 1)) > 0) {
        line[bytes_read] = '\0';
        Password *p = (Password *) line;
        if (strcmp(p->username, username) == 0) {
            strcpy(password, p->password);
            close(fd);
            return 0;
        }
    }

    close(fd);
    return -1;
}

void save_password(char *username, char *password) {
    int fd = open(DATA_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening data file");
        return;
    }

    Password p = {username, password};
    size_t size = strlen(username) + strlen(password) + sizeof(Password) - 1;
    char *data = malloc(size);
    sprintf(data, "%s:%s%s", username, password, SEP);

    write(fd, data, size);
    free(data);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    char username[MAX_PASSWORD_LENGTH];
    strcpy(username, argv[1]);

    char password[MAX_PASSWORD_LENGTH];
    if (read_password(username, password) < 0) {
        printf("Password for %s not found.\n", username);
        strcpy(password, argv[2]);
        save_password(username, password);
        printf("New password saved for %s.\n", username);
    } else {
        print_separator();
        printf("Found password for %s:\n", username);
        printf("%s\n", password);
        print_separator();
    }

    return 0;
}