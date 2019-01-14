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
    std::vector<typename decltype(input)::value_type> Const v = input;\
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
    std::vector<typename decltype(input)::value_type> Const v = input;\
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
    std::vector<typename decltype(input)::value_type> Const v = input;\
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
    std::vector<typename decltype(input)::value_type> Const v = input;\
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


#define specific_test_function_1_params_test_mutable_input(tag, function, paramOne, input, direction)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__1_params) {\
    std::vector<typename decltype(input)::value_type> expected = input;\
    std::vector<typename decltype(input)::value_type> actual = input;\
    \
    std::function(stdpp::direction##begin(actual), stdpp::direction##end(actual), paramOne);\
    stdpp::direction##function(expected, paramOne);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_1_params_test_mutable_input(tag, function, paramOne, input)\
specific_test_function_1_params_test_mutable_input(tag, function, paramOne, input,  );\
specific_test_function_1_params_test_mutable_input(tag, function, paramOne, input, r)




#define specific_test_function_2_params(tag, function, paramOne, paramTwo, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__2_params) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
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


#define specific_test_function_2_params_test_mutable_input(tag, function, paramOne, paramTwo, input, direction)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__1_params) {\
    std::vector<typename decltype(input)::value_type> expected = input;\
    std::vector<typename decltype(input)::value_type> actual = input;\
    \
    std::function(stdpp::direction##begin(actual), stdpp::direction##end(actual), paramOne, paramTwo);\
    stdpp::direction##function(expected, paramOne, paramTwo);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_2_params_test_mutable_input(tag, function, paramOne, input)\
specific_test_function_2_params_test_mutable_input(tag, function, paramOne, input, );\
specific_test_function_2_params_test_mutable_input(tag, function, paramOne, input, r)

#define specific_test_function_3_params(tag, function, paramOne, paramTwo, paramThree, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__3_params) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
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
generic_test_function_0_params(3, adjacent_find, std::vector<int>());
generic_test_function_1_params(1, adjacent_find, int_eq, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7}));
generic_test_function_1_params(2, adjacent_find, int_eq, std::vector<int>({1, 2, 3, 4, 5, 3, 2, 6, 7}));
generic_test_function_1_params(3, adjacent_find, int_eq, std::vector<int>());

generic_test_function_1_params(1, binary_search, 9, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED -- binary_search requirement! */));
generic_test_function_1_params(2, binary_search, 123, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED -- binary_search requirement! */));
generic_test_function_1_params(3, binary_search, 123, std::vector<int>());
generic_test_function_2_params(1, binary_search, 9, int_less, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED */));
generic_test_function_2_params(2, binary_search, 123, int_less, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}/* MUST BE SORTED */));
generic_test_function_2_params(3, binary_search, 123, int_less, std::vector<int>());

auto const geq_zero_int = [](int i) -> bool {return i >= 0;};
generic_test_function_1_params(1, all_of, geq_zero_int, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 6, 7, -1}));
generic_test_function_1_params(2, all_of, geq_zero_int, std::vector<int>({1, 2, 3, 4, 5, 3, 2, 6, 7}));

auto const less_than_zero_int = [](int i) -> bool {return i < 0;};
generic_test_function_1_params(1, any_of, less_than_zero_int, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));
generic_test_function_1_params(2, any_of, less_than_zero_int, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));

#define specific_test_function_0_params_for_copy(tag, function, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##_0_params_for_copy) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
    std::vector<typename decltype(input)::value_type> expected(v.size());\
    std::vector<typename decltype(input)::value_type> actual(v.size());\
    std::function(stdpp::direction##begin(v), stdpp::direction##end(v), expected.begin());\
    stdpp::direction##function(v, actual.begin());\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params_for_copy(tag, function, input)\
specific_test_function_0_params_for_copy(tag, function, input, , );\
specific_test_function_0_params_for_copy(tag, function, input, , const);\
specific_test_function_0_params_for_copy(tag, function, input, r, );\
specific_test_function_0_params_for_copy(tag, function, input, r, const);
generic_test_function_0_params_for_copy(int_1, copy, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
generic_test_function_0_params_for_copy(int_2, copy, std::vector<int>({}));
generic_test_function_0_params_for_copy(int_3, copy, std::vector<int>());
generic_test_function_0_params_for_copy(int_4, copy, std::vector<int>(10, 10));
generic_test_function_0_params_for_copy(double_1, copy, std::vector<double>({1.0, 2.0, 3.0, 4.09, 5.023, 5.12, 3.87, 12.22, 7.34, 7.09}));
generic_test_function_0_params_for_copy(double_2, copy, std::vector<double>({}));
generic_test_function_0_params_for_copy(double_3, copy, std::vector<double>());
generic_test_function_0_params_for_copy(double_4, copy, std::vector<double>(10, 10.1));


#define specific_test_function_0_params_for_copy_backward(tag, function, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##_0_params_for_copy_backward) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
    std::vector<typename decltype(input)::value_type> expected(v.size());\
    std::vector<typename decltype(input)::value_type> actual(v.size());\
    std::function(stdpp::direction##begin(v), stdpp::direction##end(v), expected.end());\
    stdpp::direction##function(v, actual.end());\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params_for_copy_backward(tag, function, input)\
specific_test_function_0_params_for_copy_backward(tag, function, input, , );\
specific_test_function_0_params_for_copy_backward(tag, function, input, , const);\
specific_test_function_0_params_for_copy_backward(tag, function, input, r, );\
specific_test_function_0_params_for_copy_backward(tag, function, input, r, const);
generic_test_function_0_params_for_copy_backward(int_1, copy_backward, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
generic_test_function_0_params_for_copy_backward(int_2, copy_backward, std::vector<int>({}));
generic_test_function_0_params_for_copy_backward(int_3, copy_backward, std::vector<int>());
generic_test_function_0_params_for_copy_backward(int_4, copy_backward, std::vector<int>(10, 9));
generic_test_function_0_params_for_copy_backward(double_1, copy_backward, std::vector<double>({1.0, 2.0, 3.0, 4.09, 5.023, 5.12, 3.87, 12.22, 7.34, 7.09}));
generic_test_function_0_params_for_copy_backward(double_2, copy_backward, std::vector<double>({}));
generic_test_function_0_params_for_copy_backward(double_3, copy_backward, std::vector<double>());
generic_test_function_0_params_for_copy_backward(double_4, copy_backward, std::vector<double>(10, 10.1));

#define specific_test_function_0_params_for_copy_if(tag, function, pred, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##_0_params_for_copy_if) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
    std::vector<typename decltype(input)::value_type> expected(v.size());\
    std::vector<typename decltype(input)::value_type> actual(v.size());\
    std::function(stdpp::direction##begin(v), stdpp::direction##end(v), expected.begin(), pred);\
    stdpp::direction##function(v, actual.begin(), pred);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params_for_copy_if(tag, function, pred, input)\
specific_test_function_0_params_for_copy_if(tag, function, pred, input, , );\
specific_test_function_0_params_for_copy_if(tag, function, pred, input, , const);\
specific_test_function_0_params_for_copy_if(tag, function, pred, input, r, );\
specific_test_function_0_params_for_copy_if(tag, function, pred, input, r, const);
generic_test_function_0_params_for_copy_if(1, copy_if, [](int i) { return 0 == i % 2; }, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
generic_test_function_0_params_for_copy_if(2, copy_if, [](int i) { return 0 >= i; }, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
generic_test_function_0_params_for_copy_if(3, copy_if, [](int i) { return 0 == i % 2; }, std::vector<int>({}));
generic_test_function_0_params_for_copy_if(4, copy_if, [](int i) { return 0 == i % 2; }, std::vector<int>());
generic_test_function_0_params_for_copy_if(5, copy_if, [](int i) { return 0 == i % 2; }, std::vector<int>(10, 10));

#define specific_test_function_0_params_for_copy_n(tag, function, num, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##_0_params_for_copy_n) {\
    std::vector<typename decltype(input)::value_type> Const v = input;\
    std::vector<typename decltype(input)::value_type> expected;\
    std::vector<typename decltype(input)::value_type> actual;\
    expected.resize(v.size());\
    actual.resize(v.size());\
    std::function(stdpp::begin(v), num, expected.begin());\
    stdpp::function(stdpp::begin(v), num, actual.begin());\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params_for_copy_n(tag, function, num, input)\
specific_test_function_0_params_for_copy_n(tag, function, num, input, , );\
specific_test_function_0_params_for_copy_n(tag, function, num, input, , const);
generic_test_function_0_params_for_copy_n(int_1, copy_n, 5, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, 7}));
generic_test_function_0_params_for_copy_n(double_1, copy_n, 5, std::vector<double>({1.0, 2.0, 3.0, 4.09, 5.023, 5.12, 3.87, 12.22, 7.34, 7.09}));

generic_test_function_1_params(1, count, 7, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));
generic_test_function_1_params(2, count, 7, std::vector<int>({}));
generic_test_function_1_params(3, count, 7, std::vector<int>());
generic_test_function_1_params(4, count, 9877, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));

generic_test_function_1_params(1, count_if, [](int i) { return 0 > i; }, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));
generic_test_function_1_params(2, count_if, [](int i) { return 0 > i; }, std::vector<int>({}));
generic_test_function_1_params(3, count_if, [](int i) { return 0 > i; }, std::vector<int>());
generic_test_function_1_params(4, count_if, [](int i) { return false; }, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));
generic_test_function_1_params(5, count_if, [](int i) { return true; }, std::vector<int>({1, 2, 3, 4, 5, 5, 3, 2, 7, -1}));

generic_test_function_1_params(1, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_1_params(2, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), std::vector<int>({1, 2, 3, 4}));
generic_test_function_1_params(3, equal, std::vector<int>({1, 2, 3, 4}).begin(), std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_1_params(4, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_1_params(5, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), std::vector<int>({1, 2, 3, 4}));
generic_test_function_1_params(6, equal, std::vector<int>({1, 2, 3, 4}).rbegin(), std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_1_params(7, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_1_params(8, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), std::vector<int>({1, 2, 3, 4}));
generic_test_function_1_params(9, equal, std::vector<int>({1, 2, 3, 4}).cbegin(), std::vector<int>({1, 2, 3, 4, 5}));

generic_test_function_2_params(1, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(2, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(3, equal, std::vector<int>({1, 2, 3, 4}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(4, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(5, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(6, equal, std::vector<int>({1, 2, 3, 4}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(7, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(8, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(9, equal, std::vector<int>({1, 2, 3, 4}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));

generic_test_function_2_params(u1, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(u2, equal, std::vector<int>({1, 2, 3, 4, 5}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(u3, equal, std::vector<int>({1, 2, 3, 4}).begin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(u4, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(u5, equal, std::vector<int>({1, 2, 3, 4, 5}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(u6, equal, std::vector<int>({1, 2, 3, 4}).rbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(u7, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));
generic_test_function_2_params(u8, equal, std::vector<int>({1, 2, 3, 4, 5}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4}));
generic_test_function_2_params(u9, equal, std::vector<int>({1, 2, 3, 4}).cbegin(), [](int l, int r) { return l == r; }, std::vector<int>({1, 2, 3, 4, 5}));

/* Input vector must be sorted for equal_range! */
generic_test_function_1_params(_1, equal_range, -1, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_1_params(0, equal_range, 0, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_1_params(1, equal_range, 1, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_1_params(2, equal_range, 2, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_1_params(9, equal_range, 9, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_1_params(10, equal_range, 10, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(_1, equal_range, -1, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(0, equal_range, 0, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(1, equal_range, 1, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(2, equal_range, 2, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(9, equal_range, 9, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));
generic_test_function_2_params(10, equal_range, 10, [](int l, int r) { return l < r; }, std::vector<int>({1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9}));


generic_test_function_1_params_test_mutable_input(int32_t_0, fill, 0, std::vector<int32_t>({1, 2, 3, 4, 5, 6, 7}));
generic_test_function_1_params_test_mutable_input(int32_t_1, fill, 333, std::vector<int32_t>({1, 2, 3, 4, 5, 6, 7}));
generic_test_function_1_params_test_mutable_input(int32_t_2, fill, 0, std::vector<int32_t>({}));
generic_test_function_1_params_test_mutable_input(double_0, fill, 9.53, std::vector<double>({1, 2, 3, 4, 5, 6, 7}));
generic_test_function_1_params_test_mutable_input(double_1, fill, 9.53, std::vector<double>({}));



#define specific_test_function_0_params_for_fill_n(tag, function, paramOne, paramTwo, input, direction, Const)\
TEST_F(TemplateTest, function##_TAG_##tag##_##direction##_##Const##__0_params_for_fill_n) {\
    std::vector<typename decltype(input)::value_type> expected = input;\
    std::vector<typename decltype(input)::value_type> actual = input;\
    \
    std::function(stdpp::direction##begin(expected), paramOne, paramTwo);\
    stdpp::direction##function(stdpp::direction##begin(actual), paramOne, paramTwo);\
\
    ASSERT_EQ(expected, actual);\
}
#define generic_test_function_0_params_for_fill_n(tag, function, paramOne, paramTwo, input)\
specific_test_function_0_params_for_fill_n(tag, function, paramOne, paramTwo, input, ,)

generic_test_function_0_params_for_fill_n(int_0, fill_n, 0, 0, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
generic_test_function_0_params_for_fill_n(int_1, fill_n, 1, 1, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
generic_test_function_0_params_for_fill_n(int_2, fill_n, 3, 4, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
