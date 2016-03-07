//
//  Deck.hpp
//  Clock Solitaire
//
//  Created by Arda Oğulcan Pektaş on 23/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "Card.hpp"

struct Deck {
    Card card[52];
    unsigned int seed;
    
    Deck();
    void Print();
    void Shuffle(int seed=0);
};

#endif /* Deck_hpp */
