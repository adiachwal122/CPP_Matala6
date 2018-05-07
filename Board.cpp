#include "Board.h"
#include "Exceptions.hpp" 
#include <iostream>


Board :: Board(Board& other){
    this -> num = other.num;
    this -> mat = new play*[other.num];
    for (int i = 0; i < this->num; ++i)
        this->mat[i] = new play[other.num];
    
    for(int i = 0; i < num;i++){
        for(int j = 0; j < num;j++){
            this ->mat [i][j] = other.mat[i][j];
        }
    }
}

Board :: Board (int n){
    this-> num = n;
    this -> mat = new play*[this->num];
    
    for (int i = 0; i < this->num; ++i)
        this->mat[i] = new play[this->num];

    init();//initial Board
}

void Board :: init(){ //to initial board
    for (int x = 0; x < this->num; ++x){
        for (int y = 0; y < this->num; ++y){
            this->mat[x][y] = this->space;
        }
    }
}

play& Board :: operator [] (Index index) {
    
    if (index.row >= this -> num || index.column >= this -> num ){
        IllegalCoordinateException coordinate;
        coordinate.set_f(index.row);
        coordinate.set_s(index.column);
        throw coordinate;
    }
    if (index.row < 0 || index.column < 0 ){
        IllegalCoordinateException coordinate;
        coordinate.set_f(index.row);
        coordinate.set_s(index.column);
        throw coordinate;
    }
    return this -> mat[index.row][index.column];
}

char Board::operator=(char place){//play turn
    cout<< "indide Board char place"<<endl;
    if (place == '.'){
        init();
    }
    
    else if (place != 'X' && place != 'O'){
        IllegalCharException ch;
        ch.set_t(place);
        throw ch;
    }
    
    return place;
}

Board& Board::operator=(const Board& obj){//copy Board
    cout<< "indide Board obj"<<endl;
     
     if (obj.num == this -> num){
       // this -> num = obj.num;
        for(int i = 0; i < num;i++){
            for(int j = 0; j < num;j++){
                this ->mat [i][j] = obj.mat[i][j];
            }
        }
    }
    else if (obj.num != this -> num)  {
        IllegalCoordinateException coordinate;
        coordinate.set_f(obj.num);
        coordinate.set_s(obj.num);
        throw coordinate;
        
    }
    return *this;
}


bool operator== (Board const& x, Board const& y){
    if (x.num != y.num)
        return false;

    for (int i = 0; i < x.num ; ++i) {
        for (int j = 0; j < x.num ; ++j) {
            if(x.mat[i][j].get_sign() != y.mat[i][j].get_sign())
                return false;
        }
    }

    return true;
}

bool operator!= (Board const& x, Board const& y){
    if (x.num != y.num)
        return true;

    for (int i = 0; i <x.num ; ++i) {
        for (int j = 0; j <x.num ; ++j) {
            if(x.mat[i][j].get_sign() != y.mat[i][j].get_sign())
                return true;
        }
    }

    return false;
}
