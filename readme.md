# CPP Module 05

This repository contains the exercises for CPP Module 05, focusing on C++ exception handling.

## Overview

This module explores exception handling in C++, introducing the concepts of try/catch blocks, exception classes, and exception propagation. The exercises revolve around implementing a bureaucratic system with forms that can be signed and executed, demonstrating how to handle errors through exceptions rather than return values.

## Exercises

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

An introduction to exception handling through a basic bureaucrat class.

#### Features:
- `Bureaucrat` class with name and grade attributes
- Grade constraints (1 to 150) enforced through exceptions
- Custom exception classes `GradeTooHighException` and `GradeTooLowException`
- Proper error messages for exception cases

#### Implementation Details:
- Orthodox Canonical Form implementation for the `Bureaucrat` class
- Exception classes inheriting from `std::exception`
- Use of `what()` method to provide error messages
- Grade increment and decrement operations with exception handling

### Exercise 01: Form up, maggots!

Extends the previous exercise by adding a `Form` class that can be signed by bureaucrats.

#### Features:
- `Form` class with attributes for name, signing grade, execution grade, and signing status
- Forms that can only be signed by bureaucrats with sufficient grade
- Exception handling for invalid grades and insufficient permissions
- Interaction between `Bureaucrat` and `Form` classes

#### Implementation Details:
- Exception propagation from `Form` to `Bureaucrat` class
- Implementation of `beSigned()` method in `Form`
- Implementation of `signForm()` method in `Bureaucrat`
- Proper error messages for different exception cases

### Exercise 02: No, you need form 28B, not 28C...

Further extends the hierarchy by creating concrete form types with specific behaviors.

#### Features:
- Abstract `AForm` class (renamed from `Form`) with pure virtual `execute()` method
- Three concrete form classes with different grade requirements and behaviors:
  - `ShrubberyCreationForm`: Creates ASCII trees in a file
  - `RobotomyRequestForm`: Attempts to robotomize a target with 50% success rate
  - `PresidentialPardonForm`: Pardons someone by Zaphod Beeblebrox

#### Implementation Details:
- Inheritance structure with an abstract base class and concrete derived classes
- Specific grade requirements for each form type
- Form execution logic with appropriate exception handling
- Implementation of `executeForm()` method in `Bureaucrat`

### Exercise 03: At least this beats coffee-making

Completes the system with an `Intern` class that can create forms on demand.

#### Features:
- `Intern` class that can create any form type given a name
- Factory pattern implementation
- Error handling for unknown form types
- Streamlined form creation process

#### Implementation Details:
- Dynamic creation of different form types through a common interface
- Use of function pointers to implement the factory pattern
- Form identification by name
- Exception handling for form creation errors

## Class Hierarchy

```
                    std::exception
                          |
                          |
                    +-----+-----+
                    |           |
      Bureaucrat::GradeTooHighException
      Bureaucrat::GradeTooLowException
      Form::GradeTooHighException        AForm
      Form::GradeTooLowException    (abstract class)
      Form::FormNotSignedException        /|\
                                          |
                    +----------+----------+----------+
                    |          |                     |
                    |          |                     |
        ShrubberyCreationForm  RobotomyRequestForm  PresidentialPardonForm
```

## Compilation

Each exercise comes with a Makefile that supports the following commands:
- `make`: Compile the program
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the entire program

## Requirements

- C++ compiler with C++98 standard support
- Linux/macOS environment
- All code must compile with the following flags:
```
c++ -Wall -Wextra -Werror -std=c++98
```

## Technical Details

### Exception Handling

Exception handling in C++ allows for error conditions to be detected and processed separately from normal code. Key concepts demonstrated in these exercises include:

- Creating custom exception classes that inherit from `std::exception`
- Using `try`/`catch` blocks to handle exceptions
- Throwing exceptions to signal error conditions
- Implementing the `what()` method to provide error messages
- Exception propagation through function calls

### Virtual Functions and Abstract Classes

In Exercise 02 and 03, the module demonstrates:

- Pure virtual functions with the `= 0` syntax
- Abstract base classes that cannot be instantiated
- Inheritance hierarchies with concrete derived classes
- Runtime polymorphism through virtual functions

### Form Execution Requirements

Each concrete form has specific requirements:
1. `ShrubberyCreationForm` (sign: 145, exec: 137): Creates a file with ASCII trees
2. `RobotomyRequestForm` (sign: 72, exec: 45): Makes drilling noises and has a 50% success rate
3. `PresidentialPardonForm` (sign: 25, exec: 5): Informs that the target has been pardoned

## Notes

These exercises demonstrate essential C++ exception handling concepts such as:
- Error handling through exceptions rather than return values or error codes
- The importance of RAII (Resource Acquisition Is Initialization) with exceptions
- Exception safety in object-oriented programming
- Exception class hierarchies
- Runtime polymorphism with virtual functions