add_executable(observer main.cpp TestSubject.cpp TestObserver.cpp)

target_compile_options(observer PUBLIC -Wall -Wextra)