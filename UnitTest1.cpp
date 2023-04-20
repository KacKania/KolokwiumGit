#include "pch.h"
#include "CppUnitTest.h"
#include "../CppTesty/CppTesty.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testy
{
	TEST_CLASS(UnitTest1)
	{
	public:
	
		TEST_METHOD(brakPierwszeTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(9, 7);

			bool expected = false;

			try {
				int i = znajdzPierwsze(tab, 4, &szukany);
			}
			catch (exception& e) {
				expected = true;
			}

			Assert::IsTrue(expected);
		}


		TEST_METHOD(brakOstatnieTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(9, 7);

			bool expected = false;

			try {
				int i = znajdzOstatnie(tab, 4, &szukany);
			}
			catch (exception& e) {
				expected = true;
			}


			Assert::IsTrue(expected);
		}

		TEST_METHOD(razPierwszeTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(2, 3);

			int i = znajdzPierwsze(tab, 4, &szukany);

			Assert::AreEqual(0,i);
		}

		TEST_METHOD(razOstatnieTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(2, 3);

			int i = znajdzOstatnie(tab, 4, &szukany);

			Assert::AreEqual(0, i);
		}

		TEST_METHOD(wiecejPierwszeTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(3, 4);

			int i = znajdzPierwsze(tab, 4, &szukany);

			Assert::AreEqual(1, i);
		}

		TEST_METHOD(wiecejOstatnieTest)
		{
			wektor w1(2, 3);
			wektor w2(3, 4);
			wektor w3(3, 4);
			wektor w4(5, 6);
			wektor tab[4] = { w1, w2, w3, w4 };

			wektor szukany(3, 4);

			int i = znajdzOstatnie(tab, 4, &szukany);

			Assert::AreEqual(2, i);
		}



	};
}
