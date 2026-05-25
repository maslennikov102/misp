#include <iostream>
#include "users.h"

int main()
{
    User user("matvey", "pass123");
    Moderator moder("yarik", "sixseven!", 1);
    Admin admin("jeff", "admin", 2);

    user.printInfo();
    moder.printInfo();
    admin.printInfo();
    std::cout << std::endl;

    std::cout << user << std::endl;

    std::cout << "matvey isBlocked: " << user.isBlocked() << std::endl;

    moder.givewarn(user);
    moder.givewarn(user);
    moder.givewarn(user);
    moder.givewarn(user);
    std::cout << "matvey isBlocked after 4 warns: " << user.isBlocked() << std::endl;
    moder.printInfo();
    std::cout << std::endl;
    std::cout << "before changePass: " << user << std::endl;
    admin.changePass(user, "123j13109213j");
    std::cout << "after changePass:  " << user << std::endl;
    std::cout << std::endl;
    User* arr[3];
    arr[0] = new User("user1", "p1");
    arr[1] = new Moderator("moder1", "p2", 1);
    arr[2] = new Admin("admin1", "p3", 2);
    for (int i = 0; i < 3; i++)
    {
        arr[i]->printInfo();
    }

    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }

    std::cout << std::endl;
    try
    {
        moder.givewarn(admin); 
    }
    catch (std::logic_error& e)
    {
        std::cout << "givewarn exception: " << e.what() << std::endl;
    }

    try
    {
        User emptyName("", "pass");
    }
    catch (std::logic_error& e)
    {
        std::cout << "constructor exception: " << e.what() << std::endl;
    }

    try
    {
        admin.changePass(admin, "hack");
    }
    catch (std::logic_error& e)
    {
        std::cout << "changePass exception: " << e.what() << std::endl;
    }

    return 0;
}
