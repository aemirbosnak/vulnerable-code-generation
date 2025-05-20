//FormAI DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_CHARS 50

/* Define structure for holding sensitive data */
struct sensitive_data {
    char name[MAX_CHARS];
    char ssn[MAX_CHARS];
    char password[MAX_CHARS];
};

/* Function to generate random alphanumeric string */
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    if (!string) {
        return NULL;
    }
    int i;
    for (i = 0; i < length; i++) {
        int rand_num = rand() % 62; /* 26 lowercase letters, 26 uppercase letters, 10 digits */
        if (rand_num < 26) {
            string[i] = 'a' + rand_num; /* Lowercase letter */
        } else if (rand_num < 52) {
            string[i] = 'A' + (rand_num - 26); /* Uppercase letter */
        } else {
            string[i] = '0' + (rand_num - 52); /* Digit */
        }
    }
    string[length] = '\0';
    return string;
}

/* Function to read sensitive data from file */
int read_sensitive_data(struct sensitive_data *data, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }
    char line[MAX_CHARS];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        strncpy(data[i].name, token, sizeof(data[i].name));
        token = strtok(NULL, ",");
        strncpy(data[i].ssn, token, sizeof(data[i].ssn));
        token = strtok(NULL, ",");
        strncpy(data[i].password, token, sizeof(data[i].password));
        i++;
    }
    fclose(file);
    return i;
}

/* Function to encrypt sensitive data */
void encrypt_data(struct sensitive_data *data, int num_lines) {
    int i;
    for (i = 0; i < num_lines; i++) {
        int j;
        for (j = 0; j < strlen(data[i].name); j++) {
            data[i].name[j] = (data[i].name[j] + 5) % 128;
        }
        for (j = 0; j < strlen(data[i].ssn); j++) {
            data[i].ssn[j] = (data[i].ssn[j] + 5) % 128;
        }
        for (j = 0; j < strlen(data[i].password); j++) {
            data[i].password[j] = (data[i].password[j] + 5) % 128;
        }
    }
}

/* Function to write encrypted data to file */
void write_encrypted_data(struct sensitive_data *data, int num_lines) {
    FILE *file = fopen("encrypted_data.txt", "w");
    if (!file) {
        return;
    }
    int i;
    for (i = 0; i < num_lines; i++) {
        fprintf(file, "%s,%s,%s\n", data[i].name, data[i].ssn, data[i].password);
    }
    fclose(file);
}

/* Main function */
int main() {
    srand(time(NULL));
    struct sensitive_data data[MAX_LINES];
    int num_lines = read_sensitive_data(data, "sensitive_data.txt");
    if (!num_lines) {
        printf("Error: could not read sensitive data file.\n");
        return 1;
    }
    encrypt_data(data, num_lines);
    write_encrypted_data(data, num_lines);
    printf("Sensitive data has been encrypted and written to encrypted_data.txt.\n");
    return 0;
}