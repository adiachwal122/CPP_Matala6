#ifndef _PLAY_HPP
#define _PLAY_HPP
#include <sstream>
#include "Exceptions.hpp"
using namespace std;
#include <iostream>


class play{
    private:
        char sign;
    
    public:
        play();
        play(char);
        play(play&);

        char get_sign();
        void set_sign(char);
        play& operator= (char);
        play& operator= (play&);
        friend ostream& operator<<(ostream&, play&);
        bool operator==(char ) const;
        bool operator!=(char ) const;
        bool operator==(const play&) const;
        bool operator!=(const play&) const;

};

inline ostream& operator<<(ostream& os, play& pl){
	    os << pl.get_sign() << endl;
        return os;
}

#endif
