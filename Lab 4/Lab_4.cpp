#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

// equal - verifies the equality between 2 strings 
bool equal(string A,string B)
{
    // eq - the equality between 2 strings, initially set as 1, positive, equal
    bool eq = 1;
    // if the lengths of the stringa are equal
    if(A.length( ) == B.length())
    {
        // then for each character of any af those strings
        for(int i = 0; i < A.length(); i++)
        {
            // if the characters of the strings at the same index are not equal
            if(A[i] != B[i])
            {
                // then we establish the inequality between those 2 strings, by negative value 0 
                eq = 0;
                // and break the loop
                break;             
            }               
        }
    }
    // otherwise we just set the inequality between those 2 strings, by negative value 0
    else eq = 0;
    return eq;
}

// retstart - will show the new first start point, which will usually be SS
string retstart(string N)
{
    // B - striing of 
    string B;
    // for each character we verify      
    for(int  i = 0; i < N.length(); i++)
    {
        // if the character is going to be a - symbol, then we break to loop
        if(N[i] == '-') break;
        // else we add to the string B the characters before - symbol
        else B += N[i];     
    }  
    return B;       
}  

// inlist2 - verifies the presence of the epsilon state (C) in other rules, especially left-hand side 
bool inlist2(int arr[],int f,int m)
{
    // arr - a separate array where we saved the index, position of state that goes in epsilon $ (in my case it is C)
    // f - the presence of the state, that goes in epsilon $
    // m - index of a character of the specific rule
    // t - the presence of the epsilon state in other rules
    bool t=0;
    // for each presence of the state, that goes in epsilon $
    for(int i = 0; i < f; i++)
    {
        // if in the array of indexes for epsilon states (C) we find the same index of the current charactre of the rule, especially left-hand side 
        // then we the presence of the epsilon state in other rules as positive, equal with 1
        if(arr[i] == m) t = 1;
    }
    return t;
}

//function to remove start state from right
//check for start
// Rstart - will show the first start point, which will usually be S
char Rstart(string N) 
{
    // s - the character of the input
 	char s;
    // if the length of the input is bigger than 0 
 	if(N.length() > 0)
 	{
        // then for each character we verify
        for(int i = 0; i < N.length(); i++)
        {
            // if there are characters
            if(N[i] != NULL)
            {
                // then set the value of char s as that character
                s = N[i];
                // and return it by breaking the loop
                break;
            }
        }
    }
 	return s;
} 

// verify if the character m is present in the string N
bool inlist(string N,char m)
{
    // t - represents the presence of the character in the string
    bool t = 0;
    // for each character we verify 
    for(int i = 0;i < N.length(); i++)
    {
        // if the currect character is the same char, then we set the presence of the same character in string as positive, by 1
        if(N[i] == m) t = 1;
    }
    return t;
}

 //fuction for checking  $
 bool search$(string N,int i)
 {
    // A - represent the presence of empty string
 	bool A = 0;
     // for the length of the input string, especially from an index that was the in the left part, we verify
 	for(int j = i; j < N.length(); j++)
 	{
        // if the character is empty string
 		if(N[j] == '$')
 		{
            // the we set the presence of the empty string, positive
 			A = 1;
            // and break the loop 
 			break;
 		}
        // if there are already a comma or a point sign, then we break the loop
 		if(N[j]==',' || N[j]=='.') break;
 	}
 	return A;
 }

 //search for LHS (NON terminal)
 char RLHS(string N,int i) 
 {
 	char m;
    // if the length of the string 
 	if(N.length() > 0)
 	{
        // for each character of the string we verify
        for(int s = i; s < N.length(); s++)
        {
            // if there are characters
            if(N[s] != NULL)
            {
                // then write those words in the new string
                m = N[s];
                // and we get tha char and break the loop
                break;
            }
        }
    }
    return m;
}
  
//check for start in RHS (right-hand side)
// checkR1 - will check for start point in RHS (right-hand side), which will usually be 1, present, positive
bool checkR1(string N,char s)
{
    // A - checks is the right-hand side is ok
 	bool A=0;
    // for each character we verify
 	for(int i = 0; i < N.length(); i++)
 	{
        // if it is already great, then we break the loop
        if(A == 1) break;
        // if there is found the > symbol
        if(N[i] == '>')
        {
            // then for each next character after > we verify
            for(int j = i + 1; j < N.length(); j++)
            {
                // if next character is the previously determined char
                if(N[j] == s)
                {
                    // then we set the value of the boolean value A equal with 1, positive
                    A = 1;
                    // and go to the next character, by setting the value of i equal to the value of j
                    i = j;
                    // and by breaking the loop
                    break;
                }	
                // if the character is a comma or point sign
                if(N[j]==','|N[j]=='.')
                {
                    // then to the next character, by setting the value of i equal to the value of j
                    i = j;
                    // and by breaking the loop 
                    break;
                }
            }	
        }
    }
    return A;
}

//Rule 1 eliminate the start symbol from the right 	 
// y - will represent the input string + one more initial start point SS -> S
string R1(string N,bool A,char s)
{
	string p;
    // if the right-hand side is ok
	if(A)
    {
        // then we add to the string p new strings
        p+="SS->";
        // we add the character S to the substring 
        p+=s;
        // and a comma, so as to divide the rules
        p+=",";
        // for each character we verify 
        for(int i = 0; i < N.length(); i++)
        {
            // if there are characters, then we add those characters to the new p string
            // we get the rest of the initial input
            if(N[i] != NULL) p+=N[i];
        }
    }
    // if the right-hand side is not ok
    else
    {
        // for each character we verify 
        for(int i = 0; i < N.length(); i++)
        {
            // if there are characters, then we add those characters to the new p string
            // we get the rest of the initial input
            if(N[i] != NULL) p+=N[i];
        }
    }
    return p;
} 	

//Rule 2
// ignore the start state
// eliminate the $ from RHS (right-hand side) for the other rules
// R2A - will show the state that goes in epsilon $ (in my case it is C)
string R2A(string N)
{
    string epslon;
    // for each character we verify 
    for(int i = 0; i < N.length(); i++)
    {
        // if the character is a comma
        if(N[i] == ',')
        {
            // then we increase the number of iterations
            i++;
            // from the left-hand side
            // the char at the next possition
            char s = RLHS(N,i);
            // if there is present empty string
            if(search$(N,i))
            {
                // then we add to the epsilon string the new char that was in the left
                epslon += s;	                                
            }
        }
    }
    return epslon;
}	

// R2B - will show all the rule starting from SS -> S, but without empsilon $ rule
string R2B(string N,string e)
{
    string p;
    // for each character we do
    for(int i = 0; i < N.length(); i++)
    {
        // add to the string the characters from the initial input 
        p += N[i];
        // if the character is a comma sign
        if(N[i] == ',')
        {
            // then we go to the next character, especially from left
            i++;
            // and add then to the new string
            p += N[i];
            // if the character from the initial string N at index i is present in the e string
            if(inlist(e, N[i]))
            {
                // then we add to the new string the new rule
                p += "->";
                // and skip the part in the input string ->
                i += 3;
                // then we go starting from the new established index, especially the right part
                for(int j = i; j < N.length(); j++)
                {
                    // if the character is one of the below symbols
                    if(N[j]!=',' && N[j]!='.' && N[j]!='$')
                    {
                        // then we just add those in our new string
                        p += N[j];
                    }
                    // but if the character is an empty string
                    else if(N[j]=='$')
                    {
                        // then we save the value of the index, positon of the empty character
                        int pp = j; //pre and post  
                        // and if at the previous index and the next index the character is a > and | sign 
                        if(N[pp-1]=='>' && N[pp+1]=='|')
                        {
                            // then we go to the character
                            j++;
                        }
                        // if at the previous index and the next index the character is a | and > sign 
                        else if(N[pp-1]=='|' && N[pp+1]=='|')
                        {
                            // then we go to the character
                            j++;
                        }
                        // if the previous character is the | sign
                        else if( N[pp-1] == '|')
                        {
                            // then we set the index value of the character from the felt equal with the character from the right
                            i = j;  
                            string s;
                            // we add to the string s the current string p
                            s += p;
                            // and set again p as empty 
                            p="";  
                            // for each character of the string s, we add to the string p the chracters from string s 
                            for(int i = 0; i < s.length() - 1; i++) p += s[i];
                            // and again initialise the srting s as empty
                            s="";
                            break; 
                        } 
                    }
                    // but if the character is not an empty string
                    else
                    {
                        // we are waiting for comma or dot.
                        i = j - 1; 
                        break;    
                    }
                } 
            }        
        } 	
    }
 return p;
}

// R2C - will show the new rules created without epsilon $, in form of S(A), which means S goes into A, without any C, like: S(A)A(AS)A(B)D(ab)
string R2C(string N,string e,string S)
{
    // N - will show all the rule starting from SS -> S, but without empsilon $ rule
    // e - will show the state that goes in epsilon $ (in my case it is C)
    // S - will show the new first start point, which will usually be SS
    // B - represent each rule of the same state
    string B;   
    // NewN - will show all the rule starting from SS -> S, but without empsilon $ rule
    string NewN;
    // LHS - represents the left-hand side
    string LHS;
    // add - string that will necessary to add in the rules
    string add;
    // for each epsilon state
    for(int i = 0; i < e.length(); i++)
    {
        // going throught each character of the input rules, that don't have already the epsilon rule
        for(int j = 0; j < N.length(); j++)
        {
            // we ferify if the current character is not a - and > symbols, then we add the current character to the left-hand side
            if(N[j]!='-' && N[j]!='>') LHS += N[j];   
            // if the current character is an > symbols       
            if(N[j] == '>')
            {
                // then we go to the next character by adding one more unit to the index
                j++; 
                // while the current character is not a , and . symbols (until we get to the next rules of other states)
                while(N[j]!=',' && N[j]!='.')
                {
                    // initialize all the variables as 0 and empty
                    int flag = 0;
                    // arr - a separate array we save the index, position of state (in my case it is C)
                    int arr[1000] = {0};  
                    B = "";      
                    // while the current character is not a |  ,  . symbols (until we get to the next rules of the same state) 
                    while(N[j]!='|' && N[j]!=',' && N[j]!='.')
                    {
                        // we add to the string B the current elements
                        B += N[j];
                        // and go to the next character
                        j++;
                    }
                    // g - ig going to be the equal with index j
                    int g = j;
                    // if the current character is a | sign
                    if(N[j] == '|')
                    {
                        // then we go to the next character by adding one more unit to the index 
                        j++;
                    }
                    // if the length of each rule of the same state is bigger than 0
                    if(B.length() > 0)
                    {
                        int in = 0;
                        // for each character of the string we do
                        for(int p = 0; p < B.length(); p++)
                        {
                            // if the current character is one the states, that goes in epsilon $ (in my case it is C)
                            if(B[p] == e[i])
                            {
                                // then we set the presence of the state, that goes in epsilon $, by increasing the flag
                                flag++;
                                // in a separate array we save the index, position of state (in my case it is C)
                                arr[in] = p;
                                in++;
                            }
                        }
                        // in case if there were found any presence of the state, that goes in epsilon $ 
                        if(flag > 0)
                        {
                            // than we add to the string for addition, the left-hand side of the rules, like for: S->AC, then we add S(
                            add += LHS;
                            add += "("; 
                            // if the length of the specific rule is bigger that 1 and there is the presence of the state, that goes in epsilon $ 
                            if(B.length() > 1 && flag == 1)
                            {
                                // for each character of the specific rule
                                for(int m = 0; m < B.length(); m++)
                                {
                                    // inlist2 - verifies the presence of the epsilon state (C) in other rules, especially right-hand side 
                                    if(!inlist2(arr,flag,m))
                                    // if it is not presence of the epsilon state then we add the characters that were near the epsilon state
                                    // like for: S->AC, then we have S(A)   
                                    add += B[m];      
                                }
                                add += ")";     
                            }
                            // if the length of the specific rule is equal with 1 and there is the presence of the state, that goes in epsilon $  
                            else if(B.length() == 1 && flag == 1)
                            {
                                // if the right-hand side and the new first start point has the same characters
                                if(equal(LHS,S))
                                { 
                                    // then we will get an empty rule, nowhere to go
                                    add += "$)";
                                }
                                // else we just put again the parantheses
                                else add += " )";
                            }
                            else 
                            {
                                // if the current character is a , or . symbols (until we get to the next rules of other states)
                                // then we add to the new-rules string the | symbol
                                if(N[j]=='.'|N[j]==',') NewN += '|';
                                // set_size - repesent as well the presence of the state, that goes in epsilon $
                                int set_size = flag;
                                // arr2 - a separate array we save the index, position of state (in my case it is C)
                                int arr2[1000] = {0};
                                // we raise to power, which means that it will returns base raised to the power exponent: base ^ exponent
                                // thus, we will get 2 ^ set_size
                                // pow_set_size - how many rules will appear, like for CC, there will be 2^2=4: CC|$C|C$|$$
                                int pow_set_size = pow(2, set_size);
                                // counter - number of the repetition of the state, that goes in epsilon $, like for CCC, there will be 3
                                int counter, j;
                                // if the presence of the state, that goes in epsilon $ is equal with the length of the specific rule, like: CCC
                                // then we decrease the pow_set_size
                                if(flag == B.length()) pow_set_size--;
                                // conter going throught the for loop, starting from 1 until pow_set_size
                                for(counter = 1; counter < pow_set_size; counter++)
                                {
                                    // for each presence of the state, that goes in epsilon $, we decrease the value from the array at that specific index by one
                                    for(int m = 0; m < set_size; m++) arr2[m] =- 1;
                                    // for the presence of the state, that goes in epsilon $
                                    for(j = 0; j < set_size; j++)
                                    {
                                        // if the counter is positive and there are more presences of the state, that goes in epsilon $
                                        if(counter & (1<<j))
                                        {
                                            // then we set the value of new array equal to the saved the index, position of state (in my case it is C)
                                            arr2[j]=arr[j];
                                        }
                                    }
                                    // for each character of the specific rule 
                                    for(int k = 0; k < B.length(); k++)
                                    {
                                        // inlist2 - verifies the presence of the epsilon state (C) in other rules, especially right-hand side 
                                        if(!inlist2(arr2,set_size,k))
                                        // if it is not presence of the epsilon state then we add the characters that were near the epsilon state
                                        // like for: S->AC, then we have S(A)
                                        add += B[k];
                                    }
                                    // we establish the value of f as how many rules will appear, like for CC, there will be 2^2=4: CC|$C|C$|$$
                                    int f = pow_set_size; 
                                    // if the repretitions of the state, that goes in epsilon $ decreased by pow_set_size and one more unit is different from 0
                                    // then we add to the new rule a | symbol        
                                    if(counter - (f - 1)!=0) add += "|";    
                                }
                                add += ")";         
                            }
                        }
                    }
                }
                // again initialise the left-hand side 
                LHS = "";       
            }
        }
    }
    return add;   
}  

// R2D - will show the new rules creted without epsilon $, in form of S->aB|AC|A, that was previously S->aB|AC 
string R2D( string N,string S)
{
    // N - will show all the rule starting from SS -> S, but without epsilon $ rule
    // S - will show the new rules created without epsilon $, in form of S(A), which means S goes into A, without any C, like: S(A)A(AS)A(B)D(ab)
    int m;
    int g;
    string A;
    // New - represent the new rules including the new rules created without and with epsilon $
    string New;
    // LHS - left-hand side of the rules from N
    string LHS;
    // for each character from the input that are without epsilon $ rule
    for(int j = 0; j < N.length(); j++)
    {
        // if the index is bigger that 0, then we add comma to the new string
        if(j > 0) New += ",";                         
        LHS = ""; 
        // while the character of the input is not equal with - and > signs
        while(N[j]!='-' && N[j]!='>')
        {
            // then we add to the new string and left-hand side the characters
            New += N[j];     
            LHS += N[j];
            // and go to the next characters
            j++;              
        }
        // when we get to the sequence "->" then, we pass over it, by adding 2 more units to the index
        j += 2;
        // and add to the new string this sequence "->"
        New += "->";
        // while the character of the input is not equal with , and . signs, especially from the right-hand side
        while(N[j]!=',' && N[j]!='.')
        {
            // then we add each character from the right-hand side
            New += N[j];
            // and go to the next character, by increasing the index value with 1
            j++;                    
        }
        // for each character from new rules created without epsilon $, in form of S(A)
        for(int i = 0; i < S.length(); i++)
        {
            // v - left-hand side of the these rules: S(A), that is S, from parameter string S
            string v = "";  
            // while the character is not a paratheses      
            while(S[i] != '(')
            {        
                // then we add the characters to the new string v
                v += S[i];
                // and go to the next characters
                i++;
            } 
            // if the left-hand side and the string v of characters has the same characters
            if(equal(LHS,v))  // which is true
            {
                // then we go to the next characters
                i++;   
                // if the current character is not equal with a blank space, then we add as well to the new rules a | symbol           
                if(S[i] != ' ') New += "|";         
                // starting from the index of the current character        
                for(int a = i; a < S.length(); a++)
                {
                    // if the characters that are not null and not a paranthesis, and a blank space, then we add as well to the new rules those characters
                    // especially what is between paranthesis      
                    if(S[a]!=NULL && S[a]!=')' && S[a]!=' ') New += S[a];
                    // if we are already at the closing parenthesis
                    if(S[a] == ')')
                    {
                        // then the save the index, position of the closing parenthesis
                        g = a;    
                        // and break the loop       
                        break;
                    }
                    // we save the index, position of the closing parenthesis
                    g = a;
                }
                // and set the index i equal with the index, position of the closing parenthesis
                i = g;
            }
            // if the left-hand side and the string v of characters has not the same characters
            else
            {
                // while the character is not a closing parenthesis, we are going to the next characters
                while(S[i] != ')') i++;
            }
            v = "";
        }                
    }
    // let see if the last character of the new rules for empilon is a . sign
    int gf = New.length() - 1;
    // if it is not, then we add to the string the point .
    if(New[gf] != '.') New += ".";                   
    return New;
} 

// R2Final - will show the final rules after removing epsilon-productions 
string R2Final(string N)
{
    // m - current index as the index at which we stopped, but with 1 more unit
    // y - current index as the index at which we stopped
    int m = 0;
    int y = 0;
    // repetitions - will define when there are the same characters in strings
    int repetitions = 0;
    // A, B - right-hand side of the each rule
    string A;
    string B;
    // New - the new string of rules
    string New;
    // for each character of the rules
    for(int i = 0; i < N.length(); i++)//All
    {
        // while the character is not equal with > symbol
        while(N[i] != '>')
        {
            // we add to the new string the left-hand side characters
            New += N[i];
            // and go to the next character, by adding one more unit to the index
            i++;
        }   
        // we add as well the > symbol
        New += N[i];
        // and go to the next character
        i++;
        // having j, that starts from the index after > symbol
        for(int j = i; j < N.length(); j++) //one rule
        {
            // A - right-hand side of the each rule
            A = "";
            // while the each character is not a . | , 
            while(N[j]!='.' && N[j]!='|' && N[j]!=',')
            {
                // then we add those characters to A string
                A += N[j];
                // and go to the next character
                j++;
            }
            // if the character is a . or , 
            if(N[j]=='.' || N[j]==',')
            {
                // then we add the gathered string A of characters to the new string of rules 
                New += A;
                // as well as the last value, which can be either . or ,
                New += N[j];
                // set the current index as the index at which we stopped
                i = j;
                // and break the loop
                break;                     
            } 
            // m - current index as the index at which we stopped, but with 1 more unit
            m = j;
            m++;
            // y - current index as the index at which we stopped
            y = j;   
            // for the next rules 
            for(int k = m; k < N.length(); k++) //comparison
            {
                repetitions = 0;      
                // if the character at this index is equal with | symbol, then we go to the next character, by increasing the index
                if(N[k] == '|') k++;
                // in case if the character is a . or , then break the loop, because it is the end of the rule 
                if(N[k]==',' || N[k]=='.') break;
                // B - right-hand side of the each rule   
                B = "";
                // while the each character is not a . | , 
                while(N[k]!='|' && N[k]!=',' && N[k]!='.') 
                {
                    // then we add those characters to B string
                    B += N[k];
                    // and go to the next character
                    k++;
                }
                // we return to the pre-last character
                k--;
                // if the strings A and B has the same characters
                if(equal(A,B))
                {
                    // then we increase the value of repetitions
                    repetitions++;
                    // and break the loop
                    break; 
                }
            }
            // in case if the number of repetitions is 0 
            if(repetitions == 0)
            {
                // then we add to the new rules the string A
                New += A;
                // if character at the current index at which we stopped is | then we add it in our rules
                if(N[y] == '|') New += '|';
            }
        }
    }
    // All - left-hand side of the rules, including the -> sign
    string All;
    // F - final rules
    string F;
    // for each character of the string of new rules 
    for(int m = 0; m < New.length(); m++)// for any c->,    or    c->.
    {
        // while the character is not equal with > symbol 
        while(New[m] != '>')
        {
            // we add to the new string the left-hand side characters
            All += New[m];
            // and go to the next character, by adding one more unit to the index
            m++;                 
        }    
        // we add as well the > symbol 
        All += New[m];
        // and go to the next character
        m++;
        // if the character is a . or ,
        if(New[m]==',' || New[m]=='.')
        {
            // then it does not have sens S->,
            All = "";                                              
        } 
        else
        {
            // we add all gotten states S, A,... to the final rules
            F += All;
            // while the character is not a . and ,
            while(New[m]!=',' && New[m]!='.')
            {
                // then we add everything from the right-hand side of the rules to the final rules
                F += New[m];
                // and go to the next character
                m++;
            }   
            // at the end we add in the . point sign, which is the last
            F += New[m];
            All = "";   
        }                         
    }      
    return F;       
} 

// step 3 - unit rule
// delete ex: A->A 
string R3A(string N)
{
    // New - the new string of rules
    string New;
    // sub - left-hand side characters of a rule
    string sub;
    // LHS - left-hand side characters of the each rule
    string LHS;
    // sub2 - right-hand side characters of a rule
    string sub2;
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        sub = "";  
        // while the character is not a . and ,  
        while(N[i]!=',' && N[i]!='.')
        {
            // we add to the new substring the left-hand side characters
            sub += N[i];
            // and go to the next character, by adding one more unit to the index
            i++;                             
        }
        // len - will be the length of the substring
        int len = sub.length(); 
        // for each character of the substring left-hand side
        for(int j = 0; j < len; j++)
        {
            // if the index is equal with 0, which will be
            if(j == 0)
            {
                LHS = "";
                // while the character of the substring is not equal with a - symbol
                while(sub[j] != '-')
                {
                    // then we add to the left-hand side and new string the characters
                    LHS += sub[j];
                    New += sub[j];
                    // and go to the next character
                    j++;
                }
                // when we get to the sequence "->" then, we pass over it, by adding 2 more units to the index
                // and add to the new string this sequence "->"
                New += "->";
                j += 2;
            }
            sub2 = "";
            // while the character of the substring is not equal with a | symbol and it does not represent the last character
            while(sub[j]!='|' && j!=len)
            {
                // then we add to the second new substring the characters from the right-hand side
                sub2 += sub[j];
                // and go to the next character
                j++;                  
            }
            // in case if the length of the second substring is bigger that 1, for ex: ASC from A->ASC
            if(sub2.length() > 1) 
            {
                // then we add the second substring to the new rules
                New += sub2;
                // if we find a | symbol, then we include it as well in the new rules string
                if(sub[j] == '|') New += sub[j];
            }
            else
            {
                // if the length of the second substring is equal with 1, for ex: B, from A->B
                if(sub2.length() == 1)
                {
                    // c - the character that is making the renaming, for ex: B  
                    char c = sub2[0]; 
                    // in case if this right-hand side is equal with a empilon sign (A->$), or if that character is not an uppercase letter (A->a), 
                    // or if the right-hand side is not equal with the left-hand side (A->B)
                    if(equal(sub2,"$") || !isupper(c) || !equal(LHS,sub2))
                    {
                        // we add this character to the new rules
                        New += sub2;
                        // if the character is equal with | symbol  
                        if(sub[j] == '|')
                        {
                            // then we add it in the new rules
                            New += sub[j];
                        }
                    }
                    else
                    {
                        // if the current index is equal with the length of the left-hand side
                        if(j == sub.length())
                        {
                            // then we create one more string for rules
                            string New2;
                            // where we store each rule
                            New2 += New;
                            // and initialise the previous string of rules
                            New = "";
                            // for each character of the new string of rules, we put back all the rules
                            for(int e = 0; e < New2.length() - 1; e++) New += New2[e];
                            New2 = ""; 
                        }
                    }
                }
            }
            // in case if the current index is equal with the length of the left-hand side
            if(j == sub.length())
            {
                // then we add the left-hand side character to the new rules
                New += N[i];
            }                                                  
        }                             
    }                                
    return New; 
}

string R3B(string N)
{
    // New - the new string of rules
    string New;
    // sub - left-hand side characters of a rule
    string sub;
    // LHS - left-hand side characters of the each rule
    string LHS;
    // sub2 - right-hand side characters of a rule
    string sub2;
    bool count = 0;
    // subloop - the right-hand side characters (A->B)
    string subloop;
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        sub = "";  
        // while the character is not a . and ,   
        while(N[i]!=',' && N[i]!='.')
        {
            // we add to the new substring the left-hand side characters
            sub += N[i];
            // and go to the next character, by adding one more unit to the index
            i++;                            
        }
        // len - will be the length of the substring
        int len = sub.length();
        // for each character of the substring left-hand side
        for(int j = 0; j < len; j++)
        {
            // if the index is equal with 0, which will be
            if(j == 0)
            {    
                LHS = "";
                // while the character of the substring is not equal with a - symbol
                while(sub[j] != '-')
                {
                    // then we add to the left-hand side and new subloop string the characters
                    LHS += sub[j];
                    subloop += sub[j];
                    // and go to the next character
                    j++;               
                }
                // when we get to the sequence "->" then, we pass over it, by adding 2 more units to the index
                // and add to the new subloop string this sequence "->"
                subloop += "->";                   
                j += 2;
            }
            sub2 = "";
            // while the character of the substring is not equal with a | symbol and it does not represent the last character
            while(sub[j]!='|' && j!=sub.length())
            {
                // then we add to the second new substring the characters from the right-hand side
                sub2 += sub[j];
                // and go to the next character
                j++;                  
            }
            // in case if the length of the second substring is bigger that 1, for ex: ASC from A->ASC
            if(sub2.length() > 1) 
            {
                // then we add the second substring to the subloop string of rules
                subloop += sub2;
                // if we find a | symbol, then we include it as well in the subloop string of rules
                if(sub[j] == '|') subloop += sub[j];
            }
            else
            {
                // if the length of the second substring is equal wuth 1, for ex: B, from A->B
                if(sub2.length() == 1)
                {
                    // c - the character that is making the renaming, for ex: B 
                    char c = sub2[0]; 
                    // in case if this right-hand side is equal with a empilon sign (A->$), or if that character is not an uppercase letter (A->a)
                    if(equal(sub2,"$") || !isupper(c))
                    {
                        // we add this character to the subloop string of rules
                        subloop += sub2;
                        // if the character is equal with | symbol, then we add it as well
                        if(sub[j] == '|') subloop += sub[j];
                    }
                    // if the right-hand side is not equal with the left-hand side (A->B)
                    else if(equal(LHS,sub2))
                    {
                        // if the current index is equal with the length of the left-hand side
                        if(j == sub.length())
                        {
                            // then we create one more string for rules
                            string New2;
                            // where we store each obtained rule
                            New2 += subloop;
                            // and initialise the previous string of rules
                            subloop = "";
                            // for each character of the new string of rules, we put back all the rules
                            for(int e = 0; e < New2.length()-1; e++) subloop += New2[e];
                            New2 = ""; 
                        }     
                    }  
                    else
                    {
                        // set count as 1 
                        count = 1;
                        // for each character ofthe initial rules
                        for(int k = 0; k < N.length(); k++)
                        {
                            string LHS2 = "";     
                            // while the character of the rules is not equal with a - symbol    
                            while(N[k] != '-')
                            { 
                                // then we add to a new left-hand side the current characters
                                LHS2 += N[k];
                                k++;               
                            } 
                            // when we get to the sequence "->" then, we pass over it, by adding 2 more units to the index
                            k += 2;
                            // in case if right-hand side characters of a rule are not equal with the left-hand side (A->B)
                            if(!equal(sub2,LHS2))
                            {
                                // and while the character is not a . and , 
                                while(N[k]!='.' && N[k]!=',')
                                {
                                    // and go to the next character, by adding one more unit to the index 
                                    k++;
                                }               
                            }
                            // in case if right-hand side characters of a rule are equal with the left-hand side (A->B)
                            else 
                            {
                                // when we include more rules in the subloop of rules
                                // while the character is not a . and , 
                                while(N[k]!='.' && N[k]!=',')
                                {
                                    // we add the current character to the new substring the subloop string of rules
                                    subloop += N[k];
                                    // and go to the next character
                                    k++;   
                                }
                                // if we find a | symbol, then we include it as well in the new subloop string of rules 
                                if(sub[j] == '|') subloop += sub[j];
                                break;
                            }
                        }       
                    }         
                }                                                       
            } 
            // in case if the current index is equal with the length of the left-hand side and count is equal with 1
            if(j==sub.length() && count==1)
            {
                // then we decrease the index
                j =- 1; 
                // set the count equal to 0
                count = 0;
                // put in the left-hand side the obtained subloop string of rules
                sub = "";
                sub += subloop;
                subloop = ""; 
                // len - will be the length of the substring
                len = sub.length();
            }
            else 
            {
                // in case if the current index is equal with the length of the left-hand side and count is equal with 0
                if(j==sub.length() && count==0)
                {
                    // then we add the left-hand side character to the new rules
                    New += sub;
                    subloop = "";
                    // we add the left-hand side character to the new rules
                    New += N[i];
                }   
            } 
        }                  
    }     
    return New;                 
} 

// inlist123 - verifies the presence of the char m in string rules N
bool inlist123(string N,char m)
{
    // t - represents the presence of the character in the string
    bool t = 0;
    // for each character we verify 
    for(int i = 0;i < N.length(); i++)
    {
        // if the currect character is the same char, then we set the presence of the same character in string as positive, by 1
        if(N[i] == m) t = 1;
    }
    return t;
}

// y4 - will show the innacessable states
string R4A(string N)
{
    // inac - innacessable states
    string inac;
    // New - the new string of rules
    string New;
    // LHS - left-hand side characters of the each rule
    // RHS1 - right-hand side characters of the each rule
    string LHS;
    string RHS1;
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        // if the current character is a - sign and the next character is a > symbol
        if(N[i] == '-' && N[i+1] == '>')
        {
            // then we add to the left-hand side characters of the each rule, the character before the actual -> sequence
            LHS += N[i-1];
        }                
    }   
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        // if the current character is not any of these -  > sign 
        if(N[i] != '-' && N[i] != '>')
        {
            // then we add to the right-hand side characters of the each rule, each character of teh rules
            RHS1 += N[i-2];
        
        }                
    }
    // for each character from the right-hand side characters of the each rule
    for(int i = 0; i < RHS1.length(); i++)
    {
        // if there is a character from left-hand side that is not the present in the right-hand side of rules 
        if(!(inlist123(RHS1, LHS[i])))
        {
            // then we add to the string of innacessable the corresponding character, in my case it is E 
            inac+=LHS[i];
            // and break the loop
            break;
        }              
    }
    return inac;                 
}  

// R5A - will show all the rules, without the rules that contain innaccesable states
string R5A(string N, string E)
{
    // New - the new string of rules
    string New;
    // we set the character which is innaccesable
    char S = E[0];
    // l, d - length of the rules of the innaccesable character
    // b - the inndex position of the innaccesable character
    int l, d, b;
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        // if the character is equal with the innaccesable character
        if (N[i] == S)
        {
            // then we save the position, index of the innaccesable character
            b = i;
            // for each character from the start until the innaccesable character, we add the rules to the new string of rules
            for (int j = 0; j<i; j++) New += N[j];
        }
    }
    // determine the length of the rules of the the innaccesable character
    // for the elements starting from the index of the innaccesable character
    for (int k = b; k < N.length(); k++)
    {
        // in case if the character is not the innaccesable character
        if(N[k] != S)
        {
            // the length of the rules of the the innaccesable character will be increased
            l++;
            // the character is going to be equal with a comma
            if(N[k] == ',') 
            {
                // then we add this one mmore unit for comma
                l++;
                // and break the loop
                break;
            }
        }    
    }
    // set d equal with ength of the rules of the innaccesable character
    d = l;
    // starting from the last character of the last rule of the innaccesable character, we add the rest of the rules
    for (int m = b + d; m< N.length(); m++) New += N[m];  
    return New;                 
}  

string R6A(string N)
{
    string B;  
    string add1; 
    // NewN - will show all the rule starting from SS -> S, but without empsilon $ rule
    string NewN;
    // LHS - represents the left-hand side
    string LHS;
    // add - string that will necessary to add in the rules
    string add;
    // for each epsilon state
        // going throught each character of the input rules, that don't have already the epsilon rule
        for(int j = 0; j < N.length(); j++)
        {
            // we ferify if the current character is not a - and > symbols, then we add the current character to the left-hand side
            if(N[j]!='-' && N[j]!='>') LHS += N[j];   
            // if the current character is an > symbols       
            if(N[j] == '>')
            {
                // then we go to the next character by adding one more unit to the index
                j++; 
                // while the current character is not a , and . symbols (until we get to the next rules of other states)
                while(N[j]!=',' && N[j]!='.')
                {
                    // initialize all the variables as 0 and empty
                    int flag = 0;
                    int flag1 = 0;
                    // arr - a separate array we save the index, position of state (in my case it is C)
                    int arr[1000] = {0};  
                    int arr1[1000] = {0}; 
                    B = "";      
                    // while the current character is not a |  ,  . symbols (until we get to the next rules of the same state) 
                    while(N[j]!='|' && N[j]!=',' && N[j]!='.')
                    {
                        // we add to the string B the current elements
                        B += N[j];
                        // and go to the next character
                        j++;
                    }
                    // g - ig going to be the equal with index j
                    int g = j;
                    // if the current character is a | sign
                    if(N[j] == '|')
                    {
                        // then we go to the next character by adding one more unit to the index 
                        j++;
                    }
                    // if the length of each rule of the same state is bigger than 0
                    if(B.length() > 0)
                    {
                        int in = 0;
                        int in1 = 0;
                        // for each character of the string we do
                        for(int p = 0; p < B.length(); p++)
                        {
                            // if the current character is one the states, that goes in epsilon $ (in my case it is C)
                            if(isupper(B[p]))
                            {
                                // then we set the presence of the state, that goes in epsilon $, by increasing the flag
                                flag++;
                                // in a separate array we save the index, position of state (in my case it is C)
                                arr[in] = p;
                                in++;
                            }
                            // else if (!isupper(B[p]))
                            // {
                            //     flag1++;
                            //     arr1[in1] = N[j];
                            //     in1++;

                            // }
                        }
                    }
                    // in case if there were found any presence of the state, that goes in epsilon $ 
                        if(flag > 0)
                        {
                            // than we add to the string for addition, the left-hand side of the rules, like for: S->AC, then we add S(
                            add += LHS;
                            add += "("; 
                            // if the length of the specific rule is bigger that 1 and there is the presence of the state, that goes in epsilon $ 
                            if(B.length() > 1 && flag == 1)
                            {
                                // for each character of the specific rule
                                for(int m = 0; m < B.length(); m++)
                                {
                                    // inlist2 - verifies the presence of the epsilon state (C) in other rules, especially right-hand side 
                                    if(!inlist2(arr,flag,m))
                                    // if it is not presence of the epsilon state then we add the characters that were near the epsilon state
                                    // like for: S->AC, then we have S(A)   
                                    add += B[m];      
                                }
                                add += ")";     
                            }
                            // if the length of the specific rule is equal with 1 and there is the presence of the state, that goes in epsilon $  
                            else if(B.length() == 1 && flag == 1)
                            {
                                // if the right-hand side and the new first start point has the same characters
                                if(equal(LHS,"S"))
                                { 
                                    // then we will get an empty rule, nowhere to go
                                    add += "$)";
                                }
                                // else we just put again the parantheses
                                else add += " )";
                            }
                            else 
                            {
                                // if the current character is a , or . symbols (until we get to the next rules of other states)
                                // then we add to the new-rules string the | symbol
                                if(N[j]=='.'|N[j]==',') NewN += '|';
                                // set_size - repesent as well the presence of the state, that goes in epsilon $
                                int set_size = flag;
                                // arr2 - a separate array we save the index, position of state (in my case it is C)
                                int arr2[1000] = {0};
                                // we raise to power, which means that it will returns base raised to the power exponent: base ^ exponent
                                // thus, we will get 2 ^ set_size
                                // pow_set_size - how many rules will appear, like for CC, there will be 2^2=4: CC|$C|C$|$$
                                int pow_set_size = pow(2, set_size);
                                // counter - number of the repetition of the state, that goes in epsilon $, like for CCC, there will be 3
                                int counter, j;
                                // if the presence of the state, that goes in epsilon $ is equal with the length of the specific rule, like: CCC
                                // then we decrease the pow_set_size
                                if(flag == B.length()) pow_set_size--;
                                // conter going throught the for loop, starting from 1 until pow_set_size
                                for(counter = 1; counter < pow_set_size; counter++)
                                {
                                    // for each presence of the state, that goes in epsilon $, we decrease the value from the array at that specific index by one
                                    for(int m = 0; m < set_size; m++) arr2[m] =- 1;
                                    // for the presence of the state, that goes in epsilon $
                                    for(j = 0; j < set_size; j++)
                                    {
                                        // if the counter is positive and there are more presences of the state, that goes in epsilon $
                                        if(counter & (1<<j))
                                        {
                                            // then we set the value of new array equal to the saved the index, position of state (in my case it is C)
                                            arr2[j]=arr[j];
                                        }
                                    }
                                    // for each character of the specific rule 
                                    for(int k = 0; k < B.length(); k++)
                                    {
                                        // inlist2 - verifies the presence of the epsilon state (C) in other rules, especially right-hand side 
                                        if(!inlist2(arr2,set_size,k))
                                        // if it is not presence of the epsilon state then we add the characters that were near the epsilon state
                                        // like for: S->AC, then we have S(A)
                                        add += B[k];
                                    }
                                    // we establish the value of f as how many rules will appear, like for CC, there will be 2^2=4: CC|$C|C$|$$
                                    int f = pow_set_size; 
                                    // if the repretitions of the state, that goes in epsilon $ decreased by pow_set_size and one more unit is different from 0
                                    // then we add to the new rule a | symbol        
                                    if(counter - (f - 1)!=0) add += "|";    
                                }
                                add += ")";         
                            }
                        }
                        
                }
                LHS = ""; 
            }
        }
        string left, t, LHS1, add2;
        for(int i = 0; i < N.length(); i++)
        {
            // if the current character is a - sign and the next character is a > symbol
            if(N[i] == '-' && N[i+1] == '>')
            {
                // then we add to the left-hand side characters of the each rule, the character before the actual -> sequence
                LHS1 += N[i-1];
            }                
        }
        for (int i= 0; i<add.length(); i++)
        {
            if(add[i] == '(' && add[i+2] == ')')
            {
                left += add[i-1];
                for (int m = i-1; m< i+3; m++) add1 += add[m];
            }
            if(add[i] == '(' && add[i+3] == ')')
            {
                left += add[i-1];
                for (int n = i-1; n< i+4; n++) add1 += add[n];
            }
        } 
        for (int i= 0; i<LHS1.length(); i++)
        {
            if (!inlist123(left, LHS1[i]))
            {
                t+=LHS1[i];
                for (int j= 0; j<add.length(); j++)
                {
                    if((add[j] == ')') && (add[j+1]==LHS1[i]))
                    {
                        left += add[j+1];
                        for (int k = j+1; k< j+7; k++) 
                        {
                            if(add[k] != '|') add1 += add[k];
                        }
                        // add1 = S(a)S(a)S(b)S(a)S(a)S(b)A(a)A(b)B(b)D(ab)C(AB)
                    }
                }
            }
            // LHS1 = SSABCD
            // left = SSSSSSAABDC
            
        }
        for (int i=0; i< LHS1.length(); i++)
        {
            if (!inlist123(LHS1, left[i]))
            {
                add2 += left[i];
            }
        }
        return add2; 
        // at the end gives nothing, because I do not have non-productive states
}

string prefinal(string N,int &m)
{
    // the rule that new will be added
    string add;
    // New - the new string of rules
    string New;
    // sub - left-hand side characters of a rule
    string sub;
    // sub2 - right-hand side characters of a rule
    string sub2;
    // NRULE - numbers of rule
    int NRULE = 0;
    // the character that is going to be used for the new rules, for ex: #X0#->a
    char A='X';
    // for each character from the rules
    for(int i = 0; i < N.length(); i++)
    {
        sub = "";   
        // while the character is not a . and ,
        while(N[i]!=',' && N[i]!='.')
        {
            // we add to the new substring the left-hand side characters
            sub += N[i];
            // and go to the next character, by adding one more unit to the index
            i++;                             
        }
        // len - will be the length of the substring
        int len = sub.length();
        // for each character of the substring left-hand side
        for(int j = 0; j < len; j++)
        { 
            // if the index is equal with 0, which will be
            if(j == 0)
            {
                // while the character of the substring is not equal with a > symbol    
                while(sub[j] != '>')
                {
                    // then we add to the new string of rules the characters
                    New += sub[j];
                    // and go to the next character
                    j++;              
                }
                // when we get to the sequence "->", especially ">", then, we add it as well
                // and increase the index
                New += sub[j];
                j++;
            }
            sub2 = "";
            // while the character of the substring is not equal with a | symbol and it does not represent the last character
            while(sub[j]!='|' && j!=sub.length())
            {
                // then we add to the second new substring the characters from the right-hand side
                sub2 += sub[j];
                // and go to the next character
                j++;                 
            }
            // B - will represent the right-hand side of the rules already established
            string B = "";
            // in case if the length of the second substring is smaller that 3 and bigger that 0, for ex: AC from S->AC
            if(sub2.length()<3 && sub2.length()>0) 
            {
                string v;                    
                // in case if the length of the second substring is equal with, specifically: AC from S->AC
                if(sub2.length() == 2)	
                {
                    // if the charactesr are not both uppercase lettres, for ex: a and b , from D->ab
                    if(!isupper(sub2[0]) && !isupper(sub2[1]))	
                    {
                        // For the first character of the right-hand side characters of a rule
                        // A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).  
                        // The stringstream class is extremely useful in parsing input. 
                        stringstream case1;  
                        // we added in the first stringstream the number of the rule                                       
                        case1 << NRULE;
                        // in B and add strings we add signs
                        B += "*"; 	
                        add += "*";
                        // and add to both B and add strings, the string A, which is 'X' 
                        add += A;
                        B += A;
                        // then we add to both B and add strings, the current contents of the stream, which is NRULE, 0  
                        B += case1.str();
                        add += case1.str();
                        // in B and add strings we add ending signs
                        B += "*";
                        add += "*";
                        // then we add the transition sequence "->" to the add srtring
                        add += "->";
                        // as well as the first character of the right-hand side characters of a rule
                        add += sub2[0];
                        // and a comma symbol
                        add += ",";
                        // to the new rules we add the right-hand side of the rules, already established
                        New += B;
                        // we increase the number of the rule
                        NRULE++;	
                        B = "";
                        // For the second character of the right-hand side characters of a rule
                        // repeat the same procedure
                        stringstream case2;
                        case2 << NRULE;
                        B += "*"; 	
                        add += "*";
                        add += A;
                        B += A;
                        B += case2.str();
                        add += case2.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        // but in this case we add the second character of the right-hand side characters of a rule to the add string
                        add += sub2[1];
                        add += ",";
                        New += B;
                        NRULE++;	
                        B = "";
                    }
                    // if the first character is an uppercase letter, but the second is not an uppercase letter, for ex: A and b , from D->Ab
                    else if(isupper(sub2[0]) && !isupper(sub2[1])) 
                    {
                        // then we include immediately the uppercase letter, because it does not have the need to be transformed
                        New += sub2[0];  
                        // ceate the stringstream class  
                        stringstream case3; 
                        // repeat the same procedure
                        case3 << NRULE;
                        B += "*";
                        add += "*";
                        add += A;
                        B += A;
                        B += case3.str();
                        add += case3.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        // but in this case we add the second character of the right-hand side characters of a rule to the add string
                        add += sub2[1];
                        add += ",";
                        New += B;
                        NRULE++;	
                        B = "";
                    }
                    // if the first character is not an uppercase letter, but the second is an uppercase letter, for ex: b and A , from D->bA
                    else if(!isupper(sub2[0]) && isupper(sub2[1]))
                    {  
                        // ceate the stringstream class 
                        stringstream case4;
                        // repeat the same procedure
                        case4 << NRULE;
                        B += "*";
                        add += "*";
                        add += A;
                        B += A;
                        B += case4.str();
                        add += case4.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        // but in this case we add the first character of the right-hand side characters of a rule to the add string
                        add += sub2[0];
                        add += ",";
                        New += B;
                        New += sub2[1];
                        NRULE++;	
                        B = "";     
                    }   
                    else 
                    { 
                        // otherwise we just add the charaters from the right-hand side characters of a rule
                        // for ex: AC from S->AC
                        New += sub2;
                    }
                    // if the character from the right is a | sign
                    if(sub[j] == '|')
                    {
                        // then we add it as well in our new rules
                        New += sub[j]; 
                    } 
                }
                // if the length of sub2 is equal with 1
                else
                {
                    // otherwise we just add the charaters from the right-hand side characters of a rule, to the new rules
                    // for ex: a from S->a
                    New += sub2;
                    // if the character from the right is a | sign, then we add it as well in our new rules
                    if(sub[j] == '|') New += sub[j]; 
                }                         
            }
            else
            {   
                // if length of the right-hand side is bigger then 2
                // length - will be the length of the substring
                int length = sub2.length();
                char d;
                int x = 0;
                int x2 = 1;
                // while the length of the right-hand side is bigger or equal to 2
                while(length >= 2)
                {
                    char d ;
                    // if the characters are not both uppercase lettres, for ex: a and b , from D->ab
                    if(!isupper(sub2[x]) && !isupper(sub2[x2]))
                    {
                        // ceate the stringstream class 
                        stringstream case5;  
                        // repeat the same procedure                                    
                        case5 << NRULE;
                        B += "*"; 	
                        add += "*";
                        add += A;
                        B += A;
                        B += case5.str();
                        add += case5.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        // but in this case we add the first character of the right-hand side characters of a rule to the add string
                        add += sub2[x];
                        add += ",";
                        New += B;
                        NRULE++;	
                        B = "";
                        stringstream case6; 
                        case6 << NRULE;
                        B += "*"; 	
                        add += "*";
                        add += A;
                        B += case6.str();
                        add += case6.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        // but in this case we add the second character of the right-hand side characters of a rule to the add string
                        add += sub2[x2];
                        add += ",";
                        New += B;
                        NRULE++;	
                        B = "";	
                    }
                    // if the first character is an uppercase letter, but the second is not an uppercase letter, for ex: A and b , from D->Ab
                    else if(isupper(sub2[x]) && !isupper(sub2[x2])) 
                    {
                        // then we include immediately the uppercase letter, because it does not have the need to be transformed
                        New += sub2[x];
                        // ceate the stringstream class
                        stringstream case7;
                        // repeat the same procedure    
                        case7 << NRULE;
                        B += "*";
                        add += "*";
                        add += A;
                        B += A;
                        B += case7.str();
                        add += case7.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        add += sub2[x2];
                        add += ",";
                        New += B;
                        NRULE++;	
                        B = "";
                    }   
                    // if the first character is not an uppercase letter, but the second is an uppercase letter, for ex: b and A , from D->bA
                    else if(!isupper(sub2[x]) && isupper(sub2[x2]))
                    {
                        // ceate the stringstream class
                        stringstream case8;    
                        // repeat the same procedure
                        case8 << NRULE;
                        B += "*";
                        add += "*";
                        add += A;
                        B += A;
                        B += case8.str();
                        add += case8.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        add += sub2[x];
                        add += ",";
                        New += B;
                        New += sub2[x2];
                        NRULE++;	
                        B = "";     
                    }    
                    else
                    {
                        // ceate the stringstream class
                        stringstream case9;
                        // repeat the same procedure
                        case9 << NRULE;
                        B += "*";
                        add += "*";
                        add += A;
                        B += A;
                        B += case9.str();
                        add += case9.str();
                        B += "*";
                        add += "*";
                        add += "->";
                        add += sub2[x];
                        add += sub2[x2];
                        add += ",";
                        New += B;
                        NRULE++;
                        B = "";
                    }      
                    // decrease by 2 units the length of the substring                              
                    length -= 2;
                    // go to the next characters by increasing the indexes
                    x++;
                    x2++;
                }
                // if the length of the substring is equal with 1
                if(length == 1)
                {
                    // then we add the last characters
                    New += sub2[x2];
                }
                // if the character is a | symbol, then we include it as well in the new rules
                if(sub[j] == '|') New += sub[j];
            }
            // if we are at the last index, and the character at this position is . then we include this point as well
            if(j==len && N[i]!='.') New += N[i];  
        } 
    }
    // in case if the length of rules that are new and will be added, is different from 0
    if(add.length() != 0)
    {
        // then we include a sign, that will help to delimiter the listed rules, and the other ones that contain X
        New += "^";
        // we add the rules that contain X
        for(int y = 0; y < add.length()-1; y++) New += add[y];
    }
    else
    // else there is nothing possible to do
    m = 0;
    return New;       
}

string CFGtoCNF(string N)
{
    // the rule that new will be added
    string add;
    // New - the new string of rules
    string New;
    string subloop;
    // sub - left-hand side characters of a rule
    string sub;
    // sub2 - right-hand side characters of a rule
    string sub2;
    // NRULE - numbers of rule
    int NRULE = 0;
    // the character that is going to be used for the new rules, for ex: *Y0*->a
    char A = 'Y';
    int m;
    
    string b = "";
    // b - is going to be equal with the previous rules
    b += N;
    N = "";
    // for each character of the previous rules
    for(int c = 0; c < b.length(); c++)
    {
        // if the character is equal to the delimiter between the rules and the listed rules for notations
        if(b[c] == '^')
        {
            // then we will save the index position of this delimiter
            m = c;
            break;            
        }      
        else
        {
            // otherwise we give back to the string of new rules, its characters
            N += b[c];  
        }           
    }
    // starting from the delimiter and going till the end
    for(int c = m+1; c < b.length(); c++)
    {
        // we add to the string of rules for listed notations, the current characters
        add += b[c];           
    }
    // at the new rule that will be added
    add += ',';
    // for each character from the new rules
    for(int i = 0; i < N.length(); i++)
    {
        sub = "";   
        // while the character is not equal with a comma and its position, index is not the last index.
        while(N[i]!=',' && i!=N.length())
        {
            // we add to the new substring the left-hand side characters
            sub += N[i];
            // and go to the next character, by adding one more unit to the index
            i++;                             
        }
        // len - will be the length of the substring
        int len = sub.length(); 
        bool count =0;
        // for each character of the substring left-hand side
        for(int j = 0; j < len; j++)
        {
            // if the index is equal with 0, which will be
            if(j == 0)
            {          
                // while the character of the substring is not equal with a > symbol       
                while(sub[j] != '>')
                {
                    // then we add to the new string of rules the characters
                    New += sub[j];
                    j++;               
                }
                // when we get to the sequence "->", especially ">", then, we add it as well
                // and increase the index
                New += sub[j];
                j++;
            }
            sub2 = "";
            // while the character of the substring is not equal with a | symbol and it does not represent the last character
            while(sub[j]!='|' && j!=sub.length())
            {
                sub2 += sub[j];
                j++;                  
            }
            //calculate the new length
            int Newlen = 0;
            for(int p = 0; p < sub2.length(); p++)
            {
                // if right-hand side characters of a rule is equal this # 
                if(sub2[p] == '*')
                {
                    // and go to the next character
                    p++;   
                    // while the right-hand side characters of a rule is not equal with that sign, then we go to the next character           
                    while(sub2[p] != '*') p++;
                    Newlen++;
                }
                else Newlen++;    
            }    
            // if the Newlenis bigger than 2, more than 2 rule with symbol         
            if(Newlen > 2)
            {
                // B - the rule that new will be added
                string B = "";
                // ws - transformed previously rules
                string ws = "";
                int m = 0;
                count = 1;  
                // then while the Newlenis bigger or equal to 2         
                while( Newlen >= 2)
                {
                    // if right-hand side characters of a rule are equal to this symbol
                    if(sub2[m] == '*')
                    {
                        // we save the symbol in the ws 
                        ws += sub2[m];
                        // and go to the next character
                        m++;           
                        // if right-hand side characters of a rule are equal to this symbol 
                        while(sub2[m] != '*')
                        {
                            // and go to the next character
                            // we save the symbol in the ws
                            ws += sub2[m];              
                            m++;
                        }   
                        ws += sub2[m]; 
                        m++;
                    }
                    else
                    {
                        ws += sub2[m];
                        m++;   
                    }
                    if(sub2[m] == '*')
                    {
                        ws += sub2[m];
                        m++;             
                        while(sub2[m] != '*')
                        {
                            ws += sub2[m];              
                            m++;
                        }
                        ws += sub2[m];    
                        m++;
                    }
                    else
                    {
                        ws += sub2[m];
                        m++;   
                    } 
                    // decrease the length by 2 
                    Newlen -= 2;
                    // ceate the stringstream class
                    // if the characters are not both uppercase lettres, for ex: a and b , from D->ab
                    stringstream case5;  
                    // repeat the same procedure                                    
                    case5 << NRULE;
                    B += "*"; 	
                    add += "*";
                    add += A;
                    B += A;
                    B += case5.str();
                    add += case5.str();
                    B += "*";
                    add += "*";
                    add += "->";
                    // then we add the transition sequence "->" to the add srtring
                    add += ws;
                    add += ",";
                    New += B;
                    NRULE++;
                    B = "";
                    ws = "";
                }
                // it the length is equal with 1
                if(Newlen == 1)
                {
                    // while the index position is smaller then the last one
                    while(m < sub2.length())
                    {           
                        // we added the left-hand, side characters of a rule, 
                        New += sub2[m];
                        m++;
                    }                         
                }
                // if the character from the right-hand side is set as | sign, then we include it as well into the new rules string
                if(sub[j] == '|') New += sub[j];
            }
            else
            {
                // it the length is smaller or equal with 2
                if(Newlen <= 2)
                {
                    // we added the left-hand, side characters of a rule, 
                    New += sub2;
                    // if the character from the right-hand side is set as | sign, then we include it as well into the new rules string
                    if(sub[j] == '|') New += sub[j];          
                }                
            }   
            // if the count variable is equal with 1 and the index position is the last index from length of the substring
            if(count==1 && j==len)
            {
                count = 0;
                sub = "";
                // we introduce all the rules to te substring
                sub += New;
                // deterrmine its length
                len = sub.length();
                New = "";
                // and go by one character in baack, by decresing
                j =- 1;          
            } 
            else
            {
                // if the count variable is equal with 0 and the index position is the last index from length of the substring
                if(j==len && count==0)
                {
                    // then we add all got rules
                    subloop += sub;
                    New = ""; 
                    // if the character is a . then e add to the new substring the  characters
                    // D->#Y0#C
                    if(N[i] == ',') subloop += N[i]; 
                } 
            }
        }
    }
    // we add the comma, the rest of the rules for the notations and the point
    subloop += ",";
    subloop += add;
    subloop += ".";
    return subloop;       
}      
                      
int main(int argc, char** argv) {
	// $ means epslon
	string input;
    input = "S->aB|AC,A->a|ASC|BC|aD,B->b|bS,C->$|BA,E->aB,D->abC.";
    cout << endl;
    // then start by calling the first char funtion
    // start - will show the first start point, which will usually be S
	char start = Rstart(input);
    // r1 - will check for start point in RHS (right-hand side), which will usually be 1, present, positive
	bool r1 = checkR1(input,start);
    // y - will represent the input string + one more initial start point SS -> S
	string y = R1(input,r1,start);
	string start2;
    // start2 - will show the new first start point, which will usually be SS
	start2 += retstart(y);
	    
    string epslon;
    // epsilon - will show the state that goes in epsilon $ (in my case it is C)
	epslon += R2A(y);
	string y2;
    // y2 - will show all the rule starting from SS -> S, but without empsilon $ rule
	y2 = R2B(y,epslon);
	string y2A;
    // y2A - will show the new rules created without epsilon $, in form of S(A), which means S goes into A, without any C, like: S(A)A(AS)A(B)D(ab)
	y2A = R2C(y2,epslon,start2);
	string y2B;
    // y2B - will show the new rules created without epsilon $, in form of S->aB|AC|A, that was previously S->aB|AC 
    y2B = R2D(y2,y2A);
    // y2final - will show the final rules after removing epsilon-productions 
    string y2final = R2Final(y2B);
        
    // y3 - will show the step 3 - unit rule, especially the delete of for exemple: A->A 
    string y3 = R3A(y2final);
    // y3final - will show the rules without any renamings, for instance: no more S->A , A->B
    string y3final = R3B(y3);

    // y4 - will show the innaccesable states
    string y4 = R4A(y3final);
    // y5 - will show all the rules, without the rules that contain innaccesable states
    string y5 = R5A(y3final, y4);

    // y6 - will show the non-productive states
    string y6 = R6A(y5);
    // y5 - will show all the rules, without the rules that contain non-productive states
    string y7;
    // going throught all the characters of the string of non-productive states
    for (int c= 0; c <= y6.length(); c++)
    {
        // in case if there are no non-productive states
        // then we set it equal to the previous obtained rules
        if (y6[c] == NULL) y7 = y5;
        else y7 = R5A(y5, y6);
    }
    int m = 1;
    // prefinal12 - will show the transformed rules with X, and the listed productions for the states X
    // it includes one delimiter, and still cannot do D->abC, which is going to be D->#X12##13#C
    string prefinal12 = prefinal(y7,m); 	
    string CNF2;
    // CNF2 - will show the Chomsky Normal Form
    CNF2 = CFGtoCNF(prefinal12);
    
    cout << start << endl;
    cout << endl;
    cout << r1 << endl;
    cout << endl;
    for(int i = 0; i < y.length(); i++)
    {
        if(y[i]!=NULL && y[i]!=',' && y[i]!='.') cout<<y[i];
        if(y[i]==',' || i==(y.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < start2.length(); i++)
    {
        if(start2[i]!=NULL && start2[i]!=',' && start2[i]!='.') cout<<start2[i];
        if(start2[i]==',' || i==(start2.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < epslon.length(); i++)
    {
        if(epslon[i]!=NULL && epslon[i]!=',' && epslon[i]!='.') cout<<epslon[i];
        if(epslon[i]==',' || i==(epslon.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y2.length(); i++)
    {
        if(y2[i]!=NULL && y2[i]!=',' && y2[i]!='.') cout<<y2[i];
        if(y2[i]==',' || i==(y2.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y2A.length(); i++)
    {
        if(y2A[i]!=NULL && y2A[i]!=',' && y2A[i]!='.') cout<<y2A[i];
        if(y2A[i]==',' || i==(y2A.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y2B.length(); i++)
    {
        if(y2B[i]!=NULL && y2B[i]!=',' && y2B[i]!='.') cout<<y2B[i];
        if(y2B[i]==',' || i==(y2B.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y2final.length(); i++)
    {
        if(y2final[i]!=NULL && y2final[i]!=',' && y2final[i]!='.') cout<<y2final[i];
        if(y2final[i]==',' || i==(y2final.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y3.length(); i++)
    {
        if(y3[i]!=NULL && y3[i]!=',' && y3[i]!='.') cout<<y3[i];
        if(y3[i]==',' || i==(y3.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y3final.length(); i++)
    {
        if(y3final[i]!=NULL && y3final[i]!=',' && y3final[i]!='.') cout<<y3final[i];
        if(y3final[i]==',' || i==(y3final.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y4.length(); i++)
    {
        cout<<y4[i];
    }
    cout << endl;
    cout << endl;
    for(int i = 0; i < y5.length(); i++)
    {
        if(y5[i]!=NULL && y5[i]!=',' && y5[i]!='.') cout<<y5[i];
        if(y5[i]==',' || i==(y5.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y6.length(); i++)
    {
        if(y6[i]!=NULL && y6[i]!=',' && y6[i]!='.') cout<<y6[i];
        if(y6[i]==',' || i==(y6.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < y7.length(); i++)
    {
        if(y7[i]!=NULL && y7[i]!=',' && y7[i]!='.') cout<<y7[i];
        if(y7[i]==',' || i==(y7.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < prefinal12.length(); i++)
    {
        if(prefinal12[i]!=NULL && prefinal12[i]!=',' && prefinal12[i]!='.') cout<<prefinal12[i];
        if(prefinal12[i]==',' || i==(prefinal12.length()-1)) cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < CNF2.length(); i++)
    {
        if(CNF2[i]!=NULL && CNF2[i]!=',' && CNF2[i]!='.') cout<<CNF2[i];
        if(CNF2[i]==',' || i==(CNF2.length()-1)) cout<<endl;
    }
    cout << endl;
    return 0;
}