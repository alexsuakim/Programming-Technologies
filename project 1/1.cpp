//assignment 1_1

#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x){
	int n, x_reverse, y;
	y = x;
	x_reverse = 0;
	while (x != 0){
		n = x % 10;
		x_reverse = (x_reverse * 10) + n;
		x = x / 10;
	}
	return (y == x_reverse);
}

bool isProduct(int x){
    int n, m = 0;
    for (n = 100; n < 1000; ++n){
        if (x % n == 0){
            if (x / n >= 100 && x / n < 1000){
                m += 1;
            }
        }
    }
    return (m > 0);
}

int main(){
    int M, N, i;
    char opt;
    cin >> M >> N >> opt;
    if (opt == 'b'){
        for (i = M; i < (N + 1); ++i){
            cout << "";
            if (isPalindrome(i) && isProduct(i)){
                cout << i << endl;
            }
        }
    }
    else if (opt == 'p'){
        for (i = M; i < (N + 1); ++i){
            cout << "";
            if (isPalindrome(i)){
                cout << i << endl;
            }
        }
    }
    else if (opt == 't'){
        for (i = M; i < (N + 1); ++i){
            cout << "";
            if (isProduct(i)){
                cout << i << endl;
            }
        }
    }
    return 0;
}

