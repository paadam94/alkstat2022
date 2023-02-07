#include <vector>

// reads stdin into a 2d vector
template <typename T>
void stdin_to_2dvec(std::vector<std::vector<T>> &vec);

// creates a vector of combinations of k element of vec
template <typename T>
std::vector<std::vector<T>> combine(std::vector<T> vec, std::size_t k);

