//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIG 100
#define MAX_SIZE 100000

typedef struct {
    char *name;
    char *signature;
    int size;
} sig_t;

sig_t signatures[MAX_SIG];
int num_sigs = 0;

void load_signatures() {
    FILE *f = fopen("signatures.txt", "r");
    if (!f) {
        perror("Could not open signatures file");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), f) != NULL) {
        if (line[0] == '#') {
            continue;
        }

        char *name = strtok(line, ":");
        char *signature = strtok(NULL, ":");
        int size = atoi(strtok(NULL, ":"));

        signatures[num_sigs].name = strdup(name);
        signatures[num_sigs].signature = strdup(signature);
        signatures[num_sigs].size = size;

        num_sigs++;
    }

    fclose(f);
}

int scan_file(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Could not open file");
        return 1;
    }

    unsigned char buffer[MAX_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_SIZE, f)) > 0) {
        for (int i = 0; i < num_sigs; i++) {
            if (strstr((char *)buffer, signatures[i].signature) != NULL) {
                printf("Found virus: %s\n", signatures[i].name);
                return 1;
            }
        }
    }

    fclose(f);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_signatures();

    int result = scan_file(argv[1]);
    if (result == 0) {
        printf("No viruses found\n");
    }

    return 0;
}