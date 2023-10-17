#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat() : _name("") , _grade(150)
{

}

Bureaucrat :: Bureaucrat(const std :: string name,int grade) : _name(name) 
{
    try
    {
        if(grade < 1)
            throw Bureaucrat ::GradeTooHighException();
        else if(grade > 150)
            throw Bureaucrat :: GradeTooLowException();
        else
            _grade = grade;
    }
    catch(std::exception& e)
    {
        std :: cout << e.what() << std :: endl;
    }
    
}
Bureaucrat :: Bureaucrat(Bureaucrat &copy) :_name(copy._name) , _grade(copy._grade)
{
    this->_grade = copy.getGrade();
    *this = copy;
}

Bureaucrat & Bureaucrat :: operator=(Bureaucrat & copy)
{
    this->_grade = copy.getGrade();
    return(*this);
}

Bureaucrat :: ~Bureaucrat()
{

}

const std :: string Bureaucrat :: getName()
{
    return (this->_name);
}

int Bureaucrat :: getGrade()
{
    return(this->_grade);
}

void Bureaucrat :: incrementGrade()
{
    try
    {
        if(this->getGrade() == 1)
            throw Bureaucrat ::GradeTooHighException();
        else
            _grade--;
    }
    catch(std::exception& e)
    {
        std :: cout << e.what() << std :: endl;
    }
    
}

void Bureaucrat :: decrementGrade()
{
    try
    {
        if(this->getGrade() == 150)
            throw Bureaucrat :: GradeTooLowException();
        else
            _grade++;
    }
    catch(std::exception& e)
    {
        std :: cout << e.what() << std :: endl;
    }
    

}


void Bureaucrat :: signForm(AForm &f)
{
    if(this->getGrade() < f.getGradsign() && this->_grade >= 1 && this->_grade <= 150)
    {
        std :: cout << this->getName() << " signs " << f.getName() << std :: endl;
        f.beSigned(*this);
    }
    else
        std :: cout << this->getName() << " cannot sign " << f.getName() << " because Grade Too Low"<< std :: endl;
        
    
}

void Bureaucrat :: executeForm(AForm const &f)
{
    try
    {
        if(this->getGrade() < const_cast<AForm &>(f).getGradexc() && const_cast<AForm &>(f).getSign())
        {
            const_cast<AForm &>(f).execute(*this);

            std :: cout << this->getName() <<" executed " << const_cast<AForm &>(f).getName() << std :: endl;
        }
        else
            throw Bureaucrat :: GradeTooLowException();
    }
    catch(std :: exception &e)
    {
        std :: cout << this->getName() << " couldn’t execute ";
        if(const_cast<AForm &>(f).getSign())
            std :: cout << const_cast<AForm &>(f).getName() << " because " << e.what() << std :: endl;
        else
            std :: cout << const_cast<AForm &>(f).getName() << " because it's Not signed"  << std :: endl;
    }
}

const char * Bureaucrat :: GradeTooHighException :: what() const throw()
{
    return("Grade Too High");
}

const char * Bureaucrat :: GradeTooLowException :: what() const throw()
{
    return ("Grade Too Low");
}

std :: ostream & operator << (std :: ostream &os,Bureaucrat &B)
{
    os << B.getName() << ", bureaucrat grade " << B.getGrade() << std :: endl;

    return os;
}