#include <iostream>
#include <cctype>

using namespace std;

const int MAXLEN = 50;  // max length for input sequence of characters
const int MAXKEY = 10;  // max length for key



int main()
{
	// to store user inputs
	char s;             // 'e' for encryption, 'd' for decryption
	char text[MAXLEN];  // the sequence of characters to encrypt/decrypt
	char key[MAXKEY];   // the key
	char output[MAXLEN]; // the output

	//first line of input
	cin >> s;
	char c = s;
	int i = 1;
	while (c != '!'){
		cin >> c;
		text [i] = c;
		i += 1;
	}
	int text_n = i - 2;

	//second line of input
	int key_n, j;
	char v;
	cin >> key_n;
	for (j = 1; j <= key_n; ++j){
		cin >> v;
		key[j] = v;
	}
	
	//encryption
	if (s == 'e'){
		for (j = 1; j <= key_n; j++){
			for (i = 1; i <= text_n; i++){
				if (i % key_n == j % key_n){
					if (isupper(text[i])){
						char encrypted = (text[i] - ('A'-'a') - 97) + (key[j] - 65) + 97;
						if (encrypted > 122){
						encrypted -= 26;
						}
						output[i] = encrypted;
					}
					else if (islower(text[i])){
						char encrypted = (text[i] - 97) + (key[j] - 65) +65;
						if (encrypted > 90){
							encrypted -= 26;
						}
						output [i] = encrypted;
					}
					else if (isalpha(text[i]) == 0){
						char encrypted = text[i];
						output[i] = encrypted;
					}
				}
			}
		}
	}

	//decryption
	if (s == 'd'){
		for (j = 1; j <= key_n; j++){
			for (i = 1; i <= text_n; i++){
				if (i % key_n == j % key_n){
					if (isupper(text[i])){
						char decrypted = (text[i] - ('A'-'a') - 97) - (key[j] -65) + 97;
						if (decrypted < 97) {
							decrypted += 26;
						}
						output[i] = decrypted;
					}
					else if (islower(text[i])){
						char decrypted = (text[i] -97) - (key[j] - 65) + 65;
						if (decrypted < 65){
							decrypted += 26;
						}
						output[i] = decrypted;
					}
					else if (isalpha(text[i]) == 0){
						char decrypted = text[i];
						output[i] =decrypted; 
					}
				}
			}
		}
	}

	//print output
	for (i = 1; i <= text_n; ++i){
		cout << output[i];
	}
	cout << "!" << endl;

	return 0;
}

