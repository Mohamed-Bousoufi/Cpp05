#include "AForm.hpp"

AForm :: AForm() : _gradeSign(150) , _gradeExc(150)
{
    _sign = false;
}

AForm :: AForm(const std :: string name,const int gradeSign,const int gradeExc)
: _name(name),_gradeSign(gradeSign),_gradeExc(gradeExc)
{

    try
    {
        _sign = false;
        if(_gradeSign < 1 || _gradeExc < 1)
            throw AForm ::GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExc > 150)
            throw AForm :: GradeTooLowException();
    }
    catch(const std::exception& e)
    {
            std :: cout << e.what() << std :: endl;
    }
    
}

AForm & AForm :: operator=(AForm &copy)
{
    this->_sign = copy._sign;
    return(*this);
}

AForm :: AForm(AForm & copy) : _name(copy._name) , _gradeSign(copy._gradeSign),_gradeExc(copy._gradeExc)
{
    this->_sign = copy._sign;
    *this = copy;
}

const std :: string AForm :: getName()
{
    return(this->_name);
}

bool AForm ::getSign()
{
    return(this->_sign);
}

int AForm ::getGradexc()
{
    return(this->_gradeExc);
}

int AForm :: getGradsign()
{
    return(this->_gradeSign);
}

void AForm :: beSigned(Bureaucrat &B)
{
    try
    {
        if(B.getGrade() > this->getGradsign())
            throw AForm :: GradeTooLowException();
        else if(B.getGrade() > 150 || B.getGrade() < 1)
            throw AForm :: GradeTooLowException();
        else
            this->_sign = true;                
    }
    catch(std :: exception &e)
    {
       std :: cout << e.what() << std :: endl;
    }
}

const char * AForm :: GradeTooHighException :: what() const throw()
{
    return("Grade Too High");
}

const char * AForm :: GradeTooLowException :: what() const throw()
{
    return ("Grade Too Low");
}
std :: ostream & operator <<(std :: ostream &out , AForm &f)
{
    out << f.getName()<< ", AForm GradeSign is " << f.getGradsign() << " and GradeExcute is " << f.getGradexc() <<" : "<<f.getSign()<< std :: endl;
    return out;
}
AForm :: ~AForm()
{

}