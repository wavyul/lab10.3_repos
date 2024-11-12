#include "pch.h"
#include "CppUnitTest.h"
#include "../LB10.3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(SortTest)
        {
            const int N = 3;
            Route routes[N] = {
              {"Point A", "Point B", 2},
              {"Point C", "Point D", 1},
              {"Point E", "Point F", 3}
            };

            Sort(routes, N);

            int expected_route_numbers[N] = { 1, 2, 3 };

            for (int i = 0; i < N; i++)
            {
                Assert::AreEqual(expected_route_numbers[i], routes[i].route_number, L"Номер маршруту не співпадає з очікуваним після сортування", LINE_INFO());
            }
        }
    };
}
