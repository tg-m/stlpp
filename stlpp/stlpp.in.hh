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

/*
 * if container will be get as sth.next(), then next will be called twice
 */
#define call_it_it(function, container)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container))

#define call_it_it_pred(function, container, pred)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), pred)

#define call_it_it_compare(function, container, compare)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), compare)

#define call_it_it_val(function, container, val)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), val)

#define call_it_it_val_compare(function, container, val, compare)\
std::function(STLPP_namespace::begin(container), STLPP_namespace::end(container), val, compare)

#define GEN_it_it_general(function)\
template<typename Container_t>\
inline auto function(Container_t& c) -> decltype(std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c))) {\
return std::function(STLPP_namespace::begin(c), STLPP_namespace::end(c));\
}

#define GEN_ref_it_it(function)\
template<typename Container_t> inline auto function(Container_t& c) -> decltype(call_it_it(function, c)) { return call_it_it(function, c); }

#define GEN_const_ref_it_it(function)\
template<typename Container_t> inline auto function(Container_t const& c) -> decltype(call_it_it(function, c)) { return call_it_it(function, c); }

#define GEN_it_it(function)\
GEN_ref_it_it(function);\
GEN_const_ref_it_it(function)

#define GEN_ref_it_it_pred(function)\
template<typename Container_t, typename Predicate_t> inline auto function(Container_t& c, Predicate_t pred) -> decltype(call_it_it_pred(function, c, pred)) { return call_it_it_pred(function, c, pred); }

#define GEN_const_ref_it_it_pred(function)\
template<typename Container_t, typename Predicate_t> inline auto function(Container_t const& c, Predicate_t pred) -> decltype(call_it_it_pred(function, c, pred)) { return call_it_it_pred(function, c, pred); }

#define GEN_it_it_pred(function)\
GEN_ref_it_it_pred(function);\
GEN_const_ref_it_it_pred(function)

#define GEN_it_it_and_it_it_pred(function)\
GEN_ref_it_it(function);\
GEN_it_it_pred(function)

#define GEN_ref_it_it_val(function)\
template<typename Container_t, typename T> inline auto function(Container_t& c, T const& val) -> decltype(call_it_it_val(function, c, val)) { return call_it_it_val(function, c, val); }

#define GEN_const_ref_it_it_val(function)\
template<typename Container_t, typename T> inline auto function(Container_t const& c, T const& val) -> decltype(call_it_it_val(function, c, val)) { return call_it_it_val(function, c, val); }

#define GEN_ref_it_it_val_compare(function)\
template<typename Container_t, typename T, typename Compare_t>\
inline auto function(Container_t& c, T const& val, Compare_t const& compare) -> decltype(call_it_it_val_compare(function, c, val, compare)){ return call_it_it_val_compare(function, c, val, compare); }

#define GEN_const_ref_it_it_val_compare(function)\
template<typename Container_t, typename T, typename Compare_t> \
inline auto function(Container_t const& c, T const& val, Compare_t const& compare) -> decltype(call_it_it_val_compare(function, c, val, compare)) { return call_it_it_val_compare(function, c, val, compare); }

namespace STLPP_namespace {
#define function_name adjacent_find
GEN_ref_it_it(function_name);
GEN_const_ref_it_it(function_name);
GEN_ref_it_it_pred(function_name);
GEN_const_ref_it_it_pred(function_name);
#undef function_name
//GEN_it_it_and_it_it_pred(adjacent_find);

#define function_name max_element
GEN_ref_it_it(function_name);
GEN_const_ref_it_it(function_name);
GEN_ref_it_it_pred(function_name);
GEN_const_ref_it_it_pred(function_name);
#undef function_name
//GEN_it_it_and_it_it_pred(max_element);

#define function_name binary_search
GEN_ref_it_it_val(function_name);
GEN_const_ref_it_it_val(function_name);
GEN_ref_it_it_val_compare(function_name);
GEN_const_ref_it_it_val_compare(function_name);
#undef function_name

#if __cplusplus >= 201103L

//GEN_it_it_pred_RETURN_bool(all_of);
#define function_name all_of
GEN_ref_it_it_pred(function_name);
GEN_const_ref_it_it_pred(function_name);
#undef function_name

//GEN_it_it_pred_RETURN_bool(any_of);
#define function_name any_of
GEN_ref_it_it_pred(function_name);
GEN_const_ref_it_it_pred(function_name);
#undef function_name

#endif /* __clpusplus */

} /* namespace STLPP_namespace */

//#endif /* STLPP_STLPP_IN_HH_ */
