#include <iostream>
#include <vector>


// Below is a really long data type
// typedef std::vector<std::pair<std::string, int>> pairlist_t;
// typedef std::string text_t;
// typedef int number_t;

using pairlist_t = std::vector<std::pair<std::string, int>>;
using text_t = std::string;
using number_t = int;

int main() {
    std::vector<std::pair<std::string, int>> pairlist;
    pairlist_t pairlist_2;
    number_t num = 342;
    return 0;
}
