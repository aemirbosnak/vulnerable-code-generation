//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
// Ada Lovelace's JSON Parser
// A voyage through the ethereal realms of data structures

// Define the celestial bodies of our parser
#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0

// Declare our cosmic variables
typedef struct JSONNode {
  char *key;
  char *value;
  struct JSONNode *next;
  struct JSONNode *child;
} JSONNode;

// Embark on our journey to parse a celestial body
JSONNode *parseJSON(char *json) {
  // Initialize our celestial abode
  JSONNode *root = NULL;
  JSONNode *current = NULL;

  // Commence our exploration
  char *p = json;
  while (*p != '\0') {
    // Seek the celestial key
    if (*p == '"') {
      // Record the coordinates of the key
      char *key = p + 1;
      while (*p != '"') p++;
      *p = '\0';

      // Create a new celestial abode
      JSONNode *node = malloc(sizeof(JSONNode));
      node->key = key;
      node->value = NULL;
      node->next = NULL;
      node->child = NULL;

      // Connect the abode to our cosmic realm
      if (root == NULL) {
        root = node;
      } else {
        current->next = node;
      }
      current = node;
    }

    // Seek the celestial value
    else if (*p == ':') {
      // Advance to the celestial value
      p++;
      while (*p == ' ') p++;

      // Record the celestial value
      char *value = p;
      while (*p != ',' && *p != '}') p++;
      *p = '\0';

      // Bestow the value upon our abode
      current->value = value;
    }

    // Ascend to the celestial parent
    else if (*p == '}') {
      // Retreat to the previous abode
      current = current->child;
    }

    // Traverse the celestial realm
    p++;
  }

  // Return our celestial abode
  return root;
}

// Print the celestial bodies in a legible manner
void printJSON(JSONNode *node) {
  // Traverse the celestial realm
  while (node != NULL) {
    // Print the celestial key
    printf("\"%s\": ", node->key);

    // Print the celestial value
    if (node->value != NULL) {
      printf("\"%s\"", node->value);
    } else if (node->child != NULL) {
      printf("{\n");
      printJSON(node->child);
      printf("}");
    }

    // Ascend to the celestial parent
    printf(",\n");
    node = node->next;
  }
}

// Embark on our celestial voyage
int main() {
  // Obtain the celestial coordinates
  char *json = "{ \"name\": \"Ada Lovelace\", \"age\": 36, \"children\": [\"William\", \"Augusta\"], \"occupation\": \"computer programmer\" }";

  // Parse the celestial body
  JSONNode *root = parseJSON(json);

  // Print the celestial bodies in a legible manner
  printJSON(root);

  return 0;
}