#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;
class AForm
{
    private :
        const std :: string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExc;

    public :
        AForm();
        AForm(const std :: string name,const int gradeSign,const int gradeExc);
        AForm(AForm &copy);
        AForm & operator = (AForm &copy);
        ~AForm();

        const std :: string getName();
        bool getSign();
        int getGradsign();
        int getGradexc();

        virtual void beSigned(Bureaucrat &B);
        virtual void execute(Bureaucrat const & executor) = 0;
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
std :: ostream  & operator << (std :: ostream &out ,AForm &f);

#include "Bureaucrat.hpp"
#endif