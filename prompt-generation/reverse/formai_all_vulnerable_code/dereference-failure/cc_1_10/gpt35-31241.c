//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_VIRUS_SIG_LEN 256

typedef struct VirusSignature {
    char signature[MAX_VIRUS_SIG_LEN];
    struct VirusSignature* next;
} VirusSignature;

void add_signature(VirusSignature** sig_start, const char* sig) {
    VirusSignature* new_sig = (VirusSignature*)malloc(sizeof(VirusSignature));
    strcpy(new_sig->signature, sig);
    new_sig->next = *sig_start;
    *sig_start = new_sig;
}

int scan_file(const char* file_path, VirusSignature* sig_start) {
    FILE* fp = fopen(file_path, "rb");
    if (!fp) {
        return -1;
    }

    int found_virus = 0;
    char buffer[MAX_VIRUS_SIG_LEN];
    while (!feof(fp)) {
        size_t read_bytes = fread(buffer, sizeof(char), MAX_VIRUS_SIG_LEN, fp);
        if (read_bytes == 0) {
            break;
        }

        VirusSignature* cur_sig = sig_start;
        while (cur_sig) {
            if (strstr(buffer, cur_sig->signature)) {
                found_virus = 1;
                printf("Virus found! Signature: %s\n", cur_sig->signature);
                break;
            }
            cur_sig = cur_sig->next;
        }

        if (found_virus) {
            break;
        }
    }

    fclose(fp);
    return found_virus;
}

int main() {
    VirusSignature* sig_start = NULL;

    add_signature(&sig_start, "bad_code_1");
    add_signature(&sig_start, "virus_sig_2");
    add_signature(&sig_start, "malware_pattern_3");
    add_signature(&sig_start, "trojan_sig_4");

    char file_path[MAX_FILE_NAME_LEN];
    printf("Please enter the file path to scan: ");
    scanf("%s", file_path);

    int result = scan_file(file_path, sig_start);
    if (result == -1) {
        printf("Error: Couldn't open the file or file doesn't exist.\n");
    } else if (result == 0) {
        printf("No virus found in the file.\n");
    }

    return 0;
}