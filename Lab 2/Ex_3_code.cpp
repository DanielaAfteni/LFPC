#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void showNFA(vector<vector<vector<int> > > table){ // main function for the representation of the NFA
    
    // it includes as a parameter table, 
    // which represents that in a table, at a specific initial state, at a corresponding transition value, we have multiple or one final state
	
    cout << "    |";
	char init = 'a';
    // init - initial non-terminal symbol
	for (int i = 0; i < table[0].size()-1; i++)
    {
        // we show the first line of non-terminal symbols
		cout<<"  "<<init++<<"  |";
	}
    // and include the last column as the one that defines the final state
	cout << "   ^   " << endl; 
    cout << endl;
	for (int i = 0; i < table.size(); i++)
    {
        // we represent the states based on the iteration
		cout << "q" << i << " ";
		for (int j = 0; j < table[i].size(); j++)
        {
            // for each state and transition value
			cout << " |  ";
			for (int k = 0; k < table[i][j].size(); k++)
            { 
                // we show the state to were it comes
				cout << "q" << table[i][j][k] << " ";
			}
		}
		cout << endl;
	}
}

void showDFA(vector<vector<int> > states, vector<vector<vector<int> > > dfa){ // funtion responsible for the representation of the DFA
	cout << "         ";
	char init = 'a';
    // init - initial non-terminal symbol
	for (int i = 0; i < dfa[0].size(); i++)
    {
        // we show the first line of non-terminal symbols
		cout<<"|   "<<init++<<"   ";
	}
	cout << endl;
    // in the table of states
	for (int i = 0; i < states.size(); i++)
    {
		cout<<"{ ";
        // we represent the states based on the iteration
		for (int h = 0; h <states[i].size(); h++)  // there can be multiple states
        {
            // we show the state
			cout << "q" << states[i][h] << " ";
        }
        // In case we have the new state that is empty, then we write it 
		if (states[i].empty())
        {
			cout << "^ ";
		}
		cout << "}  ";
		for (int j = 0; j < dfa[i].size(); j++)
        {
            // for each state and transition value
			cout<<" |  ";
			for(int k = 0; k < dfa[i][j].size(); k++)
            {
                // we show the state to were it comes
				cout << "q" << dfa[i][j][k] <<" ";
			}
            // In case we have the state, to which the value comes, that is empty, then we write it 
			if(dfa[i][j].empty())
            {
				cout << "   ";
			}
		}
		cout << endl;
	}
}

void showConvertion(vector<vector<int> > states, vector<vector<vector<int> > > dfa){
	for (int i = 0; i < states.size(); i++)
    {
		cout<<"'";
        // we represent the states based on the iteration
		for (int h = 0; h <states[i].size(); h++)  // there can be multiple states
        {
            // we show the state
			cout << "q" << states[i][h];
        }
        // In case we have the new state that is empty, then we write it 
		if (states[i].empty())
        {
			cout << "empty";
		}
		cout << "' -> {";
        char init = 'a';
        // init - initial non-terminal symbol
		for (int j = 0; j < dfa[i].size(); j++)
        {
            // for each state and transition value
            cout<<"   '"<<init++<<"' : ";
			for (int k = 0; k < dfa[i][j].size(); k++)
            {
                // we show the state to were it comes
				cout << "'q" << dfa[i][j][k] <<"',";
			}
            // In case we have the state, to which the value comes, that is empty, then we write it 
			if (dfa[i][j].empty())
            {
				cout << "empty,";
			}
            cout << endl;
        }
		cout << "}" << endl << endl;
	}
}

vector<int> new_states(int s,vector<vector<vector<int> > > v){ // function responsible for new states 
    // it has as parameters integer value and the table that represent all our NFA
	vector<int> t;
    // t - responsible for the elements of each state
	queue<int> q;
	t.push_back(s);
    // we push 0 in the vector from the back
	int a = v[s][v[s].size()-1].size();
    // a - is equal to the size of the state or row 0 and all the table, excluding the last column
	for (int i = 0; i < a; i++)
    {
        // we push all we got in the vector from the back
        // at a specific initial state, at a corresponding transition value, we have multiple or one final state
		t.push_back(v[s][v[s].size()-1][i]);
        // then we push all that we got for each state in the queue
		q.push(t[i]);
	}
	while (!q.empty()) 
    // while the queue is not empty
    {
        // we establish the reference to the first element of the queue
		int f = q.front();
        // and delete the first element of the queue.
		q.pop();
        // if the table for the corresponding state and transition values is not empty
		if(!v[f][v[f].size()-1].empty())
        {
            // then we set this value equal to a new variable
			int u = v[f][v[f].size()-1].size();
			for (int i = 0; i < u; i++)
            {
                // and by the states to where the transition comes
				int y = v[f][v[f].size()-1][i];
                // function find tries to find the element in the given range of numbers,
                // it returns an iterator to the first element in the range begin to end that compares equal to y.
                // In case the found iteration is equal to the last index
                // if nothing fount 
				if (find(t.begin(), t.end(), y) == t.end())
                {
                    // then we push that value into a vector from the back
					t.push_back(y);
                    // and push it as well at the end of the queue.
					q.push(y);
				}
			}
		}
	}
    // return the state
	return t;
}
int main(){
	int n, alpha, i, j;
    // n - int number defines the total number of states
    // alpha - int variable represent the number of elements in alphabet
    // i, j - used variables in loops
	cout << "Number of states in NFA : ";
	cin >> n;
	cout << "Number of symbols in alphabet : ";
	cin >> alpha;
	vector<vector<vector<int> > > table;
    // table - initial table, like dynamic array that will have 3 iterative parametres: i, j and k
    // it definest that in a table, at a specific initial state, at a corresponding transition value, we have multiple or one final state
	for ( int i = 0; i < n; i++)
    {
        // for each state that we got
		cout << "State nr. " << i <<endl;
		vector< vector< int > > v;
        // v - the state from were the transition is sent
		
        char a ='a';
        // a - initial non-terminal symbol
		int y, yn;
        // y - the state to which we are making the transition
        // yn - the number of transitions that we have from the current states by a specific non-terminal symbol
		
        for(int j = 0; j < alpha; j++)
        {
            // for each non-terminal symbol from alphabet
			vector<int> t;
            // t - the state to which the transition is done

			cout << "Number of transitions with "<< a++ <<" : ";
			cin >> yn;
			cout << "To states :" << endl;
			
            for(int k = 0; k < yn; k++)
            {
                // corresponding to the number of the transitions with the same symbol, we create a loop to determine each state to were it comes
				cin >> y;
                // we push the output states into the vector from the back
                // we get that: at a corresponding transition value, we have multiple or one final state
				t.push_back(y);
			}
            // we push all we got in the vector from the back
            // we get that: at a specific initial state, at a corresponding transition value, we have multiple or one final state
			v.push_back(t);
		}

        // specific case when it is a real finite state, which apears at each state
		vector<int> t;
		cout << "Number of transitions with empty, final state: ";
		cin >> yn;
        // yn - the number of transitions that we have from the current states by a empty symbol
		cout<<"To states :"<<endl;
		for (int k = 0; k < yn; k++){
			cin >> y;
            // y - the state to which we are making the transition
            // we push the output states into the vector from the back
            // we get that: at a corresponding empty value, we have multiple or one final state, which is itself
			t.push_back(y);
		}
        // we push all we got in the vector from the back
        // we get that: at a specific initial state, at a corresponding transition value, we have multiple or one final state
		v.push_back(t);
        // also we push all we got in the vector from the back
        // we get that: in a table, at a specific initial state, at a corresponding transition value, we have multiple or one final state
		table.push_back(v);
	}

    // represent the NFA
	cout << "---------- NFA ----------" << endl;
	showNFA(table); // main function for the creation of the output of the NFA
	vector<vector<vector<int> > > dfa;
    // dfa - final table, like dynamic array that will have 3 iterative parametres: i, j and k
    // it definest that in a table, at a specific initial state, at a corresponding transition value, we have multiple or one final state
    // states - the table of states
	vector<vector<int> > states;
	states.push_back(new_states(0,table));
	queue<vector<int> > q;
    // we push the first state in the queue
	q.push(states[0]);
    // and while the queue is not empty
	while(!q.empty())
    {
        // we set a reference to the first element of the queue
		vector<int> f = q.front();
        // and delete the first element of the queue
		q.pop();
        // v - the state from were the transition is sent
		vector<vector<int> > v;
        // alpha - int variable represent the number of elements in alphabet
		for (int i = 0; i < alpha; i++)
        {
			vector<int> t;
			set<int> s;
            // for the length of the first element of the queue
			for (int j = 0; j < f.size(); j++)
            {
				// for the length of the table at the position of index of f and the transition variables
				for (int k = 0; k < table[f[j]][i].size(); k++)
                {
					vector<int> cl = new_states(table[f[j]][i][k],table);
					for (int h = 0; h < cl.size(); h++)
                    {
                        // in case if the value of the indexed vertex is not found in the set
                        // then we insert this new values in the set container
						if (s.find(cl[h]) == s.end()) s.insert(cl[h]);
					}
				}
			}
            // from the begining till the end of the set
			for (set<int >::iterator u = s.begin(); u != s.end(); u++)
            {
                // we get that: at a corresponding transition value, we have multiple or one final state
                t.push_back(*u);
            }
            // we get that: at a specific initial state, at a corresponding transition value, we have multiple or one final state
			v.push_back(t);
            // in case if the state is not present in the table of states
			if (find(states.begin(), states.end(), t) == states.end())
			{	
                // we push it in the table of states
				states.push_back(t);
                // and as well in the queue
				q.push(t);
			}
		}
        // we get that: in a table, at a specific initial state, at a corresponding transition value, we have multiple or one final state
		dfa.push_back(v);
	}
    cout << endl <<"---------- Convertions ----------" << endl;
    showConvertion(states,dfa);
    cout << endl <<"---------- DFA ----------" << endl;
    showDFA(states,dfa);
}