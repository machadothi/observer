#ifndef SRC_ISUBJECT_H_
#define SRC_ISUBJECT_H_

#include "IObserver.h"

class ISubject {
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

#endif // SRC_ISUBJECT_H_