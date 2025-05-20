//GEMINI-pro DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mysterious function that takes a string and a file pointer,
// and does something...
void enigmatic(char *str, FILE *fp) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            fprintf(fp, "%c", str[i]);
        } else {
            fputc('?', fp);
        }
    }
}

// A cryptic function that takes a file pointer and a number,
// and does something else...
void cryptic(FILE *fp, int n) {
    char buf[1024];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        int len = strlen(buf);
        for (int i = 0; i < len; i++) {
            if (buf[i] >= 'A' && buf[i] <= 'Z') {
                buf[i] += n;
                if (buf[i] > 'Z') {
                    buf[i] -= 26;
                }
            } else if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] += n;
                if (buf[i] > 'z') {
                    buf[i] -= 26;
                }
            }
        }
        fprintf(fp, "%s", buf);
    }
}

// The main function that orchestrates the mystery...
int main() {
    FILE *fp = fopen("secret.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // A series of enigmatic and cryptic operations...
    char str[1024];
    fgets(str, sizeof(str), fp);
    enigmatic(str, fp);
    fclose(fp);

    fp = fopen("secret.txt", "w");
    cryptic(fp, 13);
    fclose(fp);

    // Observe the concealed message in the transformed file...
    return 0;
}