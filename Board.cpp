//
//  Board.cpp
//  KingEscape
//
//  Created by Arda Oğulcan Pektaş on 29/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
Board::Board () {
    
    deck = Deck();
    
    removeKings();
    
}

bool Board::ReleaseTheCracken() {
    
    deck.Shuffle();
    dealCards();

    cout <<endl<< "Deck [";
    deck.Print();
    cout << "]"<<endl<<endl;

    print();

    for(auto& p:player) {
        p.removeDuplicates();
    }

    cout << endl << "Duplicates Cleared" << endl << endl;
    print();

    cout << endl << "--------------------";
    cout << endl << "Let the Game Begin"<<endl<<endl;


    turn=0; // 2.oyuncu 1.oyuncudan çekecek önce

    bool finished=isFinished();

    while (!finished) {
        turn ++;
        turn = turn > 3 ? 0 : turn;
        Player& curPlayer = player[turn];

        //if(curPlayer.isEmpty()) continue;

        int prevTurn=turn-1;
        prevTurn = prevTurn<0 ? 3 :prevTurn;
        Player& prevPlayer = player[prevTurn];

        while (prevPlayer.isEmpty()) {
            prevTurn--;
            if(prevTurn==turn) continue;
            prevTurn = prevTurn < 0 ? 3 : prevTurn;
            prevPlayer = player[prevTurn];
        }

        Card givenCard=prevPlayer.giveCard();

        curPlayer.addCard(givenCard);
        curPlayer.removeDuplicates();

        cout << "Player "<< turn << " draws Card ";
        givenCard.Print();
        cout << " from Player " << prevTurn;
        cout <<endl;

        finished = isFinished();

    }

    return true;
}

void Board::removeKings() {
    unsigned int kingCount=0;
    for(auto& card:deck.card) {
        if(card.rank==13) {
            card = Card(-1);
            kingCount++;
            if(kingCount==3) break;
        }
    }
}
void Board::dealCards() {

    for(auto& card:deck.card) {
        if(card.rank==0) continue;
        turn = turn==4 ? 0 : turn;

        player[turn].addCard(card);
        turn++;
    };
    turn=0;
}
bool Board::isFinished() {

    unsigned int playerCount=0;

    for(auto& p:player) {
        playerCount += !p.isEmpty() ? 1:0;
    }

    return playerCount<=1;
}
int Board::getLooser() {
    for (int i = 0; i < 4; ++i) {
        Player tempPlayer = player[i];
        if(!tempPlayer.isEmpty()) return i;
    }

}

string Board::print() {
    string msgString = "";

    cout << "Players ["<<endl;
    for (int i = 0; i < 4; ++i) {
        Player tempPlayer = player[i];
        if(tempPlayer.isEmpty()) continue;
        cout << "   Player " << i << ": ";
        tempPlayer.print();
        cout << endl;
    }
    cout << "]";
    return "";
}
void Board::log(string message) {
    
}
