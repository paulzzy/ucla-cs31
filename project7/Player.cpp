//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    
    // TODO: randomly roll the die and adjust the score for the current round accordingly
    //  increase the score if the amount matches this round's value
    int Player::roll( )
    {
        // stubbed out for now...
        return( 0 );
    }

    // TODO: allow for cheating
    // use the amount argument as this Player's roll
    // adjust the score for the current round accordingly
    // increase the score if the amount matches this round's value
    int Player::roll( int amount )
    {
        // stubbed out for now...
        return( 0 );
    }
    
    // TODO: set the current round and reset the player's score to 0
    void Player::setRound( int round )
    {
        // stubbed out for now...
    }
    
    // TODO: return the score member variable
    int  Player::getScore( ) const
    {
        // stubbed out for now...
        return( 0 );
    }
    
    
}
