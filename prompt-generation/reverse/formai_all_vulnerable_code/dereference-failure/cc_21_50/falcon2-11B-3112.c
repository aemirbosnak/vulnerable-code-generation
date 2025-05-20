//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure to hold information about each element
typedef struct element_info {
    char name[20];
    char symbol[2];
    int atomic_number;
    char electron_configuration[100];
} ElementInfo;

// Function to convert character to uppercase
char toUpper(char c) {
    return (c >= 'a' && c <= 'z')? c - 32 : c;
}

// Function to convert number to symbol
char toSymbol(int num) {
    switch (num) {
        case 1:
            return 'H';
        case 2:
            return 'He';
        case 3:
            return 'Li';
        case 4:
            return 'Be';
        case 5:
            return 'B';
        case 6:
            return 'C';
        case 7:
            return 'N';
        case 8:
            return 'O';
        case 9:
            return 'F';
        case 10:
            return 'Ne';
        case 11:
            return 'Na';
        case 12:
            return 'Mg';
        case 13:
            return 'Al';
        case 14:
            return 'Si';
        case 15:
            return 'P';
        case 16:
            return 'S';
        case 17:
            return 'Cl';
        case 18:
            return 'Ar';
        case 19:
            return 'K';
        case 20:
            return 'Ca';
        case 21:
            return 'Sc';
        case 22:
            return 'Ti';
        case 23:
            return 'V';
        case 24:
            return 'Cr';
        case 25:
            return 'Mn';
        case 26:
            return 'Fe';
        case 27:
            return 'Co';
        case 28:
            return 'Ni';
        case 29:
            return 'Cu';
        case 30:
            return 'Zn';
        case 31:
            return 'Ga';
        case 32:
            return 'Ge';
        case 33:
            return 'As';
        case 34:
            return 'Se';
        case 35:
            return 'Br';
        case 36:
            return 'Kr';
        case 37:
            return 'Rb';
        case 38:
            return 'Sr';
        case 39:
            return 'Y';
        case 40:
            return 'Zr';
        case 41:
            return 'Nb';
        case 42:
            return 'Mo';
        case 43:
            return 'Tc';
        case 44:
            return 'Ru';
        case 45:
            return 'Rh';
        case 46:
            return 'Pd';
        case 47:
            return 'Ag';
        case 48:
            return 'Cd';
        case 49:
            return 'In';
        case 50:
            return 'Sn';
        case 51:
            return 'Sb';
        case 52:
            return 'Te';
        case 53:
            return 'I';
        case 54:
            return 'Xe';
        case 55:
            return 'Cs';
        case 56:
            return 'Ba';
        case 57:
            return 'La';
        case 58:
            return 'Ce';
        case 59:
            return 'Pr';
        case 60:
            return 'Nd';
        case 61:
            return 'Pm';
        case 62:
            return 'Sm';
        case 63:
            return 'Eu';
        case 64:
            return 'Gd';
        case 65:
            return 'Tb';
        case 66:
            return 'Dy';
        case 67:
            return 'Ho';
        case 68:
            return 'Er';
        case 69:
            return 'Tm';
        case 70:
            return 'Yb';
        case 71:
            return 'Lu';
        case 72:
            return 'Hf';
        case 73:
            return 'Ta';
        case 74:
            return 'W';
        case 75:
            return 'Re';
        case 76:
            return 'Os';
        case 77:
            return 'Ir';
        case 78:
            return 'Pt';
        case 79:
            return 'Au';
        case 80:
            return 'Hg';
        case 81:
            return 'Tl';
        case 82:
            return 'Pb';
        case 83:
            return 'Bi';
        case 84:
            return 'Po';
        case 85:
            return 'At';
        case 86:
            return 'Rn';
        case 87:
            return 'Fr';
        case 88:
            return 'Ra';
        case 89:
            return 'Ac';
        case 90:
            return 'Th';
        case 91:
            return 'Pa';
        case 92:
            return 'U';
        case 93:
            return 'Np';
        case 94:
            return 'Pu';
        case 95:
            return 'Am';
        case 96:
            return 'Cm';
        case 97:
            return 'Bk';
        case 98:
            return 'Cf';
        case 99:
            return 'Es';
        case 100:
            return 'Fm';
        case 101:
            return 'Md';
        case 102:
            return 'No';
        case 103:
            return 'Lr';
        case 104:
            return 'Rf';
        case 105:
            return 'Db';
        case 106:
            return 'Sg';
        case 107:
            return 'Bh';
        case 108:
            return 'Hs';
        case 109:
            return 'Mt';
        case 110:
            return 'Ds';
        case 111:
            return 'Rg';
        case 112:
            return 'Cn';
        case 113:
            return 'Uut';
        case 114:
            return 'Uup';
        case 115:
            return 'Uus';
        case 116:
            return 'Uuo';
        case 117:
            return 'Uuh';
        case 118:
            return 'Uus';
        case 119:
            return 'Uuo';
        default:
            return 'X';
    }
}

// Function to get user input and validate it
int getUserInput(char *prompt, char **userInput) {
    printf("%s", prompt);
    fflush(stdout);
    char buffer[100];
    fgets(buffer, 100, stdin);
    int i = 0;
    while (buffer[i]!= '\n') {
        buffer[i] = toUpper(buffer[i]);
        i++;
    }
    buffer[i] = '\0';
    *userInput = buffer;
    return 1;
}

// Function to get element information from user
ElementInfo getElementInfo(ElementInfo *elementInfo) {
    if (elementInfo->name[0] == '\0') {
        return elementInfo[0];
    } else {
        char userInput[100];
        int status = getUserInput("Element Name: ", &userInput);
        if (status == 0) {
            printf("Invalid Input\n");
            return elementInfo[0];
        }
        char symbol[2];
        getUserInput("Element Symbol: ", &symbol);
        elementInfo->name[0] = userInput[0];
        elementInfo->symbol[0] = symbol[0];
        elementInfo->atomic_number = atoi(userInput);
        elementInfo->electron_configuration[0] = '\0';
        return elementInfo[0];
    }
}

// Function to print element information
void printElementInfo(ElementInfo *elementInfo) {
    printf("Element Name: %s\n", elementInfo->name);
    printf("Element Symbol: %c%c\n", elementInfo->symbol[0], elementInfo->symbol[1]);
    printf("Atomic Number: %d\n", elementInfo->atomic_number);
    printf("Electron Configuration: %s\n", elementInfo->electron_configuration);
    printf("\n");
}

// Function to get element information from user
int main() {
    ElementInfo elements[] = {{"H", "H", 1, "1s1"}, {"He", "He", 2, "1s2"}};
    int numElements = sizeof(elements) / sizeof(ElementInfo);
    char userInput[100];

    while (1) {
        printElementInfo(elements);
        printf("Enter 'n' to exit\n");
        if (getUserInput("Choice: ", &userInput) == 0) {
            break;
        }
        if (strcmp(userInput, "n") == 0) {
            break;
        }
        ElementInfo elementInfo = getElementInfo(elements);
        printf("Enter 'y' to print again\n");
        if (getUserInput("Choice: ", &userInput) == 0) {
            break;
        }
        if (strcmp(userInput, "y") == 0) {
            printElementInfo(elements);
        }
    }

    return 0;
}