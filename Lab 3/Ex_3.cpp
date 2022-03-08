#include <iostream>
#include <string.h>

using namespace std;

// Operations
const char Equal_sign = '=';
const char Plus_sign = '+';
const char Minus_sign = '-';
const char Multi_sign = '*';
const char Divide_sign = '/';

// Symbols
const char Not_sign = '!';
const char StringDelimiters_sign = '"';

const char LT_sign = '<';
const char GT_sign = '>';

const char Lparen_sign = '(';
const char Rparen_sign = ')';

const char Lbrace_sign = '{';
const char Rbrace_sign = '}';

const char Lbracket_sign = '[';
const char Rbracket_sign = ']';

// Delimiters
const char SemiColon_sign = ';';
const char Comma_sign = ',';
const char Enum_sign = ':';

// Comment
const char Comment_sign = '#';



bool isPunctuator(char ch)	// boolean function responsible for the check if the given character is any of the listed punctuators or is not
// it has as a parameter the character ch of length 1  
{
    // if the character is equal to one of the below signs, then it returns the value true
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
        ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || 
        ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || 
        ch == '}' || ch == '&' || ch == '|' || ch == '#' || ch == '!' || 
        ch == '"' || ch == ':')
        {
            return true;
        }
    // otherwise it returns just false
    return false;
}

bool validIdentifier(char* str)	// boolean function which check if the given identifier is valid or not
{
    // in case if the first character is a digit or is a punctuator then it will return false
    // because an identifier cannot start with a symbol or number, ,eaning that identifier is not valid
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || 
        str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || 
        str[0] == '8' || str[0] == '9' || isPunctuator(str[0]) == true)
        {
            return false;
        }
    int i;
    // len - the length of string str
    int len = strlen(str);
    // in case if the length of string is equal to 1, then it means that it contains just one letter and validation is already completed, and return true
    if (len == 1)
    {
        return true;
    }
    // otherwise		
    else
    {
        for (i = 1 ; i < len ; i++)		
        {
            // if even one of the characters of the string is a punctuator (special characters), then it returns false
            if (isPunctuator(str[i]) == true)
            {
                return false;
            }
        }
    }
    // in case if those above conditions were not satisfied, then it returns just true
    return true;
}

bool isOperator(char ch) // functions which is defined for the check if the given character is an operator or not, for or and and conditions
{
    // it has as a parameter the character ch of length 1
    if (ch == '|' || ch == '&')
    {
       return true;
    }
    return false;
}

bool isEqualSign(char ch) // function that is responsible for the check if the symbol is =
{
    // it has as a parameter the character ch of length 1
    if (ch == Equal_sign)
    {
       return true;
    }
    return false;
}

bool isPlusSign(char ch) // function that is responsible for the check if the symbol is +
{
    if (ch == Plus_sign)
    {
       return true;
    }
    return false;
}

bool isMinusSign(char ch) // function that is responsible for the check if the symbol is -
{
    if (ch == Minus_sign)
    {
       return true;
    }
    return false;
}

bool isMultiSign(char ch) // function that is responsible for the check if the symbol is *
{
    if (ch == Multi_sign)
    {
       return true;
    }
    return false;
}

bool isDivideSign(char ch) // function that is responsible for the check if the symbol is /
{
    if (ch == Divide_sign)
    {
       return true;
    }
    return false;
}

bool isColonSign(char ch) // function that is responsible for the check if the symbol is ;
{
    if (ch == SemiColon_sign)
    {
       return true;
    }
    return false;
}

bool isCommaSign(char ch) // function that is responsible for the check if the symbol is ,
{
    if (ch == Comma_sign)
    {
       return true;
    }
    return false;
}

bool isNotSign(char ch) // function that is responsible for the check if the symbol is !
{
    if (ch == Not_sign)
    {
       return true;
    }
    return false;
}

bool isString(char ch) // function that is responsible for the check if the symbol is "
{
    if (ch == StringDelimiters_sign)
    {
       return true;
    }
    return false;
}

bool isLT(char ch) // function that is responsible for the check if the symbol is <
{
    if (ch == LT_sign)
    {
       return true;
    }
    return false;
}

bool isGT(char ch) // function that is responsible for the check if the symbol is >
{
    if (ch == GT_sign)
    {
       return true;
    }
    return false;
}

bool isLparen(char ch) // function that is responsible for the check if the symbol is (
{
    if (ch == Lparen_sign)
    {
       return true;
    }
    return false;
}

bool isRparen(char ch) // function that is responsible for the check if the symbol is )
{
    if (ch == Rparen_sign)
    {
       return true;
    }
    return false;
}

bool isLbrace(char ch) // function that is responsible for the check if the symbol is {
{
    if (ch == Lbrace_sign)
    {
       return true;
    }
    return false;
}

bool isRbrace(char ch) // function that is responsible for the check if the symbol is }
{
    if (ch == Rbrace_sign)
    {
       return true;
    }
    return false;
}

bool isLbracket(char ch) // function that is responsible for the check if the symbol is [
{
    if (ch == Lbracket_sign)
    {
       return true;
    }
    return false;
}

bool isRbracket(char ch) // function that is responsible for the check if the symbol is ]
{
    if (ch == Rbracket_sign)
    {
       return true;
    }
    return false;
}

bool isEnum(char ch) // function that is responsible for the check if the symbol is :
{
    if (ch == Enum_sign)
    {
       return true;
    }
    return false;
}

bool isComment(char ch) // function that is responsible for the check if the symbol is #
{
    if (ch == Comment_sign)
    {
       return true;
    }
    return false;
}


bool isKeyword(char *str) // function that is responsible for the check if the given substring is a keyword or not (to be sure that I have included everything corectly)
{
    // strcmp - compare str and another string lexicographically, of those are equal, then the result is going to be 0
    // if the strings are equal, then the result 0, will be transformed onto 1(by !), and if there is one of the listed words equalt to the given one, then the function returns true
    if (!strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "char") || 
        !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "unsigned") || 
        !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "sizeof") || !strcmp(str,"long") || 
        !strcmp(str, "typedef") || !strcmp(str, "extern") || !strcmp(str,"bool"))
        {
            return true;
        }
    else
    {
        // otherwise it is going to return false

        return false;
    }
}

bool isLetword(char *str) // function that is responsible for the check if the given substring is a let
{
    if (!strcmp(str, "let")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isMainword(char *str) // function that is responsible for the check if the given substring is a main
{
    if (!strcmp(str, "main")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isFunctionword(char *str)	// function that is responsible for the check if the given substring is a fn, that defines function
{
    if (!strcmp(str, "fn")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isTrueword(char *str)	// function that is responsible for the check if the given substring is a true
{
    if (!strcmp(str, "true")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isFalseword(char *str)	// function that is responsible for the check if the given substring is a false
{
    if (!strcmp(str, "false")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isIfword(char *str) // function that is responsible for the check if the given substring is a if
{
    if (!strcmp(str, "if")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isElseword(char *str)	// function that is responsible for the check if the given substring is a else
{
    if (!strcmp(str, "else")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isReturnword(char *str) // function that is responsible for the check if the given substring is a return
{
    if (!strcmp(str, "return")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isWhileword(char *str)	// function that is responsible for the check if the given substring is a while
{
    if (!strcmp(str, "while")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isBreakword(char *str)	// function that is responsible for the check if the given substring is a break
{
    if (!strcmp(str, "break")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isContinueword(char *str) // function that is responsible for the check if the given substring is a continue
{
    if (!strcmp(str, "continue")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isDoword(char *str) // function that is responsible for the check if the given substring is a do
{
    if (!strcmp(str, "do")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isSwitchword(char *str) // function that is responsible for the check if the given substring is a switch
{
    if (!strcmp(str, "switch")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isCaseword(char *str) // function that is responsible for the check if the given substring is a case
{
    if (!strcmp(str, "case")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isStructword(char *str) // function that is responsible for the check if the given substring is a struct
{
    if (!strcmp(str, "struct")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isEnumword(char *str) // function that is responsible for the check if the given substring is a enum
{
    if (!strcmp(str, "enum")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isConstword(char *str)	// function that is responsible for the check if the given substring is a const
{
    if (!strcmp(str, "const")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isForword(char *str)	// function that is responsible for the check if the given substring is a cfor
{
    if (!strcmp(str, "for")) 
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool isNumber(char* str) // function that represents the check if the given substring is a number or not
{
    int i;
    // len - the length of string str
    int len = strlen(str);
    int numOfDecimal = 0;
    // if the length of the string is 0, then it returns false
    if (len == 0)
    {
        return false;
    }
    for (i = 0 ; i < len ; i++)
    {
        // if the number of decimals is bigger that 1 and one of the characters is a point and the next character is a digit , then it returns true
        if (numOfDecimal > 1 && str[i] == '.' && (str[i+1] == '0' || str[i+1] == '1' || str[i+1] == '2'
            || str[i+1] == '3' || str[i+1] == '4' || str[i+1] == '5'
            || str[i+1] == '6' || str[i+1] == '7' || str[i+1] == '8'
            || str[i+1] == '9'))
        {
            return true;
        } 
        // else the number of decimals is bigger that 1 and one of the characters is a point, then it returns false
        else if (numOfDecimal > 1 && str[i] == '.')
        {
            return false;
        } 
        // otherwise if the number of decimals is equal or smaller than 1, then we increase the value of number of decimals by 1
        else if (numOfDecimal <= 1)
        {
            numOfDecimal++;
        }
        // in case if the character is not equal with one of the digits or is equal with a symbol, then it returns false
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    // other cases it returns true
    return true;
}

char* subString(char* realStr, int l, int r) //function responsible to extract the required substring from the main string
{
    // it has as parameters: the initial string of chars, the starting position from left and the end position from right 
    int i;
    char* str = (char*) malloc(sizeof(char) * (r - l + 2));
    for (i = l; i <= r; i++)
    {
        str[i - l] = realStr[i];
        str[r - l + 1] = '\0';
    }
    return str;
}


void parse(char* str) // the main funtion for the parsing process of the expression
{
    // left, right - are the delimiters of the characters, which are set initially with 0
    int left = 0, right = 0;
    // len - the length of string str
    int len = strlen(str);
    cout << "[" << endl;
    // while the right delimiter is smaller or equal with the length of the string, and the left delimiter is smaller or equal with the right one 
    while (right <= len && left <= right) 
    {
        // if there is no punctuator sign
        if (isPunctuator(str[right]) == false)
        {
            // then we extend the right delimiter
            right++;
        }
        // in case if there we find a punctuator and the left and right delimiters are of the same value
        if (isPunctuator(str[right]) == true && left == right)		
        {
            // then verify if it is true by the below functions, and print in the console that we got
            if (isOperator(str[right]) == true)
            {
                cout<< str[right] <<" IS AN OPERATOR\n";
            }
            if (isEqualSign(str[right]) == true)
            {
                cout<< str[right] <<" IS AN EQUAL SIGN\n";
            }
            if (isPlusSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A PLUS SIGN\n";
            }
            if (isMinusSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A MINUS SIGN\n";
            }
            if (isMultiSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A MULTIPLICATION SIGN\n";
            }
            if (isDivideSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A DIVISION SIGN\n";
            }
            if (isColonSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A SEMICOLON SIGN\n";
            }
            if (isCommaSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A COMMA SIGN\n";
            }
            if (isNotSign(str[right]) == true)
            {
                cout<< str[right] <<" IS A NOT SIGN\n";
            }
            if (isString(str[right]) == true)
            {
                cout<< str[right] <<" IS A STRING DELIMITER SIGN\n";
            }
            if (isLT(str[right]) == true)
            {
                cout<< str[right] <<" IS A LT SIGN\n";
            }
            if (isGT(str[right]) == true)
            {
                cout<< str[right] <<" IS A GT SIGN\n";
            }
            if (isLparen(str[right]) == true)
            {
                cout<< str[right] <<" IS A LEFT PAREN SIGN\n";
            }
            if (isRparen(str[right]) == true)
            {
                cout<< str[right] <<" IS A RIGHT PAREN SIGN\n";
            }
            if (isLbrace(str[right]) == true)
            {
                cout<< str[right] <<" IS A LEFT BRACE SIGN\n";
            }
            if (isRbrace(str[right]) == true)
            {
                cout<< str[right] <<" IS A RIGHT BRACE SIGN\n";
            }
            if (isLbracket(str[right]) == true)
            {
                cout<< str[right] <<" IS A LEFT BRACKET SIGN\n";
            }
            if (isRbracket(str[right]) == true)
            {
                cout<< str[right] <<" IS A RIGHT BRACKET SIGN\n";
            }
            if (isEnum(str[right]) == true)
            {
                cout<< str[right] <<" IS A ENUMERATION SIGN\n";
            }
            if (isComment(str[right]) == true)
            {
                cout << "COMMENT(";
                for (int i = right; i < len; i++)
                {
                    cout << str[i];
                }
                cout <<")\n";
                break;
            }
            // after each verification we go to the next character by increasing the rigth delimiter
            right++;
            // and making equal the left delimiter with the right one
            left = right;
        } 
        // in case if there we find a punctuator and the left and right delimiters are not of the same value 
        // or even when the right delimiter is equal with the length of the string and the left and right delimiters are not of the same value
        else if (isPunctuator(str[right]) == true && left != right || (right == len && left != right)) 
        {
            // then we extract the substring, considering the initial string, the start position of the substring aand its end, but without one unit because we have as the last character the punctuator
            char* sub = subString(str, left, right - 1);
            // then verify if the obtained substing is equal with one of the below words, by their functions
            // and print their type
            if (isKeyword(sub) == true)
            {
                cout<< sub <<" IS A KEYWORD\n";
            }
            else if (isLetword(sub) == true)
            {
                cout << "LET\n";
            }
            else if (isMainword(sub) == true)
            {
                cout << "MAIN\n";
            }
            else if (isFunctionword(sub) == true)
            {
                cout << "FUNCTION\n";
            }
            else if (isTrueword(sub) == true)
            {
                cout << "TRUE\n";
            }
            else if (isFalseword(sub) == true)
            {
                cout << "FALSE\n";
            }
            else if (isIfword(sub) == true)
            {
                cout << "IF\n";
            }
            else if (isElseword(sub) == true)
            {
                cout << "ELSE\n";
            }
            else if (isReturnword(sub) == true)
            {
                cout << "RETURN\n";
            }
            else if (isWhileword(sub) == true)
            {
                cout << "WHILE\n";
            }
            else if (isBreakword(sub) == true)
            {
                cout << "BREAK\n";
            }
            else if (isContinueword(sub) == true)
            {
                cout << "CONTINUE\n";
            }
            else if (isDoword(sub) == true)
            {
                cout << "DO\n";
            }
            else if (isSwitchword(sub) == true)
            {
                cout << "SWITCH\n";
            }
            else if (isCaseword(sub) == true)
            {
                cout << "CASE\n";
            }
            else if (isStructword(sub) == true)
            {
                cout << "STRUCT\n";
            }
            else if (isEnumword(sub) == true)
            {
                cout << "ENUM\n";
            }
            else if (isConstword(sub) == true)
            {
                cout << "CONST\n";
            }
            else if (isForword(sub) == true)
            {
                cout << "FOR\n";
            }
            else if (isNumber(sub) == true)
            {
                cout << "NUMBER(" << sub <<")\n";
            }
            else if (validIdentifier(sub) == true && isPunctuator(str[right - 1]) == false)
            {
                cout << "IDENTIFIER("<< sub << ")\n";
            }
            else if (validIdentifier(sub) == false && isPunctuator(str[right - 1]) == false)
            {
                cout<< sub <<" NOT A VALID IDENTIFIER\n";
            }
            // at the end of the word verification, we make the left delimiter equal with the right one
            left = right;
        }
    }
    cout << "]" << endl;
    return;
}

int main()
{
    // the main string, code of characters
    char c[1000] = "let age = 1.87; let result = 10.12 * (20 / 2);let new_array = [0, 1, 2, 3, 4, 5]; let map = {name: First_Name, age: 28}; fn add(first int, second int) { return first + second;} fn fibonacci (number int) { if (x == 0) { return 0;} else { if (x == 1) { return 1;} else { return fibonacci(number: x - 1) + fibonacci(number: x - 2);} } } main() { let i = 7; let sum = add(first: 2, second: 4); new_array[0]; map [name]; if (sum > i) { return true;} else { let difference = i - sum; fibonacci(number : difference); return false; } }";
    parse(c);
    return 0;
}