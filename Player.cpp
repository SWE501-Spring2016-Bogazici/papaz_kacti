//
//  Player.cpp
//  KingEscape
//
//  Created by Arda Oğulcan Pektaş on 29/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#include "Player.hpp"
#include "iostream"

using namespace std;

Player::Player () {
    srandom(time(NULL));
}
int Player::findEmptyPosition() {
    int i=0;
    while(i<13) {
        if(card[i].rank==0) {
            return i;
        }
        i++;
    }

}

void Player::addCard(Card& c) {
    card[findEmptyPosition()] = c;

}
void Player::removeCard(Card& c) {
    c = Card(-1);
}
Card Player::giveCard() {


    int randomPosition = random()%(12+1);


    if(card[randomPosition].rank==0) {
        return giveCard();
    }
    else {

        Card tempCard=card[randomPosition];
        removeCard(card[randomPosition]);
        return tempCard;
    }

}

void Player::removeDuplicates() {

    for (auto& firstCard:card) {
        if(firstCard.rank==0) continue;
        for (auto& secondCard:card) {
            if(secondCard.rank==firstCard.rank && secondCard.suit==firstCard.suit) continue;
            if(secondCard.rank==0) continue;
            if(firstCard.rank == secondCard.rank) {
                removeCard(firstCard);
                removeCard(secondCard);
            }
        }
    }

}

bool Player::isEmpty(){
    for(auto& c:card) {
        if(c.rank!=0) return false;
    }
    return true;
}

string Player::print() {
    string msgString = "";
    for(auto& item:card) {
        if(item.rank==0) continue;
        item.Print();
        cout << " ";
    }
    return msgString;
}