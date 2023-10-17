#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm :: ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137) ,_target("")
{

}

ShrubberyCreationForm :: ShrubberyCreationForm(const std :: string &target) : AForm("ShrubberyCreationForm",145,137) , _target(target)
{
    
}

ShrubberyCreationForm :: ShrubberyCreationForm(ShrubberyCreationForm &copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm :: operator=(ShrubberyCreationForm &copy)
{
    this->_target = copy._target;
    return(*this);
}

void ShrubberyCreationForm :: execute(Bureaucrat const &executor)
{
    try
    {
        if(this->getSign() && const_cast<Bureaucrat &>(executor).getGrade() < this->getGradexc())
        {
            std :: fstream file;

            file.open(this->_target + "_shrubbery",std :: ios::out | std :: ios::trunc);
            if(!file)
                std :: cout << "file creation failed" << std :: endl;
            else
                file <<
                    "             * *    \n"
                    "           *    *  *  \n"
                    "      *  *    *     *  *\n"
                    "     *     *    *  *    *\n"
                    " * *   *    *    *    *   *\n"
                    " *     *  *    * * .#  *   *\n"
                    " *   *     * #.  .# *   *\n"
                    "  *     \"#.  #: #\" * *    *\n"
                    " *   * * \"#. ##\"       *\n"
                    "   *       \"###\n"
                    "             \"##\n"
                    "              ##.\n"
                    "              .##:\n"
                    "              :###\n"
                    "              ;###\n"
                    "            ,####.\n"
                    "/'\'/'\'/'\'/'\'/'\'/'.######.'\'/'\'/'\'/'\'/\\";
                file.close();
        }
        else
            throw Bureaucrat :: GradeTooLowException();
    }
    catch(std :: exception &e)
    {
        if(!this->getSign())
            std :: cout << this->getName() << "  Not signed"  << std :: endl;
        else
            std :: cout << e.what() << std :: endl;
    }

}
void ShrubberyCreationForm :: beSigned(Bureaucrat &B)
{
    AForm :: beSigned(B);
}

ShrubberyCreationForm :: ~ShrubberyCreationForm()
{
    
}