//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

typedef struct {
  char symbol;
  int freq;
} huff_node;

int compare(const void *a, const void *b) {
  return ((huff_node*)a)->freq - ((huff_node*)b)->freq;
}

void print_nodes(huff_node *nodes, int n) {
  for(int i=0; i<n; i++) {
    printf("Symbol: %c\tFrequency: %d\n", nodes[i].symbol, nodes[i].freq);
  }
}

void huffman_compress(char *input_file) {
  FILE *in_ptr, *out_ptr;
  char buffer[BUFFER_SIZE];
  in_ptr = fopen(input_file, "r");
  out_ptr = fopen("output.bin", "wb");
  if(in_ptr == NULL || out_ptr == NULL) {
    printf("Error opening files\n");
    exit(1);
  }

  // Count frequencies of each symbol
  int freq_array[256] = {0};
  char ch;
  while((ch = fgetc(in_ptr)) != EOF) {
    freq_array[(int)ch]++;
  }

  // Create huff_node array with symbol and frequency
  int node_count = 0;
  huff_node nodes[256];
  for(int i=0; i<256; i++) {
    if(freq_array[i] > 0) {
      nodes[node_count] = (huff_node) { .symbol = (char) i, .freq = freq_array[i]};
      node_count++;
    }
  }

  printf("Initial Node List:\n");
  print_nodes(nodes, node_count);
  
  // Sort nodes in ascending order of frequency
  qsort(nodes, node_count, sizeof(huff_node), compare);
  
  // Huffman coding process
  for(int i=0; i<node_count-1; i++) {
    huff_node *left = &nodes[i];
    huff_node *right = &nodes[i+1];
    huff_node parent = (huff_node) {.symbol = '*', .freq = left->freq + right->freq};
    nodes[i+1] = parent;
    nodes[i] = *left;
    i--;
    // Sort nodes after adding parent node
    qsort(nodes, node_count, sizeof(huff_node), compare);
    node_count--;
  }

  printf("Final Node List:\n");
  print_nodes(nodes, node_count);
  
  // Write Huffman tree to output file
  int tree_size = node_count * 2 - 1;
  fwrite(&tree_size, sizeof(int), 1, out_ptr);
  for(int i=0; i<node_count; i++) {
    fwrite(&nodes[i].symbol, sizeof(char), 1, out_ptr);
    fwrite(&nodes[i].freq, sizeof(int), 1, out_ptr);
  }

  // Compress input file using Huffman coding
  fseek(in_ptr, 0, SEEK_SET);
  char code[256][256] = {'\0'};
  int code_index[256];
  int depth = 0;
  int index = 0;
  int tree_index = 0;
  while((ch = fgetc(in_ptr)) != EOF) {
    for(int i=0; i<tree_size; i++) {
      char symbol;
      fread(&symbol, sizeof(char), 1, out_ptr);
      if(symbol != '*') {
        if(symbol == ch) {
          fwrite(&code_index[ch], sizeof(int), 1, out_ptr);
          index = 0;
          break;
        }
        else {
          depth++;
          continue;
        }
      }
      else {
        if(index == depth) {
          depth--;
          i = code_index[tree_index];
        }
        else if(index > depth) {
          printf("Invalid tree traversal\n");
          exit(1);
        }
        else {
          left:
          fread(&symbol, sizeof(char), 1, out_ptr);
          if(symbol == '*') {
            code[tree_index][index] = '0';
            index++;
            code_index[tree_index] = i;
            fseek(out_ptr, sizeof(int), SEEK_CUR);
            goto left;
          }
          else {
            code[tree_index][index] = '0';
            code_index[tree_index] = i;
            i--;
            depth--;
            continue;
          }
        }
      }
    }
    fseek(out_ptr, sizeof(char) + sizeof(int) * tree_size, SEEK_SET);
    tree_index = (int) ch;
    if(code[tree_index][0] == '\0') {
      printf("Symbol not found\n");
      exit(1);
    }
    fwrite(&code_index[ch], sizeof(int), 1, out_ptr);
    for(int i=0; i<index; i++) {
      fwrite(&code[tree_index][i], sizeof(char), 1, out_ptr);
    }
    index = 0;
    depth = 0;
  }
  fclose(in_ptr);
  fclose(out_ptr);
}

int main() {
  printf("Huffman Encoding Program\n");
  printf("Compressing input.txt...\n");
  huffman_compress("input.txt");
  printf("Compression completed successfully\n");
  return 0;
}