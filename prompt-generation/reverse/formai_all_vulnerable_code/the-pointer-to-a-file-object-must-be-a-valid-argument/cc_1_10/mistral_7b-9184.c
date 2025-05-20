//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#define MAIL_DIR "/var/mail/"
#define REPLACE_KEYWORD "SECRET_KEYWORD"
#define NEW_KEYWORD "NEW_KEYWORD"

int main() {
    char username[256], mailbox[256], line[1024], keyword[32], replacement[32];
    int fd, i, j;

    // Get current user name and mailbox path
    getlogin_r(username, sizeof(username));
    sprintf(mailbox, "%s%s", MAIL_DIR, username);

    // Open mailbox file for reading
    fd = open(mailbox, O_RDONLY);
    if (fd < 0) {
        perror("Error opening mailbox file");
        return 1;
    }

    printf("----------------------------------------\n");
    printf("|          Your Invasive Email Client   |\n");
    printf("|                                      |\n");
    printf("----------------------------------------\n");

    // Read and process each line in the mailbox file
    while (fgets(line, sizeof(line), fd)) {
        // Replace keyword with new keyword
        i = strlen(REPLACE_KEYWORD);
        j = strlen(line);
        for (int k = 0; k < j - i; k++) {
            if (strncmp(line + k, REPLACE_KEYWORD, i) == 0) {
                strncpy(line + k, NEW_KEYWORD, i);
                break;
            }
        }

        // Print the modified line
        printf("%s", line);

        // Check for email headers and print them if found
        if (strstr(line, ": ") || strstr(line, "Subject: ")) {
            printf("\n%s", line);
        }
    }

    close(fd);
    return 0;
}

// Function to replace a keyword with a new keyword in a given string
void replace_keyword(char *str, char *old_keyword, char *new_keyword) {
    char *token, temp_str[1024];
    int i, j, len_old = strlen(old_keyword), len_new = strlen(new_keyword);

    strcpy(temp_str, str);

    token = strtok(temp_str, "\n");

    while (token != NULL) {
        i = strlen(token);
        j = i - len_old;

        if (j > 0 && strncmp(token + j, old_keyword, len_old) == 0) {
            strncpy(token + j, new_keyword, len_new);
        }

        token = strtok(NULL, "\n");
    }

    strcpy(str, temp_str);
}