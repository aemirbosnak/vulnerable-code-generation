//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pwd.h>

#define MAX_LINE 1000

int main() {
    char line[MAX_LINE];
    char *token;
    char *username;
    char *password;
    char *groupname;
    int count = 0;
    FILE *fp;
    struct passwd *pw;

    fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        printf("Cannot open /etc/passwd file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        count++;
        if (count == 1) {
            continue;
        }
        token = strtok(line, ":");
        username = token;
        token = strtok(NULL, ":");
        password = token;
        token = strtok(NULL, ":");
        groupname = token;

        pw = getpwnam(username);
        if (pw == NULL) {
            printf("User %s does not exist\n", username);
            exit(1);
        }

        printf("User: %s\n", username);
        printf("Password: %s\n", password);
        printf("Group: %s\n", groupname);
        printf("\n");
    }

    fclose(fp);
    return 0;
}