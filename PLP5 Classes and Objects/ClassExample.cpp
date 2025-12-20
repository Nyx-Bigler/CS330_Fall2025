#include <iostream>
// Base class
class Pet {
  public:
    string name = "Rascal";
    void call_pet(this.name) {
      cout << "Come here "<< name << "!" <<endl;
    }
};

// Derived class
class Dog: public Pet{
  public:
    string breed = "Beagle";
};

int main() {
  Dog exampleDog;
  exampleDog.call_pet();
  cout << exampleDog.name + " " + exampleDog.breed;
  return 0;
}
