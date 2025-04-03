#include "Base.hpp"
#include "Classes.hpp"

Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	std::cout << "Unknown type" << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "===== Random Testing =====" << std::endl;
	for (int i = 1; i <= 3; i++) {
		std::cout << "Test " << i << ":" << std::endl;

		Base *randomBase = generate();
		identify(randomBase);
		identify(*randomBase);
		delete randomBase;

		std::cout << "-------------------------" << std::endl;
	}

	std::cout << "\n===== Manual Testing =====" << std::endl;
	Base *manualBase = new A;
	identify(manualBase);
	identify(*manualBase);
	delete manualBase;

	std::cout << "\n===== Bad Casting Test =====" << std::endl;
	Base *badCastBase = new B;

	try {
		(void)dynamic_cast<A&>(*badCastBase);
	} catch (std::bad_cast &) {
		std::cout << "Caught bad_cast exception using reference cast." << std::endl;
	}

	if (!dynamic_cast<A*>(badCastBase)) {
		std::cout << "Caught bad_cast using pointer cast." << std::endl;
	}

	delete badCastBase;
	return 0;
}
