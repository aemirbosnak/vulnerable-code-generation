//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];
    FILE *fp;
} File;

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt_file(File *file, char *key) {
    char ch, line[MAX_LINE_LEN];
    int i, j;

    while (fgets(line, MAX_LINE_LEN, file->fp)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            ch = line[i];
            if (isalpha(ch)) {
                ch = (ch + key[i % strlen(key)]) % 26 + 'a';
            }
            line[i] = ch;
        }
        fputs(line, stdout);
    }
}

void decrypt_file(File *file, char *key) {
    char ch, line[MAX_LINE_LEN];
    int i, j;

    while (fgets(line, MAX_LINE_LEN, file->fp)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            ch = line[i];
            if (isalpha(ch)) {
                ch = (ch - key[i % strlen(key)]) % 26 + 'a';
            }
            line[i] = ch;
        }
        fputs(line, stdout);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LEN], key[MAX_KEY_LEN];
    File file;
    int choice;

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter key: ");
    scanf("%s", key);
    generate_key(key);

    file.fp = fopen(file_name, "r");
    if (file.fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_file(&file, key);
    } else if (choice == 2) {
        decrypt_file(&file, key);
    } else {
        printf("Invalid choice");
    }

    fclose(file.fp);
    return 0;
}