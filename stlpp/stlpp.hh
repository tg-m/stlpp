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

#include <algorithm>

#ifndef STLPP_STLPP_HH_
#define STLPP_STLPP_HH_

#define STLPP_namespace stdpp

namespace STLPP_namespace {
#if __cplusplus >= 201103L
template<typename Container_t> inline auto begin(Container_t& c) -> decltype(std::begin(c)) {
    return std::begin(c);
}
template<typename Container_t> inline auto begin(Container_t const& c) -> decltype(std::begin(c)) {
    return std::begin(c);
}
template<typename Container_t> inline auto end(Container_t& c) -> decltype(std::end(c)) {
    return std::end(c);
}
template<typename Container_t> inline auto end(Container_t const& c) -> decltype(std::end(c)) {
    return std::end(c);
}
#else
template<typename Container_t> inline typename Container_t::iterator begin(Container_t& c) {return c.begin();}
template<typename Container_t> inline typename Container_t::iterator begin(Container_t const& c) {return c.begin();}
template<typename Container_t> inline typename Container_t::iterator end(Container_t& c) {return c.end();}
template<typename Container_t> inline typename Container_t::iterator end(Container_t const& c) {return c.end();}
#endif

}
/* namespace stdpp */

#define GEN_it_it(function) \
template<typename Container_t> \
inline typename Container_t::iterator function(Container_t& c) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c)); \
}\
template<typename Container_t> \
inline typename Container_t::const_iterator function(Container_t const& c) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c)); \
}
#define GEN_it_it_pred(function) \
template<typename Container_t, typename Predicate_t> \
inline typename Container_t::iterator function(Container_t& c, Predicate_t const& pred) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), pred); \
}\
template<typename Container_t, typename Predicate_t> \
inline typename Container_t::const_iterator function(Container_t const& c, Predicate_t const& pred) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), pred); \
}
#define GEN_it_it_and_it_it_pred(function)\
GEN_it_it(function);\
GEN_it_it_pred(function)

#define GEN_it_it_pred_RETURN_bool(function)\
template<typename Container_t, typename Predicate_t> \
inline bool function(Container_t& c, Predicate_t const& pred) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), pred); \
}\
template<typename Container_t, typename Predicate_t> \
inline bool function(Container_t const& c, Predicate_t const& pred) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), pred); \
}

#define GEN_it_it_val_RETURN_bool(function)\
template<typename Container_t, typename T> \
inline bool function(Container_t& c, T const& val) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), val); \
}\
template<typename Container_t, typename T> \
inline bool function(Container_t const& c, T const& val) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), val); \
}
#define GEN_it_it_val_compare_RETURN_bool(function)\
template<typename Container_t, typename T, typename Compare_t> \
inline bool function(Container_t& c, T const& val, Compare_t const& compare) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), val, compare); \
}\
template<typename Container_t, typename T, typename Compare_t> \
inline bool function(Container_t const& c, T const& val, Compare_t const& compare) { \
    return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c), val, compare); \
}
#define GEN_it_it_val_and_it_it_val_compare_RETURN_bool(function)\
GEN_it_it_val_RETURN_bool(function);\
GEN_it_it_val_compare_RETURN_bool(function)

/*
 * define(function, return type (but how extract iterator in c++98? there is decltype), argments(?), c++ min version, c++ max version)
 *
 * What if someone want to pass vector in a reverse order? Gluing an 'r' letter could be a solution...
 */

/*
 * Result_t:
 *  bool,
 *  forward_iterator,
 *  input_iterator,
 *  output_iterator,
 *  bidirectional_iterator,
 *  void,
 *  Function (for_each),
 *  std::pair<fwd_it, fwd_it> (equal_range),
 *  iterator_traits<input_it>::difference_t (count_if, count)
 */

namespace STLPP_namespace {

GEN_it_it_and_it_it_pred(adjacent_find);
GEN_it_it_val_and_it_it_val_compare_RETURN_bool(binary_search);
GEN_it_it(max_element);

/*
 * Algorithms that were added in C++11
 */
#if __cplusplus >= 201103L
GEN_it_it_pred_RETURN_bool(all_of);
GEN_it_it_pred_RETURN_bool(any_of);
#endif

} /* namespace stdpp */

#endif /* STLPP_STLPP_HH_ */
