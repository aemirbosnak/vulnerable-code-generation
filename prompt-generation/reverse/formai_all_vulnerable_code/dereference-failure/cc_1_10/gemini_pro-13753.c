//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9
#define NR 3
#define NC 3

int a[N][N];

int
square(int i, int j)
{
	return (i/NR)*NR + j/NC;
}

int
valid(int i, int j, int y)
{
	int x;

	for(x=0; x<N; x++){
		if(a[i][x] == y || a[x][j] == y)
			return 0;
	}

	int ii = (i/NR)*NR;
	int jj = (j/NC)*NC;
	for(x=0; x<NR; x++){
		for(int y=0; y<NC; y++){
			if(a[ii+x][jj+y] == y)
				return 0;
		}
	}

	return 1;
}

void
solve(void)
{
	int i, j, y;

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(a[i][j] != 0)
				continue;
			for(y=1; y<=N; y++){
				if(valid(i, j, y)){
					a[i][j] = y;
					solve();
					a[i][j] = 0;
				}
			}
			return;
		}
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%2d", a[i][j]);
			if(j == NC-1 || j == 2*(NC-1))
				printf(" ");
		}
		if(i == NR-1 || i == 2*(NR-1))
			printf("\n");
		else
			printf("\n  ");
	}
	exit(0);
}

int
main(int argc, char **argv)
{
	int i, j;

	if (argc < 2)
		return 1;
	for(i=0, j=1; j<argc; i++, j++){
		a[i/N][i%N] = atoi(argv[j]);
	}

	solve();
	return 0;
}