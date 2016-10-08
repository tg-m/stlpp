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

TEST_F(TemplateTest, adjacent_find_it_it) {
    std::vector<int> v = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    auto expected = std::adjacent_find(std::begin(v), std::end(v));
    auto actual = stdpp::adjacent_find(v);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(*expected, *actual);
    ASSERT_EQ(*(expected + 1), *(1 + actual));
    ASSERT_EQ(5, *actual);
}
TEST_F(TemplateTest, adjacent_find_it_it_pred) {
    std::vector<int> v = {1, 2, 3, 4, 5, 5, 3, 2, 6, 7};
    auto pred = [](int l, int r) {return l == r;};
    auto expected = std::adjacent_find(std::begin(v), std::end(v), pred);
    auto actual = stdpp::adjacent_find(v, pred);

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(*expected, *actual);
    ASSERT_EQ(*(expected + 1), *(1 + actual));
    ASSERT_EQ(5, *actual);
}
