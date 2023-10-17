#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private :
        std :: string _target;
    public :
    RobotomyRequestForm();
    RobotomyRequestForm(const std :: string target);
    RobotomyRequestForm(RobotomyRequestForm &copy);
    RobotomyRequestForm & operator=(RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor);
    void beSigned(Bureaucrat &B);
};

#endif