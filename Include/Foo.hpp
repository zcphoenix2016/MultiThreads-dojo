#pragma once

class Foo
{
public:
    explicit Foo(int p_id) : m_id(p_id)
    {
    }

    int getId();

private:
    int m_id = 0;
};
