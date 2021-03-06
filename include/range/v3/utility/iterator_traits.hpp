/// \file
// Range v3 library
//
//  Copyright Eric Niebler 2013-2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//

#ifndef RANGES_V3_UTILITY_ITERATOR_TRAITS_HPP
#define RANGES_V3_UTILITY_ITERATOR_TRAITS_HPP

#include <type_traits>
#include <range/v3/range_fwd.hpp>
#include <range/v3/utility/meta.hpp>
#include <range/v3/utility/iterator_concepts.hpp>

namespace ranges
{
    inline namespace v3
    {
        /// \addtogroup group-core
        /// @{
        ////////////////////////////////////////////////////////////////////////////////////////////
        // iterator traits
        template<typename I>
        using iterator_value_t = concepts::Readable::value_t<I>;

        template<typename I>
        using iterator_reference_t = concepts::Readable::reference_t<I>;

        template<typename I>
        using iterator_rvalue_reference_t = concepts::Readable::rvalue_reference_t<I>;

        template<typename I>
        using iterator_common_reference_t = concepts::Readable::common_reference_t<I>;

        template<typename I>
        using iterator_category_t = concepts::WeakInputIterator::category_t<I>;

        template<typename I>
        using iterator_difference_t = concepts::WeaklyIncrementable::difference_t<I>;

        template<typename I>
        using iterator_size_t = meta::eval<std::make_unsigned<iterator_difference_t<I>>>;

        // Metafunctions
        template<typename I>
        using iterator_category = meta::defer<iterator_category_t, I>;

        template<typename I>
        using iterator_value = meta::defer<iterator_value_t, I>;

        template<typename I>
        using iterator_difference = meta::defer<iterator_difference_t, I>;

        template<typename I>
        using iterator_reference = meta::defer<iterator_reference_t, I>;

        template<typename I>
        using iterator_rvalue_reference = meta::defer<iterator_rvalue_reference_t, I>;

        template<typename I>
        using iterator_common_reference = meta::defer<iterator_common_reference_t, I>;

        template<typename I>
        using iterator_size = meta::defer<iterator_size_t, I>;
        /// @}
    }
}

#endif // RANGES_V3_UTILITY_ITERATOR_TRAITS_HPP
