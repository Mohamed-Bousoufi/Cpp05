#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
    Form f("Task ",14,11);
    Bureaucrat B("Morty",5);
    std :: cout << f << std :: endl;
    B.signForm(f);
    std :: cout << B << std :: endl;
    std :: cout << f << std :: endl;

    

    
    

}