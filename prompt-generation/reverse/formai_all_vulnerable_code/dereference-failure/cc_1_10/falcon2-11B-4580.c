//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BUFSIZE 2048

typedef struct {
    char username[100];
    char password[100];
    char email[100];
} user_info;

void print_usage(void) {
    printf("Usage: %s <username> <password> <email>\n", __FILE__);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
    }

    user_info info = {
       .username = "",
       .password = "",
       .email = ""
    };

    strcpy(info.username, argv[1]);
    strcpy(info.password, argv[2]);
    strcpy(info.email, argv[3]);

    char buffer[BUFSIZE];
    FILE *fp;
    char line[MAX_LINE];

    fp = fopen("mail.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "USER ")) {
            strcpy(buffer, line + strlen("USER "));
            strcat(buffer, "\r\n");
            write(1, buffer, strlen(buffer));
        } else if (strstr(line, "PASS ")) {
            strcpy(buffer, line + strlen("PASS "));
            strcat(buffer, "\r\n");
            write(1, buffer, strlen(buffer));
        } else if (strstr(line, "RETR ")) {
            strcpy(buffer, line + strlen("RETR "));
            strcat(buffer, "\r\n");
            write(1, buffer, strlen(buffer));
        } else if (strstr(line, "RSET ")) {
            strcpy(buffer, line + strlen("RSET "));
            strcat(buffer, "\r\n");
            write(1, buffer, strlen(buffer));
        } else if (strstr(line, "QUIT ")) {
            strcpy(buffer, line + strlen("QUIT "));
            strcat(buffer, "\r\n");
            write(1, buffer, strlen(buffer));
        } else {
            printf("Unknown command: %s\n", line);
        }
    }

    fclose(fp);
    exit(0);
}