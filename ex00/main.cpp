#include "Bureaucrat.hpp"

int main()
{
    
    Bureaucrat A("persone",150);
    Bureaucrat B(A);
    
    A.decrementGrade();
    A.incrementGrade();
    std :: cout << A << std :: endl;
    std :: cout << B << std :: endl;

    return 0;
}