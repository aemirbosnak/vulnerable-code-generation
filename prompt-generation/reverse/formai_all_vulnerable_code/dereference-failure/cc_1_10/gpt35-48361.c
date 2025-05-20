//FormAI DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Invalid number of arguments!\n");
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    char *password = argv[2];
    char command[100];
    strcpy(command, "echo -n '");
    strcat(command, password);
    strcat(command, "' | sha256sum | cut -d' ' -f1");

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command!\n");
        return 1;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);

    char hashed_password[65];
    strcpy(hashed_password, buffer);

    int i;
    for (i = 0; i < strlen(hashed_password); i++) {
        if (hashed_password[i] == '\n') {
            hashed_password[i] = 0;
            break;
        }
    }

    char shadow_file[100];
    sprintf(shadow_file, "/etc/shadow");
    setuid(0);

    fp = fopen(shadow_file, "a");
    if (fp == NULL) {
        printf("Error: Failed to open shadow file!\n");
        return 1;
    }

    fprintf(fp, "%s:%s:::::::\n", username, hashed_password);
    fclose(fp);

    printf("Success: User %s added to shadow file!\n", username);
    return 0;
}