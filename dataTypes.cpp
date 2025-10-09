#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    /*First let's start with the basics, here are the first primitive types you're already used to. 
    syntax: varType varName = value */

    int num = 12;
    float flNum = 6.5;
    double dblNum = 12.5;
    char letter = 'M';
    string word = "Bird";
    bool myBool = true;
    bool alsoMyBool = 6>7;

    cout << " Booleans, ints, floats, doubles, and simple strings: \n"; // just keeping the output tidy

    // for booleans if you print them it will output a 1 for true and a 0 for false
    cout << myBool << " ";
    cout <<alsoMyBool <<endl;

    // you can add ints and Doubles/floats:
    cout << num + dblNum <<" ";
    cout << num + flNum <<" ";
    cout << flNum + dblNum <<endl;

    // however ints and strings won't work when you add them
    //cout << num + word <<endl; // <- this will crash

    //These work, but why would you do this... (char will use the Askey value)
    cout << num + letter<<endl;
    cout << num + myBool <<endl;

    // Moving on to string stuff (and output by proxy) you can concatinate like this:
    cout << letter + word << endl;
    cout << letter << " intermediary string " << word << endl;

    // or like this, but when creating a string variable like so, you can't add a char datatype
    string longerString = word + " Plus whatever you like, but MUST BE A STRING \nChar's won't concatinate inside a string variable";
    cout << longerString <<endl;

    ////////////////////////////////////////////////////////////////////////////////////////////
    /* 
    Now onto arrays, maps, and pointers
    Starting with arrays!
    */
    cout << "\n List outputs: \n";

    //Syntax: arrayType arrayName[arraySize] = {stuff, in, the, array"}
    int numList[4] = {11,24,5};

    // you can ommit the array size if you want, but the above is best practice
    string strList[] = {"one", "two", "FIVE!"};

    /* you can also add things later like this, but it ONLY WORKS if a size is declared!
     it won't work if you hadn't done that step */
    numList[3] = 42;
    //strList[3] = "no, THREE!!!";

    /* ^ this won't work because the array size was not declared with room to add anything,
    so the program will crash. The size of an array is fized once it's set.
    If you want a mutable size array, you would need to use a vector. (different datatype) */

    // to access a specific value of an array, just use the index
    cout << numList[0] <<endl;

    /* if you want all the values, don't try to print out the array this way, 
    it will just show you it's memory address */
    cout << numList <<endl;

    //Instead you have to loop through the array in one of two ways
    // a classic for loop:
    for (int i = 0; i < 4; i++) {cout << numList[i] << " ";}
    cout << "\n";

    /* or a "for-each" loop specifically designed for looping through arrays like this:
    syntax: for (varType varName: listName) {whatever code you wanna do} */
    for (int aNum: numList) {cout << aNum << " ";}

    // both work just fine, but it's often more conventional to use a for-each loop in this case
    cout << "\n";

    // array utilities:
    int listSize = sizeof(numList) / sizeof(numList[0]); // getting the array size
    cout << listSize << endl;
    //if you just do this, it will give you the size in bytes, which is usually less useful
    int listBytes = sizeof(numList);
    cout << listBytes << endl;
    // you of course can also loop through and count if you like to get the array size

    ////////////////////////////////////////////////////////////////////////////////////////////
    /* 
    But anyway, moving onto Maps!
    (for these you need the #include <map> statement up  at the top)
    */
    cout << "\n Map outputs: \n";
    //syntax map<keyType, valueType> mapName
    map<string, int> dogs = {{"Bella", 4},{"Rascal", 6},{"Boomer", 7}};
    
    dogs["Fresca"] = 9; // you can add stuff!
    dogs["Boomer"] = 5; // you can change/overwrite stuff!
    dogs.insert({"Pepper", 2}); // you can also use the insert function!
    dogs.erase("Rascal"); // you can also delete stuff! (sorry Rascal...)
    //dogs.clear(); <- you can also do this to empty the map, but I'm not going to run this for sake of example.

    /*now let's say you want to access some of this 
    this of course can be done in multiple ways, one of which is more conventional than the other.*/
    cout << "Boomer's age: " << dogs.at("Boomer") << "\n";
    cout << "Bella's age: " << dogs["Bella"] << "\n";

    /* both of these will work, but using the .at() function is more proper 
    as it will throw an exception if the key isn't there, whereas the latter will just crash. */

    cout << "And this is Pepper's age: " << dogs.at("Pepper") <<endl;
    cout << dogs.size() <<endl; // this will tell you the size of the map
    cout << dogs.empty() <<endl; // 1: yes the map is empty, 0: no it's not.
    cout << dogs.count("Fresca") <<endl; // does this value exist? (also 1 or 0)

    /* to print out all the things in the map, you would loop through with a for_each loop, 
    the auto means it will detect the type, .first is the key, and .second is the value */
    for (auto dog : dogs) {cout << dog.first << "'s age is: " << dog.second << "\n";}

    ////////////////////////////////////////////////////////////////////////////////////////////
    /* 
    And now pointers
    pointers are a little weird, but not too bad once you get the hang of them.
    */
    cout << "\n Pointer outputs: \n";

    // to create a pointer, first you need a thing to point to:
    int example = 4;

    /*now you create a variable that stores the address
    IMPORTANT the type of the pointer has to match what you're pointing to */
    int *pntr = &example;

    /* and there you have it! the & is just referencing the address, and now you have a pointer!
    If you were confused earlier about array name output before, it's because the name of an array...
    IS SECRETLY A POINTER!!! (it's so it can be stored on the stack and doesn't take up ALL the room)*/
    cout << example <<endl;
    cout << pntr <<endl;

    // and because pointers do in fact point, you can use them to see what's stored at the address it's pointing to:
    cout << *pntr <<endl;

    // you can also change values through pointers (which is a little brainy, it's the last thing I promise)
    *pntr = 7;
    cout << *pntr <<endl;

    // KEEP IN MIND: the datatype has to stay the same, I can't make the address point to a string after.

    return 0; // and at last...
} // we have finished :)