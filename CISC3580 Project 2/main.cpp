// Peter Klutchko
// Professor Ammari
// CISC 3580
// 11 November 2018

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int KEY_SIZE = 64; // length of the key
int cipherCheck; // Used to see if the ciphertext has been generated yet
void changeLetter(char &sideChar, int num); // function that changes the letters of the plaintext during encryption
void respOne(char (&DES)[KEY_SIZE], int (&key)[KEY_SIZE]); // function regarding an input of '1'; assigns a letter to a corresponding number for the DES array
void respTwo(char (&DES)[KEY_SIZE], int (&key)[KEY_SIZE]); // function regarding an input of '2'; the encryption function

int main() {
    char DES[KEY_SIZE], encrypt[KEY_SIZE];
    int key[KEY_SIZE];
    int response = -1;
    srand(time(NULL));

    key[0] = -1;
    DES[0] = -1;

    cout << "This project is a DES program." << endl;
    cout << "The program generates an array to represent the 64 bits in the DES plaintext and fills the array with random letters." << endl;
    cout << "A key of the same size is also created at the same time and filled with random numbers." << endl;
    cout << "The array generated is then split into two halves which will go through 16 rounds of encryption." << endl;
    cout << "Each half is also expanded to 48 bits during this process, then back down to 32 afterward." << endl;
    cout << "The array is encrypted by comparing each letter with a number in the key." << endl;

    while (response != 0 && response != 1 && response != 2 && response != 3 && response != 4 && response != 5) {
        cout << "\nSelect an action:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Generate New Plaintext and Key" << endl;
        cout << "2. Encrypt Plaintext" << endl;
        cout << "3. Output Plaintext" << endl;
        cout << "4. Output Key" << endl;
        cout << "5. Output Ciphertext" << endl;
        cout << "Input: ";
        cin >> response;

        if (response == 0)
            break;
        if (response == 1) {
            respOne(DES, key);
            response = -1;
        }
        if (response == 2) {
            if (DES[0] == -1)
                cout << "\nPlaintext not generated yet" << endl << endl;
            else {
                for (int i = 0; i < KEY_SIZE; ++i)
                    encrypt[i] = DES[i];
                respTwo(encrypt, key);
            }
            response = -1;
        }
        if (response == 3) {
            if (DES[0] == -1)
                cout << "\nPlaintext not generated yet" << endl << endl;
            else {
                cout << "\nPlaintext: ";
                for (int i = 0; i < KEY_SIZE; ++i)
                    cout << DES[i];
                cout << endl << endl;
            }
            response = -1;
        }
        if (response == 4) {
            if (DES[0] == -1)
                cout << "\nKey not generated yet" << endl << endl;
            else {
                cout << "\nKey: ";
                for (int i = 0; i < KEY_SIZE; ++i)
                    cout << key[i];
                cout << endl << endl;
            }
            response = -1;
        }
        if (response == 5) {
            if (DES[0] == -1 || cipherCheck == false)
                cout << "\nNo ciphertext has been generated yet" << endl << endl;
            else {
                cout << "\nCiphertext: ";
                for (int i = 0; i < KEY_SIZE; ++i)
                    cout << encrypt[i];
                cout << endl << endl;
            }
            response = -1;

        }

    }



    return 0;

}

void changeLetter(char &sideChar, int num) {
    num = num % 26;

    if ((sideChar + num) > 'z')
        sideChar = (sideChar - 25) + num;
    else
        sideChar += num;


    return;
}

void respOne(char (&DES)[KEY_SIZE], int (&key)[KEY_SIZE]) {
    cipherCheck = false;

    for (int i = 0; i < KEY_SIZE; ++i) {
        DES[i] = rand()% 26;

        switch (DES[i]) {
        case 0:
            DES[i] = 'a';
            break;
        case 1:
            DES[i] = 'b';
            break;
        case 2:
            DES[i] = 'c';
            break;
        case 3:
            DES[i] = 'd';
            break;
        case 4:
            DES[i] = 'e';
            break;
        case 5:
            DES[i] = 'f';
            break;
        case 6:
            DES[i] = 'g';
            break;
        case 7:
            DES[i] = 'h';
            break;
        case 8:
            DES[i] = 'i';
            break;
        case 9:
            DES[i] = 'j';
            break;
        case 10:
            DES[i] = 'k';
            break;
        case 11:
            DES[i] = 'l';
            break;
        case 12:
            DES[i] = 'm';
            break;
        case 13:
            DES[i] = 'n';
            break;
        case 14:
            DES[i] = 'o';
            break;
        case 15:
            DES[i] = 'p';
            break;
        case 16:
            DES[i] = 'q';
            break;
        case 17:
            DES[i] = 'r';
            break;
        case 18:
            DES[i] = 's';
            break;
        case 19:
            DES[i] = 't';
            break;
        case 20:
            DES[i] = 'u';
            break;
        case 21:
            DES[i] = 'v';
            break;
        case 22:
            DES[i] = 'w';
            break;
        case 23:
            DES[i] = 'x';
            break;
        case 24:
            DES[i] = 'y';
            break;
        case 25:
            DES[i] = 'z';
            break;
        }
    }

    cout << "\nPlaintext: ";    // outputs plaintext
    for (int i = 0; i < KEY_SIZE; ++i)
        cout << DES[i];
    cout << endl;
    for (int i = 0; i < KEY_SIZE; ++i) { // assigns numbers to the key // divide the key size by 8 to get the bit amount for the key
        if (i == 0 || i == 8 || i == 16 || i == 24 || i == 32 || i == 40 || i == 48 || i == 56 || i == 64)
            key[i] = rand()% 26;
        else
            key[i] = key[i - 1];
    }
    cout << "Key: ";    // outputs the key
    for (int i = 0; i < KEY_SIZE; ++i) {
        if (i == 0 || i == 8 || i == 16 || i == 24 || i == 32 || i == 40 || i == 48 || i == 56 || i == 64)
            cout << key[i] << " ";
    }
    cout << endl << endl;

    return;
}

void respTwo(char (&DES)[KEY_SIZE], int (&key)[KEY_SIZE]) {
    cipherCheck = true;
    const int USABLE_KEY = 48;
    char* leftSide = new char[48];
    char* rightSide = new char[48];
    int counter = 0, permCounter = 0, switchSide = 0;

    for (int t = 0; t < 16; ++t) {
        cout << "\nRound " << t + 1 << " of encryption executing ...";
        for (int i = 0; i < KEY_SIZE / 2; ++ i) { // the left half of the DES array
            ++permCounter;
            if (counter == 0)
                leftSide[counter] == DES[31];
            else if (counter == KEY_SIZE / 2)
                leftSide[counter] == DES[0];
            else
                leftSide[counter] = DES[i];
            if (permCounter == 5) {
                leftSide[counter] == DES[i + 1];
                permCounter = 0;
            }
            ++counter;
        }

        permCounter = 0;
        counter = 0;

        for (int i = KEY_SIZE / 2; i < KEY_SIZE; ++ i) { // the right half of the DES array
            ++permCounter;
            if (counter == 0)
                rightSide[counter] == DES[31];
            else if (counter == KEY_SIZE / 2)
                rightSide[counter] == DES[0];
            else
                rightSide[counter] = DES[i];
            if (permCounter == 5) {
                rightSide[counter] == DES[i + 1];
                permCounter = 0;
            }
            ++counter;
        }

        if (switchSide % 2 == 0)
            for (int i = 0; i < 48; ++i)
                changeLetter(leftSide[i], key[i]);
        else
            for (int i = 0; i < 48; ++i)
                changeLetter(rightSide[i], key[i]);

         switchSide++;
    }

    for (int i = 0; i < KEY_SIZE / 2; ++i) {
        DES[i] = leftSide[i];
    }

    counter = 0;

    for (int i = KEY_SIZE / 2; i < KEY_SIZE; ++i) {
        DES[i] = rightSide[counter];
        counter++;
    }

    cout << "\n\nCiphertext: ";
    for (int i = 0; i < KEY_SIZE; ++i)
        cout << DES[i];
    cout << endl << endl;

    return;
}
