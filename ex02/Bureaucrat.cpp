#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
    std::cout << "Bureaucrat, Default constructor" << std::endl;
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name) : _name("Default") {
    std::cout << "Bureaucrat, name constructor" << std::endl;
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default") {
    std::cout << "Bureaucrat, grade constructor" << std::endl;
    if (grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat, name and grade constructor" << std::endl;
    if (grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << this->getName() << ", Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    std::cout << "Bureaucrat, Copy constructor" << std::endl;
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
    std::cout << "Bureaucrat, Copy assignment operator" << std::endl;
    if (this != &src)
        this->_grade = src._grade;

    return *this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::increment_grade(){
    std::cout << "Bureaucrat incremented grade" << std::endl;
    if (_grade > 150)
        throw GradeTooHighException();
    else if (_grade <= 1)
        throw GradeTooLowException();
    else
        this->_grade--;
}   

void Bureaucrat::decrement_grade() {

    std::cout << "Bureaucrat decrement grade" << std::endl;
    if (_grade >= 150)
        throw GradeTooHighException();
    else if (_grade < 1)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(Form &Form) {
    Form.beSigned(*this);
}

void Bureaucrat::executeForm(Form const & form){
    if (this->getGrade() >= form.getExecute_grade())
        throw Bureaucrat::GradeTooLowException();
    else if (form.getIsSigned() == false)
        std::cout << "form not signed yet!" << std::endl;
    else
        std::cout << this->getName() << ", executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "grade too low";
}


std::ostream &operator<<(std::ostream &os, Bureaucrat *Bureaucrat_obj){
    return os << Bureaucrat_obj->getName() << ", bureaucrat grade " << Bureaucrat_obj->getGrade() << "." << std::endl;
}
