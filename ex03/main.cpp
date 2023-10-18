#include "AForm.hpp"
#include "Intern.hpp"
int main()
{
    Intern someRandomIntern;
    Bureaucrat A("hola",5);

    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    rrf->beSigned(A);
    rrf->execute(A);
    std :: cout << *rrf << std :: endl;
    delete rrf;
}
