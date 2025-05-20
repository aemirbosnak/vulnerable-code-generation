//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *romeo, *juliet; // file pointers for Romeo and Juliet scripts
    char line[100];

    // Creating Romeo script file
    romeo = fopen("romeo.txt", "w");
    if (romeo == NULL) {
        printf("Oh Romeo, I cannot create thy script!");
        exit(1);
    }
    printf("Romeo: But soft, what file through yonder path breaks?\n");
    printf("Juliet: It is the script file for Romeo!\n");
    printf("Romeo: Ah, Juliet, I shall write my words of love in here!\n");

    // Romeo writes his first line
    printf("Romeo: O, speak again, bright angel, for thou art\n");
    printf("Juliet: He speaks of me! What sweet words does he write?\n");
    fgets(line, sizeof(line), stdin);
    fprintf(romeo, "%s", line);

    // Juliet creates her script file by copying Romeo's lines
    juliet = fopen("juliet.txt", "w");
    if (juliet == NULL) {
        printf("Alas, fair Romeo, I cannot create my own script!");
        exit(1);
    }
    printf("Juliet: If only I could be with Romeo always!\n");
    printf("Romeo: Fear not, my love, for I have a solution!\n");
    printf("Romeo: I shall copy my lines into thy script file!\n");

    // Copying Romeo's lines into Juliet's script file
    rewind(romeo); // Set file pointer back to the beginning
    while (fgets(line, sizeof(line), romeo) != NULL) {
        fprintf(juliet, "%s", line);
    }

    // Romeo and Juliet both read their scripts and recite their lines
    printf("Romeo: Come, let us read our lines together!\n");
    rewind(romeo);
    rewind(juliet);
    while (fgets(line, sizeof(line), romeo) != NULL) {
        printf("Romeo: %s", line);
    }
    while (fgets(line, sizeof(line), juliet) != NULL) {
        printf("Juliet: %s", line);
    }

    // Closing the files and bidding goodbye
    fclose(romeo);
    fclose(juliet);
    printf("Romeo: Farewell, my dear Juliet. May our love forever be written in these scripts.");
    
    return 0;
}