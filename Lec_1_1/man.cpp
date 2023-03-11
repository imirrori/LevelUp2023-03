#include "man.h"

Man::Man(std::shared_ptr<ISum> sum)
    : _sum{std::move(sum)}
{
    if (!_sum) {
        throw std::exception{};
    }
}

int Man::Sum(const std::vector<int> &data)
{
    int result = 0;
    for(auto el: data) {
        result = _sum->Add(el);
    }
    return result;
}
