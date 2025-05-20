//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    unsigned char *signature;
    unsigned int signature_length;
    unsigned int detection_count;
} virus_signature;

typedef struct {
    char *filename;
    unsigned char *file_data;
    unsigned int file_size;
} file_data;

virus_signature *virus_signatures;
unsigned int num_virus_signatures;

int compare_signatures(const void *a, const void *b) {
    virus_signature *va = (virus_signature *)a;
    virus_signature *vb = (virus_signature *)b;

    return strcmp(va->name, vb->name);
}

int load_virus_signatures() {
    FILE *fp;
    char line[256];
    char *name, *signature, *p;
    unsigned int signature_length;

    fp = fopen("virus_signatures.txt", "r");
    if (fp == NULL) {
        return FALSE;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        p = line;
        name = p;
        while (*p != ',') p++;
        *p++ = '\0';
        signature = p;
        while (*p != ',') p++;
        *p++ = '\0';
        signature_length = strlen(signature) / 2;
        virus_signature *vs = malloc(sizeof(virus_signature));
        vs->name = strdup(name);
        vs->signature = malloc(signature_length);
        for (unsigned int i = 0; i < signature_length; i++) {
            char *hex = signature + (i * 2);
            unsigned int value = strtol(hex, &hex, 16);
            vs->signature[i] = (unsigned char)value;
        }
        vs->signature_length = signature_length;
        vs->detection_count = 0;
        num_virus_signatures++;
        virus_signatures = realloc(virus_signatures, sizeof(virus_signature) * num_virus_signatures);
        virus_signatures[num_virus_signatures - 1] = *vs;
    }

    fclose(fp);

    qsort(virus_signatures, num_virus_signatures, sizeof(virus_signature), compare_signatures);

    return TRUE;
}

int load_file_data(const char *filename, file_data *fd) {
    FILE *fp;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return FALSE;
    }

    fseek(fp, 0, SEEK_END);
    fd->file_size = ftell(fp);
    rewind(fp);

    fd->file_data = malloc(fd->file_size);
    fread(fd->file_data, 1, fd->file_size, fp);

    fclose(fp);

    return TRUE;
}

int compare_file_data(unsigned char *file_data, unsigned int file_size, virus_signature *vs) {
    for (unsigned int i = 0; i < file_size - vs->signature_length; i++) {
        if (memcmp(file_data + i, vs->signature, vs->signature_length) == 0) {
            vs->detection_count++;
            return TRUE;
        }
    }

    return FALSE;
}

int scan_file(const char *filename, file_data *fd) {
    if (!load_file_data(filename, fd)) {
        return FALSE;
    }

    for (unsigned int i = 0; i < num_virus_signatures; i++) {
        compare_file_data(fd->file_data, fd->file_size, &virus_signatures[i]);
    }

    free(fd->file_data);

    return TRUE;
}

void print_detection_report() {
    for (unsigned int i = 0; i < num_virus_signatures; i++) {
        if (virus_signatures[i].detection_count > 0) {
            printf("Virus detected: %s (%d detections)\n", virus_signatures[i].name, virus_signatures[i].detection_count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!load_virus_signatures()) {
        printf("Error loading virus signatures\n");
        return EXIT_FAILURE;
    }

    file_data fd;

    if (!scan_file(argv[1], &fd)) {
        printf("Error scanning file\n");
        return EXIT_FAILURE;
    }

    print_detection_report();

    return EXIT_SUCCESS;
}