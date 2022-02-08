#include <iostream>
#include <sstream> 

using namespace std;

string adj[20][20]; //the adjacency matrix initially 0
// adj[20][20] - the adjacency matrix


void displayMatrix(int v, string ver[]) { // function for the display of the adjacency matrix 
// it has a "v" parameter - which represents the number of columns and rows
    int i, j;
    // i, j - variables used in loops
    for(i = 0; i < v; i++) 
    {
        cout << ver[i];
        for(j = 0; j < v; j++) 
        {
            cout << "  " << adj[i][j] << "  ";
        }
        cout << endl;
    }
}

void add_edge(string vertexinit[], int len, string a, string val, string b) { // function to add edges into the matrix depending on the regular grammar
// it contains 5 string parameters:
// vertexinit[] - array that defines the initial non-terminal array of states
// len - integer, which was calculated as the length of the initial array
// a - the state (which derives), non-terminal symbol
// val - the transitional value, terminal symbol
// b - the state (in which is derivated), non-terminal symbol
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // conditions for setting the place of each state

    for (int i = 0; i < len; i++)
    {
        // if the start state is S, then we will define its position equal to 0
        // if the next state is P, then we will define its position as 1
        // if the next state is Q, then we will define its position as 2

        if ( a == vertexinit[i]) 
        {
            u = i;
        }
    }

    for (int i = 0; i < len; i++)
    {
        // if the state in which is derivated is equal with S, then we will define its position as 0
        // if the state in which is derivated is equal with P, then we will define its position as 1
        // if the state in which is derivated is equal with Q, then we will define its position as 2

        if ( b == vertexinit[i]) 
        {
            v = i;
        }
    }
    // we fill the cells, that are initially 0, with the new chararter that is the transition between the states
    adj[u][v] = val;
}

void add_edge_end(string vertexinit[], int len, string a, string val) { // function to add edges into the matrix that represent the final state
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // conditions for setting the place of each state
    for (int i = 0; i < len; i++)
    {
        // if the final state is S, then we will define its position equal to 0
        // if the final state is P, then we will define its position as 1
        // if the final state is Q, then we will define its position as 2
        if ( a == vertexinit[i]) 
        {
            u = i;
        }
    }
    // we set the last column (third) as the one which represent the value of the final state
    // in case if the state does not have at all any terminal symbols, then this column is not going to appear
    v = len;
    adj[u][v] = val;
}

void add_edge_duble(string vertexinit[], int len, string a, string val, string b) { // function to add multiple edge into the matrix
// in case if the state has multiple transitions to itself
    int u, v;
    // u, v - variable used for the position defining of the states
    
    // we again set the conditions for the place of each state
    for (int i = 0; i < len; i++)
    {
        if ( a == vertexinit[i]) 
        {
            u = i;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if ( b == vertexinit[i]) 
        {
            v = i;
        }
    }
    
    // and we add the string to the one that we already have (the process of concatination)
    adj[u][v] += val;
}

int main()
{
    // the array which contains all the non-terminal states
    string vertex[] = {"S", "P", "Q"}; 
    
    // the length of the array of the states
    int length = sizeof(vertex)/sizeof(vertex[0]);
    int v = length +1;
    
    // the main array that includes the states: q0, q1, ...
    string vert[20];
    for (int i = 0; i < length; i++)
    {
        string ex;
        ex = to_string(i);
        vert[i] = "q" + ex;
    }
    
    for (int i = 0; i < length; i++)
    {
        cout << "   " << vert[i] << " ";
    }
    cout<< endl;

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < v - 1; j++)
        {
            adj[i][j] = "0"; // the adjacency matrix initially is set as 0
        }
    }
    
    // write the regular grammar
    add_edge(vertex,length, "S", "a", "P");
    add_edge(vertex,length, "S", "b", "Q");
    add_edge(vertex, length, "P", "b", "P");
    add_edge_duble(vertex, length, "P", "c", "P");
    add_edge(vertex, length, "P", "d", "Q");
    add_edge_end(vertex, length, "P", "e");
    add_edge(vertex, length, "Q", "e", "Q");
    add_edge_duble(vertex, length, "Q", "f", "Q");
    add_edge_end(vertex, length, "Q", "a");
    
    // display the adjacency matrix, that has at the last column the final transitions
    displayMatrix(v, vert);
    return 0;
}

