//
//  Player.hpp
//  KingEscape
//
//  Created by Arda Oğulcan Pektaş on 29/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp


#include <stdio.h>
#include "Card.hpp"

struct Player {
    Card card[13];
    
    
    Player();
    
    void addCard(Card& c);
    void removeCard(Card& c);
    void removeDuplicates();

    int findEmptyPosition();
    int findFilledPosition();

    Card giveCard();

    bool isEmpty();

    
    string print();
    
    
};

#endif /* Player_hpp */
