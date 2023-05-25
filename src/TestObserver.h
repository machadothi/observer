#ifndef SRC_TEST_OBSERVER_H_
#define SRC_TEST_OBSERVER_H_

#include "ISubject.h"

class Observer : public IObserver {
public:
    Observer(ISubject_ptr subject);
    virtual ~Observer();

    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    ISubject_ptr subject_;
    static int static_number_;
    int number_;
};

#endif // SRC_TEST_OBSERVER_H_