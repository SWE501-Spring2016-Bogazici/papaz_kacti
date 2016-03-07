//
//  Card.cpp
//  Clock Solitaire
//
//  Created by Arda Oğulcan Pektaş on 22/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#include "Card.hpp"
#include <iostream>
#include <string>

using namespace std;

Card::Card(int r,int s) {
    if(r<1 || r>13) {
        
        rank = suit = 0;
        return;
    }
    if(s<1 || s>4) {
        rank = suit = 0;
        return;
    }
    
    rank = r;
    suit = s;
    
    order = (suit-1)*13 + (rank-1);
}
Card::Card(int o) {
    if(o <0 || 0 > 51) {
        rank = suit = 0;
        return;
    }
    
    rank = (o %13) +1;
    suit = (o/13) +1;
    
    order=o;
}
void Card::Print() {
    cout << getRankByNumber(rank) << getSuitByNumber(suit);
}


// Static Functions
string Card::getRankByNumber(int number) {
    switch (number) {
        case 1:
            return "A";
            break;
        case 11:
            return "J";
            break;
        case 12:
            return "Q";
            break;
        case 13:
            return "K";
            break;
        default:
            return to_string(number);
            break;
    }
}
string Card::getSuitByNumber(int number) {
    switch(number) {
        case 1:
            return "♥︎";
            break;
        case 2:
            return "♠︎";
            break;
        case 3:
            return "♦︎";
            break;
        case 4:
            return "♣︎";
            break;
        default:
            return "na";
            break;
    }
}


