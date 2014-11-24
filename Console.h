#ifndef _Console_h_
#define _Console_h_

#include <iomanip>
#include <iostream>
using namespace std;

#include "Command.h"
#include "Player.h"
#include "PlayerList.h"

const string kcsPlayerFileName = "players.txt";
const string kcsYearFileName = "current_year.txt";

class Console
{
public:
    Console() : player_list( kcsPlayerFileName ) {}

    void run_console();

private:
    PlayerList player_list;

    void display_console() const;
    void process_command( Command & c ) const;

    void add_player( const string & player_file, const string & name ) const;
    void edit_player( const string & player_file, const Player * p ) const;
    void print_player( const Player * p ) const;
    int process_age( const string & current_year_file, int birth_year ) const;
    int process_category( int & age ) const;

    void editplayer( const string & player_file, const string & name ) const;
    void display_category( int & cat, const string & output_file ) const;

};

#endif
