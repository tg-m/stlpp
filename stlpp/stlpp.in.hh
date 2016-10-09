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
 * Created on Oct 9, 2016
 *
 */

//#ifndef STLPP_STLPP_IN_HH_
//#define STLPP_STLPP_IN_HH_
#define STLPP_namespace stdpp
#define CAR_RET CAR_RET

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
template<typename Container_t> inline typename Container_t::iterator rbegin(Container_t& c) {
    return c.rbegin();
}
template<typename Container_t> inline typename Container_t::iterator rbegin(Container_t const& c) {
    return c.rbegin();
}
template<typename Container_t> inline typename Container_t::iterator rend(Container_t& c) {
    return c.rend();
}
template<typename Container_t> inline typename Container_t::iterator rend(Container_t const& c) {
    return c.rend();
}
#else
template<typename Container_t> inline typename Container_t::iterator begin(Container_t& c) {return c.begin();}
template<typename Container_t> inline typename Container_t::iterator begin(Container_t const& c) {return c.begin();}
template<typename Container_t> inline typename Container_t::iterator end(Container_t& c) {return c.end();}
template<typename Container_t> inline typename Container_t::iterator end(Container_t const& c) {return c.end();}
#endif

}
/* namespace stdpp */

/*
 * if container will be get as sth.next(), then next will be called twice
 */
#define call_it_it(dir, function, container)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container))

#define call_it_it_pred(dir, function, container, func)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), pred)

#define call_it_it_compare(dir, function, container, compare)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), compare)

#define call_it_it_val(dir, function, container, val)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), val)

#define call_it_it_val_compare(dir, function, container, val, compare)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), val, compare)

//#define GEN_it_it_general(function, dir)\
//template<typename Container_t>\
//inline auto dir##function(Container_t& c) -> decltype(std::function(STLPP_namespace::dir##begin(c), STLPP_namespace::dir##end(c))) {\
//return std::function(STLPP_namespace::dir##begin(c), STLPP_namespace::dir##end(c));\
//}

#define GEN_general_it_it(Const, direction, function)\
template<typename Container_t> inline auto direction##function(Container_t Const& c) -> decltype(call_it_it(direction, function, c)) { return call_it_it(direction, function, c); }
#define GEN_it_it(function)\
GEN_general_it_it(     ,  , function);CAR_RET;\
GEN_general_it_it(const,  , function);CAR_RET;\
GEN_general_it_it(     , r, function);CAR_RET;\
GEN_general_it_it(const, r, function)

#define GEN_general_it_it_pred(Const, direction, function)\
template<typename Container_t, typename Predicate_t>\
inline auto direction##function(Container_t Const& c, Predicate_t pred) -> decltype(call_it_it_pred(direction, function, c, pred)) {\
    return call_it_it_pred(direction, function, c, pred);\
}
#define GEN_it_it_pred(function)\
GEN_general_it_it_pred(     ,  , function);CAR_RET;\
GEN_general_it_it_pred(const,  , function);CAR_RET;\
GEN_general_it_it_pred(     , r, function);CAR_RET;\
GEN_general_it_it_pred(const, r, function)

#define GEN_it_it_and_it_it_pred(function)\
GEN_it_it(function);CAR_RET;\
GEN_it_it_pred(function);CAR_RET

#define GEN_general_it_it_val(Const, direction, function)\
template<typename Container_t, typename T>\
inline auto direction##function(Container_t Const& c, T const/*This is always const!*/& val) -> decltype(call_it_it_val(direction, function, c, val)) {\
return call_it_it_val(direction, function, c, val);\
}
#define GEN_it_it_val(function)\
GEN_general_it_it_val(     ,  , function);CAR_RET;\
GEN_general_it_it_val(const,  , function);CAR_RET;\
GEN_general_it_it_val(     , r, function);CAR_RET;\
GEN_general_it_it_val(const, r, function)

#define GEN_general_it_it_val_compare(Const, direction, function)\
template<typename Container_t, typename T, typename Compare_t>\
inline auto direction##function(Container_t Const& c, T const/*This is always const!*/& val, Compare_t compare) -> decltype(call_it_it_val_compare(direction, function, c, val, compare)) {\
return call_it_it_val_compare(direction, function, c, val, compare);\
}
#define GEN_it_it_val_compare(function)\
GEN_general_it_it_val_compare(     ,  , function);CAR_RET;\
GEN_general_it_it_val_compare(const,  , function);CAR_RET;\
GEN_general_it_it_val_compare(     , r, function);CAR_RET;\
GEN_general_it_it_val_compare(const, r, function)

#define GEN_it_it_val_and_it_it_val_compare(function)\
GEN_it_it_val(function);CAR_RET;\
GEN_it_it_val_compare(function)

namespace STLPP_namespace {
#define r r
//GEN_it_it_general(adjacent_find, r);
//GEN_it_it_general(adjacent_find,);
GEN_it_it_and_it_it_pred(adjacent_find);
GEN_it_it_and_it_it_pred(max_element);
GEN_it_it_val_and_it_it_val_compare(binary_search);

#if __cplusplus >= 201103L

GEN_it_it_pred(any_of);
GEN_it_it_pred(all_of);

#endif /* __clpusplus */

} /* namespace STLPP_namespace */

//#endif /* STLPP_STLPP_IN_HH_ */
