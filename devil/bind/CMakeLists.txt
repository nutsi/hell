project(test_bind)

add_executable(
  ./test_bind
  main.cpp
  Caller.hpp
  Storage.hpp
  Value.hpp
  TypeList.hpp
  TypeTraits.hpp
)
