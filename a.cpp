#include <iostream>
#include <chrono>
#include <ctime>

class StartToEnd {
public:
    decltype(std::chrono::system_clock::now()) start, end;
    StartToEnd() : start(std::chrono::system_clock::now()) {}
    void set_end(uint64_t ms) { end = start + std::chrono::milliseconds(ms); }
};

int main() {
    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
        << "elapsed time: " << elapsed_seconds.count() << "s"
        << std::endl;
    // StartToEnd tmp;
    // tmp.set_end(10);
    auto now = std::chrono::system_clock::now();
    std::cout << std::ctime(&now);
    // // std::cout << std::ctime(&(tmp.start)) << std::endl << std::ctime(&(tmp.end));
}