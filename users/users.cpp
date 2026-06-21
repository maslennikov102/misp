#include "users.h"
#include <iostream>

User::User(std::string n, std::string p, int a, int w)
{
    if (n.length() == 0 || p.length() == 0) throw std::logic_error("Empty string");
    name = n;
    password = p;
    access = a;
    warn = w;
}

bool User::isBlocked() const
{
    return warn > 3 && access == 0;
}

void User::printInfo() const
{
    std::cout << "User: " << name << " Access: " << access << " Warnings: " << warn << std::endl;
}

void Moderator::givewarn(User& other)
{
    if (other.access != 0) throw std::logic_error("Cant give warn to admin/moder");
    other.warn += 1;
    cntwarn++;
}

void Moderator::printInfo() const
{
    std::cout << "Moder: " << name << " Access: " << access << " Warned: " << cntwarn << std::endl;
}

void Admin::printInfo() const
{
    std::cout << "Admin: " << name << " Access: " << access << " Warned: " << cntwarn << std::endl;
}

void Admin::changePass(User& other, std::string newp)
{
    if (other.access >= 2) throw std::logic_error("Cant change password of admin");
    changepass(other, newp);
}

void changepass(User& other, std::string newp)
{
    other.password = newp;
}

std::ostream& operator<<(std::ostream& out, User& other)
{
    out << "User: " << other.name << " Password: " << other.password << " Warnings: " << other.warn;
    return out;
}
