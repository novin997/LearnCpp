#include <coroutine>
#include <exception>
#include <iostream>
#include <optional>

template <typename T>
class Generator
{
public:
    struct promise_type
    {
        T currVal{};

        std::suspend_always yield_value(T value) noexcept
        {
            currVal = std::move(value);
            return std::suspend_always{};
        }

        // the usual members:
        Generator get_return_object() { return Generator(std::coroutine_handle<promise_type>::from_promise(*this)); }
        auto initial_suspend() { return std::suspend_always{}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
        auto final_suspend() noexcept { return std::suspend_always{}; }
    };

    Generator(auto h) : handler{h} {};
    // Generator() = default;
    // Generator(std::coroutine_handle<promise_type> hdl) : handler{hdl} {}
    ~Generator()
    {
        if (handler)
            handler.destroy();
    }
    // no copying or moving:
    Generator(const Generator &) = delete;
    Generator &operator=(const Generator &) = delete;

    bool resume() const
    {
        if (!handler || handler.done())
            return false;
        handler.resume();
        return true;
    }

    T getValue() const
    {
        return handler.promise().currVal;
    }

private:
    std::coroutine_handle<promise_type> handler;
};
