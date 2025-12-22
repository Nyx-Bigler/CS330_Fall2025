# Functions in C++

First, let's start with how to write one. In order to write a function you need to know three things:
- What data type are you going to be returning?
- What you want your function to be called?
- What data types are you going to be passing in?
- and of course, what's your function going to do?

The syntax goes as follows: `returnType FuncName(inputType inputVar){ whatever your function actually does }`
You can have whitespace between your curly brackets for readability, or you can keep it all in line if the function is very short. Generally convention is to keep it on one line if it's one line of code, but to leave space if there's multiple lines. Also as far as input goes, you can input as many and of as many datatypes as you wish, but you can only return one (more on that later).

Like so:
```
int add(int a, int b){return(a+b);}

// this is a function with multiple lines
int narratedAdd(int a, int b){
cout << "We are oing to add" << a << " and " << b <<endl;
cout << a+b <<endl;
return(a+b)
}

// this function doesn't return anthing
void cat(){cout >>"meow!">> endl;}

```
As mentioned above, functions can only return one variable, which can be difficult if you want to return more than one thing. To get around this you can have your function return an array, or you can use tuples (acessed by using `#import <tuple>` in your header). So before the code block closes after the function, you can pack the two variables into a tuple, send out the tuple, and unpack it later.

## Function Scope in C++

The next important piece to go over is scope, both of code within the function, and of the function definitions themselves. As mentioned in the previous section, curly brackets `{ }` define code blocks. Anyhting within those brackets is visible to things also within, however anything outside is not. If a value is declared and modified within a code block, unless you `return` the variable at the end of the function, it will be (metaphorically) "dropped on the floor" after the code block is completed.

```
int x = 7;
int y = 4;

int example(int a, int b){
  int z = 7;
  y = y+x;
  x = x+z;
  return(x)
}

example(x,y);
cout << x <<endl; // this will return 14
cout << y <<endl; // this will return 4, because it was not returned
cout << z <<endl; // this will crash because z was not declared in scope.
```

Also when you're writing a function definition in C++, the order that they're placed does matter. "They must be declared before they are called" (with the exception of `main()` as that is called implicitly.) so any functions that you want to use in main later, must to be written above it, otherwise they can not be seen by what is calling them.

## Things to know

Does your language support recursive functions?
- Absolutely it does!

Is your language pass-by reference or value?  Check your code against outside sources 
in case there is anything tricky going on (like in Perl).
- C++ is pass by value for most datatypes (the major acceptions being arrays, and objects). For any other datatype, if you want to pass by reference, you would need to pass in a pointer of some kind. 

Where are the arguments, parameters and local variables stored (value-on-stack, ref-to-heap-on stack) during execution?
- Local variables are usually stored on the stack, unless they are objects or other large datatypes. In that case they would be a reference to the heap. In general anything in a smaller code block, or an argument being used and modified in the current code block will have either itself, or a reference to it's heap location on the stack.

Are side-effects possible? Are there guard rails against side-effects?
- absolutely! No there aren't any safeguards in place against side effects. You can print, affect outside variables, or do just about anything else you like!
