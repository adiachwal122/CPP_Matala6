#include "play.hpp"
#include "Exceptions.hpp"
#include <iostream>


play :: play(){
    this-> sign = '.';
}

play :: play(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ch;
        ch.set_t(sign);
        throw ch;
    }
    this-> sign = sign;
}
\
play :: play(play& other){
    this-> sign = other.sign;
}
        
char play :: get_sign(){
    return this -> sign;
}
void play :: set_sign(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ch;
        ch.set_t(sign);
        throw ch;
    }
    
    this-> sign = sign;
}

play& play ::  operator= (char s){
    cout<< "inside play 1"<<endl;
    this-> sign = s;
    return *this;
}

play& play :: operator= (play& other){
    cout<< "indide play 2"<<endl;
    this-> sign = other.sign;
    return *this;
}

bool operator == (play const& x, play const& y){
    return x.sign == y.sign;
}
bool operator== (play const& x, char const& val){
    return x.sign==val;
}
bool operator== (char const& val, play const& x){
    return x.sign==val;
}
