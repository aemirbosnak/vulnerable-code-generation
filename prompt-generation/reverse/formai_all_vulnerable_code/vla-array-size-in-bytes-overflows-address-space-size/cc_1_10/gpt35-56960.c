//FormAI DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>

void generate_qr_code(int size) {
  char code[size][size];

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      code[i][j] = '.';
    }
  }

  // Generating square positions in the grid
  int squares_num = (size / 7) * (size / 7);
  int square_size = size / 7;
  int squares_x[squares_num];
  int squares_y[squares_num];
  int squares_index = 0;
  for (int i = square_size; i < size; i += 2 * square_size) {
    for (int j = square_size; j < size; j += 2 * square_size) {
      squares_x[squares_index] = i;
      squares_y[squares_index] = j;
      squares_index++;
    }
  }

  // Filling square positions in the grid
  for (int i = 0; i < squares_num; i++) {
    for (int x = squares_x[i] - square_size; x <= squares_x[i] + square_size; x++) {
      for (int y = squares_y[i] - square_size; y <= squares_y[i] + square_size; y++) {
        code[x][y] = 'X';
      }
    }
  }

  // Printing generated QR code
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", code[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int qr_size;
  printf("Enter QR code size: ");
  scanf("%d", &qr_size);

  generate_qr_code(qr_size);

  return 0;
}