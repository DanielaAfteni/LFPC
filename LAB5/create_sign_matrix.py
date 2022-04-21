from create_simple_precedence_matrix import *

# method for the determination of the Rule 1
# for example: at the production S -> dB, we will return d = B
def get_objects_rule1(right):
    # we compose objects in form of dictionary
    sign_matrix_objects = [] 
    # if the length of the RHS is bigger than 1
    if(len(right) > 1):
        # then for between each symbol in the RHS, we put = sign
        for i in range(len(right) - 1):
            # firstly we have to initialize the dictionary, where the rules will be stored,
            # to select the right and left character, 
            # and to insert a = sign, and include the obtained rule in the final representation
            sign_matrix_object = {}
            sign_matrix_object["x1"] = right[i]
            sign_matrix_object["sign"] = "="
            sign_matrix_object["x2"] = right[i+1]
            sign_matrix_objects.append(sign_matrix_object)
    return sign_matrix_objects


# method for the determination of the Rule 2
# for example: at the production S -> dB, we will return d < First(B) = {D, b}
def get_objects_rule2(right): 
    # we compose objects in form of dictionary
    sign_matrix_objects = [] 
    # if the length of the RHS is bigger than 1
    if(len(right) > 1):
        # then for between each symbol in the RHS
        for i in range(len(right) - 1):
            # which satisfy the condition that Left (first) symbol - terminal, Right (second) symbol - nonterminal (for instance: dB)
            if right[i] in get_terminals() and right[i+1] in get_nonterminals(): 
                # then for each First symbol of a concrete Right (second) symbol nonterminal (consider each First of B)
                for first in get_first_of_nonterminal(right[i+1]):
                    # firstly we have to initialize the dictionary, where the rules will be stored,
                    # to select the right and left character, 
                    # and to insert a < sign, and include the obtained rule in the final representation
                    sign_matrix_object = {}
                    sign_matrix_object["x1"] = right[i]
                    sign_matrix_object["sign"] = "<"
                    sign_matrix_object["x2"] = first
                    sign_matrix_objects.append(sign_matrix_object)
    return sign_matrix_objects


# method for the determination of the Rule 3 
# for example: at the production B -> DcB, we will return Last(D) = {A, a} > c
def get_objects_rule3(right):
    # we compose objects in form of dictionary
    sign_matrix_objects = [] 
    # if the length of the RHS is bigger than 1
    if(len(right) > 1):
        # then for between each symbol in the RHS
        for i in range(len(right) - 1):
            # which satisfy the condition that Left (first) symbol - nonterminal, Right (second) symbol - terminal (for instance: Dc)
            if right[i] in get_nonterminals() and right[i+1] in get_terminals(): 
                # then for each Last symbol of a concrete Left (first) symbol nonterminal (consider each Last of D)
                for last in get_last_of_nonterminal(right[i]):
                    # firstly we have to initialize the dictionary, where the rules will be stored,
                    # to select the right and left character, 
                    # and to insert a > sign, and include the obtained rule in the final representation
                    sign_matrix_object = {}
                    sign_matrix_object["x1"] = last
                    sign_matrix_object["sign"] = ">"
                    sign_matrix_object["x2"] = right[i+1]
                    sign_matrix_objects.append(sign_matrix_object)
    return sign_matrix_objects


# method for the determination of the Rule 4 
# for example: at the production B -> DA, we will return Last(D) = {A, a} > (First(A) = {a} & Terminal) = {a}
def get_objects_rule4(right): 
    # we compose objects in form of dictionary
    sign_matrix_objects = [] 
    # if the length of the RHS is bigger than 1
    if(len(right) > 1):
        # then for between each symbol in the RHS
        for i in range(len(right) - 1):
            # which satisfy the condition that Left (first) symbol - nonterminal, Right (second) symbol - nonterminal (for instance: DA)
            if right[i] in get_nonterminals() and right[i+1] in get_nonterminals():
                # then for each Last symbol of a concrete Left (first) symbol nonterminal (consider each Last of D)
                for last in get_last_of_nonterminal(right[i]):
                    # and for each First symbol of a concrete Right (second) symbol nonterminal (consider each First of A)
                    # in intersection of with the set of terminal symbols
                    # we use sets to remove duplicates from the obtained list 
                    for specific_first in list(set(get_first_of_nonterminal(right[i+1]))&set(get_terminals())):
                        # firstly we have to initialize the dictionary, where the rules will be stored,
                        # to select the right and left character, 
                        # and to insert a > sign, and include the obtained rule in the final representation
                        sign_matrix_object = {}
                        sign_matrix_object["x1"] = last
                        sign_matrix_object["sign"] = ">"
                        sign_matrix_object["x2"] = specific_first
                        sign_matrix_objects.append(sign_matrix_object)
    return sign_matrix_objects


# function to establish all the rules for the grammar
def get_sign_matrix_obj():
    sign_matrix = {}
    sign_matrix["matrix"] = []
    for production in get_productions():
        # left (LHS) and right (RHS) side of production
        for left, right in production.items(): 
            # we include all the obtained rules from each RHS in the corresponding matrix table
            sign_matrix["matrix"] += get_objects_rule1(right)
            sign_matrix["matrix"] += get_objects_rule2(right)
            sign_matrix["matrix"] += get_objects_rule3(right)
            sign_matrix["matrix"] += get_objects_rule4(right)

    return sign_matrix

print("\nSign Matrix")
pprint(get_sign_matrix_obj())