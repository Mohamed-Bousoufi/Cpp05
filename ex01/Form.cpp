#include "Form.hpp"

Form :: Form() : _gradeSign(150) , _gradeExc(150)
{
    _sign = false;
}

Form :: Form(const std :: string name,const int gradeSign,const int gradeExc)
: _name(name),_gradeSign(gradeSign),_gradeExc(gradeExc)
{

    try
    {
        _sign = false;
        if(_gradeSign < 1 || _gradeExc < 1)
            throw Form ::GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExc > 150)
            throw Form :: GradeTooLowException();
    }
    catch(const std::exception& e)
    {
            std :: cout << e.what() << std :: endl;
    }
    
}

Form & Form :: operator=(Form &copy)
{
    this->_sign = copy._sign;
    return(*this);
}

Form :: Form(Form & copy) :  _name(copy._name), _gradeSign(copy._gradeSign) , _gradeExc(copy._gradeExc)
{
    this->_sign = copy._sign;
    *this = copy;
}

const std :: string Form :: getName()
{
    return(this->_name);
}

bool Form ::getSign()
{
    return(this->_sign);
}

int Form ::getGradexc()
{
    return(this->_gradeExc);
}

int Form :: getGradsign()
{
    return(this->_gradeSign);
}

void Form :: beSigned(Bureaucrat &B)
{
    try
    {
        if(B.getGrade() > this->getGradsign())
            throw Form :: GradeTooLowException();
        else if(B.getGrade() > 150 || B.getGrade() < 1)
            throw Form :: GradeTooLowException();
        else
            this->_sign = true;                
    }
    catch(std :: exception &e)
    {
       std :: cout << e.what() << std :: endl;
    }
}

const char * Form :: GradeTooHighException :: what() const throw()
{
    return("Grade Too High");
}

const char * Form :: GradeTooLowException :: what() const throw()
{
    return ("Grade Too Low");
}

std :: ostream & operator <<(std :: ostream &out , Form &f)
{
    out << f.getName()<< ", Form GradeSign is " << f.getGradsign() << " and GradeExcute is " << f.getGradexc() <<" : "<<f.getSign()<< std :: endl;
    return out;
}

Form :: ~Form()
{

}