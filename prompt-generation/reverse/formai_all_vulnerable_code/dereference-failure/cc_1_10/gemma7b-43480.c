//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the periodic table
char **table = NULL;

// Initialize the periodic table
void initTable() {
  table = (char**)malloc(116 * sizeof(char*));
  for (int i = 0; i < 116; i++) {
    table[i] = (char*)malloc(20 * sizeof(char));
  }
  for (int r = 0; r < 17; r++) {
    for (int c = 0; c < 8; c++) {
      table[r][c] = ' ';
    }
  }
  table[0][0] = 'H';
  table[0][1] = 'He';
  table[1][0] = 'Li';
  table[2][0] = 'Be';
  table[3][0] = 'Na';
  table[4][0] = 'Mg';
  table[5][0] = 'Al';
  table[6][0] = 'Si';
  table[7][0] = 'P';
  table[8][0] = 'S';
  table[9][0] = 'Cl';
  table[10][0] = 'Ar';
  table[11][0] = 'K';
  table[12][0] = 'Ca';
  table[13][0] = 'Sc';
  table[14][0] = 'Ti';
  table[15][0] = 'V';
  table[16][0] = 'Cr';
  table[17][0] = 'Mn';
  table[18][0] = 'Fe';
  table[19][0] = 'Co';
  table[20][0] = 'Ni';
  table[21][0] = 'Cu';
  table[22][0] = 'Zn';
  table[23][0] = 'Ga';
  table[24][0] = 'As';
  table[25][0] = 'Se';
  table[26][0] = 'Br';
  table[27][0] = 'Kr';
  table[28][0] = 'Rb';
  table[29][0] = 'Sr';
  table[30][0] = 'Yb';
  table[31][0] = 'Zr';
  table[32][0] = 'Nb';
  table[33][0] = 'Mo';
  table[34][0] = 'Tc';
  table[35][0] = 'Ru';
  table[36][0] = 'Rh';
  table[37][0] = 'Pd';
  table[38][0] = 'Ag';
  table[39][0] = 'Cd';
  table[40][0] = 'In';
  table[41][0] = 'Sn';
  table[42][0] = 'Sb';
  table[43][0] = 'Te';
  table[44][0] = 'Ba';
  table[45][0] = 'La';
  table[46][0] = 'Ce';
  table[47][0] = 'Pr';
  table[48][0] = 'Nd';
  table[49][0] = 'Pm';
  table[50][0] = 'Sm';
  table[51][0] = 'Eu';
  table[52][0] = 'Gd';
  table[53][0] = 'Tb';
  table[54][0] = 'Dy';
  table[55][0] = 'Ho';
  table[56][0] = 'Er';
  table[57][0] = 'Tm';
  table[58][0] = 'Yb';
  table[59][0] = 'Lu';
  table[60][0] = 'Hf';
  table[61][0] = 'Ta';
  table[62][0] = 'Nb';
  table[63][0] = 'Zr';
  table[64][0] = 'Mo';
  table[65][0] = 'Tc';
  table[66][0] = 'Ru';
  table[67][0] = 'Rh';
  table[68][0] = 'Pd';
  table[69][0] = 'Ag';
  table[70][0] = 'Cd';
  table[71][0] = 'In';
  table[72][0] = 'Sn';
  table[73][0] = 'Sb';
  table[74][0] = 'Te';
  table[75][0] = 'Ba';
  table[76][0] = 'La';
  table[77][0] = 'Ce';
  table[78][0] = 'Pr';
  table[79][0] = 'Nd';
  table[80][0] = 'Pm';
  table[81][0] = 'Sm';
  table[82][0] = 'Eu';
  table[83][0] = 'Gd';
  table[84][0] = 'Tb';
  table[85][0] = 'Dy';
  table[86][0] = 'Ho';
  table[87][0] = 'Er';
  table[88][0] = 'Tm';
  table[89][0] = 'Yb';
  table[90][0] = 'Lu';
  table[91][0] = 'Hf';
  table[92][0] = 'Ta';
  table[93][0] = 'Nb';
  table[94][0] = 'Zr';
  table[95][0] = 'Mo';
  table[96][0] = 'Tc';
  table[97][0] = 'Ru';
  table[98][0] = 'Rh';
  table[99][0] = 'Pd';
  table[100][0] = 'Ag';
  table[101][0] = 'Cd';
  table[102][0] = 'In';
  table[103][0] = 'Sn';
  table[104][0] = 'Sb';
  table[105][0] = 'Te';
  table[106][0] = 'Ba';
  table[107][0] = 'La';
  table[108][0] = 'Ce';
  table[109][0] = 'Pr';
  table[110][0] = 'Nd';
  table[111][0] = 'Pm';
  table[112][0] = 'Sm';
  table[113][0] = 'Eu';
  table[114][0] = 'Gd';
  table[115][0] = 'Tb';
  table[116][0] = 'Dy';
}

// Print the periodic table
void printTable() {
  for (int r = 0; r < 17; r++) {
    for (int c = 0; c < 8; c++) {
      printf("%c ", table[r][c]);
    }
    printf("\n");
  }
}

int main() {
  initTable();
  printTable();
  return 0;
}