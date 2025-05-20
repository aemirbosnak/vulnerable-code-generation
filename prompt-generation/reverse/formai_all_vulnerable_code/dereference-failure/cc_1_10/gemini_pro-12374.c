//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum SignatureTypes {
    SIGNATURE_TYPE_NONE,
    SIGNATURE_TYPE_WILDCARD,
    SIGNATURE_TYPE_STRING
};

typedef struct Signature {
    char *name;
    char *pattern;
    enum SignatureTypes type;
} Signature;

Signature *signatures[] = {
    &(Signature){"HEUR_TROJAN.Win32.Generic", "*.exe", SIGNATURE_TYPE_WILDCARD},
    &(Signature){"HEUR_VIRUS.Win32.Generic", "*.vbs", SIGNATURE_TYPE_WILDCARD},
    &(Signature){"HEUR_SPYWARE.Win32.Generic", "*.txt", SIGNATURE_TYPE_WILDCARD},
    &(Signature){"HEUR_ROOTKIT.Win32.Generic", "*.sys", SIGNATURE_TYPE_WILDCARD},
    &(Signature){"HEUR_WORM.Win32.Generic", "*.lnk", SIGNATURE_TYPE_WILDCARD},
    &(Signature){"STRING_VIRUS.Win32.Generic", "eval(\"\\\"test\\\"\");", SIGNATURE_TYPE_STRING},
    &(Signature){"STRING_TROJAN.Win32.Generic", "regedit.exe", SIGNATURE_TYPE_STRING},
    &(Signature){"STRING_SPYWARE.Win32.Generic", "netstat.exe", SIGNATURE_TYPE_STRING},
    &(Signature){"STRING_ROOTKIT.Win32.Generic", "lsass.exe", SIGNATURE_TYPE_STRING},
    &(Signature){"STRING_WORM.Win32.Generic", "schtasks.exe", SIGNATURE_TYPE_STRING}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return 1;
    }

    fread(buffer, size, 1, file);
    fclose(file);

    int matches = 0;
    for (int i = 0; i < sizeof(signatures) / sizeof(Signature); i++) {
        Signature *signature = signatures[i];

        switch (signature->type) {
            case SIGNATURE_TYPE_WILDCARD:
                if (strstr(buffer, signature->pattern) != NULL) {
                    matches++;
                    printf("Found match for %s\n", signature->name);
                }
                break;
            case SIGNATURE_TYPE_STRING:
                if (strcmp(buffer, signature->pattern) == 0) {
                    matches++;
                    printf("Found match for %s\n", signature->name);
                }
                break;
            default:
                break;
        }
    }

    if (matches == 0) {
        printf("No matches found\n");
    }

    free(buffer);
    return 0;
}