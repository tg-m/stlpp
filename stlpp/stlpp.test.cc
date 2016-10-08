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

TEST_F(TemplateTest, adjacent_find_it_it) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    std::vector<int>::iterator expected = std::adjacent_find(stdpp::begin(v), stdpp::end(v));
    std::vector<int>::iterator actual = stdpp::adjacent_find(v);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(*expected, *actual);
    ASSERT_EQ(*(expected + 1), *(1 + actual));
    ASSERT_EQ(5, *actual);
}
TEST_F(TemplateTest, adjacent_find_it_it_pred) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    std::vector<int>::iterator expected = std::adjacent_find(stdpp::begin(v), stdpp::end(v), int_eq);
    std::vector<int>::iterator actual = stdpp::adjacent_find(v, int_eq);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(*expected, *actual);
    ASSERT_EQ(*(expected + 1), *(1 + actual));
    ASSERT_EQ(5, *actual);
}

TEST_F(TemplateTest, binary_search_it_it_val_true) {
    int init_tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; /* MUST BE SORTED -- binary_search requirement! */
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    bool expected = std::binary_search(stdpp::begin(v), stdpp::end(v), 9);
    bool actual = stdpp::binary_search(v, 9);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(true, actual);
    ASSERT_EQ(true, expected);
}
TEST_F(TemplateTest, binary_search_it_it_val_false) {
    int init_tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; /* MUST BE SORTED -- binary_search requirement! */
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    bool expected = std::binary_search(stdpp::begin(v), stdpp::end(v), 0);
    bool actual = stdpp::binary_search(v, 0);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(false, actual);
}
TEST_F(TemplateTest, binary_search_it_it_val_compare_true) {
    int init_tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; /* MUST BE SORTED -- binary_search requirement! */
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    bool expected = std::binary_search(stdpp::begin(v), stdpp::end(v), 9, int_less);
    bool actual = stdpp::binary_search(v, 9, int_less);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(true, actual);
}
TEST_F(TemplateTest, binary_search_it_it_val_compare_false) {
    int init_tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; /* MUST BE SORTED -- binary_search requirement! */
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));
    bool expected = std::binary_search(stdpp::begin(v), stdpp::end(v), 11, int_less);
    bool actual = stdpp::binary_search(v, 11, int_less);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(false, expected);
    ASSERT_EQ(false, actual);
}

/*
 * Algorithms that were added in C++11
 */
#if __cplusplus >= 201103L

TEST_F(TemplateTest, all_of_it_it_pred_true) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));

    auto pred = [](int i) -> bool {return i >= 0;};

    bool expected = std::all_of(std::begin(v), std::end(v), pred);
    bool actual = stdpp::all_of(v, pred);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(true, actual);
}
TEST_F(TemplateTest, all_of_it_it_pred_false) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, -2, 6, 7};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));

    auto pred = [](int i) -> bool {return i >= 0;};

    bool expected = std::all_of(std::begin(v), std::end(v), pred);
    bool actual = stdpp::all_of(v, pred);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(false, actual);
}

TEST_F(TemplateTest, any_of_it_it_pred_true) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, 7, -1};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));

    auto pred = [](int i) -> bool {return i < 0;};

    bool expected = std::any_of(std::begin(v), std::end(v), pred);
    bool actual = stdpp::any_of(v, pred);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(true, actual);
}
TEST_F(TemplateTest, any_of_it_it_pred_false) {
    int init_tab[] = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    std::vector<int> v(init_tab, init_tab + sizeof(init_tab)/sizeof(int));

    auto pred = [](int i) -> bool {return i < 0;};

    bool expected = std::any_of(std::begin(v), std::end(v), pred);
    bool actual = stdpp::any_of(v, pred);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(false, actual);
}

#endif
