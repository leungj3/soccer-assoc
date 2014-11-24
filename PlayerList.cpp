#include "PlayerList.h"


PlayerList::PlayerList( const string & player_list_file )
{
    ifstream f( player_list_file.c_str() );

    Player player;
    while (f >> player) {
        m_players[ player.name() ] = player;
    }
}

void PlayerList::editplayer( const string & player_file, const string & name ) const
{
    ofstream f( player_file.c_str() );

    for ( PlayerMap::const_iterator itr = m_players.begin();
            itr != m_players.end(); ++itr )
    {
        if( itr->first != name )
        {
            f << itr->first << ' '
                    << itr->second.birth_year() << ' '
                    << itr->second.category() << ' '
                    << itr->second.registration()
                    << endl;
        }
    }
    f.close();
}


void PlayerList::display_category( int & cat, const string & output_file ) const
{
    ofstream f( output_file.c_str() );

    for ( PlayerMap::const_iterator itr = m_players.begin();
            itr != m_players.end(); ++itr )
    {
        if( itr->second.category() == cat )
        {
            cout << "  " << itr->first << ' '
                    << itr->second.birth_year() << ' '
                    << itr->second.category() << ' '
                    << itr->second.registration()
                    << endl;
            cout << "Writing to file...";
            f << itr->first << ' '
                    << itr->second.birth_year() << ' '
                    << itr->second.category() << ' '
                    << itr->second.registration() << endl;
            cout << endl;
        }
    }
    f.close();
    cin.get();
}
