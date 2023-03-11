#ifndef ISUM_H
#define ISUM_H

class ISum
{
public:
    virtual ~ISum() = default;

    virtual int Add(int data) = 0;
};

#endif // ISUM_H
