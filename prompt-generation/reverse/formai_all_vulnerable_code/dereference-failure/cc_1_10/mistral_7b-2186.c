//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SALT_SIZE 16
#define KEY_SIZE 32
#define PASSWORD_SIZE 256

void generate_salt(unsigned char *salt) {
    for (int i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 128;
    }
}

void hash_password(unsigned char *password, unsigned char *salt, unsigned char *hashed_password) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        hashed_password[i] = password[i] ^ salt[i % SALT_SIZE];
    }
}

int read_file(const char *filename, unsigned char **data, size_t *size) {
    int fd;
    struct stat st;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fd, &st) < 0) {
        perror("Error fstat");
        close(fd);
        return 1;
    }

    *size = st.st_size;
    *data = calloc(1, *size);
    if (*data == NULL) {
        perror("Error allocating memory");
        close(fd);
        return 1;
    }

    if (read(fd, *data, *size) < *size) {
        perror("Error reading file");
        free(*data);
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

int write_file(const char *filename, unsigned char *data, size_t size) {
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, data, size) < size) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

int main(void) {
    unsigned char password[PASSWORD_SIZE];
    unsigned char salt[SALT_SIZE];
    unsigned char hashed_password[KEY_SIZE];
    unsigned char *stored_password = NULL;
    size_t password_size, stored_password_size;
    int error;

    printf("Enter your password: ");
    fgets(password, PASSWORD_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    generate_salt(salt);
    hash_password(password, salt, hashed_password);

    error = read_file("passwords.dat", &stored_password, &stored_password_size);
    if (error) {
        fprintf(stderr, "Error reading password file\n");
        return 1;
    }

    if (stored_password_size > 0) {
        unsigned char comparison_password[KEY_SIZE];
        hash_password(password, salt, comparison_password);

        if (memcmp(stored_password, comparison_password, KEY_SIZE) == 0) {
            printf("Your password is already stored and matches the one you entered.\n");
            free(stored_password);
            return 0;
        }

        free(stored_password);
    }

    error = write_file("passwords.dat", hashed_password, KEY_SIZE);
    if (error) {
        fprintf(stderr, "Error writing password to file\n");
        return 1;
    }

    printf("Password saved.\n");

    free(hashed_password);
    return 0;
}