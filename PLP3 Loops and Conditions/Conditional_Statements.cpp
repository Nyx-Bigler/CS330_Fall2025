#include <iostream>

using namespace std;

// we'll come back to these later
bool checkT() {
    cout << "CheckT was called!" <<endl;
    return true;
}

  bool checkF() {
    cout << "CheckF was called!" <<endl;
    return false;
}

int main(){

  // setup example values
  int sides = 6;

  if (sides<=3) {
    cout << "that's very few sides." <<endl; // one condition
    }
  else if (sides >=4 && sides <= 6) {
    cout<< "that's a good number of sides,"<<endl; // multiple conditions
    }
  else {cout <<"that's a lot of sides!"<<endl;} // else will map to the closest "if"


  // a switch statement:
  switch (sides) {
    case 1:
      cout << "Circle" <<endl;
      break;
    case 2:
      cout << "Line" <<endl;
      break;
    case 3:
      cout << "Triangle" <<endl;
      break;
    case 4:
      cout << "Rectangle or Square" <<endl;
      break;
    case 5:
      cout << "Pentagon" <<endl;
      break;
    case 6:
      cout << "HEXAGON!" <<endl;
      break;
    case 7:
      cout << "Heptagon!" <<endl;
      break;
}
  // short circuiting: (remember those functions set up earlier?)
  cout << (checkF() && checkT()) <<endl; // only prints contents from checkF
  cout << (checkT() || checkF()) <<endl; // only prints contents from checkT


    return 0;
}
