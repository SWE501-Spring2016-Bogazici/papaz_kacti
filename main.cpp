//
//  main.cpp
//  KingEscape
//
//  Created by Arda Oğulcan Pektaş on 29/02/16.
//  Copyright © 2016 Arda Oğulcan Pektaş. All rights reserved.
//

#include <iostream>
#include "Board.hpp"

int main(int argc, const char * argv[]) {


    Board board = Board();

    bool gameOver=board.ReleaseTheCracken();

    if(gameOver) {
        int looser = board.getLooser();
        cout << endl <<"--------------------";
        cout <<endl << "Game Over"<<endl;
        cout << "Looser: Player "<< looser <<endl<<endl;

        board.print();
        cout << endl;

    }

    
}
