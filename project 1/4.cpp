#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5

using namespace std;

void DealHand(int cards[]){
	int x;
	cin >> x;
	srand(x);
	for (int i = 0; i < 5; i ++){
		int RNG = rand() % 52;
		cards[i] = RNG;
	}
}

void Number(int x){
	int n = (x + 1) % 13;
	if (n == 1){
		cout << 'A';
	}
	else if (n > 1 && n < 11){
		cout << n;
	}
	else if (n == 11){
		cout << 'J';
	}
	else if (n == 12){
		cout << 'Q';
	}
	else if (n == 0){
		cout << 'K';
	}
}

void Suit(int x){
	int n = x / 13;
	if (n == 0){
		cout << SPADE << " ";
	}
	else if (n == 1){
		cout << HEART << " ";
	}
	else if (n == 2){
		cout << CLUB << " ";
	}
	else if (n == 3){
		cout << DIAMOND << " ";
	}
}

void PrintHand(int cards[]){
	for (int i = 0; i < 5; i++){
		Number(cards[i]);
		Suit(cards[i]);
	}
	cout << endl;
}

bool IsFourOfAKind(int cards[]){
	int match = 0;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			if ((cards[i] + 1) % 13 == (cards[j] + 1) % 13){
				match++;
			}
		}
	}
	if (match == 6){
		return true;
	}
	return false;
}

bool IsFullHouse(int cards[]){
	int match = 0;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			if ((cards[i] + 1) % 13 == (cards[j] + 1) % 13){
				match++;
			}
		}
	}
	if (match == 4){
		return true;
	}
	return false;
}

bool IsFlush(int cards[]){
	int match = 0, suit = cards[0] / 13, comparison;
	for (int i = 1; i < 5; i++){
		comparison = cards[i] / 13;
		if (suit == comparison){
			match++;
		}
	}
	if (match == 4){
		return true;
	}
	return false;
}

bool IsThreeOfAKind(int cards[]){
	int match = 0;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			if ((cards[i] + 1) % 13 == (cards[j] + 1) % 13){
				match++;
			}
		}
	}
	if (match == 3){
		return true;
	}
	return false;
}

bool IsTwoPair(int cards[]){
	int match = 0;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			if ((cards[i] + 1) % 13 == (cards[j] + 1) % 13){
				match++;
			}
		}
	}
	if (match == 2){
		return true;
	}
	return false;
}

bool IsOnePair(int cards[]){
	int match = 0;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			if ((cards[i] + 1) % 13 == (cards[j] + 1) % 13){
				match++;
			}
		}
	}
	if (match == 1){
		return true;
	}
	return false;
}

int main()
{
	int hand[NUMCARDS];   // declare an array of 5 integers to store a hand
	DealHand(hand);
	PrintHand(hand);

	if (IsFourOfAKind(hand)){
		cout << "four of a kind";
	}
	else if (IsFullHouse(hand)){
		cout << "full house";
	}
	else if (IsFlush(hand)){
		cout << "flush";
	}
	else if (IsThreeOfAKind(hand)){
		cout << "three of a kind";
	}
	else if (IsTwoPair(hand)){
		cout << "two pair";
	}
	else if (IsOnePair(hand)){
		cout << "one pair";
	}
	else{
		cout << "others";
	}
	cout << endl;

  return 0;
}

