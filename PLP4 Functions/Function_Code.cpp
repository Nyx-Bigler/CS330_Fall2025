#include <iostream>
#include <tuple>
using namespace std;

// Multuplying two numbers
int mult(int a, int b){return(a*b);}

// Recursion
int factorial(int x){
if(x < 0) {return(-200);} // this is the "in case something somehow went horribly wrong"

if(x == 0 || x == 1) {return(1);}
else {return(x * factorial(x-1));}
}

// String split

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

    // testing the swap
    cout << "x:  " << x <<" adr: "<< &x <<endl;
    cout << "y:  " << y <<" adr: "<< &y <<endl;
    tie(x,y) = swap(x,y);
    cout << "after swap x:  " << x <<" adr: "<< &x <<endl;
    cout << "after swap y:  " << y <<" adr: "<< &y <<endl;

    return(0);
}
