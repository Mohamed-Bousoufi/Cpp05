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
Bureaucrat :: Bureaucrat(const Bureaucrat &copy) : _name(copy._name) ,_grade(copy._grade)
{

}

Bureaucrat & Bureaucrat :: operator=(const Bureaucrat & copy)
{
    this->_grade = copy._grade;
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
        if(this->getGrade() <= 1 || this->getGrade() > 150)
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
        if(this->getGrade() >= 150 || this->getGrade() < 1)
            throw Bureaucrat :: GradeTooLowException();
        else
            _grade++;
    }
    catch(std::exception& e)
    {
        std :: cout << e.what() << std :: endl;
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