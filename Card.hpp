//
//  Card.hpp
//  Clock Solitaire
//
//  Created by Arda Oğulcan Pektaş on 22/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

using namespace std;

struct Card {
    unsigned int rank;
    unsigned int suit;
    unsigned int order;
    
    Card(int rank,int suit);
    Card(int order = -1);
    void Print();
    
    static string getRankByNumber(int n);
    static string getSuitByNumber(int n);
};

#endif /* Card_hpp */
