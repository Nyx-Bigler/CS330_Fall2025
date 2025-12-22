# Booleans and Conditional Statements

Booleans values in C++ are 1 and 0 values (1 for true, 0 for false). You can reference them by calling `true` or `false` but their output will always be 1 or 0. You can build statements with one or many conditions involved, segmenting with parentheses as needed. For building multiple condition statements, C++ and Java have the same values for and `&&`, or `||`, not `!`, equal to `==`, and does not equal `!=`. 

```
bool x = true // value is 1
bool y = (7>8) // value is 0

bool z (7>8) || (6<7) // value is 1
bool q (7>8) && (6<7) // value is 0
```

These of course are the foundation of if/else statements


What types of conditional statements are available in your language?  (if/else, if/then/else, if/elseif/else).
- if/else

Does your language allow for statements other than “if” 
(for example, Perl has an “unless” statement, which does the opposite of “if”!)
- Don't think so

How does your language delimit code blocks under each condition in selection control statements?
- what?

Does your language use short-circuit evaluation?  Include an example of the short-circuit logic working or not working (or both, if your language is like Java and supports both!)
- Yes

How does your programming language deal with the “dangling else” problem?
- Matches to the closest if within the same scope (scope meaning brackets)

If your language supports switch or case statements, do you have to use “break” to get out of them?  
Can you use “continue” to have all of the conditions evaluated?
- yes you do need to break out of switch statements

