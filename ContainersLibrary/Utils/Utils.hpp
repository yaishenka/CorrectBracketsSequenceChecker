/** @author yaishenka
    @date 08.10.2020 */
#pragma once

#include <iostream>

namespace Containers {
  namespace Utils {
  template <class Class>
    struct HasOstreamOperatorImpl {
     public:
      template <class V>
      static auto HasOstreamOperatorCheck(V*)
      -> decltype(std::declval<std::ostream>() << std::declval<V>());

      template <typename>
      static auto HasOstreamOperatorCheck(...) -> std::false_type;

      using Type = typename std::is_same<
          std::ostream&, decltype(HasOstreamOperatorCheck<Class>(nullptr))>::type;
    };

    template <class Class>
    struct HasOstreamOperator : HasOstreamOperatorImpl<Class>::Type {};
  }
}