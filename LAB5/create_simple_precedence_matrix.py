from read_string_and_grammar import *

#  method responsible for the determination: 
#                                           if the First symbol from the RHS is a terminal, 
#                                               then we add the terminal to the array of First symbols, for a concret nonterminal 
#                                           if the First symbol from the RHS is a nonterminal,
#                                               then we add the nonterminal to the array of First symbols, for a concret nonterminal
#                                               and call the function to find in all the productions, the First symbol from the RHS (right hand side) at a new specific nonterminal
def extract_first_from_right(first_array, symbol): 
    # symbol should be terminal and not present in first array
    if symbol in get_terminals() and symbol not in first_array:
        first_array.append(symbol) 
    # symbol should be nonterminal and not present in first array
    elif symbol in get_nonterminals() and symbol not in first_array:
        first_array.append(symbol)
        find_first(first_array, symbol) 


# method to find in all the productions, the First symbol from the RHS (right hand side) at a specific nonterminal
# for example: for nonterminal S, at the production S -> dB, we will call the next function for the symbol d 
def find_first(first_array, nonterminal): 
    for production in get_productions():
        # left (LHS) and right (RHS) side of production
        for left, right in production.items(): 
            # if the LHS of the production is that specific nonterminal
            if(left == nonterminal):
                # then we call the function for the analyze of the First symbol from the RHS 
                extract_first_from_right(first_array, right[0])


#  method responsible for the determination: 
#                                           if the Last symbol from the RHS is a terminal, 
#                                               then we add the terminal to the array of Last symbols, for a concret nonterminal 
#                                           if the Last symbol from the RHS is a nonterminal,
#                                               then we add the nonterminal to the array of Last symbols, for a concret nonterminal
#                                               and call the function to find in all the productions, the Last symbol from the RHS (right hand side) at a new specific nonterminal
def extract_last_from_right(last_array, symbol): 
    # symbol should be terminal and not present in last array
    if symbol in get_terminals() and symbol not in last_array:
        last_array.append(symbol)
    # symbol should be nonterminal and not present in last array
    elif symbol in get_nonterminals() and symbol not in last_array:
        last_array.append(symbol)
        find_last(last_array, symbol) 


# method to find in all the productions, the Last symbol from the RHS (right hand side) at a specific nonterminal
# for example: for nonterminal S, at the production S -> dB, we will call the next function for the symbol B 
def find_last(last_array, nonterminal): 
    for production in get_productions():
        # left (LHS) and right (RHS) side of production
        for left, right in production.items(): 
            # if the LHS of the production is that specific nonterminal
            if(left == nonterminal):
                # then we call the function for the analyze of the Last symbol from the RHS 
                extract_last_from_right(last_array, right[-1])


# function to determine the First - Last table
def get_simple_precedent_matrix(): # creates and return it
    simple_presedence_matrix = {}
    # for each nonterminal, from the list of nonterminal symbols
    for nonterminal in get_nonterminals():
        # we will have aan array for the first symbols, and for the last ones (initially are set as empty)
        first_array = []
        last_array = []
        find_first(first_array, nonterminal)
        find_last(last_array, nonterminal)
        # create the First - Last table for each nonterminal
        simple_presedence_matrix[nonterminal] = {"first": first_array,"last": last_array}
    return simple_presedence_matrix


# method for the determination of the First symbols of a concrete nonterminal
def get_first_of_nonterminal(nonterminal):
    return get_simple_precedent_matrix()[nonterminal]["first"]


# method for the determination of the Last symbols of a concrete nonterminal
def get_last_of_nonterminal(nonterminal):
    return get_simple_precedent_matrix()[nonterminal]["last"]


print("\nThe Rules")
pprint(get_productions())
print("\nFirst Last Table")
pprint(get_simple_precedent_matrix())
