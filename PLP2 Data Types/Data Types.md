# Data Types in C++

## The base types

First let's start with the basics, here are the first primitive types you're already used to. They are explicitly typed, (you declare the type when you declare the variable) and they are statically typed. ("once a string always a string" etc.) Conventionally, variable names have a lowercase first letter, no whitespace, and don't begin with a number.

syntax: varType varName = value 
```
int num = 12;
float flNum = 6.5;
double dblNum = 12.5;

char letter = 'M';
string word = "Bird";

bool myBool = true; // value == 1
bool alsoMyBool = 6>7; // value == 0
```

for booleans if you print them it will output a 1 for true and a 0 for false

There are several cross type operations that are allowed. Adding `+`, subtracting `-`, multiplying `*`, and dividing `/` between ints, doubles and floats is perfectly fine:
```
    cout << num + dblNum <<" "; 
    cout << num - flNum <<" ";
    cout << flNum * dblNum <<endl;
```
You can do the same for char type variables and/or Booleans to any of the above:
```
    cout << num + letter <<endl; // <- Will add the askey value of the char

    cout << num + myBool <<endl; // <- will add either 0 or 1 depending on the bool value
```

Trying to do any of that with strings to ints, floats, doubles, or bools however, will crash.
```
    //cout << num + word <<endl; <- This will crash
```

You can concatinate strings and chars, though there are some rules surrounding it

These will run just fine:
```
    cout << letter + word << endl;
    cout << letter << " intermediary string " << word << endl;
```
This will run, but both values MUST be a string, it will run, but the output will not be what you'd expect.
```
    string longerString = word + " Plus whatever you like, but MUST BE A STRING";
    cout << longerString <<endl;
```


## Arrays, Maps, and Pointers

### Arrays

Syntax: arrayType arrayName[arraySize] = {stuff, in, the, array"}, you can ommit the array size if you want, but it limits what you can do with the array later. For example, you can also add things to open spaces in a "size declared array", but you can't if you left it out. (To do that you would need to use a vector, which is a size mutable array).

```
int numList[4] = {11,24,5};
string strList[] = {"one", "two", "FIVE!"};

numList[3] = 42; // <- This will change the value at index 3 from null to 42
//strList[3] = "no, THREE!!!"; <- This will crash
```

to access a value in an array, just use the index like so: `numList[0]` However, if you want all the values, don't try to just cout the array, it will just show you a memory address. 
```
    cout << numList <<endl; // This will return the memory address of index[0]
```
If you want to print out everything in the array, you will have to loop through the array in one of two ways; a classic for loop, or a for-each loop. (A loop specifically designed for looping through arrays, syntax: for (varType varName: listName) {whatever code you wanna do} example: `for (int aNum: numList) {cout << aNum << " ";}` more on this in the next folder.) both work just fine, but it's often more conventional to use a for-each loop.

Some array utilities:
```
    int listSize = sizeof(numList) / sizeof(numList[0]); // getting the array size
    //if you just do this, it will give you the size in bytes, which is usually less useful
    int listBytes = sizeof(numList);

    // you of course can also loop through and count instead if you like
```
### Maps
Maps are dictionaries in C++. They are one of many more complex datatypes not included by default, so for these you need the `#include <map>` statement in the header.

syntax map<keyType, valueType> mapName

```
    map<string, int> dogs = {{"Bella", 4},{"Rascal", 6},{"Boomer", 7}};
    
    dogs["Fresca"] = 9; // you can add stuff!
    dogs["Boomer"] = 5; // you can change/overwrite stuff!
    dogs.insert({"Pepper", 2}); // you can also use the insert function!
    dogs.erase("Rascal"); // you can also delete stuff! (sorry Rascal...)
    //dogs.clear(); <- you can also do this to empty the map, but commented out
```
Now let's say you want to access some of this, this of course can be done in multiple ways, one of which is more conventional than the other. Both of these will work, but using the .at() function is more proper as it will throw an exception if the key isn't there, whereas the latter will just crash.
```
    cout << "Boomer's age: " << dogs.at("Boomer") << "\n";
    cout << "Bella's age: " << dogs["Bella"] << "\n";
```
Some more utility:
```
    cout << dogs.size() <<endl; // this will tell you the size of the map
    cout << dogs.empty() <<endl; // 1: yes the map is empty, 0: no it's not.
    cout << dogs.count("Fresca") <<endl; // does this value exist? (also 1 or 0)
```

To print out all the things in the map, you would loop through with a for_each loop, the auto means it will detect the type, .first is the key, and .second is the value.
```
    for (auto dog : dogs) {cout << dog.first << "'s age is: " << dog.second << "\n";}
```

### Pointers
  pointers are a little weird, but not too bad once you get the hang of them. To create a pointer, first you need a thing to point to, then create a variable that stores the address **IMPORTANT: The type of the pointer has to match what you're pointing to**
```
    int example = 4;
    int *pntr = &example;
```

and there you have it! the & is just referencing the address, and now you have a pointer!
If you were confused earlier about array name output before, it's because the name of an array is actually a secret pointer! (it's so it can be stored on the stack and doesn't take up ALL the room)

and because pointers do in fact point, you can use them to see what's stored at the address it's pointing to:
You can also change values through pointers (which can get a little brainy, it's the last thing I promise)
```
    int example = 4;
    int *pntr = &example; // pointer 

    *pntr = 7;
    cout << example <<endl; // this would now output 7
```

KEEP IN MIND: the datatype has to stay the same, I couldn't make the address point into a string or char after. 

**Thing to know:** If when modifying something at the other end of a pointer and it moves, or the pointer moves, or the type changes or anything like that, you will get something known as a **segmentation fault** these can be super annoying to debug, but it means that either a pointer is now pointing at nothing (nullptr), pointing to something out of scope, etc.

## Things to know

Does your language have keywords or reserved words? How many?
- C++ has reserve words, in base C++ (without any includes) there are a total of 95.

What about naming conventions? Are those enforced by the compiler/interpreter, or just standards in the community?
- just standards I think, accept for writing a number or something like that.

Are some variables mutable while others are immutable?
- Usually variables are mutable outside of certain contexts (like a Const object). However, there is a keyword `mutable` which will get around this.

At what point are identifier names and operator symbols bound in your language? 
For example if you declare a (variable, class name, function name), when is it bound to the type, address? 
- The compile step

When are operators (+,*, etc.) bound to their operations?
- I think also the compile step.

