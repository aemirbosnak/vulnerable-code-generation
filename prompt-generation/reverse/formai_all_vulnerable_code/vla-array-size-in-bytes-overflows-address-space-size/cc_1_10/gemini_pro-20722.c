//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    // Initialize variables
    char buffer[MAX_SIZE];
    int i, j, k;
    int signature_count = 0;
    int infected = 0;

    // Get the number of signatures
    scanf("%d", &signature_count);

    // Get each signature
    char signatures[signature_count][MAX_SIZE];
    for (i = 0; i < signature_count; i++) {
        scanf("%s", signatures[i]);
    }

    // Get the file to be scanned
    scanf("%s", buffer);

    // Scan the file for each signature
    for (i = 0; i < signature_count; i++) {
        for (j = 0; j < strlen(buffer) - strlen(signatures[i]); j++) {
            for (k = 0; k < strlen(signatures[i]); k++) {
                if (buffer[j + k] != signatures[i][k]) {
                    break;
                }
            }
            if (k == strlen(signatures[i])) {
                infected = 1;
                break;
            }
        }
        if (infected) {
            break;
        }
    }

    // Print the result
    if (infected) {
        printf("infected\n");
    } else {
        printf("clean\n");
    }

    return 0;
}