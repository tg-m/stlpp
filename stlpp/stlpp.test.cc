/**
 * @file
 * Copyright (C) 2016 Tomasz G. Markiewicz (tomasz.g.markiewicz@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Created on Oct 8, 2016
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

#include "stlpp.hh"
//#define stdpp STLPP_namespace

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class TemplateTest : public testing::Test {
public:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(TemplateTest, fixture_self_test) {}
TEST_F(TemplateTest, DISABLED_test) {}

bool int_eq(int l, int r) {
    return (!(l < r) && !(r < l));
}

bool int_less(int l, int r) {
    return l < r;
}

#define special_general_adjacent_find_it_it(direction, Const, input)\
TEST_F(TemplateTest, special_general_##direction##_##Const##_adjacent_find_it_it) {\
    std::vector<int> Const v = input;\
    auto expected = std::adjacent_find(stdpp::direction##begin(v), stdpp::direction##end(v));\
    auto actual = stdpp::direction##adjacent_find(v);\
\
    ASSERT_EQ(expected, actual);\
    ASSERT_EQ(*expected, *actual);\
    ASSERT_EQ(*(expected + 1), *(1 + actual));\
    ASSERT_EQ(5, *actual);\
}
special_general_adjacent_find_it_it(,, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it(, const, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it(r,, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it(r, const, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));

#define special_general_adjacent_find_it_it_pred(direction, Const, input)\
TEST_F(TemplateTest, special_general_##direction##_##Const##_adjacent_find_it_it_pred) {\
    std::vector<int> Const v = input;\
    auto expected = std::adjacent_find(stdpp::direction##begin(v), stdpp::direction##end(v), int_eq);\
    auto actual = stdpp::direction##adjacent_find(v, int_eq);\
\
    ASSERT_EQ(expected, actual);\
    ASSERT_EQ(*expected, *actual);\
    ASSERT_EQ(*(expected + 1), *(1 + actual));\
    ASSERT_EQ(5, *actual);\
}
special_general_adjacent_find_it_it_pred(,, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it_pred(, const, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it_pred(r,, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
special_general_adjacent_find_it_it_pred(r, const, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));

#define specific_test_function_0_params(tag, function, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##_0_params) {\
    std::vector<int> Const v = input;\
    auto expected = std::function(stdpp::direction##begin(v), stdpp::direction##end(v));\
    auto actual = stdpp::direction##function(v);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params(tag, function, input)\
specific_test_function_0_params(tag, function, input, , );\
specific_test_function_0_params(tag, function, input, , const);\
specific_test_function_0_params(tag, function, input, r, );\
specific_test_function_0_params(tag, function, input, r, const);

#define specific_test_function_1_params(tag, function, paramOne, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__1_params) {\
    std::vector<int> Const v = input;\
    auto expected = std::function(stdpp::direction##begin(v), stdpp::direction##end(v), paramOne);\
    auto actual = stdpp::direction##function(v, paramOne);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_1_params(tag, function, paramOne, input)\
specific_test_function_1_params(tag, function, paramOne, input, , );\
specific_test_function_1_params(tag, function, paramOne, input, , const);\
specific_test_function_1_params(tag, function, paramOne, input, r, );\
specific_test_function_1_params(tag, function, paramOne, input, r, const);

#define specific_test_function_2_params(tag, function, paramOne, paramTwo, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__2_params) {\
    std::vector<int> Const v = input;\
    auto expected = std::function(stdpp::direction##begin(v), stdpp::direction##end(v), paramOne, paramTwo);\
    auto actual = stdpp::direction##function(v, paramOne, paramTwo);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_2_params(tag, function, paramOne, paramTwo, input)\
specific_test_function_2_params(tag, function, paramOne, paramTwo, input, , );\
specific_test_function_2_params(tag, function, paramOne, paramTwo, input, , const);\
specific_test_function_2_params(tag, function, paramOne, paramTwo, input, r, );\
specific_test_function_2_params(tag, function, paramOne, paramTwo, input, r, const);

#define specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__3_params) {\
    std::vector<int> Const v = input;\
    auto expected = std::function(stdpp::direction##begin(v), stdpp::direction##end(v), paramOne, paramTwo, paramThree);\
    auto actual = stdpp::direction##function(v, paramOne, paramTwo, paramThree);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input)\
specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, , );\
specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, , const);\
specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, r, );\
specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, r, const);

generic_test_function_0_params(1, adjacent_find, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
generic_test_function_0_params(2, adjacent_find, std::vector<int>({1, 2, 3, 4, 5, 3, 2, 6, 7}));
generic_test_function_1_params(1, adjacent_find, int_eq, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
generic_test_function_1_params(2, adjacent_find, int_eq, std::vector<int>({1, 2, 3, 4, 5, 3, 2, 6, 7}));

generic_test_function_1_params(1, binary_search, 9, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED -- binary_search requirement! */));
generic_test_function_1_params(2, binary_search, 123, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED -- binary_search requirement! */));
generic_test_function_2_params(1, binary_search, 9, int_less, std::vector<int>( {1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED */));
generic_test_function_2_params(2, binary_search, 123, int_less, std::vector<int>( {1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED */));

auto const geq_zero_int = [](int i) -> bool {return i >= 0;};
generic_test_function_1_params(1, all_of, geq_zero_int, std::vector<int>( {1, 2, 3, 4, 5, 5, 3, 2, 6, 7, -1}));
generic_test_function_1_params(2, all_of, geq_zero_int, std::vector<int>( {1, 2, 3, 4, 5, 3, 2, 6, 7}));

auto const less_than_zero_int = [](int i) -> bool {return i < 0;};
generic_test_function_1_params(1, any_of, less_than_zero_int, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));
generic_test_function_1_params(2, any_of, less_than_zero_int, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
