from ctypes import *
from sys import platform

shared_lib_path = "/media/kaladin/DATA/Programming/ClionProjects/P2P_messenger/main.so"

add_lib = CDLL(shared_lib_path)
print('Success')


