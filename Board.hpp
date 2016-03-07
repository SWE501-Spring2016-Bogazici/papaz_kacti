//
//  Board.hpp
//  KingEscape
//
//  Created by Arda Oğulcan Pektaş on 29/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "Player.hpp"
#include "Deck.hpp"

struct Board {
    Deck deck;
    Player player[4];
    
    
    unsigned int turn=0;
    
    Board();
    
    bool ReleaseTheCracken();
    
    void removeKings();
    void dealCards();
    bool isFinished();
    int getLooser();

    void log(string message="");
    string print();
};

#endif /* Board_hpp */
