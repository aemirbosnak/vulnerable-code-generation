//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Welcome to the world of coding, where every code tells a story!");
  
  // Let's create a surreal Huffman tree of magical creatures
  struct node {
    char symbol;
    int freq;
    struct node *left;
    struct node *right;
  };
  
  struct node *root = (struct node*)malloc(sizeof(struct node));
  root->symbol = 'O';
  root->freq = 10;
  
  struct node *left_child = (struct node*)malloc(sizeof(struct node));
  left_child->symbol = '*';
  left_child->freq = 5;
  
  struct node *left_grandchild = (struct node*)malloc(sizeof(struct node));
  left_grandchild->symbol = '$';
  left_grandchild->freq = 3;
  left_grandchild->left = NULL;
  left_grandchild->right = NULL;
  
  struct node *right_grandchild = (struct node*)malloc(sizeof(struct node));
  right_grandchild->symbol = '@';
  right_grandchild->freq = 2;
  right_grandchild->left = NULL;
  right_grandchild->right = NULL;
  
  left_child->left = left_grandchild;
  left_child->right = right_grandchild;
  
  struct node *right_child = (struct node*)malloc(sizeof(struct node));
  right_child->symbol = '^';
  right_child->freq = 5;
  right_child->left = NULL;
  right_child->right = NULL;
  
  root->left = left_child;
  root->right = right_child;
  
  printf("\nBehold! The surreal Huffman tree of magical creatures:\n");
  printf("     %c     \n", root->symbol);
  printf("    / \\    \n");
  printf("   /   \\   \n");
  printf("  %c     %c  \n", left_child->symbol, right_child->symbol);
  printf(" / \\     \n");
  printf("%c   %c   \n", left_grandchild->symbol, right_grandchild->symbol);
  
  // Let's encode a secret message using our magical Huffman tree
  char message[] = "abacabadabacaba";
  printf("\nLet's encode a secret message: %s\n", message);
  
  int encoded_message_length = 0;
  char *encoded_message = (char*)malloc(strlen(message));
  
  for(int i=0; i<strlen(message); i++) {
    switch(message[i]) {
      case 'a':
        encoded_message[i] = '0';
        encoded_message_length++;
        break;
      case 'b':
        encoded_message[i] = '10';
        encoded_message_length += 2;
        break;
      case 'c':
        encoded_message[i] = '11';
        encoded_message_length += 2;
        break;
      default:
        printf("Error: Invalid symbol!\n");
        exit(1);
    }
  }

  printf("The encoded message is: %s\n", encoded_message);
  printf("The length of the encoded message is: %d bits\n", encoded_message_length);

  // Time to decode the secret message using our magical Huffman tree
  printf("\nNow, let's decode the secret message:\n");
  struct node *current_node = root;
  
  for(int i=0; i<strlen(encoded_message); i++) {
    if(encoded_message[i] == '0') {
      current_node = current_node->left;
    }
    else {
      current_node = current_node->right;
    }
    
    if(current_node->left == NULL && current_node->right == NULL) {
      printf("%c", current_node->symbol);
      current_node = root;
    }
  }
  
  printf("\nCongratulations! You have successfully decoded the secret message.\n");
  printf("Keep exploring the world of surreal coding!\n");
  
  return 0;
}