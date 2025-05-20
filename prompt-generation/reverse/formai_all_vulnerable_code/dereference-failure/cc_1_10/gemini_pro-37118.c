//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calcula a distância de Levenshtein entre duas strings
int levenshtein(char *s1, char *s2) {
  // Cria uma matriz para armazenar as distâncias de Levenshtein parciais
  int **d = malloc((strlen(s1) + 1) * sizeof(int *));
  for (int i = 0; i < strlen(s1) + 1; i++) {
    d[i] = malloc((strlen(s2) + 1) * sizeof(int));
  }

  // Inicializa a primeira linha e coluna da matriz
  for (int i = 0; i < strlen(s1) + 1; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j < strlen(s2) + 1; j++) {
    d[0][j] = j;
  }

  // Calcula as distâncias de Levenshtein parciais
  for (int i = 1; i < strlen(s1) + 1; i++) {
    for (int j = 1; j < strlen(s2) + 1; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
    }
  }

  // Retorna a distância de Levenshtein entre as duas strings
  return d[strlen(s1)][strlen(s2)];
}

// Calcula e imprime a distribuição de frequências das distâncias de Levenshtein
void levenshtein_distribution(char *s1, char *s2, int n) {
  // Gera um array para armazenar as frequências das distâncias de Levenshtein
  int *freq = calloc(n + 1, sizeof(int));

  // Calcula as distâncias de Levenshtein para n pares de strings gerados aleatoriamente
  for (int i = 0; i < n; i++) {
    char *random_s1 = malloc(strlen(s1) * sizeof(char));
    char *random_s2 = malloc(strlen(s2) * sizeof(char));
    for (int j = 0; j < strlen(s1); j++) {
      random_s1[j] = s1[rand() % strlen(s1)];
    }
    for (int j = 0; j < strlen(s2); j++) {
      random_s2[j] = s2[rand() % strlen(s2)];
    }
    freq[levenshtein(random_s1, random_s2)]++;
  }

  // Imprime a distribuição de frequências
  printf("Distribuição de frequências das distâncias de Levenshtein:\n");
  for (int i = 0; i < n + 1; i++) {
    printf("%d: %d\n", i, freq[i]);
  }
}

int main() {
  // Define as duas strings
  char *s1 = "abacate";
  char *s2 = "banana";

  // Calcula e imprime a distância de Levenshtein entre as duas strings
  printf("Distância de Levenshtein entre \"%s\" e \"%s\": %d\n", s1, s2, levenshtein(s1, s2));

  // Define o número de pares de strings gerados aleatoriamente
  int n = 1000;

  // Calcula e imprime a distribuição de frequências das distâncias de Levenshtein
  levenshtein_distribution(s1, s2, n);

  return 0;
}