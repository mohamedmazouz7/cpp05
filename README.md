<div align="center">

# 📋 CPP Module 05

**Repetition and exceptions — Build a bureaucratic nightmare with custom exception handling.**

![C++](https://img.shields.io/badge/language-C%2B%2B98-orange?style=for-the-badge&logo=cplusplus)
![42](https://img.shields.io/badge/school-42-black?style=for-the-badge)
![Score](https://img.shields.io/badge/score-100%2F100-brightgreen?style=for-the-badge)

</div>

---

## 🧠 Concepts Covered

- **Exception handling** — Try-catch blocks, throwing and catching exceptions
- **Custom exceptions** — Inherit from `std::exception`, override `what()`
- **Exception safety** — Ensure resources are freed even when exceptions occur
- **Abstract classes** — Pure virtual functions defining contracts
- **Grade validation** — Range checking (1 highest, 150 lowest)
- **Form workflow** — Create, sign, execute forms with permissions
- **Factory pattern** — Intern creates forms dynamically by name
- **Exception specifications** — Which exceptions functions can throw

---

## 📁 Exercises

| Ex | Name | Main Topics |
|----|------|------------|
| `ex00` | Bureaucrat | Grade validation, custom exceptions, getters |
| `ex01` | Form up, maggots! | Form signing, Bureaucrat-Form interaction |
| `ex02` | Form 28B, not 28C | Abstract AForm, concrete form types, execution |
| `ex03` | Coffee-making beats this | Intern factory, dynamic form creation |

---

## 🚀 Build & Run

```bash
cd ex00      # (or ex01, ex02, ex03)
make
./bureaucrat   # (or form, aform, intern)
```

---

## 💡 Key Learnings

### ex00 — Bureaucrat & Exceptions
Implement **Bureaucrat** with:
- Constant name, grade (1-150, 1 is highest)
- Custom exceptions: `GradeTooHighException`, `GradeTooLowException`
- Methods: `incrementGrade()`, `decrementGrade()`
- Overload `operator<<` for printing

```cpp
try {
    Bureaucrat bob("Bob", 0);  // Invalid grade
} catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

### ex01 — Form Signing
Add **Form** class with:
- Constant name, sign grade, exec grade
- Boolean: is signed?
- Method: `beSigned(const Bureaucrat& b)`
- Throws `GradeTooLowException` if bureaucrat grade not high enough
- Bureaucrat method: `signForm(Form& f)` attempts signing

**Grade comparison**: 1 is HIGHER than 150
```
Bureaucrat grade 1   ← Highest (can do everything)
Bureaucrat grade 75  ← Middle
Bureaucrat grade 150 ← Lowest
```

### ex02 — Abstract Forms & Execution
Make **Form** → **AForm** (abstract), add concrete implementations:

**ShrubberyCreationForm**
- Sign grade: 145, Exec grade: 137
- Creates `<target>_shrubbery` file with ASCII trees

**RobotomyRequestForm**
- Sign grade: 72, Exec grade: 45
- 50% success: "robotomized successfully" or "robotomy failed"
- Makes drilling noises: "Drilling noises... Bzzzzzzt..."

**PresidentialPardonForm**
- Sign grade: 25, Exec grade: 5
- Highest authority form
- Message: "<target> has been pardoned by Zaphod Beeblebrox"

Add `execute(const Bureaucrat& executor)` method:
- Check: form is signed
- Check: executor grade high enough
- Execute: perform action
- Throw: `AForm::GradeTooLowException` if not qualified

### ex03 — Intern Factory
Implement **Intern** class:
- No name, no grade
- Method: `makeForm(const std::string& name, const std::string& target)`
- Returns pointer to new AForm based on name
- Prints: "Intern creates <form_name>"
- Handle unknown form names gracefully

**No excessive if/else structure** — use a clean pattern (e.g., array of pairs)

---

## 🎯 Exception Hierarchy

```
std::exception (standard library)
├── Bureaucrat::GradeTooHighException
├── Bureaucrat::GradeTooLowException
├── Form::GradeTooHighException
├── Form::GradeTooLowException
├── AForm::GradeTooLowException
└── (others)
```

Catch as base class:
```cpp
try {
    // ... code ...
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

---

## 📋 Grade System

| Grade | Authority | Can Sign | Can Execute |
|-------|-----------|----------|-------------|
| 1 | President | ✅ Presidential | ✅ Presidential |
| 5 | High | ✅ Presidential/Robotomy | ✅ Presidential |
| 25 | Medium-High | ✅ Presidential | ❌ |
| 45 | Medium | ✅ Robotomy | ✅ Robotomy |
| 72 | Medium-Low | ✅ Robotomy | ❌ |
| 137 | Low | ✅ Shrubbery | ✅ Shrubbery |
| 145 | Very Low | ✅ Shrubbery | ❌ |
| 150 | Lowest | ❌ Nothing | ❌ Nothing |

---

## 🏭 Factory Pattern (Intern)

Clean form creation without if/else chaos:

```cpp
AForm* makeForm(const std::string& name, const std::string& target) {
    if (name == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        return new PresidentialPardonForm(target);
    // OR use a map/array of form creators
}
```

---

## 🎬 Example Workflow

```cpp
Intern someIntern;
Bureaucrat alice("Alice", 1);
Bureaucrat bob("Bob", 150);

// Intern creates a form
AForm* form = someIntern.makeForm("robotomy request", "Bender");

// High-grade bureaucrat signs it
try {
    alice.signForm(*form);      // Success: "Alice signed..."
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}

// Low-grade bureaucrat tries to execute
try {
    bob.executeForm(*form);     // Fails: "Bob couldn't execute..."
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}

// High-grade bureaucrat executes
alice.executeForm(*form);       // Success: drilling noises...

delete form;
```

---

## ⚡ Key Principles

✅ **Custom exceptions** inherit from `std::exception`  
✅ **Override `what()`** to provide error messages  
✅ **Use const** for grade values in forms  
✅ **Check permissions before execution** — never allow unauthorized actions  
✅ **Clean factory pattern** — no excessive if/else  
✅ **Resource cleanup** — delete dynamically created forms  
✅ **Exception safety** — catch and handle all error cases  

---

<div align="center">

*Exceptions: When normal flow is abnormal.*

*Part of the 42 School C++ curriculum.*

</div>
