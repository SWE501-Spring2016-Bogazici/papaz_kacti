//============================================================================
// Name        : papaz.cpp
// Author      : Gokce Yucel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Card {
	int rank;
	int suit;
	int order;

	Card(int r, int s) {

		if (r<1 or r>13) {
			cout << "Invalid Card" << endl;
			rank = suit = 0;
			return;
		}

		rank = r;
		suit = s;
		order = (s-1)*13 + r - 1;
	}

	Card(int n = 0) {

		if (n < 0 or n > 51) {
			cout << "Invalid Card" << endl;
			return;
		}

		rank = (n % 13) + 1;
		suit = (n / 13) + 1;
		order = 0;
	}

	void Print() {

		//cout << "will print this card now" << endl;

		switch(rank) {
			case 1:
				cout << 'A';
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				cout << rank;
				break;
			case 11:
				cout << 'J';
				break;
			case 12:
				cout << 'Q';
				break;
			case 13:
				cout << 'K';
				break;
			default:
				cout << "Invalid Rank " << rank;
				break;
		}

		switch(suit) {
			case 1: cout << "♥︎"; break;
			case 2: cout << "♠"; break;
			case 3: cout << "♦︎"; break;
			case 4: cout << "♣"; break;
		}
		//string status = open ? "(open)" : "(closed)";
		//cout << status << " ";
		cout << ' ';
	}
};

struct Deck {
	Card card[49];
	int top;
	int skipped = 0;

	Deck() {
		for (int i = 0; i < 49; i++) {
			if (skipped < 3 && i > 0 && i % 12 == 0) {
				skipped++;
			}
			card[i] = Card(i + skipped);
		}
		top = 48;
	}

	void Shuffle() {
		for (int i = 48; i>=0; i--) {
			int idx = random() % (i+1);
			Card temp = card[idx];
			card[idx] = card[i];
			card[i] = temp;
		}
		top = 48;
	}

	void Print() {
		cout << "(" << top + 1 << ") ";
		for (int i = 0; i <= top; i++) {
			card[i].Print();
			cout << ' ';
		}
	}

	Card nextCard() {
		if (top >= 0)
			return card[top--];
		else {
			cout << "Deck Empty";
			return card[0];
		}
	}

};

struct Player {
	int index;
	Card hand[25];
	int top;

	Player() {
		top = -1;
	}

	void takeCardFromPlayer(Player& player) {
		cout << "player" << index << " taking card from player" << player.index << endl;

		int playerCardCount = player.cardCount();
		cout << "player" << player.index << " has " << playerCardCount << " cards" << endl;

		// pick random card from player
		int rnd = random() % (playerCardCount);
		Card takenCard = player.hand[rnd];
		cout << "player" << player.index << "'s " << rnd + 1 << "th card is giving away, which is ";
		takenCard.Print();
		cout << endl;

		// add that card to hand
		hand[++top] = takenCard;

		// shift players card
		for (int i = rnd; i <= player.top; i++) {
			player.hand[i] = player.hand[i+1];
		}
		player.top--;

		cout << "now player" << player.index << " has " << player.top + 1 << " cards" << endl;
	}

	void addCardToHand(Card card) {
		if (top > 12) {
			cout << "hand is full!" << endl;
			return;
		}
		hand[++top] = card;
	}

	void printHand() {
		cout << "(" << cardCount() << " cards) ";
		for (int i = 0; i <= top; i++) {
			hand[i].Print();
			cout << ' ';
		}
	}

	int cardCount() {
		return top + 1;
	}

	void findMatches() {
		for (int i = 0; i <= top; i++) {
			if (i == top) return;

			for (int j = i + 1; j <= top; j++) {

				if (hand[i].rank == hand[j].rank) {

					for (int k = i; k<=top; k++) {
						hand[k] = hand[k+1];
					}
					top--;

					for (int k = j-1; k<=top; k++) {
						hand[k] = hand[k+1];
					}
					top--;
					i=0;
				}
			}
		}
	}
};

int main() {
	Deck d;
	srandom(time(0));
	d.Shuffle();
	d.Print();
	int playerCount = 4;
	cout << endl;
	Player player[4];
	int round = 0;

	cout << "game is starting" << endl;

	cout << "dealing cards to " << playerCount << " players" << endl;
	// deal cards to players
	for (int i = 0; i < 49; i++) {
		int playerIndex = i % playerCount;
		player[playerIndex].index = playerIndex;
		player[playerIndex].addCardToHand(d.nextCard());
	}

	cout << "printing each player's hand" << endl;
	// print each player's hand
	for (int i = 0; i < playerCount; i++) {
		cout << "player " << i << "'s hand is :";
		player[i].findMatches();
		player[i].printHand();
		cout << endl;
	}

	return 0;
}
