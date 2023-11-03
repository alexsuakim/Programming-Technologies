#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//define a function that changes all charaters in a string to lowercase
string toLower(string str){
    char newChar;
    string newStr = "";
    int length = str.size();

    //change to lowercase
    for (int i = 0; i < length; i++){
        if (isupper(str[i])){
            newChar = tolower(str[i]);
            newStr = newStr + newChar;
        }
        else{
            newChar = str[i];
            newStr = newStr + newChar;
        }
    }
    //return the lowercase string
    return newStr;
}


int main()
{
    string input = "";
    string pokemon[30];
    int n = -1;

    //take input
    while (input != "???"){
        n++;
        cin >> input;
        pokemon[n] = input;
    }

    //sort by string length
    for (int i = 0; i < n; i++){
        int max = pokemon[i].size();
        int idx = i;

        for (int j = i + 1; j < n; j++){
            if (pokemon[j].size() > max){
                max = pokemon[j].size();
                idx = j;
            }
        }

        //swap if i with the string with the longest length
        if (idx != i){
            string temp = pokemon[i];
            pokemon[i] = pokemon[idx];
            pokemon[idx] = temp;
        }
    }

    //sort by lexicographical order if string length are equal
    for (int i = 0; i < n; i++){
        string lexi_min = toLower(pokemon[i]);
        int idx = i;
        for (int j = i + 1; j < n; j++){
            if (pokemon[i].size() == pokemon[j].size()){
                if (lexi_min > toLower(pokemon[j])){
                    lexi_min = toLower(pokemon[j]);
                    idx = j;
                }
            }
        }

        //swap i with the string that is lexicographically the smallest
        if (idx != i){
            string temp = pokemon[i];
            pokemon[i] = pokemon[idx];
            pokemon[idx] = temp;
        }
    }

    // print the newly ordered array
    for (int i = 0; i < n; i++){
        cout << pokemon[i] << endl;
    }

    return 0;
}

