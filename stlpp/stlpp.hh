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

#define GEN_it_it(function) \
template<typename Container_t> \
inline typename Container_t::iterator function(Container_t& c) { \
    return std::function(std::begin(c), std::end(c)); \
}\
template<typename Container_t> \
inline typename Container_t::const_iterator function(Container_t const& c) { \
    return std::function(std::begin(c), std::end(c)); \
}

#define GEN_it_it_pred(function) \
template<typename Container_t, typename Predicate_t> \
inline typename Container_t::iterator function(Container_t& c, Predicate_t pred) { \
    return std::function(std::begin(c), std::end(c), pred); \
}\
template<typename Container_t, typename Predicate_t> \
inline typename Container_t::const_iterator function(Container_t const& c, Predicate_t pred) { \
    return std::function(std::begin(c), std::end(c), pred); \
}

#define GEN_it_it_and_it_it_pred(function)\
GEN_it_it(function);\
GEN_it_it_pred(function)

namespace stdpp {

GEN_it_it_and_it_it_pred(adjacent_find);

GEN_it_it(max_element);

}

#endif /* STLPP_STLPP_HH_ */
