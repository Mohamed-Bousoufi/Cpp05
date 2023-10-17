#include "Intern.hpp"

Intern :: Intern()
{

}
Intern :: Intern(Intern &copy)
{
    *this = copy;
}

Intern & Intern :: operator=(const Intern &copy)
{
    (void)copy;
    return(*this);
}

Intern :: ~Intern()
{

}

AForm *Intern::makeForm(const std :: string name,const std :: string  target)
{
    AForm * ptr  = NULL;
    try
    {
        int i = 0;
       std :: string cl[3] = {"presidential pardon","robotomy request","shrubbery creation"};
       while(i <= 3)
       {
            if(name == cl[i])
                break;
            i++;

       }
       switch (i)
       {
       case 0:
                ptr = new PresidentialPardonForm(target);
                    break;
        case 1 :
                ptr = new RobotomyRequestForm(target);
                    break;
        case 2 :
                ptr = new ShrubberyCreationForm(target);
                    break;
       
       default:
                throw "Can 't Find Class";
        break;
       }
    }
    catch(const char *e)
    {
        std::cout << e << std :: endl;
    }
    return(ptr);
}
