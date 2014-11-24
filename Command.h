#ifndef _Command_h_
#define _Command_h_

#include <iostream>
#include <string>
using namespace std;

class Command
{
public:
    friend istream & operator>>( istream & in, Command & c );
    Command() : command('x') {}

    bool is_add() const { return command == 'a'; }
    bool is_lookup() const { return command == 'l'; }
    bool is_edit() const { return command == 'e'; }
    bool is_generate() const { return command == 'g'; }
    bool is_close() const { return command == 'c'; }

private:
    char command;
};

inline istream & operator>>( istream & in, Command & c ) {
    string input;
    getline(in, input);
    c.command = input[0];
    return in;
}

#endif
