#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std :: string _target;
    public :
    PresidentialPardonForm();
    PresidentialPardonForm(const std :: string &target);
    PresidentialPardonForm(PresidentialPardonForm &copy);
    PresidentialPardonForm & operator=(PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor);
    void beSigned(Bureaucrat &B);
};

#endif
