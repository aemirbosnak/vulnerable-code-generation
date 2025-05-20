//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//function to encrypt the message
void encryption(char message[], int key) {
    int len = strlen(message);

    //calculating number of rows required in the matrix
    int rows = ceil(len / (float)key);

    //creating 2D matrix
    char matrix[rows][key];

    //filling matrix with message
    int index = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<key; j++) {
            if(index<len) {
                matrix[i][j] = message[index++];
            } else {
                matrix[i][j] = '-';
            }
        }
    }

    //printing matrix
    printf("\nMatrix before encryption:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<key; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    //reading matrix in zigzag pattern
    char* encrypted_msg = (char*) malloc(len * sizeof(char));
    int k=0;
    for(int i=0; i<key; i++) {
        if(i%2 == 0) {
            for(int j=0; j<rows; j++) {
                if(matrix[j][i] != '-') {
                    encrypted_msg[k++] = matrix[j][i];
                }
            }
        } else {
            for(int j=rows-1; j>=0; j--) {
                if(matrix[j][i] != '-') {
                    encrypted_msg[k++] = matrix[j][i];
                }
            }
        }
    }
    encrypted_msg[len] = '\0';

    printf("\nEncrypted message: %s\n", encrypted_msg);
}

int main() {
    char message[100];
    int key;
    printf("\nEnter message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("\nEnter key: ");
    scanf("%d", &key);

    encryption(message, key);

    return 0;
}