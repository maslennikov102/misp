#pragma once
#include <string>
#include <stdexcept>

class User
{
    private:
        std::string name;
        std::string password;
        int access;
        int warn;
    public:
        User(std::string n, std::string p, int a = 0, int w = 0);
        bool isBlocked() const;
        virtual void printInfo() const;
        friend void changepass(User& other, std::string newp);
        friend std::ostream& operator<<(std::ostream& out, User& other);
        friend class Moderator;
        friend class Admin;
};

class Moderator : public User
{
    private:
        int cntwarn = 0;
    public:
        using User::User;
        friend class Admin;
        void givewarn(User& other);
        virtual void printInfo() const override;
};

class Admin : public Moderator
{
    public:
        using Moderator::Moderator;
        void printInfo() const override;
        void changePass(User& other, std::string newp);
};

void changepass(User& other, std::string newp);
std::ostream& operator<<(std::ostream& out, User& other);
