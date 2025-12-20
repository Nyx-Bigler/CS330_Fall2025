#include <iostream>

using namespace std;

// Parent Class
class Pet {
  public:
    string name = "Ollie";
    void call_pet() {
      cout << "Come here "<< this->name << "!" <<endl;
    }
};

// Child Class
class Dog: public Pet{
  public:
    string breed = "Beagle";
    
    void bark() {
      cout << "Woof Woof!" <<endl;
    }
};

int main() {
  Dog exampleDog;
  cout << exampleDog.name + " " + exampleDog.breed <<endl; // "Ollie Beagle"

  exampleDog.call_pet(); // Come here Ollie!
  exampleDog.bark(); // "Woof Woof!"

  exampleDog.name = "Winston"; // <- modifying attributes
  exampleDog.breed = "Corgi";
  cout << exampleDog.name + " " + exampleDog.breed <<endl; // "Winston Corgi"
  exampleDog.call_pet(); // "Come here Winston!"

  return 0;
}
