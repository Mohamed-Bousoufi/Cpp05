#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
class Bureaucrat
{
    private :
        const std :: string _name;
        int _grade;
        
    public :
        /* Orthodox Canonical Form */
        Bureaucrat();
        Bureaucrat(const std :: string _name,int grade);
        Bureaucrat(Bureaucrat &copy);
        Bureaucrat & operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        //getters
        const std :: string getName();
        int getGrade();

        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);
        
    /* exception classes */

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
std :: ostream & operator << ( std :: ostream & os, Bureaucrat &B);
#endif