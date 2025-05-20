//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Morse code tree structure
struct MorseTree
{
    struct MorseTree *dot;  // Pointer to the "dot" branch of the tree
    struct MorseTree *dash; // Pointer to the "dash" branch of the tree
    char value;             // Character value associated with this node
};

// Morse code tree root node
struct MorseTree *morseRoot;

// Function to add a character and its Morse code sequence to the tree
void addMorseSequence(struct MorseTree *root, char character, char *sequence)
{
    int i;
    for (i = 0; i < strlen(sequence); i++)
    {
        // If this is the last character in the sequence, set it as the value of the node
        if (i == strlen(sequence) - 1)
        {
            if (sequence[i] == '.')
            {
                struct MorseTree *dotNode = (struct MorseTree *)malloc(sizeof(struct MorseTree));
                dotNode->dot = NULL;
                dotNode->dash = NULL;
                dotNode->value = character;
                root->dot = dotNode;
            }
            else if (sequence[i] == '-')
            {
                struct MorseTree *dashNode = (struct MorseTree *)malloc(sizeof(struct MorseTree));
                dashNode->dot = NULL;
                dashNode->dash = NULL;
                dashNode->value = character;
                root->dash = dashNode;
            }
        }
        // If this is not the last character in the sequence, keep traversing the tree
        else
        {
            if (sequence[i] == '.')
            {
                if (root->dot == NULL)
                {
                    struct MorseTree *dotNode = (struct MorseTree *)malloc(sizeof(struct MorseTree));
                    dotNode->dot = NULL;
                    dotNode->dash = NULL;
                    dotNode->value = ' ';
                    root->dot = dotNode;
                }
                root = root->dot;
            }
            else if (sequence[i] == '-')
            {
                if (root->dash == NULL)
                {
                    struct MorseTree *dashNode = (struct MorseTree *)malloc(sizeof(struct MorseTree));
                    dashNode->dot = NULL;
                    dashNode->dash = NULL;
                    dashNode->value = ' ';
                    root->dash = dashNode;
                }
                root = root->dash;
            }
        }
    }
}

// Recursive function to convert a text string to Morse code
void textToMorseRecursive(struct MorseTree *root, char *text, int index)
{
    // Base case: we have reached the end of the input string
    if (index == strlen(text))
    {
        printf("\n");
        return;
    }

    // If the current character is a space, print a slash and continue to the next character
    if (text[index] == ' ')
    {
        printf("/");
        textToMorseRecursive(morseRoot, text, index + 1);
        return;
    }

    // Traverse the tree to find the Morse code sequence for this character
    char sequence[10] = "";
    struct MorseTree *currentNode = root;
    while (1)
    {
        if (text[index] == currentNode->value)
        {
            strcat(sequence, " ");
            break;
        }
        else if (text[index] < currentNode->value)
        {
            strcat(sequence, ".");
            currentNode = currentNode->dot;
        }
        else
        {
            strcat(sequence, "-");
            currentNode = currentNode->dash;
        }
    }

    // Recurse on the Morse code sequence
    textToMorseRecursive(morseRoot, text, index + 1);

    // Print the Morse code sequence
    printf("%s", sequence);
}

// Function to convert a text string to Morse code
void textToMorse(char *text)
{
    textToMorseRecursive(morseRoot, text, 0);
}

int main()
{
    // Initialize the Morse code tree
    morseRoot = (struct MorseTree *)malloc(sizeof(struct MorseTree));
    morseRoot->dot = NULL;
    morseRoot->dash = NULL;
    morseRoot->value = ' ';

    addMorseSequence(morseRoot, 'A', ".-");
    addMorseSequence(morseRoot, 'B', "-...");
    addMorseSequence(morseRoot, 'C', "-.-.");
    addMorseSequence(morseRoot, 'D', "-..");
    addMorseSequence(morseRoot, 'E', ".");
    addMorseSequence(morseRoot, 'F', "..-.");
    addMorseSequence(morseRoot, 'G', "--.");
    addMorseSequence(morseRoot, 'H', "....");
    addMorseSequence(morseRoot, 'I', "..");
    addMorseSequence(morseRoot, 'J', ".---");
    addMorseSequence(morseRoot, 'K', "-.-");
    addMorseSequence(morseRoot, 'L', ".-..");
    addMorseSequence(morseRoot, 'M', "--");
    addMorseSequence(morseRoot, 'N', "-.");
    addMorseSequence(morseRoot, 'O', "---");
    addMorseSequence(morseRoot, 'P', ".--.");
    addMorseSequence(morseRoot, 'Q', "--.-");
    addMorseSequence(morseRoot, 'R', ".-.");
    addMorseSequence(morseRoot, 'S', "...");
    addMorseSequence(morseRoot, 'T', "-");
    addMorseSequence(morseRoot, 'U', "..-");
    addMorseSequence(morseRoot, 'V', "...-");
    addMorseSequence(morseRoot, 'W', ".--");
    addMorseSequence(morseRoot, 'X', "-..-");
    addMorseSequence(morseRoot, 'Y', "-.--");
    addMorseSequence(morseRoot, 'Z', "--..");

    // Convert a sample text string to Morse code
    printf("Text to Morse Code:\n");
    textToMorse("HELLO WORLD");

    return 0;
}