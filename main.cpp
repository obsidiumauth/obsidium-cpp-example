#include <cstdint>
#include <iostream>
#include <string>

#include "obsidium.hpp"
#include "skcrypt.h"

int main()
{
    /*
        SDK Init
    */

    auto app_id = skCrypt("APP-ID");
    auto app_version = skCrypt("APP-VERSION");

    const auto init_result = obsidium::init(app_id.decrypt(), app_version.decrypt());

    std::cout << skCrypt("init success: ").decrypt() << init_result.success << '\n';
    std::cout << skCrypt("init message: ").decrypt() << init_result.message << '\n';

    if (!init_result.success) {
        return 1;
    }

    /*
        Auth Menu
    */

    std::cout << skCrypt("\nSelect an option:\n").decrypt();
    std::cout << skCrypt("1. Login\n").decrypt();
    std::cout << skCrypt("2. Register\n").decrypt();
    std::cout << skCrypt("3. License Login\n").decrypt();
    std::cout << skCrypt("4. Activate License / Subscription\n").decrypt();
    std::cout << skCrypt("> ").decrypt();

    int option = 0;
    std::cin >> option;

    switch (option) {
    case 1:
    {
        /*
            Login Usage
        */

        std::string username;
        std::string password;

        std::cout << skCrypt("\nUsername: ").decrypt();
        std::cin >> username;

        std::cout << skCrypt("Password: ").decrypt();
        std::cin >> password;

        const auto login_result = obsidium::login(username, password);

        std::cout << skCrypt("\nlogin success: ").decrypt() << login_result.success << '\n';
        std::cout << skCrypt("login message: ").decrypt() << login_result.message << '\n';
        std::cout << skCrypt("login expiry: ").decrypt() << login_result.expiry << '\n';

        for (const auto& subscription : login_result.subscriptions) {
            std::cout << skCrypt("subscription id: ").decrypt() << subscription.id << '\n';
            std::cout << skCrypt("subscription name: ").decrypt() << subscription.name << '\n';
            std::cout << skCrypt("subscription slug: ").decrypt() << subscription.slug << '\n';
            std::cout << skCrypt("subscription expires_at: ").decrypt() << subscription.expires_at << '\n';
            std::cout << skCrypt("subscription expiry: ").decrypt() << subscription.expiry << '\n';
        }

        break;
    }
    case 2:
    {
        /*
            Register Usage
        */

        std::string username;
        std::string password;
        std::string license_key;

        std::cout << skCrypt("\nUsername: ").decrypt();
        std::cin >> username;

        std::cout << skCrypt("Password: ").decrypt();
        std::cin >> password;

        std::cout << skCrypt("License key: ").decrypt();
        std::cin >> license_key;

        const auto register_result = obsidium::register_user(username, password, license_key);

        std::cout << skCrypt("\nregister_user success: ").decrypt() << register_result.success << '\n';
        std::cout << skCrypt("register_user message: ").decrypt() << register_result.message << '\n';

        break;
    }
    case 3:
    {
        /*
            License Login Usage
        */

        std::string license_key;

        std::cout << skCrypt("\nLicense key: ").decrypt();
        std::cin >> license_key;

        const auto license_result = obsidium::license(license_key);

        std::cout << skCrypt("\nlicense success: ").decrypt() << license_result.success << '\n';
        std::cout << skCrypt("license message: ").decrypt() << license_result.message << '\n';
        std::cout << skCrypt("license license_required: ").decrypt() << license_result.license_required << '\n';
        std::cout << skCrypt("license expiry: ").decrypt() << license_result.expiry << '\n';

        break;
    }
    case 4:
    {
        /*
            Activate License / Subscription Usage
        */

        std::string username;
        std::string license_key;

        std::cout << skCrypt("\nUsername: ").decrypt();
        std::cin >> username;

        std::cout << skCrypt("License key: ").decrypt();
        std::cin >> license_key;

        const auto activate_license_result = obsidium::activate_license(license_key, username);

        std::cout << skCrypt("\nactivate_license username: ").decrypt() << username << '\n';
        std::cout << skCrypt("activate_license success: ").decrypt() << activate_license_result.success << '\n';
        std::cout << skCrypt("activate_license message: ").decrypt() << activate_license_result.message << '\n';
        std::cout << skCrypt("activate_license license_required: ").decrypt() << activate_license_result.license_required << '\n';
        std::cout << skCrypt("activate_license expiry: ").decrypt() << activate_license_result.expiry << '\n';

        break;
    }
    default:
        std::cout << skCrypt("\nInvalid option.").decrypt() << '\n';
        break;
    }

    /*
        Log Usage

        const bool log_result = obsidium::log(
            skCrypt("Application started").decrypt(),
            obsidium::log_level::info);

        std::cout << skCrypt("log success: ").decrypt() << log_result << '\n';

        if (!log_result) {
            std::cout << skCrypt("log last_error: ").decrypt() << obsidium::last_error() << '\n';
        }
    */





    /*
        Variable Usage

        auto variable_name = skCrypt("news_message");

        const auto variable_result = obsidium::variable(variable_name.decrypt());

        std::cout << skCrypt("variable success: ").decrypt() << variable_result.success << '\n';
        std::cout << skCrypt("variable message: ").decrypt() << variable_result.message << '\n';

        if (variable_result.success) {
            std::cout << skCrypt("variable value: ").decrypt() << variable_result.value << '\n';
        }
    */





    /*
        User Variable Usage

        auto user_variable_key = skCrypt("theme");

        const auto user_variable_result = obsidium::user_variable(user_variable_key.decrypt());

        std::cout << skCrypt("user_variable success: ").decrypt() << user_variable_result.success << '\n';
        std::cout << skCrypt("user_variable message: ").decrypt() << user_variable_result.message << '\n';

        if (user_variable_result.success) {
            std::cout << skCrypt("user_variable key: ").decrypt() << user_variable_result.key << '\n';
            std::cout << skCrypt("user_variable value: ").decrypt() << user_variable_result.value << '\n';
        }
    */





    /*
        Update User Variable Usage

        auto user_variable_key = skCrypt("theme");
        auto user_variable_value = skCrypt("dark");

        const auto update_user_variable_result = obsidium::update_user_variable(
            user_variable_key.decrypt(),
            user_variable_value.decrypt());

        std::cout << skCrypt("update_user_variable success: ").decrypt() << update_user_variable_result.success << '\n';
        std::cout << skCrypt("update_user_variable message: ").decrypt() << update_user_variable_result.message << '\n';

        if (update_user_variable_result.success) {
            std::cout << skCrypt("update_user_variable key: ").decrypt() << update_user_variable_result.key << '\n';
            std::cout << skCrypt("update_user_variable value: ").decrypt() << update_user_variable_result.value << '\n';
        }
    */





    /*
        File Usage

        auto file_name = skCrypt("config.bin");

        const auto file_result = obsidium::file(file_name.decrypt());

        std::cout << skCrypt("file success: ").decrypt() << file_result.success << '\n';
        std::cout << skCrypt("file message: ").decrypt() << file_result.message << '\n';

        if (file_result.success) {
            std::cout << skCrypt("file size_bytes: ").decrypt() << file_result.size_bytes << '\n';
            std::cout << skCrypt("file bytes read: ").decrypt() << static_cast<std::uint64_t>(file_result.bytes.size()) << '\n';
        }
    */





    /*
        Ban Usage

        const auto ban_result = obsidium::ban();

        std::cout << skCrypt("ban success: ").decrypt() << ban_result.success << '\n';
        std::cout << skCrypt("ban message: ").decrypt() << ban_result.message << '\n';
    */

    return 0;
}
