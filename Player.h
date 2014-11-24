#ifndef _Player_h_
#define _Player_h_

#include <iostream>
#include <string>
using namespace std;

class Player
{
public:

    friend istream & operator>>( istream & in, Player & p );

    Player() : p_name("invalid"), p_birth_year(-1), p_category(-1),
                    p_registration("invalid") {}

    const string & name() const { return p_name; }
    int birth_year() const { return p_birth_year; }
    int category() const { return p_category; }
    const string registration() const { return p_registration; }

private:
    string p_name;
    int p_birth_year;
    int p_category;
    string p_registration;

};

inline istream & operator>>( istream & in, Player & p )
{
    in >> p.p_name >> p.p_birth_year >> p.p_category
       >> p.p_registration;

    return in;
}


#endif
