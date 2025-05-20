//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 128
#define MAX_VIRUS_SIGNATURES 100

/* Structure to hold virus signatures */
struct VirusSignature {
    char signature[MAX_FILENAME];
};

/* Function to scan file for virus signatures */
void scanFile(char *filename, struct VirusSignature *virusSignatures, int numSignatures) {
    FILE *fp = fopen(filename, "r");
    int isInfected = 0;
    char line[MAX_FILENAME];
    
    /* Read file line by line and check for virus signatures */
    while(fgets(line, MAX_FILENAME , fp)) {
        for(int i=0; i<numSignatures; i++) {
            if(strstr(line, virusSignatures[i].signature)) {
                printf("Virus signature %s found in file: %s\n", virusSignatures[i].signature, filename);
                isInfected = 1;
                break;
            }
        }
        if(isInfected) {
            break;
        }
    }
    fclose(fp);
    if(!isInfected) {
        printf("File %s is clean!\n", filename);
    }
}

int main() {
    /* Load virus signatures into memory */
    struct VirusSignature *virusSignatures = (struct VirusSignature *) malloc(MAX_VIRUS_SIGNATURES * sizeof(struct VirusSignature));
    strcpy(virusSignatures[0].signature, "DeleteSystem32");
    strcpy(virusSignatures[1].signature, "Trojan");
    int numSignatures = 2;
    
    /* Scan files for virus signatures */
    printf("Scanning for viruses...\n");
    scanFile("file1.txt", virusSignatures, numSignatures);
    scanFile("file2.txt", virusSignatures, numSignatures);
    scanFile("file3.txt", virusSignatures, numSignatures);
    
    free(virusSignatures);
    return 0;
}