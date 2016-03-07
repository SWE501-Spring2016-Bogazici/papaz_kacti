//
//  Deck.cpp
//  Clock Solitaire
//
//  Created by Arda Oğulcan Pektaş on 23/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Deck.hpp"

using namespace std;

Deck::Deck() {
    for(unsigned int i =0;i<52;i++) {
        card[i]= Card(i);
    }
}
void Deck::Shuffle(int seed) {

    if(seed) { srandom(seed);}
    else srandom(time(NULL));
    for (int i=51;i>0;i--) {
        int idx = random()%(i+1);
        Card temp = card[idx];
        
        card[idx]=card[i];
        card[i] = temp;
    }
}
void Deck::Print() {
    for(auto& item:card) {
        if(item.rank==0) continue;
        item.Print();
        cout <<" ";
    }
}