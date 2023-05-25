#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include <string>

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;

    typedef std::shared_ptr<IObserver> ptr_t;
};

typedef IObserver::ptr_t IObserver_ptr;

#endif // SRC_IOBSERVER_H_