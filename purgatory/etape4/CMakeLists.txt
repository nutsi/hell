project(test_nsa_to_dfa)

add_executable(
  ./test_nsa_to_dfa
  main.cpp
  Edge.cpp
  Edge.hpp
  State.cpp
  State.hpp
  FSA.cpp
  FSA.hpp
  Matcher.cpp
  Matcher.hpp
)
