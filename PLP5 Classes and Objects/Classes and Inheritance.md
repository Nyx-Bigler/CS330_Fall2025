# Classes in C++

Now we're finally at the namesake of C++, *classes and objects!* There is a lot of functionality built in around these, and they are pretty intuitive to use. In a class there are a few main "sections" of your definition: The access specifiers, the attributes, a constructor, and the methods. You do not need all of these components to have a valid class, the only strictly necessary one of these is the attributes. That being said though, the other components are important to have if and as they are relevant to your class.

- **Access specifiers:** There are 3 to choose from. `public` means they can be used outside the class, `private` can not be used outside the class, and `protected` which means they can not be acessed outside the class, but they can be acessed by any inherited classes.
- **Attributes:** these are variables that you want your class to have, they can be any you like!
- **Constructor:** It is a function that creates a class opject and assigns attributes. It is optional, you can instantiate your class without a constructor, but they make that whole process much more convenient.
- **Methods:** Functions that you want your class to be able to do, like attributes, they can be just about anything you like.

An example
```
class Book {
// access specifier
  public: // this means that anything below can be called directly without the need of a get and set function.

// Class attributes
    string title;
    int pages;

// Constructor (optional but highly recommended)
    Book(string t, int p,){
      title = t;
      pages = p;
    }

// whatever methods you like
    void read() {
      cout << "This is a very good book!"<<endl;
    }
    void print_title(){
      cout << "Book Title: " << title <<endl;
    }
};
```
In your class definition there are a few things to keep in mind:
- Classes MUST have a capital first letter
- Classes do not need to be in their own file, you can have multiple class definitions in the same file.
- There is NOT a built in `__str__()` or `toString()` like in python or java, if you want to write/print out your object, you would need to write it manually like I did above.

I realize this is being very rapid-fired through, but let's move on to interacting with and using the class. You instantiate an object of a class either by calling `Class objectName;` and setting the attributes manually, or if you wrote a constructor by writing `Class objectName(type input 1, type input2)`. The latter with a constructor is much more conventional, (mostly just because it's faster).
```
// Intantiating and using said class:

int main() {
  Book favoriteBook;

  // You can set the values this way
  favoriteBook.pages = 512; 
  favoriteBook.title = "The Princess Bride";

  // but since we wrote a constructor, it's better to do it this way:
  Book myBook("The Fellowship of the Ring", 432)

  // Print attribute values
  cout << myBook.pages <<endl;
  cout << myBook.title <<endl;
  return 0;
}
```
## Inheritance Overview:

Inheritance in C++ is I think among the most flexible. It supports both standard single inheritance, multiple inheritance, and multi level inheritance. Anything that isn't specified with the keyword `private` can be acessed and/or utilized by an inherited class.

**Some key notes:**
- A child class can call the methods of it's parent as much as it wants to, though for constructors you will want to use the `super` keyword. This will explicitly call the constructor for the parent class, and you can add any attributes specific to the child class.
- If there is a function in the parent class you wish to modify for the child class, you can `override` functions from the parent class. You can write a child method with the same name as the parrent method and add `override` ahead of it to use the child method definition instead of the parent's. (However, if you do not use the `override` keyword, you will get an error)

  example:
  
```
// Parent class
class Parent {
  public:
    string var1= "Ford";
    void parFunc() {
      cout << "This is from the parent function" ;
    }
};

// Inheriting class
class ChildClass: public Parent {
  public:
    int var2;
};
  ```

