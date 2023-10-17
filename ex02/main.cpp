#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    Bureaucrat B("Morty",15);
    RobotomyRequestForm R("world");
    PresidentialPardonForm P("mosamha");
    ShrubberyCreationForm Shru("berry");


    R.execute(B);
    P.execute(B);
    Shru.execute(B);
    B.signForm(R);
    B.signForm(P);
    B.signForm(Shru);
    B.executeForm(R);
    B.executeForm(P);
    B.executeForm(Shru);


    

    
    

}