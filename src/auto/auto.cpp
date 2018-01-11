#include "auto.h"

namespace test_cpp11
{
	//auto will support basic type derivation.
	void test_auto_common()
	{
		auto a = 4;
		auto b = 0.6;
		auto c = "fdsafd";
		auto d  = true;
	}

    void test_auto()
	{
		test_auto_common();
	}
};