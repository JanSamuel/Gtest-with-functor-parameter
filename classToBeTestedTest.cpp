#include "classToBeTestedTest.h"

template<typename function>
functorInt FunctInt(function set, int input, int result){
    return std::make_tuple(std::bind(set, &testedClass, std::placeholders::_1), input, result);
}


TEST_P(testClassParameters, ShouldSetAndGetIntSetting)
{
    int settingValue;
    auto [function, input, result]  = GetParam();
    EXPECT_OK(function(input, settingValue));
    ASSERT_EQ(result, settingValue);
}

INSTANTIATE_TEST_CASE_P(testWithFunctor, testClassParameters, ::testing::Values(
    FunctInt(&classToBeTested::covertIntegerToInt, 1, 1),
	FunctInt(&classToBeTested::covertIntegerToInt, 2, 2),
	FunctInt(&classToBeTested::covertIntegerToInt, 3, 3),
	FunctInt(&classToBeTested::covertIntegerToInt, 10, 0),
    FunctInt(&classToBeTested::covertIntToInteger, 1, 1),
	FunctInt(&classToBeTested::covertIntToInteger, 2, 2),
	FunctInt(&classToBeTested::covertIntToInteger, 3, 3),
	FunctInt(&classToBeTested::covertIntToInteger, 10, 0),
));