#include <iostream>

using namespace std;

// Parent Class
class Pet {
  public:
    string name = "Rascal";
    void call_pet() {
      cout << "Come here "<< this->name << "!" <<endl;
    }
};

// Child Class
class Dog: public Pet{
  public:
    string breed = "Beagle";
};

int main() {
  Dog exampleDog;
  exampleDog.call_pet();
  cout << exampleDog.name + " " + exampleDog.breed;  // Would output: "Rascal Beagle"
  return 0;
}
