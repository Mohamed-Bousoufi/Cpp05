#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
    public :
        Intern();
        Intern(Intern &copy);
        Intern & operator =(const Intern &copy);
        ~Intern();
        AForm *makeForm( std :: string const name,std :: string const target);
};
#endif