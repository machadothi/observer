#include <iostream>
#include <memory>
#include <list>
#include <string>

#include "TestSubject.h"

class Observer : public IObserver {
public:
    Observer(std::shared_ptr<Subject> subject) : subject_(subject) {
        this->subject_->Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_;
    }
    virtual ~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_->Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    std::shared_ptr<Subject> subject_;
    static int static_number_;
    int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
    
    auto subject = std::make_shared<Subject>();
    auto observer1 = std::make_unique<Observer>(subject);
    auto observer2 = std::make_unique<Observer>(subject);
    auto observer3 = std::make_unique<Observer>(subject);

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    auto observer4 = std::make_unique<Observer>(subject);

    observer2->RemoveMeFromTheList();
    auto observer5 = std::make_unique<Observer>(subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();
}

int main() {
    ClientCode();
    return 0;
}