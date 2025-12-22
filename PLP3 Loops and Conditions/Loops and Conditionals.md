# Booleans and Conditional Statements

Booleans values in C++ are 1 and 0 values (1 for true, 0 for false). You can reference them by calling `true` or `false` but their output will always be 1 or 0. You can build statements with one or many conditions involved, segmenting with parentheses as needed. For building multiple condition statements, C++ and Java have the same values for and `&&`, or `||`, not `!`, equal to `==`, and does not equal `!=`. 

```
bool x = true // value is 1
bool y = (7>8) // value is 0

bool z (7>8) || (6<7) // value is 1
bool q (7>8) && (6<7) // value is 0
```
## if, else if, else
These of course are the foundation of if/else statements, build like so: `if(condition){code to execute if the condition is met}` in C++ there are three condition words, `if`, `else if`, and `else`. 

```
int x = 5

if(x < 3) {cout << "that's a small number";}
else if((x >= 3) && (x < 8)){cout << "that's a nice medium number";}
else{"that's a big number!"}

// output: "that's a nice medium number"
```
As the brackets would suggest, the code contents of each of the statements is it's own confined code block. Variables declared within an if statement will not be reachable outside, however any changes that happen within an if statement will not be lost.

```
int x = 4

if (x < 7){
  int y = (7-x);
  x += y;
}

cout << x; // this will output 7
cout << y; // this will crash, because it's out of scope
```
## switch
The other main condition statement in C++ is a switch statement. It will keep going through the cases until it finds one that matches. Tt's not necessary to `break` out of each case, but reccomended to since you usually don't need to keep testing for cases after you've found a match. (Though in cases where you may want to keep testing, it is an option to leave it there.
```
int temp = 72

switch(temp) {
  case temp<32:
    cout << "Might be snowing!";
    break;
  case (temp >= 32) && (temp < 55):
    cout << "Grab a coat, it's pretty chilly";
    break;
  case temp >=55 && temp <70 :
    cout << "little brisk, but not too bad!";
    break;
  case temp >=70 && temp <76 :
    cout << "The perfect temperature!";
    break;
  case temp =>76 :
    cout << "it is hot!";
    break;
  default:
    cout << "new england weather can change any minute!";
}
```

## Things to know:
Does your language allow for statements other than “if” 
(for example, Perl has an “unless” statement, which does the opposite of “if”!)
- Not inherantly, just if, else if, and else. Though I think there are other namespaces or header files that you can include to add one of those in.

Does your language use short-circuit evaluation?  Include an example of the short-circuit logic working or not working (or both, if your language is like Java and supports both!)
- Yes it does! Short circuit logic is bult into both && and || statements. 

How does your programming language deal with the “dangling else” problem?
- Any `else` will match to the closest `if` within it's scope. (it's part of why the brackets are important). So whichever `if`'s close bracket is closest ahead of the `else` statement will be the `if` it maps to.

