//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *host, *username, *password, *user_dir;
    int port = 110;

    if (argc < 4) {
        printf("Usage: %s host username password user_dir\n", argv[0]);
        return 1;
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];
    user_dir = argv[4];

    char *user_dir_c = strdup(user_dir);

    char *cmd = "POP3 ";
    strcat(cmd, host);
    strcat(cmd, " ");
    strcat(cmd, username);
    strcat(cmd, " ");
    strcat(cmd, password);
    strcat(cmd, " ");
    strcat(cmd, user_dir_c);

    char *output = NULL;
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen() failed");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    output = malloc(size + 1);
    if (output == NULL) {
        perror("malloc() failed");
        exit(1);
    }

    size_t bytes_read = fread(output, 1, size, fp);
    if (bytes_read!= size) {
        perror("fread() failed");
        exit(1);
    }

    output[size] = '\0';
    fclose(fp);

    printf("%s\n", output);

    free(output);
    free(user_dir_c);

    return 0;
}