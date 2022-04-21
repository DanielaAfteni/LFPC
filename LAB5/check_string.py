from create_sign_matrix import *

# method responsible for establishment of the symbols between terminals
def get_final_string(before_str):
    # we do multiple replacements
    # replace in the initial string the $< with $, '>$' with '$' and '$' with '>$<'
    after_str = before_str.replace('$<', '$').replace('>$', '$').replace('$', '>$<')
    after_str = after_str[1:len(after_str) - 1:]
    for rule in data['matrix']:
        # for each rule from the sign matrix
        # we consider the initial format equal with x1x2
        before = rule['x1'] + rule['x2']
        # and we consider the formated structure equal with x1 sign x2
        after = rule['x1'] + rule['sign'] + rule['x2']
        # at the end we replace all the initial rules with the newly formated ones
        after_str = after_str.replace(before, after)
    return after_str


# method for the replacement of the sequence < > 
# for example: <d = B> in <S>
def replace_string(final_string, productions):
    # determine the indexes of the end, start of sequence 
    end = final_string.index('>')
    cut_string = final_string[0:end + 1:1][::-1]
    begin = cut_string.index('<')
    selected_substring = cut_string[0:begin + 1:1][::-1]
    # we replace the = sign with nothing
    # for example: at the production S -> dB, we will have <d = B>, and we will get <dB>
    productions_value = selected_substring.replace('=', '')
    replace_value = ''
    # for each production, if the <dB> from the sequence is equal with the value of the production S -> dB
    for item in productions:
        for key, value in item.items():
            if '<' + value + '>' == productions_value:
                # in case if it is, then deternimed replacement for the selected substring 
                # with the current Nonterminal that determined the production (S)
                replace_value = key
    # in final we replace de facto dB with S
    final_string = final_string.replace(selected_substring, replace_value)
    final_string = get_final_string(final_string)
    return final_string.replace('<>', '')


# method for the determination of the truth of the inserted string
def check_final_string(final_string, productions):
    # we print the final string
    pprint(final_string)
    # while the final string is not a $$ string (for the TRUE -> the last printed string "$<S>$" )
    while final_string != '$$':
        # each time we refresh the final string by reprlacing the last version with other
        final_string = replace_string(final_string, productions)
        pprint(final_string)
        if final_string == '$<' + get_start() + '>$':
            return True
    return False

# we take into consideration the: obtained matrix and given string
data = get_sign_matrix_obj()
string = get_string()
# initially, we set the string by the correspondence with the sign matrix and the start and end symbols $ 
final_string = get_final_string('$' + string + '$')
productions = get_productions()

print("\nThe String: {}\n".format(string))
print("\n The process of checking the final string")
pprint(check_final_string(final_string, productions))