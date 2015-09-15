#pragma once

#include <vector>

#include "cpp_redis/replies/reply.hpp"

namespace cpp_redis {

namespace replies {

class array_reply : public reply {
public:
    //! ctor & dtor
    array_reply(const std::vector<std::shared_ptr<reply>>& rows = {});
    ~array_reply(void) = default;

    //! copy ctor & assignment operator
    array_reply(const array_reply&) = default;
    array_reply& operator=(const array_reply&) = default;

public:
    //! getters
    unsigned int size(void) const;
    const std::vector<std::shared_ptr<reply>>& get_rows(void) const;

    const std::shared_ptr<reply>& get(unsigned int idx) const;
    const std::shared_ptr<reply>& operator[](unsigned int idx) const;

    //! setters
    void set_rows(const std::vector<std::shared_ptr<reply>>& rows);
    void add_row(const std::shared_ptr<reply>& row);
    void operator<<(const std::shared_ptr<reply>& row);

private:
    std::vector<std::shared_ptr<reply>> m_rows;
};

} //! replies

} //! cpp_redis
