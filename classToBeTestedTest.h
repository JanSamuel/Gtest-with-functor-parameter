#include "classToBeTested.h"
#include "gtest/gtest.h"

typedef std::tuple<std::function<void (int)>, int, int > functorInt;

classToBeTested testedClass;

class testClass : virtual public testing::Test {
public:
    testClass() = default;
    virtual ~testClass() = default;
    void SetUp() override {
    }
};

class testClassParameters : public testClass, 
    public ::testing::WithParamInterface<functorInt>{};

