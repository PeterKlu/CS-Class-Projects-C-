/**********************************************************************
 *
 * CISC 4090 (Theory of Computation)
 * Spring, 2020
 *
 * Project 2: A Turing Machine Emulator
 *
 * Implementation file for TM class
 *
 * Author: Peter Klutchko
 * Date:   3/26/20
 *
 **********************************************************************/

// Thanks for the extra time again!

#include "TM.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// This function overloads the >> operator
istream& operator>>(istream &is, Table_entry& entry)
{
    string input;
    is >> input;
    sscanf(input.c_str(), "(%d, %c, %c)", &entry.new_state, &entry.new_char, &entry.direction);
    return is;
}

// output the contents of a Table_entry
ostream& operator<<(ostream &os, const Table_entry& entry)
{
   return os << '(' << entry.new_state << ", " << entry.new_char << ", " << entry.direction << ") ";
}


// Initializes the TM Object by reading data from a data file   
TM::TM(ifstream &ifs)
{
    ifs >> num_states >> sigma >> gamma;
    blank = gamma[gamma.length()-1];
    Table_entry pentry; // A placeholder Table-entry variable for initializing the state_table

    for (int i = 0; i < num_states; ++i) {
        vector<Table_entry> elements;
	for(long unsigned int j = 0; j < gamma.length(); ++j) {
	    ifs >> pentry;
	    elements.push_back(pentry);
	}
	state_table.push_back(elements);
    }
}

// Prints a description of the TM
void TM::describe()
{
    cout << "Sigma: " << sigma << endl;
    cout << "Gamma: " << gamma << endl;
    cout << "Blank Character: " << gamma[gamma.length()-1] << endl;
    cout << "Transition Table" << endl;

    for (int i = 0; i < num_states; ++i) {
	for (long unsigned int j = 0; j < gamma.length(); ++j) {
	    cout << state_table[i][j];
	}
	cout << endl;
    }
}

// Traces an input string and will return true if the TM halts
bool TM::trace(string& in_string)
{
    int curS = 1; // Represents the curent state
    int curP = 0; // Represents the current position
    string tp = in_string + blank; // Represents the tape
    char curC = tp[curP]; // Represents the current char
    
    while (curS != 0) {
	print_config(curS, curP, tp); 
	curC = tp[curP];
	size_t gamma_index = gamma.find(curC);
	Table_entry trans = state_table[curS-1][gamma_index];
	if (trans.new_state == -1) {
	    return false;
	}
	else {
	    curS = trans.new_state;
	    tp[curP] = trans.new_char;

	    if (trans.direction == 'L') {
		--curP;
	    }
	    if (trans.direction == 'R') {
		++curP;
	    }
	}
	
    }

    return true;
}

// Prints out the TM
void TM::print_config(int state, unsigned int pos, 
                      const string& in_string)
{
    int comparablePos = static_cast<int>(pos); // So I can actually compare an integer with pos without typecasting in multiple lines
    for (int i = 0; i < static_cast<int>(in_string.length()); ++i) {
	if (i == comparablePos) {
	    cout << "q" << state << in_string[i];
	}
	if (i != comparablePos) {
	    cout << in_string[i];
	}
    }
    cout << endl;
}

