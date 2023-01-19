#pragma once
#include <exception>
#include "Functions.h"
class BadInput :
    public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Wprowadzona liczba nie spelnia wymagan (jest za mala lub za duza)";    
    }

};

