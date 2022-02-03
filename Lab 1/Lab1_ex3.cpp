#include <iostream>

using namespace std;

string adj[20][20]; //the adjacency matrix initially 0
// adj[20][20] - the adjacency matrix


void displayMatrix(int v) { // function for the display of the adjacency matrix 
// it has a "v" parameter - which represents the number of columns and rows
    int i, j;
    // i, j - variables used in loops
    for(i = 0; i < v; i++) 
    {
        for(j = 0; j < v; j++) 
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edge(string a, string val, string b) { // function to add edges into the matrix depending on the regular grammar
// it contains 3 string parameters:
// a - the state (which derives), non-terminal symbol
// val - the transitional value, terminal symbol
// b - the state (in which is derivated), non-terminal symbol
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // conditions for setting the place of each state
    // if the start state is S, then we will define its position equal to 0  
    if (a == "S") u = 0;
    // if the next state is P, then we will define its position as 1 
    if (a == "P") u = 1;
    // if the next state is Q, then we will define its position as 2 
    if (a == "Q") u = 2;
    
    // if the state in which is derivated is equal with S, then we will define its position as 0
    if (b == "S") v = 0;
    // if the state in which is derivated is equal with P, then we will define its position as 1
    if (b == "P") v = 1;
    // if the state in which is derivated is equal with Q, then we will define its position as 2
    if (b == "Q") v = 2;
    
    // we fill the cells, that are initially 0, with the new chararter that is the transition between the states 
    adj[u][v] = val;
}

void add_edge_end(string a, string val) { // function to add edges into the matrix that represent the final state
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // conditions for setting the place of each state
    // if the final state is S, then we will define its position equal to 0  
    if (a == "S") u = 0;
    // if the final state is P, then we will define its position as 1
    if (a == "P") u = 1;
    // if the final state is Q, then we will define its position as 2 
    if (a == "Q") u = 2;
    
    // we set the last column (third) as the one which represent the value of the final state
    // in case if the state does not have at all any terminal symbols, then this column is not going to appear
    adj[u][3] = val;
}

void add_edge_duble(string a, string val, string b) { // function to add multiple edge into the matrix
// in case if the state has multiple transitions to itself
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // we again set the conditions for the place of each state
    if (a == "S") u = 0;
    if (a == "P") u = 1;
    if (a == "Q") u = 2;
    
    if (b == "S") v = 0;
    if (b == "P") v = 1;
    if (b == "Q") v = 2;
    
    // and we add the string to the one that we already have (the process of concatination)
    adj[u][v] += val;
}

int main()
{
    int v = 4;    
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < v - 1; j++)
        {
            adj[i][j] = "0"; // the adjacency matrix initially is set as 0
        }
    }
    
    // write the regular grammar
    add_edge("S", "a", "P");
    add_edge("S", "b", "Q");
    add_edge("P", "b", "P");
    add_edge_duble("P", "c", "P");
    add_edge("P", "d", "Q");
    add_edge_end("P", "e");
    add_edge("Q", "e", "Q");
    add_edge_duble("Q", "f", "Q");
    add_edge_end("Q", "a");
    
    // display the adjacency matrix, that has at the last column the final transitions
    displayMatrix(v);
    return 0;
}

