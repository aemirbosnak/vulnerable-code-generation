//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void print_matrix(int *m, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", m[i * cols + j]);
		printf("\n");
	}
}

void transpose_matrix(int *m, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			int tmp = m[i * cols + j];
			m[i * cols + j] = m[j * cols + i];
			m[j * cols + i] = tmp;
		}
	}
}

void multiply_matrices(int *a, int *b, int *c, int rows1, int cols1, int rows2, int cols2)
{
	if (cols1 != rows2)
		return;

	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			c[i * cols2 + j] = 0;
			for (int k = 0; k < cols1; k++)
				c[i * cols2 + j] += a[i * cols1 + k] * b[k * cols2 + j];
		}
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int c[ROWS * COLS];

	printf("Original matrices:\n");
	print_matrix(a, ROWS, COLS);
	print_matrix(b, ROWS, COLS);

	transpose_matrix(a, ROWS, COLS);
	transpose_matrix(b, ROWS, COLS);

	printf("\nTransposed matrices:\n");
	print_matrix(a, ROWS, COLS);
	print_matrix(b, ROWS, COLS);

	multiply_matrices(a, b, c, ROWS, COLS, ROWS, COLS);

	printf("\nMultiplied matrix:\n");
	print_matrix(c, ROWS, COLS);

	return 0;
}