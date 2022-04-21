import json
from pprint import pprint
import os

#Returns the read base_string
def read_json_file(file_name):
    fo = open(file_name,"r") # Open base_string.json for reading
    data_string = fo.read() # obtain string from file
    data = json.loads(data_string) # from string to data
    fo.close()
    return data

def get_string():
    return read_json_file("C:/Users/user/Desktop/python/LAB5/base_string.json")["string"]

def get_terminals():
    return read_json_file("C:/Users/user/Desktop/python/LAB5/grammar.json")["Grammar"]["Terminal"]

def get_nonterminals():
    return read_json_file("C:/Users/user/Desktop/python/LAB5/grammar.json")["Grammar"]["Nonterminal"]

def get_productions():
    return read_json_file("C:/Users/user/Desktop/python/LAB5/grammar.json")["Grammar"]["Productions"]

def get_start():
    return read_json_file("C:/Users/user/Desktop/python/LAB5/grammar.json")["Grammar"]["Start"]
