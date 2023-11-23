#include "Base.hpp"

/*
Dynamic casts are evaluated at runtime and 
requires a virtual function in the base class
Dynamic casts check if a derived class object 
can be safely cast to a base class pointer. 
dynamic casts check if the object being cast is 
an instance of the base class or one of its derived classes.
If the object is not of the correct type, 
the dynamic cast will return a null pointer.
*/

Base *generate(void)
{
    std::srand(std::time(NULL));
    const size_t choice = std::rand() % 3;
    switch (choice)
    {
    case 0:
        std::cout << "Generated A" << std::endl;
        return (new A());
    case 1:
        std::cout << "Generated B" << std::endl;
        return (new B());
    case 2:
        std::cout << "Generated C" << std::endl;
        return (new C());
    default:
        return (0);
    }
}

void identify(Base *p)
{
    const A *aPtr = dynamic_cast<A *>(p);
    if (aPtr){
        std::cout << "Pointer A" << std::endl;
        return;
    }
    const B *bPtr = dynamic_cast<B *>(p);
    if (bPtr) {
        std::cout << "Pointer B" << std::endl;
        return;
    }
    const C *cPtr = dynamic_cast<C *>(p);
    if (cPtr) {
        std::cout << "Pointer C" << std::endl;
        return;
    }
}

void identify(Base &p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "Reference A" << std::endl;
    }
    catch (const std::exception &e){
    }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "Reference B" << std::endl;
    }
    catch (const std::exception &e){
    }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "Reference C" << std::endl;
    }
    catch (const std::exception &e){
    }
}