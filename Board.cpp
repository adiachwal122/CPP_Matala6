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

Board :: ~Board(){
    del();
}

void Board:: del(){  //distructor

    for (int i = 0; i < num; i++) //free
	    delete[] mat[i];
	delete[] mat;
}

void Board :: init(){ //to initial board
    for (int x = 0; x < this->num; ++x){
        for (int y = 0; y < this->num; ++y){
            this->mat[x][y] = this->space;
        }
    }
}

play& Board :: operator [] (Index index) {
    
    if (index.row >= this -> num || index.column >= this -> num || index.row < 0 || index.column < 0 ){
        IllegalCoordinateException coordinate;
        coordinate.set_f(index.row);
        coordinate.set_s(index.column);
        throw coordinate;
    }
    return this -> mat[index.row][index.column];
}

play Board :: operator [] (Index index) const {//read only
    return this -> mat[index.row][index.column];

}

Board& Board::operator=(char place){//play turn
    if (place == '.'){
        init();
    }
    
    else if (place != 'X' && place != 'O' && place != '.'){
        IllegalCharException ch;
        ch.set_t(place);
        throw ch;
    }
    
    else{
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                mat[i][j] = place;
    }
    
    return *this;
}

Board& Board::operator=(const Board& obj){//copy Board

    if (this==&obj){
        return *this;
    }
    
    del();
    
    num = obj.num;
    mat = new play*[num];  
	for (int i = 0; i < num; i++){
		mat[i] = new play[num];
        for (int j = 0; j < num; j++) 
            mat[i][j] = obj.mat[i][j];
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
