#include "cpp11_auto.h"
#include <vector>
#include <typeinfo>

namespace test_cpp11
{
	//auto will support basic type derivation.
	void test_auto_common()
	{
		auto a = 4;
		auto b = 0.6;
		auto c = "fdsafd";
		auto d  = true;

		int value = 333;
		auto *pValue = new auto(value);
		auto **ppValue = new auto(&value);
		const auto n = 9;
	}

	//auto support iterator
	void test_auto_iterator()
	{
		std::vector<int> vecA;
		vecA.push_back(10);
		vecA.push_back(12);

		for(auto a = vecA.begin(); a != vecA.end(); a++)
		{
			printf("a:%d\n", *a);
		}

		for(auto b : vecA)
		{
			printf("b:%d\n", b);
		}
		for each (auto c in vecA)
		{
			printf("c:%d\n", c);
		}
	}

	//auto will simple template
	template <typename BuiltType, typename Builder>
	void makeAndProcessObject(Builder& build)
	{
		BuiltType val = build.makeobject();
	}

	template <typename Builder>
	void makeAndProcessObject1(Builder& builder)
	{
		auto val = builder.makeobject();
	}

	class MyObj
	{
	public:
		MyObj(int a) {m_nA = a;}

		int m_nA;
	};

	class MyObjBuilder
	{
	public:
		MyObjBuilder(){}
		MyObj makeobject(){return MyObj(10);}
	};

	void test_auto_tempalte()
	{
		MyObjBuilder builder;
		makeAndProcessObject<MyObj>(builder);

		makeAndProcessObject1(builder);
	}

	//Auto support return value and decltype
	template <typename Builder>
	auto makeAndProcessObject2(Builder& builder) -> decltype(builder.makeobject())
	{
		auto val = builder.makeobject();

		return val;
	}

	void test_auto_return_value()
	{
		MyObjBuilder builder;
		makeAndProcessObject2(builder);
	}

	// Auto support reference
	int n = 10;
	int & getN()
	{
		return n;
	}

	void test_auto_reference()
	{
		auto m = getN();
		printf("the value of n is %d.\n", m);
		m = 8;//don't change n
		printf("the value of n is %d after auto m = getN().\n", n);
		
		auto & h = getN();
		h = 8;//change n
		printf("the value of h is %d after auto & h = getN().\n", n);
	}

	// Auto support point
	int m = 10;
	int * getMPoint()
	{
		return &m;
	}

	void test_auto_point()
	{
		auto pM = getMPoint();
		printf("the value of m is %d.\n", m);
		*pM = 8;
		printf("the value of n is %d after auto pM = getMPoint().\n", m);

		auto *pH = getMPoint();
		*pH = 6;
		printf("the value of n is %d after auto *pH = getMPoint().\n", m);
	}

	// Auto support const
	void test_auto_const()
	{
		int a = 6;
		const auto pM = getMPoint(); // equivalent to int * const pM = getMPoint(); so we don't support "pM = &a"
		*pM = 8;

		const auto temp = 9; // we can't modify temp
		//temp = 6;
	}

	// we need to pay attention to matter when we use auto
	void test_auto_warning()
	{
		
	    // no casting using auto	
		int value = 333;
		/*auto x2 = (auto)value;

		auto x3 = static_cast(auto)value;
		
		
		//This is too much....we cannot combine like this
		auto x1 = 5, x4 = 6, x5 = 33, x6 = 'f';

		//we must initialize auto pamarater.
		auto m;

		//we don't use auto with other type as below
		auto int nn = 4;
		*/

		// auto don't support CV-qualifiers(constant & volatile qualifiers)
		const int i = 99;
		auto j = i; 
		j = 33;

		// auto is one point when set array to be auto
		int a[9] = {0};
		auto f = a;
		printf("type of j is %s\n", typeid(f).name());
		auto &k = a;
		printf("type of j is %s\n", typeid(k).name());
	}
	//void MyFunction(auto parameter){}
	//template<auto T>
	//void Fun(T t){}

    void test_auto()
	{
		test_auto_common();
		test_auto_iterator();
		test_auto_tempalte();
		test_auto_return_value();
		test_auto_reference();
		test_auto_point();
		test_auto_const();
		test_auto_warning();
		auto i = 12;
	}
};