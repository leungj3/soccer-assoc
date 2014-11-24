#include "Console.h"

void Console::run_console()
{
    do {
        display_console();

        Command c;
        cin >> c;
        if ( c.is_close() ) return;
        cout << endl;

        process_command( c );

    } while (true);
}

void Console::display_console() const
{
    cout << "Welcome to the Youth Soccer Association player console." << endl
         << "Please enter a command... " << endl << endl
         << "(a)dd a new player  (l)ook up player" << endl
         << "(e)dit an existing player's information" << endl
         << "(g)enerate a list of players  (c)lose console" << endl;
    string separator(20, '-');
    cout << separator << endl
         << "... ";
}

void Console::process_command( Command & c ) const
{
    if ( c.is_add() )
    {
        string name = "invalid";
        cout << "Enter the name of the player you would like to add: " << endl;
        cin >> name;

        add_player( kcsPlayerFileName, name );
        cin.get();

    } else if ( c.is_edit() )
    {
        string name = "invalid";
        cout << "Enter the name of the player you would like to edit: " << endl;
        cin >> name;

        const Player * player = player_list.get_player( name );
        if ( player == NULL ) {
            cout << "Player not found."
	             << endl << endl;
        } else {
            player_list.editplayer( kcsPlayerFileName, name );
            add_player( kcsPlayerFileName, name );
        }
        cin.get();

    } else if ( c.is_lookup() )
    {
        string name = "invalid";
        cout << "Enter the name of the player you would like to lookup: " << endl;
        cin >> name;

        const Player * player = player_list.get_player( name );
        if ( player == NULL ) {
            cout << "Player not found."
	             << endl << endl;
        } else {
            print_player( player );
        }
        cin.get();

    } else if ( c.is_generate() )
    {
        int cat;
        cout << "Which category would you like to see?" << endl
             << "U(17), U(14), U(12), U(10), U(8), U(6)..." << endl;
        cin >> cat;

        string output_file;
        cout << "Please type the name of the output file you would like to print the players to: " << endl;
        cin >> output_file;

        player_list.display_category( cat, output_file );


    } else
    {
        cout << "ERROR: Command not recognized..." << endl << endl;
    }

    cout << endl << "Thank you. Press ENTER to continue..." << endl;
    cin.get();
    }

void Console::add_player( const string & player_file, const string & name ) const
{
    ofstream f( player_file.c_str(), ios::app );
    string registration;
    int birth;

    cout << "Enter the player's year of birth: " << endl;
    cin >> birth;

    int age = Console::process_age( kcsYearFileName, birth );
    int category = Console::process_category( age );

    if ( category == -1 )
    {
        f.close();
        return;
    }

    cout << "Registration Status (Paid) (Unpaid): " << endl;
    cin >> registration;

    cout << name << " has been assigned to category U" << category << endl;

    f << name << ' '
            << birth << ' '
            << category << ' '
            << registration << endl;

    cout << endl;
    f.close();
}

void Console::print_player( const Player * player ) const
{
    int age = Console::process_age( kcsYearFileName, player->birth_year() );
    int category = Console::process_category( age );

    cout << "Name: " << player->name() << endl
         << "Age: " << age << endl
         << "Birth Year: " << player->birth_year() << endl
         << "Category: U" << category << endl
         << "Registration Status: " << player->registration() << endl;
}

int Console::process_age( const string & current_year_file, int birth_year ) const
{
    ifstream y( current_year_file.c_str() );
    int year;
    y >> year;

    int age = year - birth_year;

    y.close();
    return age;
}

int Console::process_category( int & age ) const
{
    if( age < 4 ){
        cout << "Only children ages 4 and above are allowed to play in this league" << endl;
        return -1;
    } else if ( age < 6 ){
        return 6;
    } else if ( age < 8 ){
        return 8;
    } else if ( age < 10){
        return 10;
    } else if ( age < 14){
        return 14;
    } else if ( age < 17 ){
        return 17;
    } else {
        cout << "Only children ages 16 and below are allowed to play in this league" << endl;
        return -1;
    }
}
