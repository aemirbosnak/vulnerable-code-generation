//FormAI DATASET v1.0 Category: Data recovery tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to recover deleted data */
void recoverData(char *filename) {

    FILE *fptr;
    char ch, *temp;
    int fileSize, i = 0, j = 0, count = -1, check = 0;

    /* Open file in binary mode */
    fptr = fopen(filename, "rb");

    /* Return if file not opened successfully */
    if(fptr == NULL) {
        printf("Error in opening file!\n");
        return;
    }

    /* Get size of file */
    fseek(fptr, 0, SEEK_END);
    fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    
    /* Allocate memory to store data */
    temp = (char*) malloc(fileSize * sizeof(char));

    /* Read data from file */
    while((ch = fgetc(fptr)) != EOF) {
        temp[i] = ch;
        i++;
    }

    /* Check for deleted data */
    for(i = 0; i < fileSize; i++) {
        if(temp[i] == '\0') {
            count++;
            check = 1;
            continue;
        }
        else {
            if(check) {
                printf("Deleted Data %d: ", count);
                for(j = i - count - 1; j < i; j++)
                    printf("%c", temp[j]);
                printf("\n");
                count = -1;
                check = 0;
            }
        }
    }

    /* If no deleted data found */
    if(!check) {
        printf("No deleted data found!\n");
    }

    /* Free dynamically allocated memory */
    free(temp);

    /* Close file */
    fclose(fptr);
}

int main() {
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    recoverData(filename);

    return 0;
}