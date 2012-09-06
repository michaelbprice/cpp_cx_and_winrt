#include "pch.h"
#include <memory>
#include <iostream>

using namespace Platform;

/*
   STLDODN '12 - Scope Resolution Operator (global scope)
*/
void a() { }

/*
   STLDODN '12 - Inheritance
   STLDODN '12 - Multiple Inheritance
*/
class BaseA
{
public:
	int a() { return 1; }
};

class BaseB
{
public:
	bool b() { return true; }
};

class PureVirtual
{
public:
	virtual double abstract_func () = 0;
};

class Derived : public BaseA, public BaseB, public PureVirtual
{
public:
	virtual double abstract_func () { ::a(); /*a();*/ return 1.0f; }
};

/*
   STLDODN '12 - Object Lifetime
*/
void user_of_Derived()
{
	std::unique_ptr<Derived> p2d;
	{
		Derived d;
		p2d.reset(new Derived());

		d.a();
		d.b();
		d.abstract_func();
	}
}


/*
   STLDODN '12 - Construction
   STLDODN '12 - Destruction
   STLDODN '12 - Copying
   STLDODN '12 - Moving + r-value References
   STLDODN '12 - Operator Overloading
*/
class MyClass
{
public:
	MyClass();
	virtual ~MyClass();

	MyClass(const MyClass& other);
	MyClass& operator=(const MyClass& other);

	MyClass(MyClass&& other);
	MyClass& operator=(MyClass&& other);

};



/*
   STLDODN '12 - Templates
   STLDODN '12 - Template Type Deduction
*/
template <typename T>
void print(const T& t)
{ std::cout << t << std::endl; }

void printer()
{
	print(1);
	print("Hello World");
	print<int>(1.0f);
	print<double>(1.0f);
};


/*
   STLDODN '12 - WinRT Type Declarations
*/

value class MyValClass { public: int i; };

/*
   STLDODN '12 - WinRT Interface Declaration
   STLDODN '12 - WinRT Class Accessibility
*/
private interface class IMyInterface { };

/*
   STLDODN '12 - WinRT Inheritance
*/
ref class MyRefBase { };

/*
   STLDODN '12 - WinRT Delegate
*/
delegate void OnSomethingHandler();

ref class MyRefClass : public MyRefBase, public IMyInterface
{
public:
/*
   STLDODN '12 - WinRT Properties
*/
	property int Value;
	
/*
   STLDODN '12 - WinRT Event
*/
	event OnSomethingHandler^ OnSomething;
};

/*
   STLDODN '12 - WinRT ^
   STLDODN '12 - WinRT %
   STLDODN '12 - WinRT ref new
*/
void winrt_func()
{
	MyRefClass^ c = ref new MyRefClass();

	c->Value = 1;

	c->OnSomething += ref new OnSomethingHandler([]() { std::cout << "In Handler" << std::endl; });

	MyRefClass^ copy_of_c = c;

	MyRefClass% not_a_copy_of_c = *c;
}

/*
   STLDODN '12 - WinRT Generics
*/
generic <typename T>
interface class IGenericPrinter
{
	void Print(T thing);
};

ref class StringPrinter : IGenericPrinter<String^>
{
public:
	virtual void Print(String^ thing) { std::cout << thing->Data() << std::endl; }
};

ref class IntPrinter : IGenericPrinter<int>
{
public:
	virtual void Print(int thing) { std::cout << thing << std::endl; }
};

ref class MyRefClassPrinter : IGenericPrinter<MyRefClass^>
{
public:
	virtual void Print(MyRefClass^ thing) { std::cout << thing->ToString()->Data() << std::endl; }
};

/*
   STLDODN '12 - WinRT Generics (using Templates)
*/
template <typename T>
ref class Printer : IGenericPrinter<T>
{
public:
	virtual void Print(T thing) { std::cout << thing->ToString()->Data() << std::endl; }
};

template <>
ref class Printer<String^> : IGenericPrinter<String^>
{
public:
	virtual void Print(String^ thing) { std::cout << thing->Data() << std::endl; }
};

template <>
ref class Printer<int> : IGenericPrinter<int>
{
public:
	virtual void Print(int thing) { std::cout << thing << std::endl; }
};

void print_function()
{
	IGenericPrinter<int>^ gp_int = ref new IntPrinter();
	IGenericPrinter<String^>^ gp_String = ref new StringPrinter();
	IGenericPrinter<MyRefClass^>^ gp_MRC = ref new MyRefClassPrinter();

	gp_int = ref new Printer<int>();
	gp_String = ref new Printer<String^>();
	gp_MRC = ref new Printer<MyRefClass^>();
	IGenericPrinter<Object^>^ gp_obj = ref new Printer<Object^>();
}

/*
   STLDODN '12 - Scoped Enumerations
*/
enum OldEnum
{
	A = 1,
	Z = 26
};

enum class ScopedEnum : unsigned char
{
	Alpha = 0,
	Omega = 255,
	//OmegaPlus = 256
};

void enum_func()
{
	OldEnum old_enum = A;
	//ScopedEnum scoped_enum = Alpha;
	ScopedEnum scoped_enum = ScopedEnum::Alpha;
}

/*
   STLDODN '12 - WinRT Enumerations
*/
enum class WinRTEnum : unsigned short
{
	Alpha = 0,
	Omega = 65535,
	//OmegaPlus = 65536
};
