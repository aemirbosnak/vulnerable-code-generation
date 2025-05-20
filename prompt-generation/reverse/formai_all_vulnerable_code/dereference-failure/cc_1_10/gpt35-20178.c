//FormAI DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// function to generate QR code
void generateQRCode(char arr[][MAX_SIZE], int size) {
  // add border to QR code
  for(int i=0; i<size+2; i++) {
    arr[0][i] = '-';
    arr[size+1][i] = '-';
    arr[i][0] = '|';
    arr[i][size+1] = '|';
  }

  // encode data in QR code
  for(int i=1; i<=size; i++) {
    for(int j=1; j<=size; j++) {
      if((i+j)%2 == 0) {
        arr[i][j] = '#';
      } else {
        arr[i][j] = ' ';
      }
    }
  }

  // print QR code
  for(int i=0; i<size+2; i++) {
    for(int j=0; j<size+2; j++) {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int size;
  char arr[MAX_SIZE][MAX_SIZE];

  printf("Enter size of QR code (maximum is %d): ", MAX_SIZE);
  scanf("%d", &size);

  // check if size is within allowed limit
  if(size <= MAX_SIZE) {
    // generate QR code
    generateQRCode(arr, size);
  } else {
    printf("Error: Size is too large. Maximum size is %d.\n", MAX_SIZE);
  }

  return 0;
}