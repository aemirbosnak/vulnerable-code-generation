//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_VERSION 1
#define QR_SIZE 21
#define QR_MARGIN 4

typedef unsigned char qr_byte_t;

void qr_init(qr_byte_t *qr_code) {
  memset(qr_code, 0, (QR_SIZE + 2 * QR_MARGIN) * (QR_SIZE + 2 * QR_MARGIN));
  qr_code += QR_MARGIN * (QR_SIZE + 2 * QR_MARGIN) + QR_MARGIN;
}

void qr_set_finder_patterns(qr_byte_t *qr_code) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + j] = 0xFF;
      qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + QR_SIZE + 1 + j] = 0xFF;
      qr_code[(QR_SIZE + 1 + j) * (QR_SIZE + 2 * QR_MARGIN) + i] = 0xFF;
      qr_code[(QR_SIZE + 1 + j) * (QR_SIZE + 2 * QR_MARGIN) + QR_SIZE + 1 + i] = 0xFF;
    }
  }
}

void qr_set_alignment_patterns(qr_byte_t *qr_code) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + j] = 0xFF;
      qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + QR_SIZE + 1 + j] = 0xFF;
      qr_code[(QR_SIZE + 1 + j) * (QR_SIZE + 2 * QR_MARGIN) + i] = 0xFF;
      qr_code[(QR_SIZE + 1 + j) * (QR_SIZE + 2 * QR_MARGIN) + QR_SIZE + 1 + i] = 0xFF;
    }
  }
}

void qr_set_timing_patterns(qr_byte_t *qr_code) {
  for (int i = 8; i < QR_SIZE + 8; i++) {
    qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + 6] = ((i % 2) == 0) ? 0xFF : 0;
    qr_code[6 * (QR_SIZE + 2 * QR_MARGIN) + i] = ((i % 2) == 0) ? 0xFF : 0;
  }
}

void qr_set_data_bits(qr_byte_t *qr_code, const char *data) {
  int bit_index = 0;
  int data_index = 0;
  int mask_bit = 0;

  while (bit_index < QR_SIZE * QR_SIZE) {
    if (data[data_index] >> mask_bit & 1) qr_code[bit_index] = 0xFF;

    bit_index++;

    if (++mask_bit == 8) {
      mask_bit = 0;
      data_index++;
    }
  }
}

void qr_set_error_correction_bits(qr_byte_t *qr_code) {
  // TODO: Implement error correction
}

void qr_print(qr_byte_t *qr_code) {
  for (int i = 0; i < QR_SIZE + 2 * QR_MARGIN; i++) {
    for (int j = 0; j < QR_SIZE + 2 * QR_MARGIN; j++) {
      printf("%c", qr_code[i * (QR_SIZE + 2 * QR_MARGIN) + j] ? 'X' : ' ');
    }
    printf("\n");
  }
}

int main(void) {
  qr_byte_t qr_code[(QR_SIZE + 2 * QR_MARGIN) * (QR_SIZE + 2 * QR_MARGIN)];

  qr_init(qr_code);
  qr_set_finder_patterns(qr_code);
  qr_set_alignment_patterns(qr_code);
  qr_set_timing_patterns(qr_code);
  qr_set_data_bits(qr_code, "Hello, world!");
  qr_set_error_correction_bits(qr_code);
  qr_print(qr_code);

  return 0;
}