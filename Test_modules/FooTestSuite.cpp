#include "gtest/gtest.h"
#include "../Include/Foo.hpp"

TEST(FooTestSuite, getIdShouldReturnTheParamValueOfConstructor)
{
    Foo foo(10);

    ASSERT_EQ(10, foo.getId());
}
