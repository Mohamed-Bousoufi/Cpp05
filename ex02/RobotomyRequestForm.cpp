#include "RobotomyRequestForm.hpp"


RobotomyRequestForm :: RobotomyRequestForm() : AForm("RobotomyRequestForm",72,45) ,_target("")
{

}

RobotomyRequestForm :: RobotomyRequestForm(const std :: string target) : AForm("RobotomyRequestForm",72,45) , _target(target)
{
    
}

RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm :: operator=(const RobotomyRequestForm &copy)
{
    this->_target = copy._target;
    return(*this);
}

void RobotomyRequestForm :: execute( const Bureaucrat &B)
{
    try
    {
        if(this->getSign() && const_cast<Bureaucrat &>(B).getGrade() < this->getGradexc())
        {         
            time_t current;
            time(&current);
                if(current % 2 == 0)
                    std :: cout << this->_target <<" has been robotomized "<< std :: endl;
                else
                    std :: cout << "robotomized Failed !!!" << std :: endl;
        }
        else
        {
                throw Bureaucrat ::GradeTooLowException();
        }
    }
    catch(std :: exception &e)
    {
        if(!this->getSign())
            std :: cout << this->getName() << "  Not signed"  << std :: endl;
        else
            std :: cout << e.what() << std :: endl;
    }
}

void RobotomyRequestForm :: beSigned(Bureaucrat &B)
{
    if(this->getGradsign() > B.getGrade())
    {
        AForm :: beSigned(B);
    }
}

RobotomyRequestForm :: ~RobotomyRequestForm()
{

}