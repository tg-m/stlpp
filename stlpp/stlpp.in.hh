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

#define STLPP_namespace stdpp
#define CAR_RET CAR_RET

namespace STLPP_namespace {
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
template<typename Container_t> inline auto rbegin(Container_t& c) -> decltype(c.rbegin()) {
    return c.rbegin();
}
template<typename Container_t> inline auto rbegin(Container_t const& c) -> decltype(c.rbegin()) {
    return c.rbegin();
}
template<typename Container_t> inline auto rend(Container_t& c) -> decltype(c.rend()) {
    return c.rend();
}
template<typename Container_t> inline auto rend(Container_t const& c) -> decltype(c.rend()) {
    return c.rend();
}

/*
 * NOTE: call_b_e stands for call_begin_end
 * Names of algorithms that search in the reverse order start with r, e.g., all_of vs rall_of
 */
#define call_b_e(dir, function, container)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container))

#define call_b_e_pred(dir, function, container, pred)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), pred)

#define call_b_e_it(dir, function, container, it)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), it)

#define call_b_e_it_pred(dir, function, container, it, pred)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), it, pred)

#define call_b_e_compare(dir, function, container, compare)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), compare)

#define call_b_e_val(dir, function, container, val)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), val)

#define call_b_e_val_compare(dir, function, container, val, compare)\
std::function(STLPP_namespace::dir##begin(container), STLPP_namespace::dir##end(container), val, compare)

#define call_it_num_it(function, it_l, num, it_r)\
std::function(it_l, num, it_r)

#define call_it_num_val(function, it_l, num, val)\
std::function(it_l, num, val)


#define GEN_general_b_e(Const, direction, function)\
template<typename Container_t> inline auto direction##function(Container_t Const& c) -> decltype(call_b_e(direction, function, c)) { return call_b_e(direction, function, c); }
#define GEN_b_e(function)\
GEN_general_b_e(     ,  , function);CAR_RET;\
GEN_general_b_e(const,  , function);CAR_RET;\
GEN_general_b_e(     , r, function);CAR_RET;\
GEN_general_b_e(const, r, function)

#define GEN_general_b_e_pred(Const, direction, function)\
template<typename Container_t, typename Predicate_t>CAR_RET;\
inline auto direction##function(Container_t Const& c, Predicate_t pred) -> decltype(call_b_e_pred(direction, function, c, pred)) {CAR_RET;\
    return call_b_e_pred(direction, function, c, pred);CAR_RET;\
}
#define GEN_b_e_pred(function)\
GEN_general_b_e_pred(     ,  , function);CAR_RET;\
GEN_general_b_e_pred(const,  , function);CAR_RET;\
GEN_general_b_e_pred(     , r, function);CAR_RET;\
GEN_general_b_e_pred(const, r, function)

#define GEN_b_e_and_b_e_pred(function)\
GEN_b_e(function);CAR_RET;\
GEN_b_e_pred(function);CAR_RET

#define GEN_general_b_e_val(Const, direction, function)\
template<typename Container_t, typename T>\
inline auto direction##function(Container_t Const& c, T const/*This is always const!*/& val) -> decltype(call_b_e_val(direction, function, c, val)) {\
return call_b_e_val(direction, function, c, val);\
}
#define GEN_b_e_val(function)\
GEN_general_b_e_val(     ,  , function);CAR_RET;\
GEN_general_b_e_val(const,  , function);CAR_RET;\
GEN_general_b_e_val(     , r, function);CAR_RET;\
GEN_general_b_e_val(const, r, function);CAR_RET
#define GEN_b_e_val_non_const(function)\
GEN_general_b_e_val(     ,  , function);CAR_RET;\
GEN_general_b_e_val(     , r, function);CAR_RET

#define GEN_general_b_e_val_compare(Const, direction, function)\
template<typename Container_t, typename T, typename Compare_t>CAR_RET;\
inline auto direction##function(Container_t Const& c, T const/*This is always const!*/& val, Compare_t compare) -> decltype(call_b_e_val_compare(direction, function, c, val, compare)) {CAR_RET;\
return call_b_e_val_compare(direction, function, c, val, compare);CAR_RET;\
}
#define GEN_b_e_val_compare(function)\
GEN_general_b_e_val_compare(     ,  , function);CAR_RET;\
GEN_general_b_e_val_compare(const,  , function);CAR_RET;\
GEN_general_b_e_val_compare(     , r, function);CAR_RET;\
GEN_general_b_e_val_compare(const, r, function);CAR_RET

#define GEN_b_e_val_and_b_e_val_compare(function)\
GEN_b_e_val(function);CAR_RET;\
GEN_b_e_val_compare(function)

#define GEN_general_b_e_it(Const, direction, function)\
template<typename Container_t, typename Iterator_t>CAR_RET;\
inline auto direction##function(Container_t Const& c, Iterator_t it) -> decltype(call_b_e_it(direction, function, c, it)) {CAR_RET;\
    return call_b_e_it(direction, function, c, it);CAR_RET;\
}
#define GEN_b_e_it(function)\
GEN_general_b_e_it(     ,  , function);CAR_RET;\
GEN_general_b_e_it(const,  , function);CAR_RET;\
GEN_general_b_e_it(     , r, function);CAR_RET;\
GEN_general_b_e_it(const, r, function);CAR_RET

#define GEN_general_b_e_it_pred(Const, direction, function)\
template<typename Container_t, typename Iterator_t, typename Predicate_t>CAR_RET;\
inline auto direction##function(Container_t Const& c, Iterator_t it, Predicate_t pred) -> decltype(call_b_e_it_pred(direction, function, c, it, pred)) {CAR_RET;\
    return call_b_e_it_pred(direction, function, c, it, pred);CAR_RET;\
}
#define GEN_b_e_it_pred(function)\
GEN_general_b_e_it_pred(     ,  , function);CAR_RET;\
GEN_general_b_e_it_pred(const,  , function);CAR_RET;\
GEN_general_b_e_it_pred(     , r, function);CAR_RET;\
GEN_general_b_e_it_pred(const, r, function);CAR_RET

#define GEN_b_e_it_and_b_e_it_pred(function)\
GEN_b_e_it(function);CAR_RET;\
GEN_b_e_it_pred(function);CAR_RET


#define GEN_it_num_it(function)\
template<typename IteratorLeft_t, typename Num_t, typename IteratorRight_t>CAR_RET;\
inline auto function(IteratorLeft_t it_l, Num_t num, IteratorRight_t it_r) -> decltype(call_it_num_it(function, it_l, num, it_r)) {CAR_RET;\
    return call_it_num_it(function, it_l, num, it_r);CAR_RET;\
};CAR_RET

#define GEN_it_num_val(function)\
template<typename Iterator_t, typename Num_t, typename T>CAR_RET;\
inline auto function(Iterator_t it, Num_t num, T const/*This is always const!*/& val) -> decltype(call_it_num_val(function, it, num, val)) {CAR_RET;\
    return call_it_num_val(function, it, num, val);CAR_RET;\
};CAR_RET

GEN_b_e_and_b_e_pred(adjacent_find);
GEN_b_e_and_b_e_pred(max_element);
GEN_b_e_val_and_b_e_val_compare(binary_search);

GEN_b_e_it(copy);
GEN_b_e_it(copy_backward);
GEN_b_e_it_pred(copy_if);
GEN_it_num_it(copy_n);
GEN_b_e_val(count);
GEN_b_e_pred(count_if);
GEN_b_e_it_and_b_e_it_pred(equal);
GEN_b_e_val_and_b_e_val_compare(equal_range);
GEN_b_e_val_non_const(fill);
GEN_it_num_val(fill_n);
GEN_b_e_val(find);


GEN_b_e_pred(any_of);
GEN_b_e_pred(all_of);


} /* namespace STLPP_namespace */

