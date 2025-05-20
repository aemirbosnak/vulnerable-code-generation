//Falcon2-11B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_passwords(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char* passwords = NULL;
    size_t len = 0;
    char c;

    if (!fp) {
        fprintf(stderr, "Error opening %s\n", filename);
        exit(1);
    }

    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            len++;
            passwords = realloc(passwords, len * sizeof(char));
            if (!passwords) {
                fprintf(stderr, "Out of memory\n");
                exit(1);
            }
            passwords[len-1] = '\0';
        } else {
            passwords[len-1] = c;
        }
    }

    fclose(fp);
    return passwords;
}

int main(int argc, char* argv[]) {
    const char* passwords_file = "passwords.txt";

    char* passwords = read_passwords(passwords_file);
    if (!passwords) return 1;

    char* password = NULL;
    int i;

    printf("Please enter password: ");
    fgets(password, sizeof(password), stdin);

    for (i = 0; passwords[i]!= '\0'; i++) {
        if (strcmp(passwords[i], password) == 0) {
            printf("Password found!\n");
            return 0;
        }
    }

    printf("Password not found\n");
    free(passwords);
    return 1;
}