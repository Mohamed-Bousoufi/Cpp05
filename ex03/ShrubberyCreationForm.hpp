#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
    private :
        std :: string _target;
    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std :: string &target);
    ShrubberyCreationForm(ShrubberyCreationForm &copy);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor);
    void beSigned(Bureaucrat &B);
};

#endif