#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5) ,_target("")
{

}

PresidentialPardonForm :: PresidentialPardonForm(const std :: string &target) : AForm("PresidentialPardonForm",25,5) , _target(target)
{
    
}

PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm &copy) 
{
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm :: operator=( const PresidentialPardonForm &copy)
{
    this->_target = copy._target;
    return(*this);
}

void PresidentialPardonForm :: execute( const Bureaucrat &B)
{
    try
    {
        if(this->getSign() && const_cast<Bureaucrat &>(B).getGrade() < this->getGradexc())
        {         
            std :: cout << this->_target << " has been pardoned by Zaphod Beeblebrox. " << std :: endl;
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

void PresidentialPardonForm :: beSigned(Bureaucrat &B)
{
    if(this->getGradsign() > B.getGrade())
    {
        AForm :: beSigned(B);
    }
}

PresidentialPardonForm :: ~PresidentialPardonForm()
{

}