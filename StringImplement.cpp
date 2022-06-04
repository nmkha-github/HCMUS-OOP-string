// StringImplement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "String.h"
#include <iostream>
#include <string>
int main()
{
    string a("123", 2);
    string b("234", 2);
    std::cout << b << std::endl;
    /*string b(a);
    string c(b, 1, 2);
    string d("123", 2);*/
    //a.shrink_to_fit(); 
    a.append(b, 3, 2);
    std::cout << a;
    /*std::string s("12", 3);
    std::cout << s.capacity(); s.resize(16);
    std::cout << s.capacity();*/
}