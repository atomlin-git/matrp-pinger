#include "headers.hpp"

prequest req;

int main() {
    req.hello();
    std::this_thread::sleep_for(std::chrono::seconds(3));
};
