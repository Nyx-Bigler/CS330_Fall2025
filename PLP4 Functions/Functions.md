# Functions in C++

First, let's start with how to write one. In order to write a function you need to know three things:
- What data type are you going to be returning?
- What you want your function to be called?
- What data types are you going to be passing in?
- and of course, what's your function going to do?

The syntax goes as follows: `returnType FuncName(inputType inputVar){ whatever your function actually does }`
You can have whitespace between your curly brackets for readability, or you can keep it all in line if the function is very short. Generally convention is to keep it on one line if it's one line of code, but to leave space if there's multiple lines.

Like so:
```
int add(int a, int b){return(a+b);}

//this is a function with multiple lines
int narratedAdd(int a, int b){
cout << "We are oing to add" << a << " and " << b <<endl;
cout << a+b <<endl;
return(a+b)
}

// this function doesn't return anthing
void cat(){cout >>"meow!">> endl;}

```

What is the syntax for declaring a function in your language?

Are there any rules about where the function has to be placed in your code file so that it can run?

Does your language support recursive functions?

Can functions in your language accept multiple parameters?  Can they be of different data types?

Can functions in your language return multiple values at the same time?  
How is that implemented?  If not, are there ways around that problem?  What are they?

Is your language pass-by reference or value?  Check your code against outside sources 
in case there is anything tricky going on (like in Perl).

Where are the arguments, parameters and local variables stored (value-on-stack, ref-to-heap-on stack) during execution?

What are the scoping rules in your language (visibility and lifetime of variables before, during and after code blocks)?

Are side-effects possible? Are there guard rails against side-effects?

Where are local variable values stored? (on the stack? On the heap?)

Are there any other aspects of functions in your language that aren't specifically asked about here, 
but that are important to know in order to write one?  What are they? (e.g. dynamic vs static scope)
