#ifndef _PlayerList_h_
#define _PlayerList_h_

#include <fstream>
#include <map>
#include <string>
using namespace std;

#include "Player.h"

class PlayerList
{
public:
    PlayerList( const string & player_list_file );

    const Player * get_player( string name ) const
    {
        PlayerMap::const_iterator itr = m_players.find( name );
        if ( itr == m_players.end() )
            return NULL;
        else
            return &(itr->second);
    }
    void editplayer( const string & player_file, const string & name ) const;
    void display_category( int & cat, const string & output_file ) const;


private:
    typedef map<string, Player> PlayerMap;

    PlayerMap m_players;
};

#endif
