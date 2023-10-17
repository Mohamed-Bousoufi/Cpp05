#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;
class Form
{
    private :
        const std :: string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExc;

    public :
        Form();
        Form(const std :: string name,const int gradeSign,const int gradeExc);
        Form(Form &copy);
        Form & operator = (Form &copy);
        ~Form();

        const std :: string getName();
        bool getSign();
        int getGradsign();
        int getGradexc();

        void beSigned(Bureaucrat &B);
        class GradeTooHighException : public std :: exception
        {
            public :
                const char * what() const throw();
        };

        class GradeTooLowException : public std :: exception
        {
            public :
                const char * what() const throw();
        };

};
std :: ostream  & operator << (std :: ostream &out ,Form &f);

#include "Bureaucrat.hpp"
#endif