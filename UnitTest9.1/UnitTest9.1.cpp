#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
    TEST_CLASS(UnitTest91)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int N = 3;
            Student students[N];

            students[0].physicsm = 5; students[0].mathm = 5;
            students[1].physicsm = 5; students[1].mathm = 5;
            students[2].physicsm = 5; students[2].mathm = 5;

            double result = PercentageOfStudentsWith5(students, N);

            Assert::AreEqual(100.0, result);
        }
    };
}
