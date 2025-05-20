//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function that checks if a user exists and returns user information
char *get_user_info(char *username) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *user_info = malloc(sizeof(char) * 100);
    memset(user_info, 0, sizeof(user_info));

    fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token;
        token = strtok(line, ":");
        if (strcmp(token, username) == 0) {
            // we found the user
            strcat(user_info, "Username: ");
            strcat(user_info, token);
            token = strtok(NULL, ":"); // skip the password field
            strcat(user_info, "\nUID: ");
            strcat(user_info, token);
            fclose(fp);
            if (line)
                free(line);
            return user_info;
        }
    }

    // if we get here, the user doesn't exist
    strcat(user_info, "Error: User not found.");
    fclose(fp);
    if (line)
        free(line);
    return user_info;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *username = argv[1];
    char *user_info = get_user_info(username);

    printf("%s\n", user_info);

    free(user_info);
    return 0;
}