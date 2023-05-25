#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include <string>

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

#endif // SRC_IOBSERVER_H_