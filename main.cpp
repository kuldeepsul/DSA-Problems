#include <iostream>
#include "Tree.h"
#include "Linked_List.h"
#include "Backtracking.h"
#include "Array.h"


//class Base
//{
//public:
//	virtual void function1()
//	{
//		std::cout << "Function from Base Class" << std::endl;
//	}
//	void function2()
//	{
//		std::cout << "Function2 from Base Class" << std::endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	void function1()
//	{
//		std::cout << "Function from Derived1 Class" << std::endl;
//	}
//	
//};
//
//class Derived2 : public Base
//{
//public:
//	void function3()
//	{
//		std::cout << "Function3 from Derived2 class" << std::endl;
//	}
//
//};
//
//
//int main(void) 
//{
//	Base* pbase = new Base();
//	Derived* pderived1 = new Derived();
//	Derived2* pderived2 = new Derived2();
//
//	pbase->function1();
//	pderived1->function1();
//	pderived2->function1();
//
//	Base* pbase1 = new Derived();
//	Base* pbase2 = new Derived2();
//
//	std::cout << "Using Base Pointer and creating derived object instance on it." << std::endl;
//	pbase1->function1();
//	pbase2->function1();
//
//
//	std::cout << "Using Base pointer and derived pointer , and calling function2" << std::endl;
//	pbase1->function2();
//	pderived1->function2();
//	pderived2->function2();
//
//
//	std::cout << "Using Function 3 only present in Derived2 , once from a base pointer and after from its own pointer." << std::endl;
//	pderived2->function3();
//	pbase2->function3();
//
//	return 0;
//}

int main()
{
	std::vector <int> nums = { 1,2,3 };

	std::vector <std::vector<int>> res = Backtracking::permute(nums);
	return 0;
}