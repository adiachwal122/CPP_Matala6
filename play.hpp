#include "Exceptions.hpp"

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
};

inline ostream& operator<<(ostream& os, play& pl){
	    os << pl.get_sign() << endl;
        return os;
}