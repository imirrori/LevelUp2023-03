#ifndef MAN_H
#define MAN_H

#include "isum.h"

#include <memory>
#include <vector>

class Man
{
public:
    explicit Man(std::shared_ptr<ISum> sum);

    int Sum(const std::vector<int>& data);

private:
    std::shared_ptr<ISum> _sum;
};

#endif // MAN_H
