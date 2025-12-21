#include <iostream>
#include <tuple>
#include <string>

using namespace std;

// For tuples, I wound up using this resource quite a bit: https://www.geeksforgeeks.org/cpp/tuples-in-c

// Multuplying two numbers
int mult(int a, int b){return(a*b);}

// Recursion
int factorial(int x){
if(x < 0) {return(-200);} // this is the "in case something somehow went horribly wrong"

if(x == 0 || x == 1) {return(1);}
else {return(x * factorial(x-1));}
}

// String Split (This is very rudementary, anything more sophisticated needs a tokenizer)
tuple <string, string> split(string origional){

    //start at index 0, take 5 characters
    string part1 = origional.substr(0,5);

    // start at index 6, take 6 characters
    string part2 = origional.substr(6, 6); 

    return(make_tuple(part1,part2));
}


// Reference or value? (the SWAP!)
// Had to use tuples because functions can only return one value
tuple <int, int> swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    cout << "in swap x:  "<< x << " address: " << &x <<endl;
    cout << "in swap y:  "<< y << " address: " << &y <<endl;
    return(make_tuple(x,y));
    /*
    C++ is pass by value because: 
        1: the function works
        2: the variable addresses are different within the swap function than outside it
    */
}

int main() {
    int x = 4;
    int y = 7;

    // multiplication
    int result = mult(x,y);
    cout << "Multiplication: " << result <<endl;

    // factorial:
    int fact = factorial(x);
    cout << "Factorial: " << fact <<endl;

    // string split
    string example = "Hello World!";
    tuple <string, string> tupOutput = split(example); // can't just cout a tuple
    cout << get<0>(tupOutput) <<endl; // gotta get the pieces
    cout << get<1>(tupOutput) <<endl;

    // testing the swap
    cout << "x:  " << x <<" adr: "<< &x <<endl;
    cout << "y:  " << y <<" adr: "<< &y <<endl;
    tie(x,y) = swap(x,y);
    cout << "after swap x:  " << x <<" adr: "<< &x <<endl;
    cout << "after swap y:  " << y <<" adr: "<< &y <<endl;

    return(0);
}
