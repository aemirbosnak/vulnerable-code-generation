//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 // Struct to hold element information
struct Element {
    char *name;
    char *symbol;
    int atomic_number;
};

typedef struct Element Element;

// Function to create a new element
Element* new_element(char *n, char *s, int num) {
    Element *e = malloc(sizeof(Element));
    e->name = malloc(strlen(n) + 1);
    e->symbol = malloc(strlen(s) + 1);
    strcpy(e->name, n);
    strcpy(e->symbol, s);
    e->atomic_number = num;
    return e;
}

// Function to free element memory
void free_element(Element *e) {
    free(e->name);
    free(e->symbol);
    free(e);
}

// Function to print all elements in the periodic table
void print_table(Element **table) {
    printf("Periodic Table:\n");
    for (int i = 0; i < 118; i++) {
        printf("%3d %-3s %s\n", table[i]->atomic_number, table[i]->symbol, table[i]->name);
    }
}

// Function to check if user input is valid and return atomic number
int get_atomic_number(char *symbol, Element **table) {
    // If symbol is not 2 capital letters then return -1
    if (strlen(symbol) != 2 || symbol[0] < 'A' || symbol[0] > 'Z' || symbol[1] < 'A' || symbol[1] > 'Z') {
        return -1;
    } else {
        // Search table for matching symbol and return atomic number
        for (int i = 0; i < 118; i++) {
            if (strcmp(symbol, table[i]->symbol) == 0) {
                return table[i]->atomic_number;
            }
        }
        // If symbol not in table then return -1
        return -1;
    }
}

int main() {
    // Create array to hold pointers to elements in periodic table
    Element **table = malloc(sizeof(Element*) * 118);
    // Create elements and add to table array
    table[0] = new_element("Hydrogen", "H", 1);
    table[1] = new_element("Helium", "He", 2);
    table[2] = new_element("Lithium", "Li", 3);
    table[3] = new_element("Beryllium", "Be", 4);
    table[4] = new_element("Boron", "B", 5);
    table[5] = new_element("Carbon", "C", 6);
    table[6] = new_element("Nitrogen", "N", 7);
    table[7] = new_element("Oxygen", "O", 8);
    table[8] = new_element("Fluorine", "F", 9);
    table[9] = new_element("Neon", "Ne", 10);
    table[10] = new_element("Sodium", "Na", 11);
    table[11] = new_element("Magnesium", "Mg", 12);
    table[12] = new_element("Aluminum", "Al", 13);
    table[13] = new_element("Silicon", "Si", 14);
    table[14] = new_element("Phosphorus", "P", 15);
    table[15] = new_element("Sulfur", "S", 16);
    table[16] = new_element("Chlorine", "Cl", 17);
    table[17] = new_element("Argon", "Ar", 18);
    table[18] = new_element("Potassium", "K", 19);
    table[19] = new_element("Calcium", "Ca", 20);
    table[20] = new_element("Scandium", "Sc", 21);
    table[21] = new_element("Titanium", "Ti", 22);
    table[22] = new_element("Vanadium", "V", 23);
    table[23] = new_element("Chromium", "Cr", 24);
    table[24] = new_element("Manganese", "Mn", 25);
    table[25] = new_element("Iron", "Fe", 26);
    table[26] = new_element("Cobalt", "Co", 27);
    table[27] = new_element("Nickel", "Ni", 28);
    table[28] = new_element("Copper", "Cu", 29);
    table[29] = new_element("Zinc", "Zn", 30);
    table[30] = new_element("Gallium", "Ga", 31);
    table[31] = new_element("Germanium", "Ge", 32);
    table[32] = new_element("Arsenic", "As", 33);
    table[33] = new_element("Selenium", "Se", 34);
    table[34] = new_element("Bromine", "Br", 35);
    table[35] = new_element("Krypton", "Kr", 36);
    table[36] = new_element("Rubidium", "Rb", 37);
    table[37] = new_element("Strontium", "Sr", 38);
    table[38] = new_element("Yttrium", "Y", 39);
    table[39] = new_element("Zirconium", "Zr", 40);
    table[40] = new_element("Niobium", "Nb", 41);
    table[41] = new_element("Molybdenum", "Mo", 42);
    table[42] = new_element("Technetium", "Tc", 43);
    table[43] = new_element("Ruthenium", "Ru", 44);
    table[44] = new_element("Rhodium", "Rh", 45);
    table[45] = new_element("Palladium", "Pd", 46);
    table[46] = new_element("Silver", "Ag", 47);
    table[47] = new_element("Cadmium", "Cd", 48);
    table[48] = new_element("Indium", "In", 49);
    table[49] = new_element("Tin", "Sn", 50);
    table[50] = new_element("Antimony", "Sb", 51);
    table[51] = new_element("Tellurium", "Te", 52);
    table[52] = new_element("Iodine", "I", 53);
    table[53] = new_element("Xenon", "Xe", 54);
    table[54] = new_element("Cesium", "Cs", 55);
    table[55] = new_element("Barium", "Ba", 56);
    table[56] = new_element("Lanthanum", "La", 57);
    table[57] = new_element("Cerium", "Ce", 58);
    table[58] = new_element("Praseodymium", "Pr", 59);
    table[59] = new_element("Neodymium", "Nd", 60);
    table[60] = new_element("Promethium", "Pm", 61);
    table[61] = new_element("Samarium", "Sm", 62);
    table[62] = new_element("Europium", "Eu", 63);
    table[63] = new_element("Gadolinium", "Gd", 64);
    table[64] = new_element("Terbium", "Tb", 65);
    table[65] = new_element("Dysprosium", "Dy", 66);
    table[66] = new_element("Holmium", "Ho", 67);
    table[67] = new_element("Erbium", "Er", 68);
    table[68] = new_element("Thulium", "Tm", 69);
    table[69] = new_element("Ytterbium", "Yb", 70);
    table[70] = new_element("Lutetium", "Lu", 71);
    table[71] = new_element("Hafnium", "Hf", 72);
    table[72] = new_element("Tantalum", "Ta", 73);
    table[73] = new_element("Tungsten", "W", 74);
    table[74] = new_element("Rhenium", "Re", 75);
    table[75] = new_element("Osmium", "Os", 76);
    table[76] = new_element("Iridium", "Ir", 77);
    table[77] = new_element("Platinum", "Pt", 78);
    table[78] = new_element("Gold", "Au", 79);
    table[79] = new_element("Mercury", "Hg", 80);
    table[80] = new_element("Thallium", "Tl", 81);
    table[81] = new_element("Lead", "Pb", 82);
    table[82] = new_element("Bismuth", "Bi", 83);
    table[83] = new_element("Polonium", "Po", 84);
    table[84] = new_element("Astatine", "At", 85);
    table[85] = new_element("Radon", "Rn", 86);
    table[86] = new_element("Francium", "Fr", 87);
    table[87] = new_element("Radium", "Ra", 88);
    table[88] = new_element("Actinium", "Ac", 89);
    table[89] = new_element("Thorium", "Th", 90);
    table[90] = new_element("Protactinium", "Pa", 91);
    table[91] = new_element("Uranium", "U", 92);
    table[92] = new_element("Neptunium", "Np", 93);
    table[93] = new_element("Plutonium", "Pu", 94);
    table[94] = new_element("Americium", "Am", 95);
    table[95] = new_element("Curium", "Cm", 96);
    table[96] = new_element("Berkelium", "Bk", 97);
    table[97] = new_element("Californium", "Cf", 98);
    table[98] = new_element("Einsteinium", "Es", 99);
    table[99] = new_element("Fermium", "Fm", 100);
    table[100] = new_element("Mendelevium", "Md", 101);
    table[101] = new_element("Nobelium", "No", 102);
    table[102] = new_element("Lawrencium", "Lr", 103);
    table[103] = new_element("Rutherfordium", "Rf", 104);
    table[104] = new_element("Dubnium", "Db", 105);
    table[105] = new_element("Seaborgium", "Sg", 106);
    table[106] = new_element("Bohrium", "Bh", 107);
    table[107] = new_element("Hassium", "Hs", 108);
    table[108] = new_element("Meitnerium", "Mt", 109);
    table[109] = new_element("Darmstadtium", "Ds", 110);
    table[110] = new_element("Roentgenium", "Rg", 111);
    table[111] = new_element("Copernicium", "Cn", 112);
    table[112] = new_element("Nihonium", "Nh", 113);
    table[113] = new_element("Flerovium", "Fl", 114);
    table[114] = new_element("Moscovium", "Mc", 115);
    table[115] = new_element("Livermorium", "Lv", 116);
    table[116] = new_element("Tennessine", "Ts", 117);
    table[117] = new_element("Oganesson", "Og", 118);

    // Seed random number generator
    srand(time(0));

    // Print intro message
    printf("Welcome to the Periodic Table Quiz!\nCan you guess the element based on its symbol?\n");

    // Loop to ask user for atomic number of random element from table
    int correct_count = 0;
    int incorrect_count = 0;
    while(1) {
        // Choose random element from table
        int index = rand() % 118;
        Element *e = table[index];
        printf("\n%s", e->symbol);
        // Ask user for atomic number
        char input[3];
        printf(": ");
        fgets(input, 3, stdin);
        int guess = atoi(input);
        // Check if guess is correct
        if (guess == e->atomic_number) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Incorrect. The atomic number of %s is %d.\n", e->name, e->atomic_number);
            incorrect_count++;
        }
        // Ask user if they want to continue playing        
        printf("\nPlay again? (y/n): ");
        fgets(input, 3, stdin);
        if (input[0] == 'n') {
            break;
        }
    }

    // Print results
    printf("\nResults: %d correct, %d incorrect.\n", correct_count, incorrect_count);

    // Free element memory
    for (int i = 0; i < 118; i++) {
        free_element(table[i]);
    }
    free(table);

    return 0;
}