#include <iostream>
#include <string>
#include <sstream>

/**
 * A morse code decoder.
 */

using namespace std;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate


/**
 * Decode the morse code `s` and return the text character
 */

string Morse [36] = {"._", "_...", "_._.", "_..",".", ".._.", "__.", "....", "..", ".___", "_._", "._..", "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.", "_____"};
string Letter [36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

string morseCodeToText(string s) {
	string text = "";

	//separate the string with '|'
	istringstream iss(s);
	string word;
	while (getline(iss, word, '|')){

        //if word is blank, print " "
        if (word == ""){
                text = text + " ";
        }
        //if word is not blank, print the according letter
        else{
            for (int i = 0; i < 36; i++){
                if (word == Morse[i]){
                    text = text + Letter[i];
                }
            }
        }
	}

	return text;
}


int main()
{
		string s;
		cin >> s;
		cout << morseCodeToText(s) << '\n';

    return 0;
}
