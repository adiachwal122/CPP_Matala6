#include <exception>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception{
    
    int first;
    int second;
    
    public:
        const char* theCoordinate() const throw (){
            return (to_string(first) + ',' +to_string(second) + '\n').c_str();
            
        }
        void set_f(int f){ this ->first = f;}
        void set_s(int s){ this ->second = s;}
};

class IllegalCharException : public exception{
    
    char temp;
    
    public:
        const char* theChar() const throw (){
            const char* ans =  &temp;
            return ans;
        }
        void set_t(char t){ this ->temp = t;}
};