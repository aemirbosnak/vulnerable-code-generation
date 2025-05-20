//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 256

typedef struct {
    char *name;
    char *sig;
    int sig_len;
} signature;

signature sigs[MAX_SIGS];
int num_sigs = 0;

void load_signatures(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while (fgets(sigs[num_sigs].name, MAX_SIG_LEN, fp)) {
        sigs[num_sigs].name[strlen(sigs[num_sigs].name) - 1] = '\0';
        fgets(sigs[num_sigs].sig, MAX_SIG_LEN, fp);
        sigs[num_sigs].sig[strlen(sigs[num_sigs].sig) - 1] = '\0';
        sigs[num_sigs].sig_len = strlen(sigs[num_sigs].sig);
        num_sigs++;
    }

    fclose(fp);
}

int scan_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buf = malloc(file_size);
    if (!buf) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(buf, 1, file_size, fp);
    fclose(fp);

    for (int i = 0; i < num_sigs; i++) {
        if (strstr(buf, sigs[i].sig)) {
            printf("Found %s in %s\n", sigs[i].name, filename);
            free(buf);
            return 1;
        }
    }

    free(buf);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <signature file> <file to scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_signatures(argv[1]);
    int ret = scan_file(argv[2]);
    if (ret) {
        printf("File is infected\n");
    } else {
        printf("File is clean\n");
    }

    return EXIT_SUCCESS;
}